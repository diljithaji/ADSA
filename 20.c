#include <stdio.h>

int bi_ser(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;
    if (arr[mid] == key) {
        return mid;
    }
    else if (arr[mid] > key) {
        return bi_ser(arr, low, mid - 1, key);
    }
    else {
        return bi_ser(arr, mid + 1, high, key);
    }
}

int main() {
    int bookIDs[] = {101, 205, 308, 412, 534, 615, 789};
    int n = sizeof(bookIDs)/sizeof(bookIDs[0]);
    int key, result;

    printf("Book_id available:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", bookIDs[i]);
    }
    printf("\n\nEnter a Book_id: ");
    scanf("%d", &key);

    result=bi_ser(bookIDs, 0, n - 1, key);

    if (result != -1) {
        printf("%d found at index %d.\n", key, result);
    } else {
        printf("%d not found in the list.\n", key);
    }

    return 0;
}