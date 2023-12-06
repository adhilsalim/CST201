/*
This program performs priority queue operations
Author: Adhil Salim
*/
#include <stdio.h>
#include <stdbool.h>

int PQ[2][10];
int REAR = -1, FRONT = -1;

void insert(int, int);
int delete();
void display();

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
    if (REAR == -1 && FRONT == -1)
    {
        printf("DELETION NOT POSSIBLE");
    }
    else if (REAR == FRONT)
    {
        int element = PQ[0][FRONT];
        FRONT = -1;
        REAR = -1;
        return element;
    }
    else
    {
        int element = PQ[0][FRONT];
        FRONT++;
        return element;
    }
}

void display()
{
    if (FRONT != -1 && REAR != -1)
    {
        printf("\n\n");
        for (int i = FRONT; i <= REAR; i++)
        {
            printf("[%d,%d] ", PQ[0][i], PQ[1][i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nNOTHING TO DISPLAY\n");
    }
}

void main()
{
    bool EXIT_LOOP = false;

    while (!EXIT_LOOP)
    {

        int choice, element, priority;
        printf("\n\n[1]INSERT [2]DELETE [3]DISPLAY [4]EXIT\nchoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nenter element: ");
            scanf("%d", &element);
            printf("enter priority for %d: ", element);
            scanf("%d", &priority);
            insert(element, priority);
            break;
        case 2:
            element = delete ();
            printf("\n%d deleted from PQ", element);
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