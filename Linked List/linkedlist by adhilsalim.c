#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//=========================STRUCTURE=========================//
bool linkedListCreated = false;

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;

//==========================CREATING LL=========================//
void createLL()
{
    if (linkedListCreated == false)
    {
        printf("\n\n| Creating a LinkedList |\n\n");
        head = (struct node *)malloc(sizeof(struct node));
        printf("[CONSOLE]Linked List created");
        linkedListCreated = true;
        free(head);
    }
    else
    {
        printf("\n[CONSOLE]A LinkedList is already created.\n");
    }
}

void displayLL()
{
    printf("Hello");
}

void insertLL()
{
    printf("Hello");
}

void deleteLL()
{
    printf("Hello");
}

void main()
{
    int choice;

    while (true)
    {
        printf("\n\n[HOME] Select an operation from the list: \n");
        printf("1.Create LinkedList\n2.Display LinkedList\n3.Insert element to LinkedList\n4.Delete element from LinkedList\n5.Exit");
        printf("\n\nOperation Number: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createLL();
            break;
        case 2:
            displayLL();
        case 3:
            insertLL();
            break;
        case 4:
            deleteLL();
        case 5:
            exit(0);
        default:
            printf("\nInvalid operation number.\n");
            break;
        }
    }
}