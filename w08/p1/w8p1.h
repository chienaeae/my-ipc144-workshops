/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
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

#define MAX_PRODUCT_NUM 3
#define SERVING_GRAMS 64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
    // skuId is product sku
    int skuId;

    // product is the product price
    double price;

    // calories is calories per suggested serving
    int calories;

    // weight is product weight in pounds
    double weight;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *val);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *val);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int productNum);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int productSeq);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skuId, const double *price, const int calories, const double *weight);

// 7. Logic entry point
void start(void);