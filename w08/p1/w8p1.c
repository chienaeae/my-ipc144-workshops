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

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *val)
{
	while (1)
	{
		int tmp = 0;
		scanf("%d", &tmp);
		if (tmp <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			if (val != NULL)
			{
				*val = tmp;
			}
			return tmp;
		}
	}
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *val)
{
	while (1)
	{
		double tmp = 0.0f;
		scanf("%lf", &tmp);
		if (tmp <= 0.0f)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			if (val != NULL)
			{
				*val = tmp;
			}
			return tmp;
		}
	}
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int productNum)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", productNum);
	printf("NOTE: A 'serving' is %dg\n", SERVING_GRAMS);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int productSeq)
{
	struct CatFoodInfo info = {};
	printf("Cat Food Product #%d\n", productSeq);
	printf("--------------------\n");
	printf("SKU           : ");
	info.skuId = getIntPositive(&info.skuId);
	printf("PRICE         : $");
	info.price = getDoublePositive(&info.price);
	printf("WEIGHT (LBS)  : ");
	info.weight = getDoublePositive(&info.weight);
	printf("CALORIES/SERV.: ");
	info.calories = getIntPositive(&info.calories);
	return info;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skuId, const double *price, const int calories, const double *weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", skuId, *price, *weight, calories);
}

// 7. Logic entry point
void start()
{
	struct CatFoodInfo infoArray[MAX_PRODUCT_NUM] =
		{
			{},
			{},
			{}};

	openingMessage(MAX_PRODUCT_NUM);
	printf("\n");

	int i = 0;
	for (i = 0; i < MAX_PRODUCT_NUM; i++)
	{
		infoArray[i] = getCatFoodInfo(i + 1);
		printf("\n");
	}

	displayCatFoodHeader();

	for (i = 0; i < MAX_PRODUCT_NUM; i++)
	{
		displayCatFoodData(infoArray[i].skuId, &infoArray[i].price, infoArray[i].calories, &infoArray[i].weight);
	}
	printf("\n");
}
