#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

int compareStudents(struct Student s1, struct Student s2) {
    if (s1.rollNumber != s2.rollNumber) {
        return 0;
    }
    if (s1.marks != s2.marks) {
        return 0;
    }
    if (strcmp(s1.name, s2.name) != 0) {
        return 0;
    }
    return 1;
}

int main() {

    struct Student student1 = {"Alice", 101, 85.5};
    struct Student student2 = {"Alice", 101, 85.5};
    
    struct Student student3 = {"Bob", 102, 90.0};
    
    if (compareStudents(student1, student2)) {
        printf("student1 and student2 are identical.\n");
    } else {
        printf("student1 and student2 are not identical.\n");
    }
    
    if (compareStudents(student1, student3)) {
        printf("student1 and student3 are identical.\n");
    } else {
        printf("student1 and student3 are not identical.\n");
    }
    
    return 0;
}