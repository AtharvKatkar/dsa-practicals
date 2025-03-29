/*
Write a C program that accepts the vertices and edges of a graph and stores it as an adjacency
matrix. Display the adjacency matrix. Implement functions to print indegree of all vertices of graph
*/

#include <stdio.h>

void calculateIndegree(int n, int m[n][n])
{
    int key = 0;
    int count = 0;

    while (key < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (m[key][i] == 1)
            {
                count = count + 1;
            }
        }
        if (key == n)
        {
            break;
        }
        else
        {
            printf("%d: %d \n", key, count);
            key = key + 1;
            count = 0;
        }
    }
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

    calculateIndegree(n, m);
}