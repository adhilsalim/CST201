/*
This program perform the following operations on a linked list:
1. Create
2. Display
3. Insert
4. Delete
Author: Adhil Salim
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//======================================= STRUCTURE =====================================//
bool LLExist = false;

struct node
{
    int data;
    struct node *link;
};

struct node *head = NULL;
struct node *temp = NULL;

//======================================= CREATE LL =====================================//
void createLL()
{
    int LLdata;

    if (LLExist == false)
    {
        head = (struct node *)malloc(sizeof(struct node));
        LLExist = true;
        printf("Enter data for first node: ");
        scanf("%d", &LLdata);

        head->data = LLdata;
        head->link = NULL;

        printf("\n[Linked List Created]\n");
    }
    else
    {
        printf("\nA linked list is already created.\n");
    }
    printf("\n-----------------------------------------\n");
}

//======================================= DISPLAY LL =====================================//
void displayLL()
{

    if (head != NULL)
    {
        struct node *tempHead = NULL;
        tempHead = head;

        while (tempHead != NULL)
        {
            printf("%d", tempHead->data);
            tempHead = tempHead->link;

            if (tempHead != NULL)
            {
                printf(" - ");
            }
        }
    }
    else
    {
        printf("\nLinked List Doesn't exist.\n");
        LLExist = false;
    }
    printf("\n-----------------------------------------\n");
}

//======================================= INSERT FRONT =====================================//

void insertF()
{

    int data;

    if (head != NULL)
    {
        temp = head;

        struct node *newNode = NULL;
        newNode = (struct node *)malloc(sizeof(struct node));

        printf("\nEnter data for new node: ");
        scanf("%d", &data);

        newNode->data = data;
        newNode->link = head;
        head = newNode;
    }
    else
    {
        printf("\nLinked List Doesn't Exist.\n");
        LLExist = false;
    }
    printf("\n-----------------------------------------\n");
}

//======================================= INSERT END =====================================//

void insertE()
{
    int data;

    if (head != NULL)
    {
        temp = head;

        struct node *newNode = NULL;
        struct node *temp = NULL;

        newNode = (struct node *)malloc(sizeof(struct node));

        printf("\nEnter data for new node: ");
        scanf("%d", &data);

        newNode->data = data;
        newNode->link = NULL;

        temp = head;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = newNode;
    }
    else
    {
        printf("\nLinked List Doesn't Exist.\n");
        LLExist = false;
    }
    printf("\n-----------------------------------------\n");
}

//======================================= INSERT PARTICULAR =====================================//

void insertP(struct node *hd, int pos, int dir)
{

    if (head != NULL)
    {
        int data;

        if (dir == 2 || dir == 1)
        {

            struct node *temp = NULL;
            struct node *prevtemp = NULL;
            struct node *newNode = NULL;
            newNode = (struct node *)malloc(sizeof(struct node));

            temp = hd; // temp =  head; //(global)

            printf("Enter data for new node: ");
            scanf("%d", &data);

            newNode->data = data;
            newNode->link = NULL;

            if (dir == 1)
            {
                // AFTER
                while (temp->data != pos)
                {
                    temp = temp->link;

                    if (temp == NULL)
                    {
                        break;
                    }
                }

                if (temp == NULL)
                {
                    printf("\nElement %d is not present in Linked List.", pos);
                    free(newNode);
                }
                else
                {

                    // printf("%p", temp->link);

                    newNode->link = temp->link;
                    temp->link = newNode;
                }
            }
            else
            {
                // BEFORE

                temp = hd;
                prevtemp = NULL;

                while (temp->data != pos)
                {
                    prevtemp = temp;
                    temp = temp->link;

                    if (temp == NULL)
                    {
                        break;
                    }
                }

                if (temp == NULL)
                {
                    printf("\nElement %d is not present in Linked List.", pos);
                    free(newNode);
                }

                if (prevtemp != NULL)
                {
                    prevtemp->link = newNode;
                    newNode->link = temp;
                }
                else
                {
                    newNode->link = temp;
                    head = newNode;
                }
            }
        }
        else
        {
            printf("\nInvalid direction.");
        }
    }
    else
    {
        printf("Linked List Doesn't Exist.");
        LLExist = false;
    }
    printf("\n-----------------------------------------\n");
}

//======================================= INSERT LL =====================================//
void insertLL()
{

    int choice, position, direction;
    bool exitLoop = false;

    for (int i = 0; i >= 0 && exitLoop != true; i++)
    {
        if (i > 500)
        {
            i = 0;
        }

        printf("\n\n[INSERT]\n\n");
        printf("1.Insert at front of LL\n2.Insert at end of LL\n3.Insert at particular position\n4.Exit");
        printf("\n\nOperation Number: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n-----------------------------------------\n");
            insertF(head);
            break;

        case 2:
            printf("\n-----------------------------------------\n");
            insertE(head);
            break;

        case 3:
            printf("\n-----------------------------------------\n");
            printf("Enter position: ");
            scanf("%d", &position);

            printf("Insert after/before %d\n\n1.After\n2.Before\n\nOption: ", position);
            scanf("%d", &direction);

            insertP(head, position, direction);
            break;

        case 4:
            exitLoop = true;
            break;

        default:
            printf("\n[ERROR] Invalid Operation Number.");
        }
    }
    printf("\n-----------------------------------------\n");
}
//======================================= DELETE FRONT =====================================//

void deleteF()
{
    int data;

    if (head != NULL)
    {
        data = head->data;

        struct node *tempHead = NULL;
        tempHead = head;

        if (tempHead->link != NULL)
        {
            // printf("multiple node case");
            head = head->link;
            free(tempHead);
        }
        else
        {
            // printf("one node case");
            data = tempHead->data;
            free(tempHead);
            head = NULL;
        }

        printf("\n%d deleted from linked list.\n", data);
    }
    else
    {
        printf("\nLinked List Doesn't Exist\n");
        LLExist = false;
    }
}
//======================================= DELETE END =====================================//

void deleteE()
{
    int data;

    if (head != NULL)
    {

        temp = head;

        if (temp->link != NULL)
        {

            while ((temp->link)->link != NULL)
            {
                temp = temp->link;
            }

            data = (temp->link)->data;
            free(temp->link);
            temp->link = NULL;
        }
        else
        {
            data = temp->data;
            free(temp);
            head = NULL;
        }
        printf("\n%d deleted from linked list.\n", data);
    }
    else
    {
        printf("\nLinked List Doesn't Exist.\n");
        LLExist = false;
    }
}

//======================================= DELETE PARTICULAR =====================================//
void deleteP(int pos)
{
    int data;
    bool present = false;

    if (head != NULL)
    {

        if (head->data == pos)
        {
            deleteF();
        }
        else
        {

            temp = head;
            struct node *nodeToDelete = NULL;

            while (temp != NULL)
            {
                if (temp->data == pos)
                {
                    present = true;
                    break;
                }
                temp = temp->link;
            }

            temp = head;

            if (present == true)
            {
                while ((temp->link)->data != pos && temp->link != NULL)
                {

                    temp = temp->link;
                }
                nodeToDelete = temp->link;
                data = nodeToDelete->data;

                temp->link = (temp->link)->link;
                free(nodeToDelete);

                printf("\n%d deleted from linked list.\n", data);
            }
            else
            {
                printf("\nElement %d is not present in Linked List.", pos);
            }
        }
    }
    else
    {
        printf("\nLinked List Doesn't Exist.\n");
        LLExist = false;
    }
}
//======================================= DELETE LL =====================================//

void deleteLL()
{
    int choice, position;
    bool exitLoop = false;

    for (int i = 0; i >= 0 && exitLoop != true; i++)
    {
        if (i > 500)
        {
            i = 0;
        }

        printf("\n\n[DELETE]\n\n");
        printf("1.Delete from front of LL\n2.Delete from end of LL\n3.Delete from particular position\n4.Exit");
        printf("\n\nOperation Number: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n-----------------------------------------\n");
            deleteF();
            break;

        case 2:
            printf("\n-----------------------------------------\n");
            deleteE();
            break;

        case 3:
            printf("\n-----------------------------------------\n");
            printf("Enter position: ");
            scanf("%d", &position);
            deleteP(position);
            break;

        case 4:
            exitLoop = true;
            break;

        default:
            printf("\n[ERROR] Invalid Operation Number.");
        }
    }
}

//=======================================MAIN=====================================//
void main()
{

    int choice;

    while (true)
    {

        printf("\n\n[HOME]\n\n");
        printf("1.Create a LL\n2.Display LL\n3.Insert element to LL\n4.Delete element from LL\n5.Exit");
        printf("\n\nOperation Number: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n-----------------------------------------\n");
            createLL();
            break;

        case 2:
            printf("\n-----------------------------------------\n");
            displayLL();
            break;

        case 3:
            printf("\n-----------------------------------------\n");
            insertLL();
            break;

        case 4:
            printf("\n-----------------------------------------\n");
            deleteLL();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("\n[ERROR] Invalid Operation Number.");
        }
    }
}