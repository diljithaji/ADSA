#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=newNode->right=NULL;
    return newNode;
}

int height(struct Node *root) {
    if (root==NULL)
        return 0;

    int lh=height(root->left);
    int rh=height(root->right);

    return 1+(lh>rh ? lh:rh);
}

int countLeaves(struct Node *root) {
    if (root==NULL)
        return 0;

    if (root->left==NULL && root->right==NULL)
        return 1;

    return countLeaves(root->left)+countLeaves(root->right);
}

int main() {
    struct Node *root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);

    printf("Height of tree: %d\n",height(root));
    printf("Total leaf nodes: %d\n",countLeaves(root));

    return 0;
}
