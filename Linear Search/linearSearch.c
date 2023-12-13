/*
This program performs linear search
Author: Adhil Salim
*/
#include <stdio.h>

void main()
{

    int totalElements, key, flag = 0, i;

    printf("Enter the number of elements: ");
    scanf("%d", &totalElements);

    int mainArray[totalElements];

    // getting elements into array
    for (int i = 0; i < totalElements; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &mainArray[i]);
    }

    // printing array
    printf("\nPrinting Array: ");
    for (int i = 0; i < totalElements; i++)
    {
        printf("%d ", mainArray[i]);
    }

    printf("\nEnter element to be searched: ");
    scanf("%d", &key);

    // searching for element
    for (i = 0; i < totalElements; i++)
    {
        if (mainArray[i] == key)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        printf("Element %d found at index position %d", key, i);
    }
    else
    {
        printf("Element %d not found", key);
    }
}