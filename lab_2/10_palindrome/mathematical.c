#include <stdio.h>

int main() {
    int id = 12321;
    int original_id = id;
    int reversed_id = 0;
    int remainder;

    while (id > 0) {
        remainder = id % 10;
        reversed_id = reversed_id * 10 + remainder;
        id /= 10;
    }

    if (original_id == reversed_id) {
        printf("%d is a palindrome ID.\n", original_id);
    } else {
        printf("%d is not a palindrome ID.\n", original_id);
    }
    
    return 0;
}