#include <stdio.h>

void selectionSort(int arr[], int n);
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main()
{
    int n, choice;
    int arr[100], temp[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nChoose Sorting Algorithm\n");
    printf("1. Selection Sort\n");
    printf("2. Bubble Sort\n");
    printf("3. Insertion Sort\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    // Copy array to temp
    for(int i = 0; i < n; i++)
        temp[i] = arr[i];

    switch(choice)
    {
        case 1:
            selectionSort(temp, n);
            break;

        case 2:
            bubbleSort(temp, n);
            break;

        case 3:
            insertionSort(temp, n);
            break;

        default:
            printf("Invalid choice");
    }

    return 0;
}

void selectionSort(int arr[], int n)
{
    int i, j, min, temp;
    int comparisons = 0, swaps = 0;

    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            comparisons++;
            if(arr[j] < arr[min])
                min = j;
        }
        if(min != i)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
            swaps++;
        }
    }

    printf("\nSorted Array (Selection Sort): ");
    printArray(arr, n);
    printf("\nComparisons: %d", comparisons);
    printf("\nSwaps: %d\n", swaps);
}

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    int comparisons = 0, swaps = 0;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            comparisons++;
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
        }
    }

    printf("\nSorted Array (Bubble Sort): ");
    printArray(arr, n);
    printf("\nComparisons: %d", comparisons);
    printf("\nSwaps: %d\n", swaps);
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    int comparisons = 0, shifts = 0;

    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
            shifts++;
        }
        arr[j + 1] = key;
    }

    printf("\nSorted Array (Insertion Sort): ");
    printArray(arr, n);
    printf("\nComparisons: %d", comparisons);
    printf("\nShifts: %d\n", shifts);
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
