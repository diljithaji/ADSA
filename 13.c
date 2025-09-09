#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the num: ");
    scanf("%d", &n);

    float arr[n];

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; ++i) {
        printf("Element %d: ", i + 1);
        scanf("%f", &arr[i]);
    }

    float max = arr[0];

    for (i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("The max: %.2f\n", max);

    return 0;
}