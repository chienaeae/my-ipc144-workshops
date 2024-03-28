/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  : Chia-Yu Chien
Student ID#: 157049222
Email      : cchien8@myseneca.ca
Section    : NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

#include "core.h"

int inputInt(void)
{
    int value;
    char newLine = '0';
    while (newLine != '\n')
    {
        scanf("%d%c", &value, &newLine);
        if (newLine != '\n')
        {
            // diaply error message
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
    }
    return value;
}

int inputIntPositive(void)
{
    int value;
    char newLine = '0';
    while (newLine != '\n' || value <= 0)
    {
        scanf("%d%c", &value, &newLine);
        if (newLine != '\n')
        {
            // diaply error message
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else if (value <= 0)
        {
            // diaply error message
            printf("ERROR! Value must be > 0: ");
        }
    }
    return value;
}

int inputIntRange(int lower, int upper)
{
    int value;
    char newLine = '0';
    while (newLine != '\n' || value < lower || value > upper)
    {
        scanf("%d%c", &value, &newLine);
        if (newLine != '\n')
        {
            // diaply error message
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else if (value < lower || value > upper)
        {
            // diaply error message
            printf("ERROR! Value must be between %d and %d inclusive: ", lower, upper);
        }
    }
    return value;
}

char inputCharOption(const char matches[])
{
    char value;
    int isMatch = 0;
    while (!isMatch)
    {
        scanf(" %c", &value);
        int i = 0;
        for (i = 0; matches[i] != '\0' && !isMatch; i++)
        {
            if (value == matches[i])
            {
                isMatch = 1;
            }
        }

        if (!isMatch)
        {
            // display error message
            printf("ERROR: Character must be one of [%s]: ", matches);
        }
    }

    return value;
}

void inputCString(char *str, int minSize, int maxSize)
{
    int size = minSize - 1;
    while (size < minSize || size > maxSize)
    {
        scanf(" %[^\n]", str);
        int i = 0;
        for (i = 0; str[i] != '\0'; i++)
        {
        }
        size = i;
        if (size < minSize || size > maxSize)
        {
            if (minSize == maxSize)
            {
                // display error message
                printf("ERROR: String length must be exactly %d chars: ", minSize);
            }
            else if (size > maxSize)
            {
                // display error message
                printf("ERROR: String length must be no more than %d chars: ", maxSize);
            }
            else if (size < minSize)
            {
                // display error message
                printf("ERROR: String length must be between %d and %d chars: ", minSize, maxSize);
            }
        }
    }
}

void displayFormattedPhone(const char *phoneStr)
{
    const int PHONE_LENGTH = 10;

    // validate
    if (phoneStr == NULL)
    {

        printf("(___)___-____");
        return;
    }

    int i = 0;
    int length = 0;
    for (i = 0; i < PHONE_LENGTH || phoneStr[i] != '\0'; i++)
    {
        length++;
        if (phoneStr[i] < '0' || phoneStr[i] > '9')
        {
            printf("(___)___-____");
            return;
        }
    }

    if (length != PHONE_LENGTH)
    {
        printf("(___)___-____");
        return;
    }

    // display phone formatted
    i = 0;
    for (i = 0; i < PHONE_LENGTH; i++)
    {
        if (i == 0)
        {
            printf("(");
        }
        else if (i == 3)
        {
            printf(")");
        }
        else if (i == 6)
        {
            printf("-");
        }
        printf("%c", phoneStr[i]);
    }
}

// As demonstrated in the course notes:
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer
// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}