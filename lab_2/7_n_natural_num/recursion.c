#include <stdio.h>

void printNaturalNumbers(int n){
    if (n < 1) {
        return;
    }
    // Recursive Step:Call the function for n-1
    printNaturalNumbers(n - 1);

    printf("%d ", n);
}

int main() {
    int n;

    printf("Enter the number: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Please enter a positive integer.\n");
    } else {
        printf("First %d natural numbers are:\n", n);
        printNaturalNumbers(n);
        printf("\n");
    }
    
    return 0;
}