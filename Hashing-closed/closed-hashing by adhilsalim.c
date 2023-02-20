#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int hashFunction(int);
void display(int[]);
void insert(int[]);

void insert(int hashTable[])
{
    int element, index;

    printf("ELEMENT: ");
    scanf("%d", &element);

    index = hashFunction(element);

    if (hashTable[index] != -1)
    {
        printf("\ncollision occurs at %d\n", index);

        bool EXIT_LOOP = false;
        int count = 0;

        while (!EXIT_LOOP && count <= 9)
        {
            count++;

            if (index >= 9)
            {
                index = 0;
            }
            else if (index < 9)
            {
                index++;
            }

            if (hashTable[index] == -1)
            {
                hashTable[index] = element;
                EXIT_LOOP = true;
            }
        }
        if (count >= 9)
        {
            printf("\ninsertion not possible.");
        }
        display(hashTable);
    }
    else
    {
        hashTable[index] = element;
        display(hashTable);
    }
}
void display(int a[])
{
    printf("HASHTABLE: ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
}

int hashFunction(int e)
{
    return e % 10;
}

void main()
{
    int hashTable[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, choice;
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