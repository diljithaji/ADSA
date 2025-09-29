#include <stdio.h>

// 1. Define the Inner Structure (Date)
struct Date {
    int day;
    int month;
    int year;
};

// 2. Define the Outer Structure (Student)
struct Student {
    int rollNumber;
    char name[50];
    // Nested structure declaration
    struct Date dob; // 'dob' is a variable of type struct Date
};

int main() {
    int n, i;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Declare array of outer structs
    struct Student students[n];

    // --- Input Details ---
    for (i = 0; i < n; i++) {
        printf("\n--- Enter details for Student %d ---\n", i + 1);
        printf("Name: ");
        scanf(" %s", students[i].name);
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        
        // Accessing nested members for DOB input
        printf("Date of Birth (dd mm yyyy): ");
        scanf("%d %d %d", 
              &students[i].dob.day, 
              &students[i].dob.month, 
              &students[i].dob.year);
    }

    // --- Display Details ---
    printf("\n\n--- Student Records ---\n");
    for (i = 0; i < n; i++) {
        printf("\nStudent %d (Roll: %d)\n", i + 1, students[i].rollNumber);
        printf("Name: %s\n", students[i].name);
        // Displaying nested members
        printf("D.O.B.: %d/%d/%d\n", 
               students[i].dob.day, 
               students[i].dob.month, 
               students[i].dob.year);
    }

    return 0;
}