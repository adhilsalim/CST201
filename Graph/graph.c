#include <stdio.h>
#include <stdlib.h>

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

    display(Q);
}

int deQueue(int Q[])
{
    if (REAR == -1 && FRONT == -1)
    {
        printf("\nDELETION NOT POSSIBLE\n");
    }
    else if (REAR == FRONT)
    {
        return Q[FRONT];
        FRONT = -1;
        REAR = -1;
    }
    else
    {
        return Q[FRONT];
        FRONT++;
    }

    display(Q);
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
        exit(0);
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

    int start_vertex;
    printf("enter node you want to start: ");
    scanf("%d", &start_vertex);

    printf("\nDFS: ");
    DFS(STACK, GRAPH_MATRIX, VISIT, start_vertex);

    for (int i = 0; i < TOTAL_VERTICES; i++)
    {
        VISIT[i] = 0;
    }

    // printf("\nBFS: ");
    //  BFS(STACK, GRAPH_MATRIX, VISIT, start_vertex);
    enQueue(QUEUE, 3);
    deQueue(QUEUE);

    enQueue(QUEUE, 5);
    enQueue(QUEUE, 6);

    deQueue(QUEUE);
    enQueue(QUEUE, 7);

    deQueue(QUEUE);
    deQueue(QUEUE);
    deQueue(QUEUE);
    deQueue(QUEUE);
    deQueue(QUEUE);

    enQueue(QUEUE, 1);
    enQueue(QUEUE, 2);
    enQueue(QUEUE, 3);
    enQueue(QUEUE, 4);
    enQueue(QUEUE, 5);
    enQueue(QUEUE, 6);
}