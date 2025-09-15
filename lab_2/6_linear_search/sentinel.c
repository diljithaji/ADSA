#include <stdio.h>

int linearSearchSentinel(int arr[], int n, int key) {
    int last_element = arr[n - 1]; 
    arr[n - 1] = key; // Place the key at the end (sentinel)
    int i = 0;

    //checks for the key
    while (arr[i] != key) {
        i++;
    }
    // Restore the last element
    arr[n - 1] = last_element;

    // Check if the key was found at the original location
    if (i < n - 1 || last_element == key) {
        return i;
    } else {
        return -1;
    }
}

int main() {
    int customerIDs[] = {1234, 5678, 9101, 1213, 1415};
    int n = sizeof(customerIDs) / sizeof(customerIDs[0]);
    int key = 1415; // A key at the last position to test the sentinel logic
    int result = linearSearchSentinel(customerIDs, n, key);

    if (result != -1) {
        printf("Customer ID %d found at index %d.\n", key, result);
    } else {
        printf("Customer ID %d not found.\n", key);
    }

    return 0;
}