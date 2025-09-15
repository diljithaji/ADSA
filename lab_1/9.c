#include <stdio.h>

int main() {
    int n, og_num,rev=0,rem;

    printf("Enter an integer: ");
    scanf("%d", &n);

    og_num = n;
    while (n != 0) {
        rem= n % 10;
        rev=rev*10+rem;
        n /= 10;
    }

    if (og_num == rev) {
        printf("%d Is palindrome.\n", og_num);
    } else {
        printf("%d Not a palindrome.\n", og_num);
    }
    return 0;
}