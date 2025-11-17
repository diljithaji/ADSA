#include <stdio.h>

// Function to perform Selection Sort on a subarray
void selectionSort(int arr[], int start, int end)
{
    for (int i = start; i < end - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < end; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // Swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// Function to merge two sorted halves of the array
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays
    int L[n1], R[n2];

    // Copy data
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Function to merge sorted chunks
void mergeChunks(int arr[], int n, int chunkSize)
{
    for (int size = chunkSize; size < n; size *= 2)
    {
        for (int left = 0; left < n - size; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = (left + 2 * size - 1 < n) ? (left + 2 * size - 1) : (n - 1);
            merge(arr, left, mid, right);
        }
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11, 90, 45, 72, 30, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int chunkSize = 3; // You can adjust this

    printf("Original Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    // Step 1: Sort each chunk using Selection Sort
    for (int i = 0; i < n; i += chunkSize)
    {
        int end = (i + chunkSize < n) ? (i + chunkSize) : n;
        selectionSort(arr, i, end);
    }

    printf("After Selection Sort on Each Chunk:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    // Step 2: Merge sorted chunks using merge procedure
    mergeChunks(arr, n, chunkSize);

    printf("Final Sorted Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
