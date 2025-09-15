#include <stdio.h>

int main() {
    int n, i;
    unsigned long long factorial = 1;

    printf("Enter a number: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Error");
    } 
    else if (n == 0) {
        printf("Factorial= 1\n");
    } 
    else {
        for (i = 1; i <= n; ++i) {
            factorial *= i;
        }
        printf("Factorial of %d = %llu\n", n, factorial);
    }

    return 0;
}