#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} NODE;

NODE *createNode(int num)
{
    NODE *newNode = malloc(sizeof(*newNode));
    if (newNode == NULL)
    {
        perror("Memory allocation failed");
        exit(1);
    }
    newNode->data = num;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

NODE *insertAtHead(NODE *head, int num)
{
    NODE *newNode = createNode(num);
    if (head == NULL)
        return newNode;

    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

NODE *insertAtEnd(NODE *head, int num)
{
    NODE *newNode = createNode(num);
    if (head == NULL)
        return newNode;

    NODE *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

NODE *deleteNode(NODE *head, int key)
{
    if (head == NULL)
        return NULL;

    NODE *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Value %d not found in list.\n", key);
        return head;
    }

    if (temp->prev == NULL)
    {
        // Deleting head
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        // Middle or last node
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);

    return head;
}

// Display the list from head to tail
void display(NODE *head)
{
    NODE *temp = head;
    printf("List (forward): ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

NODE *insertAtPosition(NODE *head, int num, int pos)
{
    if (pos < 1)
    {
        printf("Invalid position!\n");
        return head;
    }

    NODE *newNode = createNode(num);

    // Case 1: insert at the beginning
    if (pos == 1)
    {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        return newNode;
    }

    NODE *temp = head;
    int i;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    // If position is out of bounds
    if (temp == NULL)
    {
        printf("Position out of range!\n");
        free(newNode);
        return head;
    }

    // Check for both at the end and position
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) // position
        temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}

NODE *deleteValue(NODE *head, int value)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    NODE *temp = head;

    // Find the first node with the given value
    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Value %d not found in list.\n", value);
        return head;
    }

    if (temp->prev == NULL)
    {
        // Deleting head
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
    }
    else
    {
        // Middle or last node
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
    }

    free(temp);

    printf("Deleted first occurrence of %d\n", value);
    return head;
}

NODE *reverseList(NODE *head)
{
    NODE *current = head;
    NODE *temp = NULL;

    // Empty or single-node list
    if (head == NULL || head->next == NULL)
        return head;

    // Traverse the list and swap next and prev for each node
    while (current != NULL)
    {
        // Swap next and prev
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node (which is current->prev now)
        current = current->prev;
    }

    // After the loop, temp points to the previous node of NULL — i.e., new head
    if (temp != NULL)
        head = temp->prev;

    return head;
}

// Main function to demonstrate usage
int main()
{
    NODE *head = NULL;

    // Insert nodes
    head = insertAtHead(head, 10);
    head = insertAtHead(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);

    // Display list
    display(head);

    // Delete a node
    head = deleteNode(head, 20);

    return 0;
}