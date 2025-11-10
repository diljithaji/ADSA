#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

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
    return front == NULL;
}

void enqueue(int data) {
    Node *newNode = createNode(data);
    
    if (rear == NULL) {
        front = newNode;
        rear = newNode;
        printf("Enqueued %d.\n", data);
        return;
    }
    
    rear->next = newNode;
    rear = newNode;
    printf("Enqueued %d.\n", data);
}

int dequeue() {
    if (isEmpty()) {
        printf("\nERROR: Queue Underflow! Cannot dequeue from an empty queue.\n");
        return -1;
    }
    
    Node *temp = front;
    int data = temp->data;
    
    front = front->next;
    
    if (front == NULL) {
        rear = NULL;
    }
    
    free(temp);
    return data;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    
    Node *current = front;
    printf("\nQueue elements (Front to Rear):\n");
    while (current != NULL) {
        printf("| %d ", current->data);
        current = current->next;
    }
    printf("|\n");
}

void freeQueue() {
    Node *temp;
    while(front != NULL) {
        temp = front;
        front = front->next;
        free(temp);
    }
}

int main() {
    display(); 

    printf("--- Enqueue Operations ---\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();
    
    printf("\n--- Dequeue Operations ---\n");
    int dequeued_val;
    
    dequeued_val = dequeue();
    if (dequeued_val != -1) {
        printf("Dequeued element: %d\n", dequeued_val);
    }
    
    enqueue(40);

    display();

    dequeued_val = dequeue();
    if (dequeued_val != -1) {
        printf("Dequeued element: %d\n", dequeued_val);
    }
    
    dequeued_val = dequeue();
    if (dequeued_val != -1) {
        printf("Dequeued element: %d\n", dequeued_val);
    }

    dequeued_val = dequeue();
    if (dequeued_val != -1) {
        printf("Dequeued element: %d\n", dequeued_val);
    }
    
    dequeued_val = dequeue(); 
    
    freeQueue();
    return 0;
}