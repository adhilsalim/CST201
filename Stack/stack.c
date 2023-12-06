/*
This program performs stack operations
Author: Adhil Salim
*/
#include <stdio.h>
#include <stdlib.h>

// --------------------------------STACK SHOW-----------------------------------
void stackShow(int array[], int TOP)
{

    printf("\nSTACK IS: ");
    for (int i = 0; i < TOP + 1; i++)
    {
        printf("%d | ", array[i]);
    }
    printf("\n");
}

// --------------------------------STACK PUSH-----------------------------------
void stackPush(int array[], int *TOP, int size, int item)
{

    if (*TOP == -1 || *TOP < size - 1)
    {

        *TOP = *TOP + 1; //*TOP++ points to item
        array[*TOP] = item;
    }
    else
    {
        printf("Push() cannot be performed. STACK IS FULL\n");
    }
}

// ---------------------------------STACK POP-----------------------------------
void stackPop(int array[], int *TOP, int size)
{

    if (*TOP != -1)
    {
        *TOP = *TOP - 1;
        printf("\npop() performed.");
    }
    else
    {
        printf("Pop() cannot be performed. STACK IS EMPTY");
    }
}

// -----------------------------------DEFAULT-----------------------------------
void continueWithDef()
{

    int choice, def_stackSize = 6, TOP = 2, item;

    int def_stack[5] = {10, 20, 30};

    printf("\n\n[GETTING DEFAULT STACK]");

    printf("\n\nCHOOSE OPERATION:\n\n1.Insertion\n2.Deletion\n3.Show\n4.Exit\n");

    for (int loop = 0, flag = 0; loop >= 0 && flag != 1; loop++)
    {
        printf("\nOperation number: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nItem to push(): ");
            scanf("%d", &item);
            stackPush(def_stack, &TOP, def_stackSize, item);
            break;

        case 2:
            stackPop(def_stack, &TOP, def_stackSize);
            break;

        case 3:
            stackShow(def_stack, TOP);
            break;

        case 4:
            flag = 1;
            break;

        default:
            printf("\n\nERROR: INVALID CHOICE");
        }
    }
}

//  -----------------------------------NEW STACK---------------------------------------
void createNewStack()
{
    int stackSize, choice, TOP = -1, item;

    printf("\n\n[CREATING NEW STACK]\n");
    printf("\nEnter size of stack: ");

    scanf("%d", &stackSize);

    int new_stack[stackSize];

    // printf("\n\n[CREATING NEW STACK]");

    printf("\n\nCHOOSE OPERATION:\n\n1.Insertion\n2.Deletion\n3.Show\n4.Exit\n");

    for (int loop = 0, flag = 0; loop >= 0 && flag != 1; loop++)
    {
        printf("\nOperation number: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nItem to push(): ");
            scanf("%d", &item);
            stackPush(new_stack, &TOP, stackSize, item);
            break;

        case 2:
            stackPop(new_stack, &TOP, stackSize);
            break;

        case 3:
            stackShow(new_stack, TOP);
            break;

        case 4:
            flag = 1;
            break;

        default:
            printf("\n\nERROR: INVALID CHOICE");
        }
    }
}

void main()
{

    int choice;

    printf("This program has a built in stack to perform operations.\nYou can either continue with default stack or create a new one.\n\nDefault stack: | 10 | 20 | 30 |   |   |   | SIZE: 6");

    for (int loop = 0; loop >= 0; loop++)
    {
        printf("\n\n\nCHOOSE OPERATION:\n\n1.Continue with default stack.\n2.Create a new stack.\n3.Exit\n");
        printf("\nOperation number: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            continueWithDef();
            break;

        case 2:
            createNewStack();
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("\n\nERROR: INVALID CHOICE");
        }
    }
