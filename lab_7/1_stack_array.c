#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;

int isFull() {
    return top == MAX_SIZE - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int data) {
    if (isFull()) {
        printf("\nERROR: Stack Overflow! Cannot push %d.\n", data);
        return;
    }
    top++;
    stack[top] = data;
    printf("Pushed %d onto the stack.\n", data);
}

int pop() {
    if (isEmpty()) {
        printf("\nERROR: Stack Underflow! Cannot pop from an empty stack.\n");
        return INT_MIN;
    }
    int data = stack[top];
    top--;
    return data;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty (no elements to display).\n");
        return;
    }
    printf("\nStack elements (Top to Bottom):\n");
    for (int i = top; i >= 0; i--) {
        printf("| %d |\n", stack[i]);
    }
    printf("-------\n");
}

int main() {
    display(); 

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    
    display();
    
    push(60);

    int popped_val;
    popped_val = pop();
    if (popped_val != INT_MIN) {
        printf("\nPopped element: %d\n", popped_val);
    }
    
    popped_val = pop();
    if (popped_val != INT_MIN) {
        printf("Popped element: %d\n", popped_val);
    }
    
    display();

    pop(); pop(); pop();
    
    popped_val = pop();
    
    display();

    return 0;
}