#include <stdio.h>

int VERTEX = 0;
int EDGES = 0;

int GRAPH[50][50];
int VISIT[50];

void main()
{
    printf("NO OF VERTICES: ");
    scanf("%d", &VERTEX);

    printf("NO OF EDGES: ");
    scanf("%d", &EDGES);

    for (int i = 0; i < EDGES; i++)
    {
        int vertex_one, vertex_two;

        printf("enter A in (A,B): ");
        scanf("%d", &vertex_one);

        printf("enter B in (A,B): ");
        scanf("%d", &vertex_two);

        GRAPH[vertex_one][vertex_two] = 1;
        GRAPH[vertex_two][vertex_one] = 1;
    }

    printf("\nAdjacency matrix: \n");
    for (int i = 0; i < VERTEX; i++)
    {
        for (int j = 0; j < VERTEX; j++)
        {
            printf("%d ", GRAPH[i][j]);
        }
        printf("\n");
    }
}