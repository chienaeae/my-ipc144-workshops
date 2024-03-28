/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Chia-Yu Chien
Student ID#: 157049222
Email      : cchien8@myseneca.ca
Section    : NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient *patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ",
               patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do
    {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient *patient)
{
    int selection;

    do
    {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ",
               patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}

// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    if (max == 0)
    {
        printf("*** No records found ***\n");
        putchar('\n');
        return;
    }
    displayPatientTableHeader();

    int i = 0;
    for (i = 0; i < max; i++)
    {
        const struct Patient *p = &patient[i];
        if (p->patientNumber)
        {
            displayPatientData(p, FMT_TABLE);
        }
    }
    putchar('\n');
}

// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max)
{
    int selection;
    do
    {
        printf("Search Options\n"
               "==========================\n"
               "1) By patient number\n"
               "2) By phone number\n"
               "..........................\n"
               "0) Previous menu\n"
               "..........................\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        switch (selection)
        {
        case 1:
            searchPatientByPatientNumber(patient, max);
            suspend();
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max)
{
    // find bound to add
    int bound = 0;
    int i = 0;
    for (i = 0; i < max; i++)
    {
        struct Patient *p = &patient[i];
        if (p->patientNumber)
        {
            bound = i;
        }
        else
        {
            break;
        }
    }

    // check is full
    if (bound + 1 >= max)
    {
        printf("ERROR: Patient listing is FULL!\n");
        putchar('\n');
        return;
    }
    // create new paitent
    struct Patient newPatint = {};
    newPatint.patientNumber = nextPatientNumber(patient, max);
    inputPatient(&newPatint);

    // append new paitent
    patient[bound + 1] = newPatint;
    printf("*** New patient record added ***\n");
    putchar('\n');
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max)
{
    printf("Enter the patient number: ");
    int patientNum = inputIntPositive();
    putchar('\n');
    int index = findPatientIndexByPatientNum(patientNum, patient, max);
    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n");
        putchar('\n');
    }
    else
    {
        struct Patient *p = &patient[index];
        menuPatientEdit(p);
    }
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max)
{
    printf("Enter the patient number: ");
    int patientNum = inputIntPositive();
    putchar('\n');
    int index = findPatientIndexByPatientNum(patientNum, patient, max);
    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n");
        putchar('\n');
    }
    else
    {
        // display patient data to remove
        struct Patient *p = &patient[index];
        displayPatientData(p, FMT_FORM);
        putchar('\n');

        // prompt to ensure remove
        char option;
        printf("Are you sure you want to remove this patient record? (y/n): ");
        option = inputCharOption("yn") == 'y';

        // handle option
        if (option)
        {
            p->patientNumber = 0;
            printf("Patient record has been removed!\n");
            putchar('\n');
        }
        else
        {
            printf("Operation aborted.\n");
            putchar('\n');
        }
    }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    printf("Search by patient number: ");
    int patientNum = inputIntPositive();
    putchar('\n');
    int index = findPatientIndexByPatientNum(patientNum, patient, max);
    if (index == -1)
    {
        printf("*** No records found ***\n");
        putchar('\n');
    }
    else
    {
        const struct Patient *p = &patient[index];
        displayPatientData(p, FMT_FORM);
        putchar('\n');
    }
}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    printf("Search by phone number: ");
    char phoneNumber[PHONE_LEN + 1];
    inputCString(phoneNumber, PHONE_LEN, PHONE_LEN);
    putchar('\n');

    displayPatientTableHeader();
    int any = 0;
    int i = 0;
    for (i = 0; i < max; i++)
    {
        const struct Patient *p = &patient[i];
        if (p->patientNumber && strcmp(p->phone.number, phoneNumber) == 0)
        {
            displayPatientData(p, FMT_TABLE);
            any = 1;
        }
    }
    putchar('\n');

    if (any == 0)
    {
        printf("*** No records found ***\n");
        putchar('\n');
    }
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int maxPaitentNumber = 0;
    int i = 0;
    for (i = 0; i < max; i++)
    {
        const struct Patient *p = &patient[i];
        if (p->patientNumber > maxPaitentNumber)
        {
            maxPaitentNumber = p->patientNumber;
        }
    }
    return maxPaitentNumber + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber,
                                 const struct Patient patient[], int max)
{
    int i = 0;
    for (i = 0; i < max; i++)
    {
        const struct Patient *p = &patient[i];
        if (p->patientNumber && p->patientNumber == patientNumber)
        {
            return i;
        }
    }
    return -1;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient *patient)
{
    printf("Patient Data Input\n"
           "------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    char name[NAME_LEN];
    inputCString(name, 0, NAME_LEN);
    strcpy(patient->name, name);
    putchar('\n');
    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone *phone)
{
    int flag = 1;
    int selection;
    do
    {
        printf("Phone Information\n"
               "-----------------\n"
               "How will the patient like to be contacted?\n"
               "1. Cell\n"
               "2. Home\n"
               "3. Work\n"
               "4. TBD\n"
               "Selection: ");
        selection = inputIntRange(1, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            strcpy(phone->description, "CELL");
            flag = 0;
            break;
        case 2:
            strcpy(phone->description, "HOME");
            flag = 0;
            break;
        case 3:
            strcpy(phone->description, "WORK");
            flag = 0;
            break;
        case 4:
            strcpy(phone->description, "TBD");
            flag = 0;
            break;
        }
    } while (flag);

    if (selection != 4)
    {
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        char phoneNumber[PHONE_LEN + 1];
        inputCString(phoneNumber, PHONE_LEN, PHONE_LEN);
        putchar('\n');
        strcpy(phone->number, phoneNumber);
    }
}
