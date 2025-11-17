#include <stdio.h>
#include <stdlib.h>

// Node structure for queue
struct Node
{
    int data;
    struct Node *next;
};

// Queue structure
struct Queue
{
    struct Node *front;
    struct Node *rear;
};

// Function to create an empty queue
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if queue is empty
int isEmpty(struct Queue *q)
{
    return q->front == NULL;
}

// Function to enqueue (add) an element
void enqueue(struct Queue *q, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to dequeue (remove) an element
int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue underflow!\n");
        exit(1);
    }

    struct Node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}

// Function to print queue elements
void printQueue(struct Queue *q)
{
    struct Node *temp = q->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to merge two sorted queues into one sorted queue
struct Queue *mergeQueues(struct Queue *q1, struct Queue *q2)
{
    struct Queue *merged = createQueue();

    while (!isEmpty(q1) && !isEmpty(q2))
    {
        if (q1->front->data <= q2->front->data)
            enqueue(merged, dequeue(q1));
        else
            enqueue(merged, dequeue(q2));
    }

    // Enqueue remaining elements
    while (!isEmpty(q1))
        enqueue(merged, dequeue(q1));

    while (!isEmpty(q2))
        enqueue(merged, dequeue(q2));

    return merged;
}

// Main function
int main()
{
    // Create two queues
    struct Queue *q1 = createQueue();
    struct Queue *q2 = createQueue();

    // Queue 1: sorted elements
    enqueue(q1, 1);
    enqueue(q1, 4);
    enqueue(q1, 7);
    enqueue(q1, 10);

    // Queue 2: sorted elements
    enqueue(q2, 2);
    enqueue(q2, 3);
    enqueue(q2, 6);
    enqueue(q2, 8);
    enqueue(q2, 9);

    printf("Queue 1: ");
    printQueue(q1);

    printf("Queue 2: ");
    printQueue(q2);

    struct Queue *merged = mergeQueues(q1, q2);

    printf("\nMerged Sorted Queue: ");
    printQueue(merged);

    return 0;
}
