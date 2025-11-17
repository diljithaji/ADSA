#include <stdio.h>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void partialSelectionSort(int arr[], int n, int k)
{
    int i, j, minIndex, temp;

    // Perform only first k iterations
    for (i = 0; i < k; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
        {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        printf("After iteration %d: ", i + 1);
        printArray(arr, n);
    }
}

int main()
{
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter value of k (number of smallest elements to sort): ");
    scanf("%d", &k);

    if (k > n || k <= 0)
    {
        printf("Invalid value of k!\n");
        return 0;
    }

    printf("\nPartial selection sort progress:\n");
    partialSelectionSort(arr, n, k);

    printf("\nArray after partial sorting: ");
    printArray(arr, n);

    return 0;
}
