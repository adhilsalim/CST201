/*
This program perform addition of two matrices using tuple matrix
Author: Adhil Salim
*/

#include <stdio.h>

void main()
{

    int sparseRowsOne, sparseRowsTwo, sparseColsOne, sparseColsTwo, nonZeroNumbers_One = 0, nonZeroNumbers_Two = 0;

    printf("Enter the number of rows of sparse matrix one: ");
    scanf("%d", &sparseRowsOne);
    printf("Enter the number of columns of sparse matrix one: ");
    scanf("%d", &sparseColsOne);

    printf("Enter the number of rows of sparse matrix two: ");
    scanf("%d", &sparseRowsTwo);
    printf("Enter the number of columns of sparse matrix two: ");
    scanf("%d", &sparseColsTwo);

    if (sparseColsOne == sparseColsTwo && sparseRowsOne == sparseRowsTwo)
    {

        // Declaring Sparse Matrix
        int sparseMatrixOne[sparseRowsOne][sparseColsOne];
        int sparseMatrixTwo[sparseRowsTwo][sparseColsTwo];

        // Input the sparse matrix one
        printf("Enter the elements of sparse matrix one: \n");
        for (int i = 0; i < sparseRowsOne; i++)
        {
            for (int j = 0; j < sparseColsOne; j++)
            {
                printf("Enter the element at position (%d,%d): ", i, j);
                scanf("%d", &sparseMatrixOne[i][j]);
            }
        }

        // Input the sparse matrix two
        printf("Enter the elements of sparse matrix two: \n");
        for (int i = 0; i < sparseRowsTwo; i++)
        {
            for (int j = 0; j < sparseColsTwo; j++)
            {
                printf("Enter the element at position (%d,%d): ", i, j);
                scanf("%d", &sparseMatrixTwo[i][j]);
            }
        }

        // printing the sparse matrix one
        printf("\nThe sparse matrix one is: \n");

        for (int i = 0; i < sparseRowsOne; i++)
        {
            for (int j = 0; j < sparseColsOne; j++)
            {
                printf("%d ", sparseMatrixOne[i][j]);
            }
            printf("\n");
        }

        printf("\n");

        // printing the sparse matrix two
        printf("\nThe sparse matrix two is: \n");

        for (int i = 0; i < sparseRowsTwo; i++)
        {
            for (int j = 0; j < sparseColsTwo; j++)
            {
                printf("%d ", sparseMatrixTwo[i][j]);
            }
            printf("\n");
        }

        printf("\n");

        // Counting the number of non-zero elements in the sparse matrix one
        for (int i = 0; i < sparseRowsOne; i++)
        {
            for (int j = 0; j < sparseColsOne; j++)
            {
                if (sparseMatrixOne[i][j] != 0)
                {
                    nonZeroNumbers_One++;
                }
            }
        }

        // Counting the number of non-zero elements in the sparse matrix two
        for (int i = 0; i < sparseRowsTwo; i++)
        {
            for (int j = 0; j < sparseColsTwo; j++)
            {
                if (sparseMatrixTwo[i][j] != 0)
                {
                    nonZeroNumbers_Two++;
                }
            }
        }

        // declaring tuple matrix one and two
        int tupleMatrixOne[nonZeroNumbers_One + 1][3];
        int tupleMatrixTwo[nonZeroNumbers_Two + 1][3];
        int tupleMatrixSum[nonZeroNumbers_One + nonZeroNumbers_Two + 1][3];

        // storing the number of rows, columns and non-zero numbers in the first row of tuple matrix
        tupleMatrixOne[0][0] = sparseRowsOne;
        tupleMatrixOne[0][1] = sparseColsOne;
        tupleMatrixOne[0][2] = nonZeroNumbers_One;

        tupleMatrixTwo[0][0] = sparseRowsTwo;
        tupleMatrixTwo[0][1] = sparseColsTwo;
        tupleMatrixTwo[0][2] = nonZeroNumbers_Two;

        /*
        If the sum of a matrix element is 0, (eg -2+2=0) that results in 0
        */
        tupleMatrixSum[0][0] = sparseRowsOne;
        tupleMatrixSum[0][1] = sparseColsOne;
        tupleMatrixSum[0][2] = nonZeroNumbers_One + nonZeroNumbers_Two;

        // storing the non-zero elements of sparse matrix in tuple matrix one
        for (int i = 0, k = 1; i < sparseRowsOne; i++)
        {
            for (int j = 0; j < sparseColsOne; j++)
            {
                if (sparseMatrixOne[i][j] != 0)
                {
                    tupleMatrixOne[k][0] = i;
                    tupleMatrixOne[k][1] = j;
                    tupleMatrixOne[k][2] = sparseMatrixOne[i][j];
                    k++;
                }
            }
        }

        // storing the non-zero elements of sparse matrix in tuple matrix two
        for (int i = 0, k = 1; i < sparseRowsTwo; i++)
        {
            for (int j = 0; j < sparseColsTwo; j++)
            {
                if (sparseMatrixTwo[i][j] != 0)
                {
                    tupleMatrixTwo[k][0] = i;
                    tupleMatrixTwo[k][1] = j;
                    tupleMatrixTwo[k][2] = sparseMatrixTwo[i][j];
                    k++;
                }
            }
        }

        // printing the tuple matrix one
        printf("\nThe tuple matrix one is: \n");

        for (int i = 0; i < nonZeroNumbers_One + 1; i++) // index of rows of tuple matrix = non zero numbers
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d ", tupleMatrixOne[i][j]);
            }
            printf("\n");
        }

        // printing the tuple matrix two
        printf("\nThe tuple matrix two is: \n");

        for (int i = 0; i < nonZeroNumbers_Two + 1; i++) // index of rows of tuple matrix = non zero numbers
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d ", tupleMatrixTwo[i][j]);
            }
            printf("\n");
        }

        for (int i = 1; i < tupleMatrixSum[0][2]; i++)
        {
            if (tupleMatrixOne[i][0] == tupleMatrixTwo[i][0])
            {
                if (tupleMatrixOne[i][1] == tupleMatrixTwo[i][1])
                {
                    tupleMatrixSum[i][0] = tupleMatrixOne[i][0];
                    tupleMatrixSum[i][1] = tupleMatrixOne[i][1];
                    tupleMatrixSum[i][2] = tupleMatrixOne[i][2] + tupleMatrixTwo[i][2];
                }
                else
                {
                    tupleMatrixSum[i][0] = tupleMatrixOne[i][0];
                    tupleMatrixSum[i][1] = tupleMatrixOne[i][1];
                    tupleMatrixSum[i][2] = tupleMatrixOne[i][2];

                    i++;

                    tupleMatrixSum[i][0] = tupleMatrixTwo[i][0];
                    tupleMatrixSum[i][1] = tupleMatrixTwo[i][1];
                    tupleMatrixSum[i][2] = tupleMatrixTwo[i][2];
                }
            }
        }

        printf("\nThe tuple matrix sum is: \n");

        for (int i = 0; i < tupleMatrixSum[0][2] + 1; i++) // index of rows of tuple matrix = non zero numbers
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%d ", tupleMatrixSum[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Matrix addition is not possible.");
    }
}