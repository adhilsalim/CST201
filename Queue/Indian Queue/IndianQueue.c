

#include <stdio.h>

void insertion(int this, int to, int in)
{
}

void deletion(int from)
{
}

void jump(int from, int to)
{
}

void display(int array)
{
}

void main()
{
    int queueSize, operationNumber, element, position = -1, jumpPosition = -1, endPosition = -1;

    printf("[INDIAN QUEUE]\n\n");
    printf("[CREATING QUEUE]\n");
    printf("Enter the size of the queue: ");
    scanf("%d", &queueSize);

    int queue[queueSize];

    printf("[QUEUE CREATED WITH SIZE %d]\n", queueSize);
    printf("\nEnter number of elements in queue: ");
    scanf("%d", &endPosition);

    printf("[SETUP QUEUE]\n");

    for (int i = 0; i <= endPosition; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &queue[i]);
    }

    printf("Operations:\n1.Insertion\n2.Deletion\n3.Jump\n4.Display\n5.Exit\n");
    printf("Enter operation number: ");
    scanf("%d", &operationNumber);

    for (int loop = 0; loop >= 0; loop++)
    {
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

            deletion(position);
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