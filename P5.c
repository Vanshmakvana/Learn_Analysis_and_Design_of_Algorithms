#include <stdio.h>

int linearSearch(int arr[], int n, int key, int *comparisons)
{
    for (int i = 0; i < n; i++)
    {
        (*comparisons)++;
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int n, int key, int *comparisons)
{
    int low = 0, high = n - 1, mid;

    while (low <= high)
    {
        (*comparisons)++;
        mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n, key, choice;
    int arr[100];
    int comparisons = 0, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order (for Binary Search):\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    printf("\n1. Linear Search\n2. Binary Search\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        comparisons = 0;
        result = linearSearch(arr, n, key, &comparisons);

        if (result != -1)
            printf("\nLinear Search: Element found at index %d", result);
        else
            printf("\nLinear Search: Element not found");

        printf("\nComparisons: %d\n", comparisons);
    }
    else if (choice == 2)
    {
        comparisons = 0;
        result = binarySearch(arr, n, key, &comparisons);

        if (result != -1)
            printf("\nBinary Search: Element found at index %d", result);
        else
            printf("\nBinary Search: Element not found");

        printf("\nComparisons: %d\n", comparisons);
    }
    else
    {
        printf("Invalid choice");
    }

    return 0;
}
