#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char data) {
    if (top == MAX_SIZE - 1) {
        return; 
    }
    top++;
    stack[top] = data;
}

char pop() {
    if (top == -1) {
        return '\0'; 
    }
    char data = stack[top];
    top--;
    return data;
}

void reverseString(char *str) {
    int len = strlen(str);
    int i;
    
    for (i = 0; i < len; i++) {
        push(str[i]);
    }
    
    for (i = 0; i < len; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX_SIZE];
    
    printf("Enter a string to reverse: ");
    scanf("%s", str);
    
    printf("Original String: %s\n", str);
    
    reverseString(str);
    
    printf("Reversed String: %s\n", str);
    
    return 0;
}