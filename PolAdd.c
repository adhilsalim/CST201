/*
name: PolAdd
desc: This program performs addition on polynomial expression
author: Adhil Salim
date: 05/10/2022 (last modified)
*/

#include <stdio.h>

// function for bubble sort
int BubbleSortArray(int *array[][2], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j][1] < array[j + 1][1])
            {
                int temp = array[j][1];
                array[j][1] = array[j + 1][1];
                array[j + 1][1] = temp;

                temp = array[j][0];
                array[j][0] = array[j + 1][0];
                array[j + 1][0] = temp;
            }
        }
    }
    return 1;
}

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
    bubbleSortArray(mainPol, totalTerms);

    // printing the array of polynomial equations
    for (int i = 0; i < totalTerms; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", mainPol[i][j]);
        }
        printf("\n");
    }
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

    // printing the array of polynomial equations
    for (int i = 0; i < totalTerms; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", mainPol[i][j]);
        }
        printf("\n");
    }

    // sorting mainPol array
    bubbleSortArray(mainPol, totalTerms);
    printf("\n");

    // printing the array of polynomial equations
    for (int i = 0; i < totalTerms; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", mainPol[i][j]);
        }
        printf("\n");
    }
}
