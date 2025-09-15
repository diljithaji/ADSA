#include <stdio.h>

int main() {
    int n, i;
    int sum = 0;

    printf("Enter the number of sales: ");
    scanf("%d", &n);

    int sales[n];

    printf("Enter %d sales figures:\n", n);
    for (i = 0; i < n; i++) {
        printf("Sale %d: ", i + 1);
        scanf("%d", &sales[i]);
    }

    for (i = 0; i < n; i++) {
        sum += sales[i];
    }

    printf("The sum of all sales is: %d\n", sum);

    return 0;
}