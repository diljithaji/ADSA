#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 5

int deque[MAX_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    return (rear + 1) % MAX_SIZE == front;
}

int isEmpty() {
    return front == -1;
}

void insertFront(int data) {
    if (isFull()) {
        printf("\nERROR: Deque Overflow! Cannot insert %d at front.\n", data);
        return;
    }

    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = MAX_SIZE - 1;
    } else {
        front--;
    }

    deque[front] = data;
    printf("Inserted %d at front.\n", data);
}

void insertRear(int data) {
    if (isFull()) {
        printf("\nERROR: Deque Overflow! Cannot insert %d at rear.\n", data);
        return;
    }

    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX_SIZE;
    }

    deque[rear] = data;
    printf("Inserted %d at rear.\n", data);
}

int deleteFront() {
    if (isEmpty()) {
        printf("\nERROR: Deque Underflow! Cannot delete from front.\n");
        return INT_MIN;
    }

    int data = deque[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }

    return data;
}

int deleteRear() {
    if (isEmpty()) {
        printf("\nERROR: Deque Underflow! Cannot delete from rear.\n");
        return INT_MIN;
    }

    int data = deque[rear];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = MAX_SIZE - 1;
    } else {
        rear--;
    }

    return data;
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }

    printf("\nDeque elements (Front to Rear):\n");
    int i = front;
    do {
        printf("| %d ", deque[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (rear + 1) % MAX_SIZE);
    
    printf("|\n");
}

int main() {
    int val;

    printf("--- Initial Operations ---\n");
    insertFront(10);
    insertRear(20);
    insertFront(5);
    display();

    printf("\n--- Deletion and Re-insertion ---\n");
    val = deleteRear();
    if (val != INT_MIN) printf("Deleted from rear: %d\n", val);

    insertRear(30);
    insertFront(1);
    display();

    printf("\n--- Test Wrap-around and Overflow ---\n");
    deleteFront();
    deleteFront();
    deleteFront();
    display();

    insertFront(40);
    insertFront(50);
    insertFront(60);
    
    display();
    
    return 0;
}