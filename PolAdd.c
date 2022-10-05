/*
name: PolAdd
desc: This program performs addition on polynomial expression
author: Adhil Salim
date: 05/10/2022 (last modified)
hello how are you ?
*/

#include <stdio.h>

void main()
{
    int totalPolEqns = 0, totalTerms = 0;

    // getting the number of polynomial equations
    printf("Enter the number of polynomial equations: ");
    scanf("%d", &totalPolEqns);

    // for storing the number of terms in each polynomial equation
    int totalTermsInEachPol[totalPolEqns];

    // getting the number of terms in each polynomial equation
    for (int i = 0; i < totalPolEqns; i++)
    {
        printf("Enter the number of terms in polynomial equation %d: ", i + 1);
        scanf("%d", &totalTermsInEachPol[i]);

        //
        totalTerms += totalTermsInEachPol[i];
    }

    // array that contains coefficient and exponent of each term of all polynomial equations
    int mainPol[totalTerms][2];

    // getting the coefficient and exponent of each term of all polynomial equations
    for (int i = 0, k = 0; i < totalPolEqns; i++)
    {

        while (totalTermsInEachPol[i] != 0)
        {
            // log 1
            // printf("\nLOG:   TOTAL-TERMS-IN-EACH-POL[%d]: %d\n", i, totalTermsInEachPol[i]);

            printf("Enter the coefficient of term %d of polynomial equation %d: ", totalTermsInEachPol[i], i + 1);
            scanf("%d", &mainPol[k][0]);

            // log 2
            // printf("LOG:   MAIN-POL[%d][0]: %d\n", i, mainPol[i][0]);

            printf("Enter the exponent of term %d of polynomial equation %d: ", totalTermsInEachPol[i], i + 1);
            scanf("%d", &mainPol[k][1]);

            // log 3
            // printf("LOG:   MAIN-POL[%d][1]: %d", i, mainPol[i][1]);
            totalTermsInEachPol[i]--;
            k++;
        }
        // k++;
    }

    // sorting mainPol array
    for (int i = 0; i < totalTerms - 1; i++)
    {
        for (int j = 0; j < totalTerms - i - 1; j++)
        {
            if (mainPol[j][1] < mainPol[j + 1][1])
            {
                int temp = mainPol[j][1];
                mainPol[j][1] = mainPol[j + 1][1];
                mainPol[j + 1][1] = temp;

                temp = mainPol[j][0];
                mainPol[j][0] = mainPol[j + 1][0];
                mainPol[j + 1][0] = temp;
            }
        }
    }

    // printing the array of polynomial equations
    /*for (int i = 0; i < totalTerms; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", mainPol[i][j]);
        }
        printf("\n");
    }*/
    printf("\n");

    for (int i = 0; i < totalTerms; i++)
    {

        for (int j = i + 1; j < totalTerms; j++)
        {
            if (mainPol[i][1] == mainPol[j][1])
            {
                mainPol[i][0] += mainPol[j][0];
                mainPol[j][0] = 0;
                mainPol[j][1] = 0;
            }
        }
    }

    /*for (int i = 0; i < totalTerms; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", mainPol[i][j]);
        }
        printf("\n");
    }*/

    for (int i = 0; i < totalTerms - 1; i++)
    {
        for (int j = 0; j < totalTerms - i - 1; j++)
        {
            if (mainPol[j][1] < mainPol[j + 1][1])
            {
                int temp = mainPol[j][1];
                mainPol[j][1] = mainPol[j + 1][1];
                mainPol[j + 1][1] = temp;

                temp = mainPol[j][0];
                mainPol[j][0] = mainPol[j + 1][0];
                mainPol[j + 1][0] = temp;
            }
        }
    }
    printf("\n");
    /*for (int i = 0; i < totalTerms; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", mainPol[i][j]);
        }
        printf("\n");
    }*/
    while (mainPol[totalTerms - 1][0] == 0)
    {
        totalTerms--;
    }

    printf("The sum of the polynomial equations is: ");

    for (int i = 0; i < totalTerms; i++)
    {
        if (mainPol[i][0] != 0)
        {
            printf("%dX^%d", mainPol[i][0], mainPol[i][1]);
            if (i != totalTerms - 1)
            {
                printf(" + ");
            }
        }
    }
}