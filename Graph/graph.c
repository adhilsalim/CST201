#include <stdio.h>

int CONST_VERTEX = 0;

int pop(int[]);
void push(int[], int);
void DFS(int stack[], int graph[][CONST_VERTEX], int visit[], int vertex);

int TOP = -1;

int pop(int stack[])
{
    int element = stack[TOP];
    TOP--;
    return element;
}

void push(int stack[], int element)
{
    TOP++;
    stack[TOP] = element;
}

void DFS(int stack[], int graph[][CONST_VERTEX], int visit[], int vertex)
{
    visit[vertex] = 1;
    push(stack, vertex);

    while (TOP != -1)
    {
        int j = pop(stack);
        printf("%d ", j);

        for (int i = 0; i < CONST_VERTEX; i++)
        {
            if (graph[j][i] == 1 && visit[i] != 1)
            {
                visit[i] = 1;
                push(stack, visit[i]);
            }
        }
    }
}

void main()
{
    int TOTAL_VERTICES = 0, TOTAL_EDGES = 0;

    printf("No of vertices: ");
    scanf("%d", &TOTAL_VERTICES);

    CONST_VERTEX = TOTAL_VERTICES;

    int GRAPH_MATRIX[TOTAL_VERTICES][TOTAL_VERTICES];
    int STACK[TOTAL_VERTICES];
    int VISIT[TOTAL_VERTICES];

    for (int i = 0; i < TOTAL_VERTICES; i++)
    {
        for (int j = 0; j < TOTAL_VERTICES; j++)
        {
            GRAPH_MATRIX[i][j] = 0;
        }
    }

    int vertex_one, vertex_two;

    printf("No of edges: ");
    scanf("%d", &TOTAL_EDGES);

    printf("\nEnter edges in the order (A,B):\n");

    int k = 0;
    while (k < TOTAL_EDGES)
    {
        printf("\n(A,B) enter value for A: ");
        scanf("%d", &vertex_one);
        printf("\n(%d,B) enter value for A: ", vertex_one);
        scanf("%d", &vertex_two);
        printf("\nadding edge (%d,%d)\n", vertex_one, vertex_two);

        GRAPH_MATRIX[vertex_one][vertex_two] = 1;
        GRAPH_MATRIX[vertex_two][vertex_one] = 1;

        k++;
    }

    printf("\nAdjacency matrix: \n");
    for (int i = 0; i < TOTAL_VERTICES; i++)
    {
        for (int j = 0; j < TOTAL_VERTICES; j++)
        {
            printf("%d ", GRAPH_MATRIX[i][j]);
        }
        printf("\n");
    }

    int start_vertex;
    printf("enter node you want to start: ");
    scanf("%d", &start_vertex);

    DFS(STACK, GRAPH_MATRIX, VISIT, start_vertex);
}