#include <stdio.h>

// Define the Date structure
struct Date {
    int day;
    int month;
    int year;
};

void dates(struct Date d1, struct Date d2) {
    if (d1.year < d2.year) {
        printf("Date 1 is earlier.\n");
    } else if (d1.year > d2.year) {
        printf("Date 2 is earlier.\n");
    } else {
        if (d1.month < d2.month) {
            printf("Date 1 is earlier.\n");
        } else if (d1.month > d2.month) {
            printf("Date 2 is earlier.\n");
        } else {
            if (d1.day < d2.day) {
                printf("Date 1 is earlier.\n");
            } else if (d1.day > d2.day) {
                printf("Date 2 is earlier.\n");
            } else {
                printf("Both dates are the same.\n");
            }
        }
    }
}

int main() {
    struct Date date1, date2;

    printf("Enter Date 1 (dd mm yyyy): ");
    scanf("%d %d %d", &date1.day, &date1.month, &date1.year);

    printf("Enter Date 2 (dd mm yyyy): ");
    scanf("%d %d %d", &date2.day, &date2.month, &date2.year);

    dates(date1, date2);

    return 0;
}