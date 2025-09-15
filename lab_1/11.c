#include <stdio.h>

int main() {
    int n, sum = 0, remainder;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 0) {
        n = -n;
    }

    while (n != 0) {
        remainder = n % 10;
        sum += remainder;
        n/=10;
    }

    printf("sum: %d\n", sum);

    return 0;
}