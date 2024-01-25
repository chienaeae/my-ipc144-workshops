/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
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

int taxable(char taxed)
{
    if (taxed == 'Y')
    {
        return 1;
    }
    return 0;
}

void printProduct(char *name, int id, char taxed, float price)
{
    printf("%s (ID:%d)\n", name, id);
    printf("  Taxed: %c\n", taxed);
    printf("  Price: $%.4f\n", price);
    printf("\n");
}

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;

    const int p1Id = 111;
    const char p1Taxed = 'Y';
    const float p1Price = 111.4900f;
    const int p2Id = 222;
    const char p2Taxed = 'N';
    const float p2Price = 222.9900f;
    const int p3Id = 111;
    const char p3Taxed = 'N';
    const float p3Price = 334.4900f;
    const float avgPrice = (p1Price + p2Price + p3Price) / 3;

    printf("Product Information\n");
    printf("===================\n");
    printProduct("Product-1", p1Id, p1Taxed, p1Price);
    printProduct("Product-2", p2Id, p2Taxed, p2Price);
    printProduct("Product-3", p3Id, p3Taxed, p3Price);
    printf("The average of all prices is: $%.4f\n", avgPrice);
    printf("\n");
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n");
    printf("\n");
    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n", taxable(p1Taxed));
    printf("\n");
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n", !taxable(p2Taxed) && !taxable(p3Taxed));
    printf("\n");
    printf("3. Is product 3 less than testValue ($%.2f)? -> %d\n", testValue, p3Price < testValue);
    printf("\n");
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n", p3Price > p1Price + p2Price);
    printf("\n");
    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2f)\n", p1Price >= p3Price - p2Price, p3Price - p2Price);
    printf("\n");
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n", p2Price >= avgPrice);
    printf("\n");
    printf("7. Based on product ID, product 1 is unique -> %d\n", p1Id != p2Id && p1Id != p3Id);
    printf("\n");
    printf("8. Based on product ID, product 2 is unique -> %d\n", p2Id != p1Id && p2Id != p3Id);
    printf("\n");
    printf("9. Based on product ID, product 3 is unique -> %d\n", p3Id != p1Id && p3Id != p2Id);
    printf("\n");
    return 0;
}