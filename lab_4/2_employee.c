#include <stdio.h>

// Define the Employee structure
struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n, i;

    // Get the number of employees
    printf("Enter the number of employees (n): ");
    scanf("%d", &n);

    // Declare a variable-length array (VLA) of Employee structs
    struct Employee employees[n];

    // --- INPUT SECTION ---
    for (i = 0; i < n; i++) {
        printf("\nEntering details for Employee %d:\n", i + 1);
        printf("Employee ID: ");
        scanf("%d", &employees[i].id); 
        
        printf("Name: ");
        scanf(" %s", employees[i].name); 
        
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    // --- DISPLAY SECTION ---
    printf("\n--- Employee Records ---\n");
    
    for (i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("ID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Salary: %.2f\n", employees[i].salary);
    }

    return 0;
}