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

#pragma once

int inputInt(void);

int inputIntPositive(void);

int inputIntRange(int lower, int upper);

char inputCharOption(const char matches[]);

void inputCString(char *str, int minSize, int maxSize);

void displayFormattedPhone(const char *phoneStr);

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);