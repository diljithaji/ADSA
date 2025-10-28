#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


struct Node* createDynamicList(int n) {
    if (n <= 0) return NULL;

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


void searchElement(struct Node *head, int target) {
    struct Node *current = head;
    int position = 1;
    while (current != NULL) {
        if (current->data == target) {
            printf("\nElement %d found at position %d.\n", target, position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("\nElement %d was not found in the list.\n", target);
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
    int n, target;

    printf("Enter the number of elements for the list: ");
    scanf("%d", &n);

    struct Node *head = createDynamicList(n);

    if (head != NULL) {
        printf("\nEnter the element to search for: ");
        scanf("%d", &target);

        searchElement(head, target);

        freeList(head);
    } else {
        printf("List creation failed or list is empty.\n");
    }

    return 0;
}