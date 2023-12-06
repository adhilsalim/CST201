/*
This program gets a sparse matrix then gives the transpose of the given sparse matrix by using tuple matrix.
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

    /*

    ----+----+----+----+ Tuple Matrix of Transpose of Sparse Matrix +----+----+----+----+

    Swap col 1 and col 2 of tuple matrix to get the tuple matrix of transpose of sparse matrix
    After swapping, convert tuple matrix to sparse matrix

    */

    // swapping col 1 and col 2 of tuple matrix

    for (int i = 0; i <= nonZeroNumbers; i++)
    {
        int temp = tupleMatrix[i][1];
        tupleMatrix[i][1] = tupleMatrix[i][0];
        tupleMatrix[i][0] = temp;
    }

    printf("\nThe tuple matrix of transpose is: \n");

    for (int i = 0; i < nonZeroNumbers + 1; i++) // index of rows of tuple matrix = non zero numbers
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", tupleMatrix[i][j]);
        }
        printf("\n");
    }

    // declaring transpose matrix
    int transposeMatrix[tupleMatrix[0][0]][tupleMatrix[0][1]];

    // initializing zeroes to transpose matrix
    for (int i = 0; i < tupleMatrix[0][0]; i++)
    {
        for (int j = 0; j < tupleMatrix[0][1]; j++)
        {
            transposeMatrix[i][j] = 0;
        }
    }

    // converting tuple to transpose
    for (int i = 1; i <= nonZeroNumbers; i++)
    {
        transposeMatrix[tupleMatrix[i][0]][tupleMatrix[i][1]] = tupleMatrix[i][2];
    }

    // printing transpose of sparse matrix
    printf("\nThe transpose of the matrix is: \n");

    for (int i = 0; i < tupleMatrix[0][0]; i++)
    {
        for (int j = 0; j < tupleMatrix[0][1]; j++)
        {
            printf("%d  ", transposeMatrix[i][j]);
        }
        printf("\n");
    }
}
