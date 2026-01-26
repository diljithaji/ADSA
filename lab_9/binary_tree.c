#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node*left;
    struct Node*right;
};

struct Node* createNode(int value) {
    struct Node*newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=newNode->right=NULL;
    return newNode;
}

struct Node*queue[100];
int front=0,rear=-1;

void push(struct Node* node) {
    queue[++rear]=node;
}

struct Node* pop() {
    return queue[front++];
}

int isEmpty() {
    return front>rear;
}


struct Node*insertLevelOrder(struct Node*root,int value) {
    struct Node*newNode=createNode(value);

    if (root==NULL)
        return newNode;

    push(root);

    while (!isEmpty()) {
        struct Node*temp=pop();

        if (temp->left==NULL) {
            temp->left=newNode;
            break;
        } else {
            push(temp->left);
        }

        if (temp->right==NULL) {
            temp->right=newNode;
            break;
        } else {
            push(temp->right);
        }
    }

    return root;
}

void preorder(struct Node *root) {
    if (root==NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct Node *root) {
    if (root==NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(struct Node *root) {
    if (root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int main() {
    struct Node*root=NULL;
    int n,value;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    for (int i=0;i<n;i++) {
        printf("Enter value %d: ",i+1);
        scanf("%d",&value);
        root=insertLevelOrder(root,value);

        front=0; 
        rear=-1;
    }

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}
