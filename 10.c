#include <stdio.h>

int main() {
    int n,c= 0;
    printf("Enter a num: ");
    scanf("%d", &n);
    if (n == 0) {
        printf("No of digits: 1\n");
        return 0;
    }
    if (n < 0) {
        n = -n;
    }
    while (n != 0) {
        n /= 10;
        ++c;
    }
    printf("digits: %d\n", c);

    return 0;
}
