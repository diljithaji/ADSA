#include <stdio.h>

int main() {
    int n, i;

    printf("Enter the number of natural numbers to print: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("First %d natural numbers are:\n", n);
        for (i = 1; i <= n; i++) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}