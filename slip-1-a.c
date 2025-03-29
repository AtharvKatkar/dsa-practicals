/*
Implement a Binary search tree (BST) library (btree.h) with operations – create, insert, inorder.Write a menu driven program that performs the above operations.
*/

#include <stdio.h>
#include "slip-1-a.h"

void printMenu()
{
    printf("BST menu driven program ;) \n\n Menu:\n");
    printf("1) Insert data \n");
    printf("2) Preorder \n");
    printf("3) Count leaf \n");
    printf("4) Exit \n\n");

    printf("Enter your choice: ");
}

void main()
{
    Node *root = createNode(10);
    int ch;
    int data;

    while (1)
    {
        printMenu();
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter data you want to insert: ");
            scanf("%d", &data);
            if (root == NULL)
            {
                root = insert(root, data);
            }
            insert(root, data);
            printf("%d inserted to tree \n", data);
            break;

        case 2:
            printf("preorder \n");
            inorder(root);
            printf("\n");
            break;

        case 3:
            printf("Count leaf nodes \n");
            int count = countLeafNode(root);
            int countN = countNonLeafNode(root);
            int countTotal = countNodes(root);
            printf("Leaf: %d\n", count);
            printf("Non leaf: %d\n", countN);
            printf("Total nodes: %d\n", countTotal);
            break;

        case 4:
            exit(0);
        default:
            printf("!! Invalid choice selected !!");
        }
    }
}