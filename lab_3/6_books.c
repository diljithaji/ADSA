#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[50];
    float price;
};

int main() {
    int n, i;
    float searchPrice;

    printf("Enter the number of books: ");
    scanf("%d", &n);

    struct Book books[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter details for Book %d:\n", i + 1);
        printf("Title: ");
        scanf(" %99[^\n]", books[i].title);
        printf("Author: ");
        scanf(" %49[^\n]", books[i].author);
        printf("Price: ");
        scanf("%f", &books[i].price);
    }

    printf("\nEnter a price to search for: ");
    scanf("%f", &searchPrice);

    // Display books with a price above the given value
    printf("\nBooks with price more than %.2f\n", searchPrice);
    for (i = 0; i < n; i++) {
        if (books[i].price > searchPrice) {
            printf("\nTitle: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("Price: %.2f\n", books[i].price);
        }
    }

    return 0;
}