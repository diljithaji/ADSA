#include <stdio.h>
#include <string.h>

void reverse_new_array(char *original, char *reversed) {
    int len = strlen(original);
    int i, j;

    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        reversed[j] = original[i];
    }
    reversed[len] = '\0';
}

int main() {
    char username[] = "john.doe";
    int len = strlen(username);
    char reversed_username[len + 1];
    printf("Original username: %s\n", username);
    reverse_new_array(username, reversed_username);
    printf("Reversed username: %s\n", reversed_username);
    return 0;
}