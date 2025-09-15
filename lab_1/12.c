#include <stdio.h>
#include <math.h>

int main() {
    int n, i, p= 1;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n <= 1) {
        p=0;
    } 
    else {
        for (i = 2; i <= sqrt(n); ++i) {
            if (n % i == 0) {
                p=0;
                break;
            }
        }
    }

    if (p) {
        printf("%d is a prime", n);
    } else {
        printf("%d not a prime", n);
    }

    return 0;
}