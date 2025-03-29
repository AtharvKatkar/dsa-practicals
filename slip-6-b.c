/*
Write a C program that accepts the vertices and edges of a graph and stores it as an adjacency
matrix. Display the adjacency matrix. Implement functions to print indegree of all vertices of graph
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *nn = (Node *)malloc(sizeof(Node));
    nn->data = data;
    nn->next = NULL;
    return nn;
}

Node *printList(Node *root)
{
    Node *temp = root;
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("X");
}

void joinNode(Node *n1, Node *n2)
{
    n1->next = n2;
}

Node *getLastNode(Node *root)
{
    Node *temp = root;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}

void main()
{
    int n;
    printf("Enter no of vertice: ");
    scanf("%d", &n);

    int m[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &m[i][j]);

    printf("\nThe adjacency matrix is\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", m[i][j]);
        printf("\n");
    }

    Node *adjList[n];

    for (int i = 0; i < n; i++)
    {
        adjList[i] = createNode(i);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (m[i][j] == 1)
            {
                Node *lastNode = getLastNode(adjList[i]);
                Node *newNode = createNode(j);
                joinNode(lastNode, newNode);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        printList(adjList[i]);
        printf("\n");
    }
}