#include <stdio.h>
#include <stdbool.h>

int PQ[2][10];
int REAR = -1, FRONT = -1;

void insert(int, int);

void insert(int e, int p)
{
    if (REAR == -1 && FRONT == -1)
    {
        REAR++;
        FRONT++;
        PQ[0][REAR] = e;
        PQ[1][REAR] = p;
    }
    else if (REAR == 9)
    {
        printf("\nINSERTION NOT POSSIBLE\n");
    }
    else
    {
        REAR++;
        PQ[0][REAR] = e;
        PQ[1][REAR] = p;
    }
}

int delete()
{
}

void display()
{
}

void main()
{
    bool EXIT_LOOP = false;

    while (!EXIT_LOOP)
    {

        int choice;
        printf("[1]INSERT [2]DELETE [3]DISPLAY [4]EXIT\n\nchoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            int element, priority;
            printf("enter element: ");
            scanf("%d", &element);
            printf("enter element: ");
            scanf("%d", &priority);
            insert(element, priority);
            break;
        case 2:
            int element = delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            EXIT_LOOP = true;
            break;

        default:
            printf("\nerror\n");
            break;
        }
    }
}