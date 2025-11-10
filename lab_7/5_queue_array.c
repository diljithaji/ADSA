#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return rear == MAX_SIZE - 1;
}

int isEmpty() {
    return front == -1;
}

void enqueue(int data) {
    if (isFull()) {
        printf("\nERROR: Queue Overflow! Cannot enqueue %d.\n", data);
        return;
    }
    
    if (isEmpty()) {
        front = 0;
    }
    
    rear++;
    queue[rear] = data;
    printf("Enqueued %d.\n", data);
}

int dequeue() {
    if (isEmpty()) {
        printf("\nERROR: Queue Underflow! Cannot dequeue from an empty queue.\n");
        return INT_MIN;
    }
    
    int data = queue[front];
    
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    
    return data;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("\nQueue elements (Front to Rear):\n");
    for (int i = front; i <= rear; i++) {
        printf("| %d ", queue[i]);
    }
    printf("|\n");
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
    if (dequeued_val != INT_MIN) {
        printf("Dequeued element: %d\n", dequeued_val);
    }
    
    enqueue(40);
    enqueue(50);
    enqueue(60);

    display();

    dequeued_val = dequeue();
    if (dequeued_val != INT_MIN) {
        printf("Dequeued element: %d\n", dequeued_val);
    }
    
    display();

    return 0;
}