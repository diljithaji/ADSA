#include <stdio.h>

int gcd(int a, int b) {

    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int main() {
    int num1, num2, result;

    printf("Enter two num: ");
    scanf("%d %d", &num1, &num2);
    if (num1 < 0) {
        num1 = -num1;
    }
    if (num2 < 0) {
        num2 = -num2;
    }

    result = gcd(num1, num2);
    
    printf("GCD: %d\n",result);

    return 0;
}