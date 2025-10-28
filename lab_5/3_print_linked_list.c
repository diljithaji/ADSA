#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createDynamicList(int n) {
    if (n <= 0) {
        printf("Invalid list size.\n");
        return NULL;
    }

    struct Node *head = NULL;
    struct Node *tail = NULL;

    for (int i = 0; i < n; i++) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        /*
        if (newNode == NULL) {
            printf("Memory allocation failed! Stopping list creation.\n");
            break;
        }
        */

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode; 
        }
    }
    return head;
}

void displayList(struct Node *head) {
    struct Node *current = head;
    if (current == NULL) {
        printf("The list is empty.\n");
        return;
    }
    
    printf("\nList elements are: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(struct Node *head) {
    struct Node *temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;

    printf("Enter the number of nodes (n) for the linked list: ");
    scanf("%d", &n);

    struct Node *head = createDynamicList(n);

    displayList(head); 
    freeList(head);

    return 0;
}