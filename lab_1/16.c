#include <stdio.h>

long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int number;
    long long result;

    printf("Enter a number: ");
    scanf("%d", &number);
    if (number < 0) {
        printf("Error");
    } else {
        result = factorial(number);
        printf("Factorial of %d is %lld\n", number, result);
    }

    return 0;
}