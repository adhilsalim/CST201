#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int hashFunction(int);
void display();
void insert();

struct node
{
    int data;
    struct node *link;
};

struct node *hashTable[10];
struct node *head = NULL;
struct node *temp = NULL;

void insert()
{
    int element, index;

    printf("ELEMENT: ");
    scanf("%d", &element);
    index = hashFunction(element);

    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = element;
    new_node->link = NULL;

    head = hashTable[index];

    if (head == NULL)
    {
        hashTable[index] = new_node;
    }
    else
    {
        new_node->link = hashTable[index];
        hashTable[index] = new_node;
    }

    display(hashTable);
}
void display()
{
    printf("\nHASHTABLE:\n");
    for (int i = 0; i < 10; i++)
    {
        temp = hashTable[i];

        if (temp == NULL)
        {
            printf("null");
        }
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n\n");
    }
}

int hashFunction(int e)
{
    return e % 10;
}

void main()
{
    int choice;
    bool EXIT_LOOP = false;

    while (!EXIT_LOOP)
    {
        printf("\n\n(1) - insert element (2) - display hashtable (3) - exit\noperation: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert(hashTable);
            break;
        case 2:
            display(hashTable);
            break;
        case 3:
            exit(0);
            break;

        default:
            printf("\ninvalid operation number. please try again.");
            break;
        }
    }
}