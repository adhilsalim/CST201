

#include <stdio.h>
#include <stdlib.h>

int endPosition = -1, queueSize = 0;

void insertion(int this, int to, int in[])
{

    if (endPosition != queueSize - 1)
    {
        for (int i = endPosition; i >= to; i--)
        {
            printf("\ncurrent endposition: %d\ncurrent i: %d", endPosition, i);
            printf("\nswapping %d and %d\n", in[endPosition], in[endPosition - 1]);
            in[i + 1] = in[i];
        }
        in[to] = this;
        endPosition++;
        printf("\n[INSERTED]\n");
    }
    else
    {
        printf("\n[FAILED] Queue is full");
    }
}

void deletion(int from, int array[])
{
    if (!(from <= endPosition))
    {
        printf("\n[FAILED] out of range");
    }
    else if (endPosition != -1)
    {
        for (int i = from; i < endPosition; i++)
        {
            printf("\ncurrent endposition: %d\ncurrent i: %d", endPosition, i);
            printf("\nswapping %d and %d\n", array[i], array[i + 1]);
            array[i] = array[i + 1];
        }
        endPosition--;
        printf("\n[DELETED]\n");
    }
    else
    {
        printf("\n[FAILED] Queue is empty");
    }
}

void jump(int from, int to)
{
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

            insertion(element, position, queue);

            break;

        case 2:
            printf("\nEnter index position of item to be deleted: ");
            scanf("%d", &position);

            deletion(position, queue);
            break;

        case 3:
            printf("Enter position of item to be jumped: ");
            scanf("%d", &position);

            printf("Enter position to jump to: ");
            scanf("%d", &jumpPosition);

            jump(position, jumpPosition);
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