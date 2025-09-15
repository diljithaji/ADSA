#include <stdio.h>

int main() {
    int n, i,t1 = 0, t2 = 1,nxt = t1 + t2;

    printf("Enter the number: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Error");
        return 1;
    }

    printf("Series: ");

    if (n >= 1) {
        printf("%d", t1);
    }
    if (n >= 2) {
        printf(", %d", t2);
    }


    for (i = 3; i <= n; ++i) {
        printf(", %d", nxt);
        t1 = t2;
        t2 = nxt;
        nxt = t1 + t2;
    }

    return 0;
}