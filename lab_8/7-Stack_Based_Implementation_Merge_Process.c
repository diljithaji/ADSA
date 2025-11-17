#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent a stack frame (a subarray range)
struct Frame
{
    int left, right, mid;
    int stage; // 0 = split, 1 = merge
};

// Manual stack
struct Frame stack[MAX];
int top = -1;

// Push frame onto stack
void push(int left, int right, int mid, int stage)
{
    top++;
    stack[top].left = left;
    stack[top].right = right;
    stack[top].mid = mid;
    stack[top].stage = stage;
}

// Pop frame from stack
struct Frame pop()
{
    return stack[top--];
}

// Merge function (same as merge sort)
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Iterative merge sort using explicit stack
void mergeSortIterative(int arr[], int n)
{
    // Initial frame: whole array
    push(0, n - 1, 0, 0);

    while (top != -1)
    {
        struct Frame frame = pop();
        int left = frame.left, right = frame.right;
        int mid = (left + right) / 2;

        if (frame.stage == 1)
        {
            merge(arr, left, mid, right);
        }
        else if (left < right)
        {
            // Push merge step (stage 1)
            push(left, right, mid, 1);
            // Push right half to sort first
            push(mid + 1, right, 0, 0);
            // Push left half
            push(left, mid, 0, 0);
        }
    }
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11, 90, 45, 72};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");

    mergeSortIterative(arr, n);

    printf("Sorted Array (using stack-based merge simulation):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
