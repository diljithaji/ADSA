#include <stdio.h>

void check_even_odd(int num) {
    if (num % 2 == 0) {
        printf("%d is Even.\n", num);
    } else {
        printf("%d is Odd.\n", num);
    }
}

int main() {
    int numbers[] = {4, 7, 10, 13, 16};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int i;

    for (i = 0; i < n; i++) {
        check_even_odd(numbers[i]);
    }

    return 0;
}