#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *nn = (Node *)malloc(sizeof(Node));
    nn->data = data;
    nn->right = NULL;
    nn->left = NULL;
    return nn;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (root->data > data)
    {
        root->left = insert(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = insert(root->right, data);
    }

    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int countLeafNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return countLeafNode(root->left) + countLeafNode(root->right);
}

int countNonLeafNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left || root->right)
    {
        return 1;
    }

    return countNonLeafNode(root->left) + countNonLeafNode(root->right);
}

int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}