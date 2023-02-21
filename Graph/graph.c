#include <stdio.h>

int VERTEX = 0;
int EDGES = 0;
int REAR = -1;
int FRONT = -1;
int TOP = -1;

int Q[100];
int STACK[100];
int GRAPH[50][50];
int VISIT[50];

void enQueue(int);
int deQueue();
int pop();
void push(int);
void DFS(int v);
void BFS(int v);

void DFS(int v)
{
    VISIT[v] = 1;

    while (TOP != -1)
    {
        int popped_vertex;
        popped_vertex = pop();
        printf("%d ", popped_vertex);

        for (int i = 0; i < VERTEX; i++)
        {
            if (GRAPH[popped_vertex][i] == 1 && VISIT[i] != 0)
            {
                VISIT[i] = 1;
                push(i);
            }
        }
    }

    for (int i = 0; i < VERTEX; i++)
    {
        if (VISIT[i] == 0)
        {
            DFS(i);
            break;
        }
    }
}

void BFS(int v)
{
}

void enQueue(int element)
{
    if (REAR == VERTEX - 1)
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

int deQueue()
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

int pop()
{
    int element = STACK[TOP];
    TOP--;
    return element;
}

void push(int element)
{
    TOP++;
    STACK[TOP] = element;
}

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

    int start_vertex;
    printf("\nenter node you want to start: ");
    scanf("%d", &start_vertex);

    for (int i = 0; i < 50; i++)
    {
        VISIT[i] = 0;
    }

    printf("\nDFS: ");
    DFS(start_vertex);

    for (int i = 0; i < 50; i++)
    {
        VISIT[i] = 0;
    }

    printf("\nBFS: ");
    // BFS(start_vertex);
}