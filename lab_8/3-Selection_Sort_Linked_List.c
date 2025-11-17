// C program to sort a linked list
// using selection sort
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *selectionSort(struct Node *head)
{
    for (struct Node *start = head; start != NULL; start = start->next)
    {
        struct Node *min_node = start;

        for (struct Node *curr = start->next; curr != NULL; curr = curr->next)
        {
            if (curr->data < min_node->data)
            {
                min_node = curr;
            }
        }
        if (min_node != start)
        {
            int node = start->data;
            start->data = min_node->data;
            min_node->data = node;
        }
    }
    return head;
}

void printList(struct Node *node)
{
    struct Node *curr = node;
    while (curr != NULL)
    {
        printf(" %d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

struct Node *createNode(int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

int main()
{
    struct Node *head = createNode(5);
    head->next = createNode(3);
    head->next->next = createNode(4);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(2);

    head = selectionSort(head);

    printList(head);

    return 0;
}