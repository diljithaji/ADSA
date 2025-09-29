#include <stdio.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

int main() {
    int n, i;

    printf("Enter the number of students (n): ");
    scanf("%d", &n);

    struct Student students[n];

    // --- INPUT SECTION ---
    for (i = 0; i < n; i++) {
        printf("\n--- Entering details for Student %d ---\n", i + 1);
        printf("Name: ");
        scanf(" %s", students[i].name); 
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Marks (out of 100): ");
        scanf("%f", &students[i].marks);
    }

    // --- FIND HIGHEST MARKS ---
    int high= 0;
    
    for (i = 1; i < n; i++) {
        if (students[i].marks > students[high].marks) {
            high = i;
        }
    }

    // --- DISPLAY WINNER'S DETAILS ---
    printf("\nStudent with the highest marks is:\n");
    printf("Name: %s\n", students[high].name);
    printf("Roll Number: %d\n", students[high].rollNumber);
    printf("Marks: %.2f\n", students[high].marks);

    return 0;
}