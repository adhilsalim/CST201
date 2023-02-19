#include <stdio.h>

void main()
{
    int TOTAL_VERTICES = 0;

    printf("No of vertices: ");
    scanf("%d", &TOTAL_VERTICES);

    int row = TOTAL_VERTICES + 1;
    int col = row;

    int GRAPH_MATRIX[row][col];

    for (int i = 0; i <= TOTAL_VERTICES; i++)
    {
        for (int j = 0; j <= TOTAL_VERTICES; j++)
        {
            GRAPH_MATRIX[i][j] = 0;
        }
    }

    printf("Enter vertices in order: \n");

    for (int i = 1; i <= TOTAL_VERTICES; i++)
    {
        scanf("%d", &GRAPH_MATRIX[0][i]);
        GRAPH_MATRIX[i][0] = GRAPH_MATRIX[0][i];
    }

    for (int i = 0; i <= TOTAL_VERTICES; i++)
    {
        for (int j = 0; j <= TOTAL_VERTICES; j++)
        {
            printf("%d ", GRAPH_MATRIX[i][j]);
        }
        printf("\n");
    }
}