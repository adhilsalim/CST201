/*
This program performs multiplication of two polynomials
Author: Adhil Salim
*/

#include <stdio.h>

int POLYNOMIAL_ONE[2][10];
int POLYNOMIAL_TWO[2][10];
int POLYNOMIAL_PRO[2][100];
int TOTAL_TERMS_ONE = 0, TOTAL_TERMS_TWO = 0;

void main()
{
    printf("enter the no. of terms in the first polynomial: ");
    scanf("%d", &TOTAL_TERMS_ONE);

    printf("enter the no. of terms in the second polynomial: ");
    scanf("%d", &TOTAL_TERMS_TWO);

    int coefficient, exponent;

    printf("\nENTER POLYNOMIAL ONE: \n");
    for (int i = 0; i < TOTAL_TERMS_ONE; i++)
    {
        printf("coefficient of term %d: ", i + 1);
        scanf("%d", &coefficient);
        printf("exponent of term %d: ", i + 1);
        scanf("%d", &exponent);

        POLYNOMIAL_ONE[0][i] = coefficient;
        POLYNOMIAL_ONE[1][i] = exponent;
    }

    printf("\nENTER POLYNOMIAL TWO: \n");
    for (int i = 0; i < TOTAL_TERMS_TWO; i++)
    {
        printf("coefficient of term %d: ", i + 1);
        scanf("%d", &coefficient);
        printf("exponent of term %d: ", i + 1);
        scanf("%d", &exponent);

        POLYNOMIAL_TWO[0][i] = coefficient;
        POLYNOMIAL_TWO[1][i] = exponent;
    }

    printf("\nPOLYNOMIAL TWO: ");
    for (int i = 0; i < TOTAL_TERMS_ONE; i++)
    {
        printf("%dX^%d", POLYNOMIAL_ONE[0][i], POLYNOMIAL_ONE[1][i]);
        if (i != TOTAL_TERMS_ONE - 1)
        {
            printf(" + ");
        }
    }

    printf("\nPOLYNOMIAL TWO: ");
    for (int i = 0; i < TOTAL_TERMS_TWO; i++)
    {
        printf("%dX^%d", POLYNOMIAL_TWO[0][i], POLYNOMIAL_TWO[1][i]);
        if (i != TOTAL_TERMS_TWO - 1)
        {
            printf(" + ");
        }
    }

    int i = 0, j = 0, k = 0;

    while (i < TOTAL_TERMS_ONE)
    {
        j = 0;
        while (j < TOTAL_TERMS_TWO)
        {
            POLYNOMIAL_PRO[0][k] = POLYNOMIAL_ONE[0][i] * POLYNOMIAL_TWO[0][j];
            POLYNOMIAL_PRO[1][k] = POLYNOMIAL_ONE[1][i] + POLYNOMIAL_TWO[1][j];
            k++;
            j++;
        }
        i++;
    }

    printf("\nPRODUCT OF POLYNOMIAL: ");
    for (int i = 0; i < k; i++)
    {
        printf("%dX^%d", POLYNOMIAL_PRO[0][i], POLYNOMIAL_PRO[1][i]);
        if (i != k - 1)
        {
            printf(" + ");
        }
    }
}