#include <stdio.h>

/* ---------- MERGE SORT ---------- */
void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int temp[100];

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

/* ---------- QUICK SORT ---------- */
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1, temp;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* ---------- MAIN ---------- */
int main()
{
    int n, choice;
    int arr[100], temp[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        temp[i] = arr[i];   // copy for second sort
    }

    printf("\n1. Merge Sort\n2. Quick Sort\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        mergeSort(arr, 0, n - 1);
        printf("\nSorted Array using Merge Sort:\n");
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
    }
    else if (choice == 2)
    {
        quickSort(temp, 0, n - 1);
        printf("\nSorted Array using Quick Sort:\n");
        for (int i = 0; i < n; i++)
            printf("%d ", temp[i]);
    }
    else
    {
        printf("Invalid choice");
    }

    return 0;
}
