#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int CONST_VERTEX = 0;
int TOP = -1;
int REAR = -1;
int FRONT = -1;

int pop(int[]);
void push(int[], int);
void enQueue(int[], int);
int deQueue(int[]);

void DFS(int[], int[][CONST_VERTEX], int[], int);
void BFS(int[], int[][CONST_VERTEX], int[], int);

void display(int[]);

void enQueue(int Q[], int element)
{
    if (REAR == CONST_VERTEX - 1)
    {
        printf("\nINSERTION NOT POSSIBLE\n");
    }
    else if (REAR == -1 && FRONT == -1)
    {
        REAR++;
        FRONT++;
        Q[REAR] = element;
    }
    else
    {
        REAR++;
        Q[REAR] = element;
    }
}

int deQueue(int Q[])
{
    int element;
    if (REAR == -1 && FRONT == -1)
    {
        printf("\nDELETION NOT POSSIBLE\n");
    }
    else if (REAR == FRONT)
    {
        element = Q[FRONT];
        FRONT = -1;
        REAR = -1;
        return element;
    }
    else
    {
        element = Q[FRONT];
        FRONT++;
        return element;
    }
}

void display(int array[])
{
    if (FRONT != -1 && REAR != -1)
    {
        printf("\nQ: ");
        for (int i = FRONT; i <= REAR; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
}

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
                push(stack, i);
                break;
            }
        }
    }

    for (int i = 0; i < CONST_VERTEX; i++)
    {
        if (visit[i] == 0)
        {
            DFS(stack, graph, visit, i);
        }
    }
}

void BFS(int Q[], int graph[][CONST_VERTEX], int visit[], int vertex)
{
    visit[vertex] = 1;
    enQueue(Q, vertex);

    while (REAR != -1 && FRONT != -1)
    {
        int j = deQueue(Q);
        printf("%d ", j);

        for (int i = 0; i < CONST_VERTEX; i++)
        {
            if (graph[j][i] == 1 && visit[i] != 1)
            {
                visit[i] = 1;
                enQueue(Q, i);
                break;
            }
        }
    }

    for (int i = 0; i < CONST_VERTEX; i++)
    {
        if (visit[i] == 0)
        {
            BFS(Q, graph, visit, i);
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
    int QUEUE[TOTAL_VERTICES];
    int VISIT[TOTAL_VERTICES];

    for (int i = 0; i < TOTAL_VERTICES; i++)
    {
        for (int j = 0; j < TOTAL_VERTICES; j++)
        {
            GRAPH_MATRIX[i][j] = 0;
            VISIT[i] = 0;
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

    bool EXIT_LOOP = false;
    int choice;

    while (!EXIT_LOOP)
    {
        printf("\n\n[1]TRAVERSE  [2]EXIT\nOPERATION NUMBER: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            break;
        case 2:
            exit(0);
            break;
        default:
            printf("\nInvalid operation number.\n");
            break;
        }
        int start_vertex;
        printf("\nenter node you want to start: ");
        scanf("%d", &start_vertex);

        printf("\nDFS: ");
        DFS(STACK, GRAPH_MATRIX, VISIT, start_vertex);

        for (int i = 0; i < TOTAL_VERTICES; i++)
        {
            VISIT[i] = 0;
        }

        printf("\nBFS: ");
        BFS(STACK, GRAPH_MATRIX, VISIT, start_vertex);
    }
}