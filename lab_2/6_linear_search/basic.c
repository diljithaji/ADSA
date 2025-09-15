#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Return the index if the key is found
        }
    }
    return -1; // Return -1 if the key is not found
}

int main() {
    int customerIDs[] = {1234, 5678, 9101, 1213, 1415};
    int n = sizeof(customerIDs) / sizeof(customerIDs[0]);
    int key = 9101;
    int result = linearSearch(customerIDs, n, key);

    if (result != -1) {
        printf("Customer ID %d found at index %d.\n", key, result);
    } else {
        printf("Customer ID %d not found.\n", key);
    }

    return 0;
}