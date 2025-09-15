#include <stdio.h>
#include <string.h>

int isPalindrome(int id) {
    char str[20];
    sprintf(str, "%d", id);
    
    int left = 0;
    int right = strlen(str) - 1;
    
    while (left < right) {
        if (str[left] != str[right]) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Is a palindrome
}

int main() {
    int id = 12321;
    
    if (isPalindrome(id)) {
        printf("%d is a palindrome ID.\n", id);
    } else {
        printf("%d is not a palindrome ID.\n", id);
    }
    
    return 0;
}