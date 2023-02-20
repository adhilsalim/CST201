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

        int current_element = PQ[0][REAR];
        int current_priority = PQ[1][REAR];
        int j = REAR - 1;

        while (j >= 0 && PQ[1][j] < current_priority)
        {
            PQ[0][j + 1] = PQ[0][j];
            PQ[1][j + 1] = PQ[1][j];
            j--;
        }
        PQ[0][j + 1] = current_element;
        PQ[1][j + 1] = current_priority;
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