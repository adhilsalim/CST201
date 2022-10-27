/*
This program perform binary search
Author: Adhil Salim
*/

#include <stdio.h>

void main()
{
    int totalElements, key, found = 0;
    int low, high, mid;

    printf("Enter the number of elements: ");
    scanf("%d", &totalElements);

    int mainArray[totalElements];

    // setting low, high and mid
    low = 0;
    high = totalElements - 1;
    mid = (low + high) / 2;

    // getting sorted array
    printf("Enter the sorted array: \n");
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

    while (low != high)
    {
        if (mainArray[mid] == key)
        {
            found = 1;
            printf("L %d H %d M %d\n", low, high, mid);
            break;
        }
        else if (key > mid)
        {
            low = mid + 1;
            mid = (low + high) / 2;
            printf("L %d H %d M %d\n", low, high, mid);
        }
        else if (key < mid)
        {
            high = mid - 1;
            mid = (low + high) / 2;
            printf("L %d H %d M %d\n", low, high, mid);
        }
    }

    if (found)
        printf("element found at %d", mid);
    else
        printf("\nElement not found.");
}