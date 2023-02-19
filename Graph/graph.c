#include <stdio.h>

void main()
{
    int TOTAL_VERTICES = 0;

    printf("No of vertices: ");
    scanf("%d", &TOTAL_VERTICES);

    int GRAPH_MATRIX[TOTAL_VERTICES][TOTAL_VERTICES];

    for (int i = 0; i <= TOTAL_VERTICES; i++)
    {
        for (int j = 0; j <= TOTAL_VERTICES; j++)
        {
            GRAPH_MATRIX[i][j] = 0;
        }
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