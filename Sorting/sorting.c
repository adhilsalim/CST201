#include <stdio.h>
#include <stdbool.h>

void display(int[], int);
void insertionSort(int[], int);
void selectionSort(int[], int);
void swap(int *, int *);
void quickSort(int[], int, int);
int partition(int[], int, int);
void restoreUnsortedArray(int[], int[], int);
void bubbleSort(int[], int);
void mergeSort(int[], int, int);
void merge(int[], int, int, int);
void copyElements(int from[], int to[], int low, int n);
void heapSort(int[], int);
void BuildMaxHeap(int[], int);
void heapify(int[], int, int);

void heapify(int a[], int n, int i)
{
    int leftChildIndex = (2 * i) + 1;
    int rightChildIndex = (2 * i) + 2;
    int largest = i;

    if (leftChildIndex < n && a[leftChildIndex] > a[largest])
    {
        largest = leftChildIndex;
    }
    if (rightChildIndex < n && a[rightChildIndex] > a[largest])
    {
        largest = rightChildIndex;
    }

    if (largest != i)
    {
        swap(&a[largest], &a[i]);
        heapify(a, n, largest);
    }
}

void BuildMaxHeap(int a[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
}

void heapSort(int a[], int n)
{
    BuildMaxHeap(a, n);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

void copyElements(int fromArray[], int toArray[], int low, int n)
{
    for (int i = 0; i < n; i++)
    {
        toArray[i] = fromArray[low + i];
    }
}

void merge(int a[], int low, int middle, int high)
{
    int n1, n2;
    n1 = middle - low + 1;
    n2 = high - middle;

    int LEFT_ARRAY[n1], RIGHT_ARRAY[n2];
    copyElements(a, LEFT_ARRAY, low, n1);
    copyElements(a, RIGHT_ARRAY, middle + 1, n2);

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2)
    {
        if (LEFT_ARRAY[i] <= RIGHT_ARRAY[j])
        {
            a[k] = LEFT_ARRAY[i];
            i++;
        }
        else
        {
            a[k] = RIGHT_ARRAY[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = LEFT_ARRAY[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = RIGHT_ARRAY[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int middle = (low + high) / 2;
        mergeSort(a, low, middle);
        mergeSort(a, middle + 1, high);
        merge(a, low, middle, high);
    }
}

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }
    }

    display(a, n);
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j <= high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void selectionSort(int a[], int n)
{
    int k, j, min, loc;
    k = 0;
    while (k < n)
    {
        min = a[k];
        loc = k;
        j = k + 1;

        while (j < n)
        {
            if (a[j] < min)
            {
                min = a[j];
                loc = j;
            }
            j++;
        }
        swap(&a[loc], &a[k]);
        k++;
    }
    display(a, n);
}

void insertionSort(int a[], int n)
{

    int current, j;
    for (int i = 1; i < n; i++)
    {
        current = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > current)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = current;
    }

    display(a, n);
}

void swap(int *numberOne, int *numberTwo)
{
    int temp = *numberOne;
    *numberOne = *numberTwo;
    *numberTwo = temp;
}

void display(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void restoreUnsortedArray(int current[], int copy[], int n)
{
    for (int i = 0; i < n; i++)
    {
        current[i] = copy[i];
    }

    printf("\nUNSORTED ARRAY: ");
    display(current, n);
}

void main()
{

    int TOTAL_ELEMENTS = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &TOTAL_ELEMENTS);

    int UNSORTED_ARRAY_COPY[TOTAL_ELEMENTS];
    int UNSORTED_ARRAY[TOTAL_ELEMENTS];

    printf("\nEnter the elements: \n");

    for (int i = 0; i < TOTAL_ELEMENTS; i++)
    {
        printf("enter element %d: ", i + 1);
        scanf("%d", &UNSORTED_ARRAY[i]); // INCLUDE & IN SCANF ALWAYS
        UNSORTED_ARRAY_COPY[i] = UNSORTED_ARRAY[i];
    }

    printf("\nThe unsorted array is: ");
    display(UNSORTED_ARRAY, TOTAL_ELEMENTS);

    int choice;
    bool EXIT_LOOP = false;

    while (!EXIT_LOOP)
    {

        printf("\nSELECT SORTING METHOD: ");
        printf("\n[1] BUBBLE SORT\n[2] INSERTION SORT\n[3] SELECTION SORT\n[4] QUICK SORT\n[5] MERGE SORT\n[6] HEAP SORT\n[7] EXIT");
        printf("\n\nENTER OPERATION NUMBER: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nperforming bubble sort.\n__SORTED ARRAY: ");
            bubbleSort(UNSORTED_ARRAY, TOTAL_ELEMENTS);
            restoreUnsortedArray(UNSORTED_ARRAY, UNSORTED_ARRAY_COPY, TOTAL_ELEMENTS);
            break;
        case 2:
            printf("\nperforming insertion sort.\n__SORTED ARRAY: ");
            insertionSort(UNSORTED_ARRAY, TOTAL_ELEMENTS);
            restoreUnsortedArray(UNSORTED_ARRAY, UNSORTED_ARRAY_COPY, TOTAL_ELEMENTS);
            break;
        case 3:
            printf("\nperforming selection sort.\n__SORTED ARRAY: ");
            selectionSort(UNSORTED_ARRAY, TOTAL_ELEMENTS);
            restoreUnsortedArray(UNSORTED_ARRAY, UNSORTED_ARRAY_COPY, TOTAL_ELEMENTS);
            break;
        case 4:
            printf("\nperforming quick sort.\n__SORTED ARRAY: ");
            quickSort(UNSORTED_ARRAY, 0, TOTAL_ELEMENTS - 1);
            display(UNSORTED_ARRAY, TOTAL_ELEMENTS);
            restoreUnsortedArray(UNSORTED_ARRAY, UNSORTED_ARRAY_COPY, TOTAL_ELEMENTS);
            break;
        case 5:
            printf("\nperforming merge sort.\n__SORTED ARRAY: ");
            mergeSort(UNSORTED_ARRAY, 0, TOTAL_ELEMENTS - 1);
            display(UNSORTED_ARRAY, TOTAL_ELEMENTS);
            restoreUnsortedArray(UNSORTED_ARRAY, UNSORTED_ARRAY_COPY, TOTAL_ELEMENTS);
            break;
        case 6:
            printf("\nperforming heap sort.\n__SORTED ARRAY: ");
            heapSort(UNSORTED_ARRAY, TOTAL_ELEMENTS);
            display(UNSORTED_ARRAY, TOTAL_ELEMENTS);
            restoreUnsortedArray(UNSORTED_ARRAY, UNSORTED_ARRAY_COPY, TOTAL_ELEMENTS);
            break;
        case 7:
            EXIT_LOOP = true;
            break;
        default:
            printf("\ninvalid choice. please try again.");
            break;
        }
    }
}