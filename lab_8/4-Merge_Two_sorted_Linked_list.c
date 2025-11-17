#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node *sortedMerge(struct Node *head1, struct Node *head2)
{
    // base cases
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    // recursive merging based on smaller value
    if (head1->data <= head2->data)
    {
        head1->next = sortedMerge(head1->next, head2);
        return head1;
    }
    else
    {
        head2->next = sortedMerge(head1, head2->next);
        return head2;
    }
}

struct Node *mergeSortedLists(struct Node *list1, struct Node *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct Node *head = NULL; // Head of merged list
    struct Node *tail = NULL; // Last node of merged list

    // Initialize head
    if (list1->data <= list2->data)
    {
        head = tail = list1;
        list1 = list1->next;
    }
    else
    {
        head = tail = list2;
        list2 = list2->next;
    }

    // Traverse both lists
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Attach the remaining part (if any)
    if (list1 != NULL)
        tail->next = list1;
    else
        tail->next = list2;

    return head;
}

int main()
{
    // Create first sorted list: 1 -> 3 -> 5 -> 7
    struct Node *head1 = createNode(1);
    head1->next = createNode(3);
    head1->next->next = createNode(5);
    head1->next->next->next = createNode(7);

    // Create second sorted list: 2 -> 4 -> 6 -> 8
    struct Node *head2 = createNode(2);
    head2->next = createNode(4);
    head2->next->next = createNode(6);
    head2->next->next->next = createNode(8);

    // struct Node *res = mergeSortedLists(head1, head2);
    struct Node *res = sortedMerge(head1, head2);

    printf("\nMerged Sorted List: ");
    printList(res);

    return 0;
}
