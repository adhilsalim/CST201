/*
This program converts tuple matrix to sparse matrix
Author: Adhil Salim
*/

#include <stdio.h>

void main()
{

    int tupleRows, tupleCols = 3;

    printf("Enter the number of rows of tuple matrix: ");
    scanf("%d", &tupleRows);

    // Declaring Tuple Matrix
    int tupleMatrix[tupleRows][tupleCols];

    printf("Enter the elements of tuple matrix: \n");

    // Input the tuple matrix
    for (int i = 0; i < tupleRows; i++)
    {
        for (int j = 0; j < tupleCols; j++)
        {
            printf("Enter the element at position (%d,%d): ", i, j);
            scanf("%d", &tupleMatrix[i][j]);
        }
    }

    // declaring sparse matrix
    int sparseMatrix[tupleMatrix[0][0]][tupleMatrix[0][1]];

    // initializing sparse matrix with 0
    for (int i = 0; i < tupleMatrix[0][0]; i++)
    {
        for (int j = 0; j < tupleMatrix[0][1]; j++)
        {
            sparseMatrix[i][j] = 0;
        }
    }

    // converting tuple matrix to sparse matrix
    for (int i = 1; i < tupleRows; i++)
    {
        sparseMatrix[tupleMatrix[i][0]][tupleMatrix[i][1]] = tupleMatrix[i][2];
    }

    // printing the sparse matrix
    printf("\nThe sparse matrix is: \n");

    for (int i = 0; i < tupleMatrix[0][0]; i++)
    {
        for (int j = 0; j < tupleMatrix[0][1]; j++)
        {
            printf("%d ", sparseMatrix[i][j]);
        }
        printf("\n");
    }
}