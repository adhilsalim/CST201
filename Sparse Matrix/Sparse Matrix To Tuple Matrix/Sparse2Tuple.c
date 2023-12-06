/*
This program converts sparse matrix to tuple matrix
Author: Adhil Salim
*/

#include <stdio.h>

void main()
{

    int sparseRows, sparseCols, nonZeroNumbers = 0;

    printf("Enter the number of rows of sparse matrix: ");
    scanf("%d", &sparseRows);
    printf("Enter the number of columns of sparse matrix: ");
    scanf("%d", &sparseCols);

    // Declaring Sparse Matrix
    int sparseMatrix[sparseRows][sparseCols];

    printf("Enter the elements of sparse matrix: \n");

    // Input the sparse matrix
    for (int i = 0; i < sparseRows; i++)
    {
        for (int j = 0; j < sparseCols; j++)
        {
            printf("Enter the element at position (%d,%d): ", i, j);
            scanf("%d", &sparseMatrix[i][j]);
        }
    }

    // printing the sparse matrix
    printf("\nThe sparse matrix is: \n");

    for (int i = 0; i < sparseRows; i++)
    {
        for (int j = 0; j < sparseCols; j++)
        {
            printf("%d ", sparseMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Counting the number of non-zero elements in the sparse matrix
    for (int i = 0; i < sparseRows; i++)
    {
        for (int j = 0; j < sparseCols; j++)
        {
            if (sparseMatrix[i][j] != 0)
            {
                nonZeroNumbers++;
            }
        }
    }

    // declaring tuple matrix
    int tupleMatrix[nonZeroNumbers + 1][3];

    // storing the number of rows, columns and non-zero numbers in the first row of tuple matrix
    tupleMatrix[0][0] = sparseRows;
    tupleMatrix[0][1] = sparseCols;
    tupleMatrix[0][2] = nonZeroNumbers;

    // storing the non-zero elements of sparse matrix in tuple matrix
    for (int i = 0, k = 1; i < sparseRows; i++)
    {
        for (int j = 0; j < sparseCols; j++)
        {
            if (sparseMatrix[i][j] != 0)
            {
                tupleMatrix[k][0] = i;
                tupleMatrix[k][1] = j;
                tupleMatrix[k][2] = sparseMatrix[i][j];
                k++;
            }
        }
    }

    // printing the tuple matrix
    printf("\nThe tuple matrix is: \n");

    for (int i = 0; i < nonZeroNumbers + 1; i++) // index of rows of tuple matrix = non zero numbers
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", tupleMatrix[i][j]);
        }
        printf("\n");
    }
}