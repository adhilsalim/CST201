

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int endPosition = -1, queueSize = 0, jumpStatus = 0;
bool jumping = false;

void insertion(int this, int to, int in[], bool jumping)
{

    if (endPosition != queueSize - 1)
    {
        for (int i = endPosition; i >= to; i--)
        {
            in[i + 1] = in[i];
        }
        in[to] = this;
        endPosition++;
        jumpStatus++;

        if (!jumping)
            printf("\n[INSERTED]\n");
    }
    else
    {
        if (!jumping)
            printf("\n[FAILED] Queue is full");
    }
}

void deletion(int from, int array[], bool jumping)
{
    if (!(from <= endPosition) || 1 == 0)
    {
        if (!jumping)
            printf("\n[FAILED] out of range");
    }
    else if (endPosition != -1)
    {
        for (int i = from; i < endPosition; i++)
        {
            array[i] = array[i + 1];
        }
        endPosition--;
        jumpStatus++;

        if (!jumping)
            printf("\n[DELETED]\n");
    }
    else
    {
        if (!jumping)
            printf("\n[FAILED] Queue is empty");
    }
}

void jump(int from, int to, int in[])
{
    jumpStatus = 0;
    // if(from>=endPosition)
    int temp1 = in[from]; // from
    int temp2 = in[to];   // to

    deletion(to, in, true);
    insertion(temp2, from, in, true);
    deletion(from + 1, in, true);
    insertion(temp1, to, in, true);

    if (jumpStatus != 2)
    {
        printf("\n[FAILED] Jumping is not possible");
    }
    else
    {
        printf("\n[JUMPED]\n");
    }
}

void display(int array[])
{
    for (int i = 0; i <= endPosition; i++)
    {
        printf("%d ", array[i]);
    }
    if (endPosition == -1)
    {
        printf("\n[EMPTY] queue is empty");
    }

    printf("\n");
}

void main()
{
    int operationNumber, element, position = -1, jumpPosition = -1;

    printf("[INDIAN QUEUE]\n\n");
    printf("[CREATING QUEUE]\n");
    printf("Enter the size of the queue: ");
    scanf("%d", &queueSize);

    int queue[queueSize]; // creating the queue

    printf("[QUEUE CREATED WITH SIZE %d]\n", queueSize);
    printf("\nEnter number of elements in queue: ");
    scanf("%d", &endPosition); // taking the number of elements in the queue
    endPosition--;
    printf("\n");

    // checking overflow conidition
    if (endPosition > queueSize - 1)
    {
        printf("\n[ERROR] Queue Overflow\n");
        exit(0);
    }

    printf("[SETUP QUEUE]\n\n");

    // taking the elements in the queue
    for (int i = 0; i <= endPosition; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &queue[i]);
    }

    printf("\n");
    printf("[CHOOSE OPERATION]:\n\n1.Insertion\n2.Deletion\n3.Jump\n4.Display\n5.Exit\n");

    for (int loop = 0; loop >= 0; loop++)
    {
        printf("\nEnter operation number: ");
        scanf("%d", &operationNumber);

        switch (operationNumber)
        {
        case 1:
            printf("\nEnter item to insert: ");
            scanf("%d", &element);

            printf("\nEnter index position to insert: ");
            scanf("%d", &position);

            insertion(element, position, queue, false);

            break;

        case 2:
            printf("\nEnter index position of item to be deleted: ");
            scanf("%d", &position);

            deletion(position, queue, false);
            break;

        case 3:
            printf("Enter position of item to be jumped: ");
            scanf("%d", &position);

            printf("Enter position to jump to: ");
            scanf("%d", &jumpPosition);

            jump(position, jumpPosition, queue);
            break;

        case 4:
            display(queue);
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid operation number. Please try again.\n");
            break;
        }
    }
}