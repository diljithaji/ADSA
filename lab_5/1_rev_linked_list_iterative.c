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

struct Node* rev(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next_node = NULL;

    while (current != NULL) {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    return prev; 
}

struct Node* create(int n) {
    if (n <= 0) {
        return NULL;
    }

    struct Node *head = NULL;
    struct Node *tail = NULL;

    for (int i = 0; i < n; i++) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));


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


int main() {
    int n;

    printf("Enter the number of elements for the list: ");
    scanf("%d", &n);

    struct Node *head = create(n);

    if (head != NULL) {
        printf("\nOriginal List: ");
        printList(head); 

        head = rev(head);
        
        printf("Reversed List: ");
        printList(head); 

        while(head != NULL) {
            struct Node *temp = head;
            head = head->next;
            free(temp);
        }
    } else {
        printf("List is empty or creation failed.\n");
    }

    return 0;
}