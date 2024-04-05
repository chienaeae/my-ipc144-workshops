/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date *date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient *patient,
                         const struct Appointment *appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData *data)
{
    int selection;

    do
    {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data); // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient); // ToDo: You will need to create this function!
            suspend();
            break;
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
    for (bound = 0; bound < max; bound++)
    {
        struct Patient *p = &patient[bound];
        if (!p->patientNumber)
        {
            break;
        }
    }

    // check is full
    if (bound >= max)
    {
        printf("ERROR: Patient listing is FULL!\n");
        putchar('\n');
        return;
    }
    // create new paitent
    struct Patient newPatint = {0, {}, {}};
    newPatint.patientNumber = nextPatientNumber(patient, max);
    inputPatient(&newPatint);

    // append new paitent
    patient[bound] = newPatint;
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

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData *data)
{
    int isAllRecords = 1;
    int includeDateField = 1;
    displayScheduleTableHeader(NULL, isAllRecords);

    int i = 0;
    for (i = 0; i < data->maxAppointments; i++)
    {
        const struct Appointment *appointment = &data->appointments[i];

        // find the patient by patientNumber
        const struct Patient *patient = NULL;
        int patientIndex = getPatientIndexByPatientNumber(data->patients, data->maxPatient, appointment->patientNumber);
        if (patientIndex != -1)
        {
            patient = &data->patients[patientIndex];
        }

        if (patient != NULL)
        {
            displayScheduleData(patient, appointment, includeDateField);
        }
    }

    putchar('\n');
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData *data)
{
    struct Date searchDate;
    inputDate(&searchDate);
    putchar('\n');

    int isAllRecords = 0;
    int includeDateField = 0;
    displayScheduleTableHeader(&searchDate, isAllRecords);

    int i = 0;
    for (i = 0; i < data->maxAppointments; i++)
    {
        struct Date appointmentDate = data->appointments[i].date;
        if (dateCmp(appointmentDate, searchDate) == 0)
        {
            const struct Appointment *appointment = &data->appointments[i];

            // find the patient by patientNumber
            const struct Patient *patient = NULL;
            int patientIndex = getPatientIndexByPatientNumber(data->patients, data->maxPatient, appointment->patientNumber);
            if (patientIndex != -1)
            {
                patient = &data->patients[patientIndex];
            }

            if (patient != NULL)
            {
                displayScheduleData(patient, appointment, includeDateField);
            }
        }
    }

    putchar('\n');
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment *appointments, int maxAppointments,
                    struct Patient *patients, int maxPatient)
{
    // find bound to add
    int bound = 0;
    for (bound = 0; bound < maxAppointments; bound++)
    {
        struct Appointment *p = &appointments[bound];
        if (!p->patientNumber)
        {
            break;
        }
    }

    // check is full
    if (bound >= maxAppointments)
    {
        printf("ERROR: Appointment listing is FULL!\n");
        putchar('\n');
        return;
    }

    struct Appointment newAppointment;
    inputAppointment(&newAppointment);
    printf("\n");

    int flag = 1;
    do
    {
        // check valid appointment time range
        if (newAppointment.time.hour < START_HOUR || newAppointment.time.hour > END_HOUR)
        {
            printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n",
                   START_HOUR, END_HOUR, APPOINTMENT_INTERVAL);
            putchar('\n');
            inputTime(&newAppointment.time);
            flag = 1;
        }
        else if (newAppointment.time.hour == END_HOUR && newAppointment.time.min != 0)
        {
            printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n",
                   START_HOUR, END_HOUR, APPOINTMENT_INTERVAL);
            putchar('\n');
            inputTime(&newAppointment.time);
            flag = 1;
        }
        // check overlap time booking
        else if (newAppointment.time.min % APPOINTMENT_INTERVAL != 0)
        {
            printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n",
                   START_HOUR, END_HOUR, APPOINTMENT_INTERVAL);
            putchar('\n');
            inputTime(&newAppointment.time);
            flag = 1;
        }
        // check timeslot is available
        else if (getAppointmentIndexByTime(appointments, maxAppointments, &newAppointment.date, &newAppointment.time) != -1)
        {
            printf("ERROR: Appointment timeslot is not available!\n");
            putchar('\n');
            inputDate(&newAppointment.date);
            inputTime(&newAppointment.time);
            flag = 1;
        }
        else
        {
            appointments[bound] = newAppointment;
            bubbleSortAppointments(appointments, maxAppointments);
            putchar('\n');
            printf("*** Appointment scheduled! ***\n");
            putchar('\n');
            flag = 0;
        }

    } while (flag);
}

// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment *appointments, int maxAppointments,
                       struct Patient *patients, int maxPatient)
{
    // input patient number
    printf("Patient Number: ");
    int patientNumber = inputIntPositive();
    int patientIndex = getPatientIndexByPatientNumber(patients, maxPatient, patientNumber);
    if (patientIndex == -1)
    {
        printf("ERROR: Patient record not found!\n");
        printf("\n");
        return;
    }

    // input date
    struct Date date;
    inputDate(&date);
    printf("\n");

    // iterate appointments
    int i = 0;
    for (i = 0; i < maxAppointments; i++)
    {
        if (appointments[i].patientNumber == patientNumber && dateCmp(appointments[i].date, date) == 0)
        {
            struct Patient *p = NULL;

            // find patient to remove
            int patientIndex = getPatientIndexByPatientNumber(patients, maxPatient, patientNumber);
            if (patientIndex != -1)
            {
                p = &patients[patientIndex];
            }

            if (p != NULL)
            {
                displayPatientData(p, FMT_FORM);

                // prompt to ensure remove
                char option;
                printf("Are you sure you want to remove this appointment (y,n): ");
                option = inputCharOption("yn") == 'y';

                // handle option
                if (option)
                {
                    appointments[i].patientNumber = 0;
                    putchar('\n');
                    printf("Appointment record has been removed!\n");
                    putchar('\n');
                }
                else
                {
                    printf("Operation aborted.\n");
                    putchar('\n');
                }
            }
        }
    }
}

int getPatientIndexByPatientNumber(struct Patient *patients, int maxPatient,
                                   int patientNumber)
{
    int i = 0;
    for (i = 0; i < maxPatient; i++)
    {
        if (patients[i].patientNumber == patientNumber)
        {
            return i;
        }
    }
    return -1;
}

// Get an appointment index from appointment list by date and time
int getAppointmentIndexByTime(struct Appointment *appointments, int maxAppointments,
                              struct Date *date, struct Time *time)
{
    int i = 0;
    for (i = 0; i < maxAppointments; i++)
    {
        struct Date appointmentDate = appointments[i].date;
        struct Time appointmentTime = appointments[i].time;
        if (dateCmp(appointmentDate, *date) == 0 && timeCmp(appointmentTime, *time) == 0)
        {
            return i;
        }
    }
    return -1;
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

void swapAppointments(struct Appointment *x, struct Appointment *y)
{
    struct Appointment z = *x;
    *x = *y;
    *y = z;
}

void bubbleSortAppointments(struct Appointment *appointments, int maxAppointments)
{
    if (appointments == NULL || maxAppointments <= 1)
    {
        return;
    }

    int bound = maxAppointments;
    for (bound = maxAppointments; bound >= 1; bound--)
    {
        int i = 1;
        for (i = 1; i < bound; i++)
        {
            struct Appointment prev = appointments[i - 1];
            struct Appointment curr = appointments[i];

            // date multiply a bigger base than time's
            int c = dateCmp(prev.date, curr.date) * 10;
            c += timeCmp(prev.time, curr.time);

            if (c > 0)
            {
                swapAppointments(&appointments[i - 1], &appointments[i]);
            }
        }
    }
}

// Compare two dates
int dateCmp(struct Date x, struct Date y)
{
    if (x.year > y.year)
    {
        return 1;
    }
    else if (x.year < y.year)
    {
        return -1;
    }
    else if (x.month > y.month)
    {
        return 1;
    }
    else if (x.month < y.month)
    {
        return -1;
    }
    else if (x.day > y.day)
    {
        return 1;
    }
    else if (x.day < y.day)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

// Compare two times
int timeCmp(struct Time x, struct Time y)
{

    if (x.hour > y.hour)
    {
        return 1;
    }
    else if (x.hour < y.hour)
    {
        return -1;
    }
    else if (x.min > y.min)
    {
        return 1;
    }
    else if (x.min < y.min)
    {
        return -1;
    }
    else
    {
        return 0;
    }
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
    char name[NAME_LEN + 1];
    inputCString(name, 0, NAME_LEN);
    strncpy(patient->name, name, sizeof(patient->name) - 1);
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
            strncpy(phone->description, "CELL", sizeof(phone->description) - 1);
            flag = 0;
            break;
        case 2:
            strncpy(phone->description, "HOME", sizeof(phone->description) - 1);
            flag = 0;
            break;
        case 3:
            strncpy(phone->description, "WORK", sizeof(phone->description) - 1);
            flag = 0;
            break;
        case 4:
            strncpy(phone->description, "TBD", sizeof(phone->description) - 1);
            flag = 0;
            break;
        }
    } while (flag);

    if (selection != 4)
    {
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        char phoneNumber[PHONE_LEN + 1];

        int size = 0;
        do
        {
            char temp[PHONE_LEN + 1];
            scanf(" %[^\n]", temp);
            clearInputBuffer();
            size = strlen(temp);
            if (size != PHONE_LEN)
            {
                printf("Invalid 10-digit number! ");
                printf("Number: ");
            }
            else
            {
                putchar('\n');
                strncpy(phoneNumber, temp, PHONE_LEN);
            }
        } while (size != PHONE_LEN);
        strncpy(phone->number, phoneNumber, sizeof(phone->number) - 1);
    }
}

// Get user input for appointment information
void inputAppointment(struct Appointment *appointment)
{
    printf("Patient Number: ");
    int patientNumber = inputIntPositive();
    struct Date appointmentDate;
    inputDate(&appointmentDate);
    struct Time appointmentTime;
    inputTime(&appointmentTime);

    appointment->patientNumber = patientNumber;
    appointment->date = appointmentDate;
    appointment->time = appointmentTime;
}

// Get user input for date struct
void inputDate(struct Date *date)
{
    printf("Year        : ");
    date->year = inputIntPositive();
    printf("Month (1-12): ");
    date->month = inputIntRange(1, 12);
    if (date->month == 2 && date->year % 4 == 0)
    {
        printf("Day (1-29)  : ");
        date->day = inputIntRange(1, 29);
    }
    else if (date->month == 2)
    {
        printf("Day (1-28)  : ");
        date->day = inputIntRange(1, 28);
    }
    else if ((date->month < 8 && date->month % 2 == 1) || (date->month >= 8 && date->month % 2 == 0))
    {
        printf("Day (1-31)  : ");
        date->day = inputIntRange(1, 31);
    }
    else
    {
        printf("Day (1-30)  : ");
        date->day = inputIntRange(1, 30);
    }
}

// Get user input for time struct
void inputTime(struct Time *time)
{
    printf("Hour (0-23)  : ");
    time->hour = inputIntRange(0, 23);
    printf("Minute (0-59): ");
    time->min = inputIntRange(0, 59);
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char *datafile, struct Patient patients[], int max)
{
    int count = 0;
    FILE *fp = NULL;
    fp = fopen(datafile, "r");
    if (fp != NULL)
    {
        struct Patient loadedPatient;
        while (fscanf(fp, "%d%*c%[^|]%*c%[^|]%*c%[^\n]",
                      &loadedPatient.patientNumber,
                      loadedPatient.name,
                      loadedPatient.phone.description,
                      loadedPatient.phone.number) != EOF &&
               count != max)
        {
            count++;
            patients[count - 1] = loadedPatient;

            // clean the previous loaded paitent data
            strncpy(loadedPatient.phone.number, "", sizeof(loadedPatient.phone.number) - 1);
        }
        fclose(fp);
    }
    else
    {
        printf("File not exists");
    }

    // Note: Display imported data
    // int i = 0;
    // for (i = 0; i < count; i++)
    // {
    //     displayPatientData(&patients[i], FMT_TABLE);
    // }

    return count;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char *datafile, struct Appointment appoints[], int max)
{
    int count = 0;
    FILE *fp = NULL;
    fp = fopen(datafile, "r");
    if (fp != NULL)
    {
        struct Appointment loadedAppointment;
        while (fscanf(fp, "%d,%d,%d,%d,%d,%d",
                      &loadedAppointment.patientNumber,
                      &loadedAppointment.date.year,
                      &loadedAppointment.date.month,
                      &loadedAppointment.date.day,
                      &loadedAppointment.time.hour,
                      &loadedAppointment.time.min) != EOF &&
               count != max - 1)
        {
            count++;
            appoints[count - 1] = loadedAppointment;
        }
        fclose(fp);
    }
    else
    {
        printf("File not exists");
    }

    bubbleSortAppointments(appoints, count);
    // Note: Display imported data
    // int i = 0;
    // for (i = 0; i < count; i++)
    // {
    //     printf("%d %d %d %d %d %d\n",
    //            appoints[i].patientNumber,
    //            appoints[i].date.year, appoints[i].date.month, appoints[i].date.day,
    //            appoints[i].time.hour, appoints[i].time.min);
    // }

    return count;
}
