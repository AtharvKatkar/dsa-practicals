/*
C program to implement graph traversal method using depth first search.
*/

#include <stdio.h>
#include <limits.h>

int stack[100];
int pt = -1;

int visited[100];
int vpt = 0;

void push(int data)
{
    printf("\nPush %d to stack\n", data);
    stack[++pt] = data;
}

int pop()
{
    printf("\nPop %d from stack\n", stack[pt]);
    return stack[pt--];
}

int checkInStack(int data)
{
    int found = 0;
    for (int i = 0; i < pt; i++)
    {
        if (data == stack[i])
        {
            printf("\n%d found in stack\n", data);
            found = 1;
            break;
        }
    }

    return found;
}

int checkVisited(int data)
{
    int found = 0;
    for (int i = 0; i < vpt; i++)
    {
        if (data == visited[i])
        {
            printf("\n%d found in visited\n", data);
            found = 1;
            break;
        }
    }

    return found;
}

void pushVisited(int data)
{
    visited[vpt] = data;
    vpt = vpt + 1;
}

void dfs(int n, int m[n][n])
{
    int key = pop();
    if (pt == -1 && vpt == n)
    {
        printf("\n\n\n\nDFS for the graph is: \n");
        for (int i = 0; i < vpt; i++)
        {
            printf("%d\t", visited[i]);
        }
        return;
    }

    if (pt == -1)
    {
        printf("\nOverflow!!!!!!!!!!\nChanging key if exists\n");
        key = key + 1;
    }

    int adj[n];
    int adjp = 0;
    pushVisited(key);

    for (int j = 0; j < n; j++)
        if (m[key][j] == 1)
        {
            adj[adjp] = j;
            adjp = adjp + 1;
        }

    printf("\nFor key=%d adjacent list is: \n", key);
    for (int i = 0; i < adjp; i++)
        printf("%d ", adj[i]);
    printf("\n");

    // push all adjacent items which are non duplicate nor visited to the stack
    for (int i = 0; i < adjp; i++)
    {
        int element = adj[i];
        if (checkInStack(element) == 0 && checkVisited(element) == 0)
        {
            push(element);
        }
    }

    dfs(n, m);
}

void main()
{
    int n;
    printf("Enter total vertices: ");
    scanf("%d", &n);
    n = 4;

    int m[4][4] = {{0, 0, 1, 0}, {1, 0, 1, 1}, {0, 0, 0, 0}, {0, 1, 0, 0}};

    // Currently set to hardcode mode
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         scanf("%d", &m[i][j]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", m[i][j]);
        printf("\n");
    }

    // dfs start
    visited[0] = 0;
    push(0);
    dfs(n, m);
}