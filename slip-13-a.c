/*
Write a C program which uses Binary search tree library and implements following function with
recursion:
int compare(T1, T2) – compares two binary search trees and returns 1 if they are equal and 0
otherwise
*/

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

int compare(Node *t1, Node *t2)
{

    if (t1 == NULL && t2 == NULL)
    {
        return 1;
    }

    if (t1 == NULL || t2 == NULL)
    {
        return 0;
    }

    if (
        t1->data == t2->data &&
        compare(t1->left, t2->left) == 1 &&
        compare(t1->right, t2->right) == 1)
    {
        return 1;
    }

    return 0;
}

void main()
{
    Node *t1 = createNode(10);
    insert(t1, 20);
    insert(t1, 5);

    Node *t2 = createNode(10);
    insert(t2, 20);
    insert(t2, 5);

    int same = compare(t1, t2);

    if (same == 1)
    {
        printf("Equal");
    }
    else
    {
        printf("Not Equal");
    }
}