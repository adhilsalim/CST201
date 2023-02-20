#include <stdio.h>

int POLYNOMIAL_ONE[2][10];
int POLYNOMIAL_TWO[2][10];
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
}