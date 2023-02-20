#include <stdio.h>

int POLYNOMIAL_ONE[2][10];
int POLYNOMIAL_TWO[2][10];
int POLYNOMIAL_SUM[2][20];
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

    while (i != TOTAL_TERMS_ONE - 1 && j != TOTAL_TERMS_TWO - 1)
    {
        if (POLYNOMIAL_ONE[1][i] == POLYNOMIAL_TWO[1][j])
        {

            POLYNOMIAL_SUM[0][k] = POLYNOMIAL_ONE[0][i] + POLYNOMIAL_TWO[0][j];
            POLYNOMIAL_SUM[1][k] = POLYNOMIAL_ONE[1][i];
            i++;
            j++;
        }
        else if (POLYNOMIAL_ONE[1][i] > POLYNOMIAL_TWO[1][j])
        {
            POLYNOMIAL_SUM[0][k] = POLYNOMIAL_ONE[0][i];
            POLYNOMIAL_SUM[1][k] = POLYNOMIAL_ONE[1][i];
            i++;
        }
        else
        {
            POLYNOMIAL_SUM[0][k] = POLYNOMIAL_TWO[0][j];
            POLYNOMIAL_SUM[1][k] = POLYNOMIAL_TWO[1][j];
            j++;
        }

        k++;
    }

    while (i != TOTAL_TERMS_ONE - 1)
    {
        POLYNOMIAL_SUM[0][k] = POLYNOMIAL_ONE[0][i];
        POLYNOMIAL_SUM[1][k] = POLYNOMIAL_ONE[1][i];
        i++;
        k++;
    }

    while (j != TOTAL_TERMS_ONE - 1)
    {
        POLYNOMIAL_SUM[0][k] = POLYNOMIAL_TWO[0][j];
        POLYNOMIAL_SUM[1][k] = POLYNOMIAL_TWO[1][j];
        j++;
        k++;
    }

    printf("\nPOLYNOMIAL SUM: ");
    for (int i = 0; i <= k; i++)
    {
        printf("%dX^%d", POLYNOMIAL_TWO[0][i], POLYNOMIAL_TWO[1][i]);
        if (i != TOTAL_TERMS_TWO - 1)
        {
            printf(" + ");
        }
    }
}