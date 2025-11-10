#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} NODE;

NODE *createNode(int num) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    newNode->data = num;
    newNode->next = newNode;
    return newNode;
}

void displayList(NODE *tail) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }

    NODE *head = tail->next;
    NODE *current = head;

    printf("List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    
    printf("(Head %d)\n", head->data);
}

void freeList(NODE *tail) {
    if (tail == NULL) return;
    
    NODE *head = tail->next;
    NODE *current = head;
    
    tail->next = NULL;
    
    NODE *temp;
    while(current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

NODE *insertAtBeginning(NODE *tail, int num) {
    NODE *newNode = createNode(num);

    if (tail == NULL) {
        return newNode; 
    }

    newNode->next = tail->next;
    tail->next = newNode;
    
    return tail;
}

NODE *insertAtEnd(NODE *tail, int num) {
    NODE *newNode = createNode(num);

    if (tail == NULL) {
        return newNode; 
    }

    newNode->next = tail->next;
    tail->next = newNode;
    
    return newNode;
}

NODE *insertAfterNode(NODE *tail, int afterValue, int num) {
    if (tail == NULL) {
        printf("List is empty. Cannot insert after %d.\n", afterValue);
        return tail;
    }

    NODE *head = tail->next;
    NODE *current = head;

    do {
        if (current->data == afterValue) {
            NODE *newNode = createNode(num);
            
            newNode->next = current->next;
            current->next = newNode;
            
            if (current == tail) {
                return newNode;
            }
            return tail;
        }
        current = current->next;
    } while (current != head);

    printf("Node with value %d not found for insertion.\n", afterValue);
    return tail;
}

NODE *deleteNodeByValue(NODE *tail, int key) {
    if (tail == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    NODE *head = tail->next;
    NODE *current = head;
    NODE *prev = tail;

    do {
        if (current->data == key) {
            if (current == tail && current == head) {
                free(current);
                return NULL;
            }

            if (current == head) {
                tail->next = current->next;
                free(current);
                return tail;
            }

            if (current == tail) {
                prev->next = head;
                free(current);
                return prev;
            }

            prev->next = current->next;
            free(current);
            return tail;
        }

        prev = current;
        current = current->next;
    } while (current != head);

    printf("Value %d not found for deletion.\n", key);
    return tail;
}

int isCircular(NODE *head) {
    if (head == NULL) return 0;
    
    NODE *slow = head;
    NODE *fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            return 1;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return 0;
}

void splitCircularList(NODE *tail, NODE **tail1_ref, NODE **tail2_ref) {
    if (tail == NULL || tail->next == tail) {
        *tail1_ref = tail;
        *tail2_ref = NULL;
        return;
    }

    NODE *slow = tail->next;
    NODE *fast = tail->next->next;
    NODE *head = tail->next;
    
    while (fast != head && fast->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *tail1_ref = slow;
    *tail2_ref = tail;

    NODE *head2 = slow->next;

    (*tail1_ref)->next = head;

    (*tail2_ref)->next = head2;
}

int main() {
    NODE *tail = NULL;
    
    tail = insertAtBeginning(tail, 10);
    tail = insertAtEnd(tail, 30);
    tail = insertAtBeginning(tail, 5);
    tail = insertAtEnd(tail, 40);

    printf("1. Initial List (Tail: %d):\n", tail->data);
    displayList(tail); 

    tail = insertAtBeginning(tail, 1);
    printf("\n2. After Insert 1 at Beginning:\n");
    displayList(tail);

    tail = insertAfterNode(tail, 30, 35);
    printf("\n3. After Insert 35 after 30:\n");
    displayList(tail);

    tail = deleteNodeByValue(tail, 5);
    printf("\n4. After Delete 5:\n");
    displayList(tail);

    printf("\n5. Check if List is Circular:\n");
    if (isCircular(tail->next)) {
        printf("Result: The list IS circular.\n");
    } else {
        printf("Result: The list is NOT circular.\n");
    }

    NODE *tail1 = NULL;
    NODE *tail2 = NULL;
    
    printf("\n6. Splitting the List:\n");
    splitCircularList(tail, &tail1, &tail2);
    
    printf("  First Half: ");
    displayList(tail1);
    printf("  Second Half: ");
    displayList(tail2);

    freeList(tail1);
    freeList(tail2);

    return 0;
}