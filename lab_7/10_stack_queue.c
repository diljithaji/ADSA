#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *next;
} Node;

Node *stackTop = NULL;
Node *queueFront = NULL;
Node *queueRear = NULL;

void push(char data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) exit(1);
    
    newNode->data = data;
    newNode->next = stackTop;
    stackTop = newNode;
}

char pop() {
    if (stackTop == NULL) return '\0';
    
    Node *temp = stackTop;
    char data = temp->data;
    stackTop = temp->next;
    free(temp);
    return data;
}

void enqueue(char data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) exit(1);
    
    newNode->data = data;
    newNode->next = NULL;
    
    if (queueRear == NULL) {
        queueFront = newNode;
        queueRear = newNode;
        return;
    }
    
    queueRear->next = newNode;
    queueRear = newNode;
}

char dequeue() {
    if (queueFront == NULL) return '\0';
    
    Node *temp = queueFront;
    char data = temp->data;
    
    queueFront = queueFront->next;
    
    if (queueFront == NULL) {
        queueRear = NULL;
    }
    
    free(temp);
    return data;
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

int isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int isPalindrome(char *str) {
    int len = strlen(str);
    int i;
    
    for (i = 0; i < len; i++) {
        if (isAlpha(str[i])) {
            char processed_char = toLower(str[i]);
            push(processed_char);
            enqueue(processed_char);
        }
    }
    
    char charStack, charQueue;
    
    while (stackTop != NULL) {
        charStack = pop();
        charQueue = dequeue();
        
        if (charStack != charQueue) {
            return 0;
        }
    }
    
    return 1;
}

void freeAll() {
    Node *temp;
    while(stackTop != NULL) {
        temp = stackTop;
        stackTop = stackTop->next;
        free(temp);
    }
    while(queueFront != NULL) {
        temp = queueFront;
        queueFront = queueFront->next;
        free(temp);
    }
}

int main() {
    char str[100];
    
    printf("Enter a string to check (e.g., Madam): ");
    fgets(str, sizeof(str), stdin);
    
    str[strcspn(str, "\n")] = 0;

    if (isPalindrome(str)) {
        printf("'%s' is a PALINDROME.\n", str);
    } else {
        printf("'%s' is NOT a palindrome.\n", str);
    }
    
    freeAll();

    return 0;
}