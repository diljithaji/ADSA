#include <stdio.h>
int sumOfArray(int arr[], int n) {
    if (n <= 0) {
        return 0;
    }
    else {
        return arr[n - 1] + sumOfArray(arr, n - 1);
    }
}

int main() {
    int n, i;

    printf("Enter the number of sales: ");
    scanf("%d", &n);

    int sales[n];

    printf("Enter %d sales figures:\n", n);
    for (i = 0; i < n; i++) {
        printf("Sale %d: ", i + 1);
        scanf("%d", &sales[i]);
    }

    int sum = sumOfArray(sales, n);

    printf("The sum of all sales is: %d\n", sum);

    return 0;
}