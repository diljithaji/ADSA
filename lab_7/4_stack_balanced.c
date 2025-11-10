#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

Node *top = NULL;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int isEmpty() {
    return top == NULL;
}

void push(char data) {
    Node *newNode = createNode(data);
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (isEmpty()) {
        return '\0';
    }
    Node *temp = top;
    char data = temp->data;
    top = top->next;
    free(temp);
    return data;
}

int isMatching(char char1, char char2) {
    if (char1 == '(' && char2 == ')')
        return 1;
    if (char1 == '{' && char2 == '}')
        return 1;
    if (char1 == '[' && char2 == ']')
        return 1;
    return 0;
}

int checkBalancedParentheses(char *exp) {
    int i;
    char popped_char;
    
    for (i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isEmpty()) {
                return 0;
            }
            popped_char = pop();
            if (!isMatching(popped_char, exp[i])) {
                return 0;
            }
        }
    }
    
    if (isEmpty())
        return 1;
    else
        return 0;
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
    char exp[100];
    
    printf("Enter an expression: ");
    fgets(exp, sizeof(exp), stdin);
    
    // Remove the newline character added by fgets
    exp[strcspn(exp, "\n")] = 0; 

    if (checkBalancedParentheses(exp)) {
        printf("The expression is BALANCED.\n");
    } else {
        printf("The expression is NOT BALANCED.\n");
    }
    
    freeStack();
    return 0;
}