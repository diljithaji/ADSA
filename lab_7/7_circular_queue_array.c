#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return (rear + 1) % MAX_SIZE == front;
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
    
    rear = (rear + 1) % MAX_SIZE;
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
        front = (front + 1) % MAX_SIZE;
    }
    
    return data;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    
    printf("\nQueue elements (Front to Rear):\n");
    int i = front;
    do {
        printf("| %d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    
    printf("|\n");
}

int main() {
    printf("--- Initial Operations ---\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    printf("\n--- Dequeue and Wrap-Around Insertion ---\n");
    dequeue();
    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    enqueue(60);
    
    display();

    printf("\n--- Test Overflow ---\n");
    enqueue(70);

    printf("\n--- Final Dequeue and Underflow ---\n");
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    display();

    dequeue();
    
    dequeue();

    return 0;
}