#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool EXIT_LOOP = false;
bool DUPLICATE_ELEMENT = false;

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
struct node *new_node = NULL;
struct node *child = NULL;

void insert();
void delete(int);
void traverse();

void preOrder(struct node *);
void postOrder(struct node *);
void inOrder(struct node *);

void delete(int data)
{
    if (root == NULL)
    {
        printf("\nTREE DOESN'T EXIST\n");
    }
    else
    {
        current = root;

        while (current != NULL && current->data != data)
        {
            parent = current;

            if (data < current->data)
            {
                current = current->leftChild;
            }
            else if (data > current->data)
            {
                current = current->rightChild;
            }
        }

        if (current == NULL)
        {
            printf("\nTHE NODE DOESN'T EXIST IN TREE\n");
        }
        else
        {
            bool isLeftChild;

            if (parent->leftChild != NULL && (parent->leftChild)->data == data)
            {
                child = parent->leftChild;
                isLeftChild = true;
            }
            else if (parent->rightChild != NULL && (parent->rightChild)->data == data)
            {
                child = parent->rightChild;
                isLeftChild = false;
            }
            else
            {
                printf("\nAN INTERNAL ERROR OCCURRED\n");
                exit(0);
            }

            if (child->leftChild == NULL && child->rightChild == NULL)
            {
                if (isLeftChild)
                {
                    parent->leftChild = NULL;
                }
                else
                {
                    parent->rightChild = NULL;
                }

                free(child);
            }
            else if (child->leftChild != NULL && child->rightChild == NULL)
            {
                if (isLeftChild)
                {
                    parent->leftChild = child->leftChild;
                }
                else
                {
                    parent->rightChild = child->leftChild;
                }
            }
            else if (child->leftChild == NULL && child->rightChild != NULL)
            {
                if (isLeftChild)
                {
                    parent->leftChild = child->rightChild;
                }
                else
                {
                    parent->rightChild = child->rightChild;
                }
            }
            else
            {
            }
        }
    }
}

void preOrder(struct node *t)
{
    if (t != NULL)
    {
        printf("%d ", t->data);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}

void inOrder(struct node *t)
{
    if (t != NULL)
    {
        inOrder(t->leftChild);
        printf("%d ", t->data);
        inOrder(t->rightChild);
    }
}

void postOrder(struct node *t)
{
    if (t != NULL)
    {
        postOrder(t->leftChild);
        postOrder(t->rightChild);
        printf("%d ", t->data);
    }
}

void traverse()
{
    int choice;
    bool traversalMenu = true;

    while (traversalMenu)
    {
        printf("\n\nSelect an operation: ");
        printf("\n1.Preorder\n2.Inorder\n3.Postorder\n4.Exit");
        printf("\n\noperation No: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nPREORDER:  ");
            preOrder(root);
            break;
        case 2:
            printf("\nINORDER:  ");
            inOrder(root);
            break;
        case 3:
            printf("\nPOSTORDER:  ");
            postOrder(root);
            break;
        case 4:
            traversalMenu = false;
            break;
        default:
            printf("\nInvalid operation number.\n");
        }
    }
}

void insert()
{
    int data;
    printf("\nENTER ELEMENT TO INSERT: ");
    scanf("%d", &data);

    if (root == NULL)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->leftChild = NULL;
        new_node->rightChild = NULL;

        root = new_node;
        printf("\nROOT CREATED.\n");
    }
    else
    {
        current = root;

        DUPLICATE_ELEMENT = false;

        while (current != NULL)
        {
            parent = current;

            if (data > current->data)
            {
                current = current->rightChild;
            }
            else if (data < current->data)
            {
                current = current->leftChild;
            }
            else
            {
                printf("\nDUPLICATE DATA IS NOT ALLOWED. INSERTION DENIED.\n");
                DUPLICATE_ELEMENT = true;
                break;
            }
        }

        if (!DUPLICATE_ELEMENT)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = data;
            new_node->leftChild = NULL;
            new_node->rightChild = NULL;

            if (data < parent->data)
            {
                parent->leftChild = new_node;
                printf("\nNEW NODE ADDED AS LEFT CHILD\n");
            }
            else
            {
                parent->rightChild = new_node;
                printf("\nNEW NODE ADDED AS RIGHT CHILD\n");
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