#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void createLL()
{
}

void displayLL()
{
}

void insertLL()
{
}

void deleteLL()
{
}

void main()
{
    int choice;

    printf(" [HOME] Select an operation from the list: \n");
    printf("1.Create LinkedList\n2.Display LinkedList\n3.Insert element to LinkedList\n4.Delete element from LinkedList\n5.Exit");
    printf("\n\nOperation Number: ");
    scanf("%d", &choice);

    while (true)
    {
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