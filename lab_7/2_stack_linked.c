#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Global stack pointer
Node *top = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty() {
    return top == NULL;
}

void push(int data) {
    Node *newNode = createNode(data);
    
    // New node becomes the new top, pointing to the old top
    newNode->next = top;
    top = newNode;
    printf("Pushed %d onto the stack.\n", data);
}

int pop() {
    if (isEmpty()) {
        printf("\nERROR: Stack Underflow! Cannot pop from an empty stack.\n");
        return -1;
    }
    
    Node *temp = top;
    int data = temp->data;
    
    // Move top to the next node
    top = top->next;
    
    free(temp);
    return data;
}

int peek() {
    if (isEmpty()) {
        printf("\nERROR: Stack is empty. Cannot peek.\n");
        return -1;
    }
    return top->data;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    
    Node *current = top;
    printf("\nStack elements (Top to Bottom):\n");
    while (current != NULL) {
        printf("| %d |\n", current->data);
        current = current->next;
    }
    printf("-------\n");
}

void freeStack() {
    Node *temp;
    while(top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

int main() {
    display(); 

    push(10);
    push(20);
    push(30);

    display();
    
    printf("\nPeeked element: %d\n", peek()); 

    int popped_val;
    popped_val = pop();
    if (popped_val != -1) {
        printf("Popped element: %d\n", popped_val);
    }
    
    popped_val = pop();
    if (popped_val != -1) {
        printf("Popped element: %d\n", popped_val);
    }
    
    display();
    
    popped_val = pop();
    if (popped_val != -1) {
        printf("Popped element: %d\n", popped_val);
    }
    
    popped_val = pop(); 
    
    freeStack();
    return 0;
}