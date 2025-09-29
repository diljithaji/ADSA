#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

char *longestCommonPrefix(char strs[][MAX_LEN], int n)
{
    static char prefix[MAX_LEN]; // static so we can return it
    strcpy(prefix, strs[0]);     // assume first string is prefix

    for (int i = 1; i < n; i++)
    {
        int j = 0;
        while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j])
        {
            j++;
        }
        prefix[j] = '\0'; // cut prefix at mismatch
        if (prefix[0] == '\0')
        {
            return ""; // no common prefix
        }
    }
    return prefix;
}

int main()
{
    char strs[3][MAX_LEN] = {"flower", "flow", "flight"};
    int n = 3;

    char *prefix = longestCommonPrefix(strs, n);
    if (strlen(prefix) > 0)
        printf("Longest Common Prefix: %s\n", prefix);
    else
        printf("No common prefix\n");

    return 0;
}
