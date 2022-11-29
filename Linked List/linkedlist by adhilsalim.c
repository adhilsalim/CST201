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
        printf("\n\n| Creating a Linked List |\n\n");
        head = (struct node *)malloc(sizeof(struct node));
        printf("[CONSOLE]Linked List created");
        linkedListCreated = true;
        free(head);
    }
    else
    {
        printf("\n[CONSOLE]A Linked List is already created.\n");
    }
}

void displayLL()
{
    printf("Hello");
}

//==========================INSERT LL=========================//
void insertLL()
{
    int choice;
    printf("\n\n[INSERT ELEMENT]Selection an operation number from the list: \n");
    printf("1.Insertion at front of Linked List.\n2.Insertion at end of Linked List.\nInsertion at particular position.\n4.Exit.");
    printf("Select an operation number: ");
    scanf("%d", % choice);

    switch (choice)
    {
    case 1:
        insertF();
        break;
    case 2:
        insertE();
        break;
    case 3:
        insertP();
        break;
    case 4:
        insertE();
        break;
    default:
        break;
    }
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
        printf("1.Create Linked List\n2.Display Linked List\n3.Insert element to Linked List\n4.Delete element from Linked List\n5.Exit");
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