#include <stdio.h>
#include <string.h>

void reverse_in_place(char *str) {
    int left = 0;
    int right = strlen(str) - 1;
    char temp;

    while (left < right) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }
}

int main() {
    char username[] = "john.doe";
    printf("Original username: %s\n", username);
    reverse_in_place(username);
    printf("Reversed username: %s\n", username);
    return 0;
}