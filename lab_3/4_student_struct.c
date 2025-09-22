#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int roll;
    float mark;
};

int main() {
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].roll);
        printf("Marks: ");
        scanf("%f", &students[i].mark);
    }

    // Find the student with the highest marks
    float max=students[0].mark;
    int high_index= 0;

    for (i = 1; i < n; i++) {
        if (students[i].mark > max) {
            max=students[i].mark;
            high_index = i;
        }
    }

    // Display the details of the student with the highest marks
    printf("\n\nDetails of the student with the highest marks:\n");
    printf("Name: %s\n", students[high_index].name);
    printf("Roll Number: %d\n", students[high_index].roll);
    printf("Marks: %.2f\n", students[high_index].mark);

    return 0;
}