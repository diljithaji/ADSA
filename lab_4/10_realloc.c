#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int id;
    char name[50];
    float marks;
};

int main()
{
    int n, i, extra;

    printf("Enter initial number of students: ");
    scanf("%d", &n);

    struct Student *s = (struct Student *)malloc(n * sizeof(struct Student));

    if (s == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &s[i].id);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    printf("\nHow many more students do you want to add? ");
    scanf("%d", &extra);

    // Reallocate memory for (n + extra) students
    s = (struct Student *)realloc(s, (n + extra) * sizeof(struct Student));

    if (s == NULL)
    {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    // Input details for new students
    for (i = n; i < n + extra; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &s[i].id);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }

    printf("\n--- Student Information ---\n");
    for (i = 0; i < n + extra; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("ID: %d\n", s[i].id);
        printf("Name: %s\n", s[i].name);
        printf("Marks: %.2f\n", s[i].marks);
    }

    // Free memory
    free(s);

    return 0;
}
