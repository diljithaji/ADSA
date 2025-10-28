#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void printList(struct Node *head) {
    struct Node *current = head;
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

struct Node* createDynamicList(int n) {
    if (n <= 0) {
        return NULL;
    }

    struct Node *head = NULL;
    struct Node *tail = NULL;

    for (int i = 0; i < n; i++) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        /*
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
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


struct Node* reverseRecursive(struct Node *head) {
    if (head == NULL || head->next == NULL) {
        return head; 
    }
    struct Node *new_head = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}


int main() {
    int n;

    printf("Enter the number of elements for the list: ");
    scanf("%d", &n);
    struct Node *head = createDynamicList(n);

    if (head != NULL) {
        printf("\nOriginal List: ");
        printList(head); 

        head = reverseRecursive(head);
        
        printf("Reversed List: ");
        printList(head); 

        freeList(head);
    } else {
        printf("List is empty or creation failed.\n");
    }

    return 0;
}