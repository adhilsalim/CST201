#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool EXIT_LOOP = false;

struct node
{
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

struct node *root = NULL;
struct node *temp = NULL;
struct node *current = NULL;
struct node *parent = NULL;

void insert();
void delete();
void traverse();

void insert()
{
    int data;
    printf("\nENTER ELEMENT TO INSERT: ");
    scanf("%d", &data);

    if (root == NULL)
    {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));

        new_node->data = data;
        new_node->leftChild = NULL;
        new_node->rightChild = NULL;

        root = new_node;
    }
    else
    {
        current = root;

        while (current != NULL)
        {
            parent = current;

            if (data > current->data)
            {
            }
            else if (data < current->data)
            {
            }
            else
            {
                printf("\nDUPLICATE DATA IS NOT ALLOWED. INSERTION DENIED.\n");
            }
        }
    }
}

void main()
{
    int choice;
    while (!EXIT_LOOP)
    {
        printf("\n[1]INSERT [2]DELETE [3]TRAVERSAL [4]EXIT\nOPERATION: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            traverse();
            break;
        case 4:
            EXIT_LOOP = true;
            break;

        default:
            printf("\nINVALID OPERATION NUMBER\n");
            break;
        }
    }
}