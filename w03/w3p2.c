/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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

static char c1Type;
static int c1Weight;
static int c1WithCream;

static char c2Type;
static int c2Weight;
static int c2WithCream;

static char c3Type;
static int c3Weight;
static int c3WithCream;

void inputCoffee(char *name, char *type, int *weight, int *withCream)
{
    printf("%s...\n", name);
    // coffee type
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    char tmp;
    scanf(" %c", &tmp);
    if (tmp == 'L' || tmp == 'l')
    {
        *type = 'l';
    }
    else if (tmp == 'M' || tmp == 'm')
    {
        *type = 'm';
    }
    else
    {
        *type = 'r';
    }

    // coffee weight
    printf("Bag weight (g): ");
    scanf("%d", weight);

    // coffee served with cream
    printf("Best served with cream ([Y]es,[N]o): ");
    char tmp3;
    scanf(" %c", &tmp3);
    if (tmp3 == 'Y' || tmp3 == 'y')
    {
        *withCream = 1;
    }
    else
    {
        *withCream = 0;
    }
    printf("\n");
}

void inputPersonFavour()
{
    char type;
    int withCream;
    int dailyNum;
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    char tmp;
    scanf(" %c", &tmp);
    if (tmp == 'L' || tmp == 'l')
    {
        type = 'l';
    }
    else if (tmp == 'M' || tmp == 'm')
    {
        type = 'm';
    }
    else
    {
        type = 'r';
    }
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    char tmp2;
    scanf(" %c", &tmp2);
    if (tmp2 == 'Y' || tmp2 == 'y')
    {
        withCream = 1;
    }
    else
    {
        withCream = 0;
    }
    printf("Typical number of daily servings: ");
    scanf(" %d", &dailyNum);
    printf("\n");
    printf("The below table shows how your preferences align to the available products:\n");
    printf("\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n",
           type == c1Type, dailyNum >= 1 && dailyNum <= 4, withCream == c1WithCream);
    printf(" 2|       %d         |      %d      |   %d   |\n",
           type == c2Type, dailyNum >= 5 && dailyNum <= 9, withCream == c2WithCream);
    printf(" 3|       %d         |      %d      |   %d   |\n",
           type == c3Type, dailyNum >= 10, withCream == c3WithCream);
    printf("\n");
}

int main(void)
{
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n");
    printf("\n");
    printf("Enter the coffee product information being sold today...\n");
    printf("\n");
    inputCoffee("COFFEE-1", &c1Type, &c1Weight, &c1WithCream);
    inputCoffee("COFFEE-2", &c2Type, &c2Weight, &c2WithCream);
    inputCoffee("COFFEE-3", &c3Type, &c3Weight, &c3WithCream);

    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
           c1Type == 'l', c1Type == 'm', c1Type == 'r', c1Weight, c1Weight / GRAMS_IN_LBS, c1WithCream);
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
           c2Type == 'l', c2Type == 'm', c2Type == 'r', c2Weight, c2Weight / GRAMS_IN_LBS, c2WithCream);
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
           c3Type == 'l', c3Type == 'm', c3Type == 'r', c3Weight, c3Weight / GRAMS_IN_LBS, c3WithCream);
    printf("\n");

    printf("Enter how you like your coffee...\n");
    printf("\n");
    inputPersonFavour();
    printf("Enter how you like your coffee...\n");
    printf("\n");
    inputPersonFavour();
    printf("Hope you found a product that suits your likes!\n");
    printf("\n");

    return 0;
}

/*

Provided formatting parts for printf statements:

As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",

*/