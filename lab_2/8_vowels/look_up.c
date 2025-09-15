#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int count = 0;
    int i;

    // Create a lookup table for vowels. ASCII has 256 characters.
    int vowel_lookup[256] = {0};
    vowel_lookup['a'] = 1;
    vowel_lookup['e'] = 1;
    vowel_lookup['i'] = 1;
    vowel_lookup['o'] = 1;
    vowel_lookup['u'] = 1;
    vowel_lookup['A'] = 1;
    vowel_lookup['E'] = 1;
    vowel_lookup['I'] = 1;
    vowel_lookup['O'] = 1;
    vowel_lookup['U'] = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; ++i) {
        if (vowel_lookup[str[i]] == 1) {
            count++;
        }
    }
    printf("Number of vowels: %d\n", count);
    
    return 0;
}