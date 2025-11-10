#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 5

struct Item {
    int data;
    int priority;
};

struct Item pq[MAX_SIZE];
int rear = -1;

int isFull() {
    return rear == MAX_SIZE - 1;
}

int isEmpty() {
    return rear == -1;
}

void enqueue(int data, int priority) {
    if (isFull()) {
        printf("\nERROR: Queue Overflow! Cannot enqueue (%d, %d).\n", data, priority);
        return;
    }
    
    rear++;
    pq[rear].data = data;
    pq[rear].priority = priority;
    printf("Enqueued (%d, Priority: %d).\n", data, priority);
}

int dequeue() {
    if (isEmpty()) {
        printf("\nERROR: Queue Underflow! Cannot dequeue from an empty queue.\n");
        return INT_MIN;
    }
    
    int highest_priority = INT_MIN;
    int highest_priority_index = -1;
    
    for (int i = 0; i <= rear; i++) {
        if (pq[i].priority > highest_priority) {
            highest_priority = pq[i].priority;
            highest_priority_index = i;
        }
    }
    
    int data = pq[highest_priority_index].data;
    
    for (int i = highest_priority_index; i < rear; i++) {
        pq[i] = pq[i + 1];
    }
    
    rear--;
    return data;
}

void display() {
    if (isEmpty()) {
        printf("Priority Queue is empty.\n");
        return;
    }
    
    printf("\nPriority Queue elements (Front to Rear):\n");
    for (int i = 0; i <= rear; i++) {
        printf("| Data: %d, Priority: %d | ", pq[i].data, pq[i].priority);
    }
    printf("|\n");
}

int main() {
    printf("--- Enqueue Operations ---\n");
    enqueue(10, 2);
    enqueue(20, 5);
    enqueue(30, 1);
    enqueue(40, 4);
    enqueue(50, 3);
    
    display();

    printf("\n--- Dequeue Operations (Highest Priority First) ---\n");
    
    int dequeued_val;
    
    dequeued_val = dequeue();
    printf("Dequeued element (Highest Priority): %d\n", dequeued_val);
    display();

    dequeued_val = dequeue();
    printf("Dequeued element (Next Highest Priority): %d\n", dequeued_val);
    display();

    enqueue(60, 6);
    
    dequeued_val = dequeue();
    printf("Dequeued element (Highest Priority is 6): %d\n", dequeued_val);
    display();

    return 0;
}