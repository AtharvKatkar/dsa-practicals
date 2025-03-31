#include <stdio.h>
int stack[100], pt = -1, visited[100], vp = 0;
void push(int data)
{
    stack[++pt] = data;
}
int pop()
{
    if (pt == -1)
        return -1;
    return stack[pt--];
}
int check(int data)
{
    int found = 0;
    for (int i = 0; i < pt; i++)
        if (data == stack[i] && found != 1)
            found = 1;
    for (int i = 0; i < vp; i++)
        if (data == visited[i] && found != 1)
            found = 1;
    return found;
}
void dfs(int v, int m[v][v])
{
    int vertex = pop();
    if (vertex == -1)
    {
        if (vp < v)
            vertex = vertex + 1;
        return;
    }
    visited[vp] = vertex;
    vp = vp + 1;
    int adjacentVertices[v], ap = 0;
    for (int i = 0; i < v; i++)
        if (m[vertex][i] == 1)
        {
            adjacentVertices[ap] = i;
            ap = ap + 1;
        }
    for (int i = 0; i < ap; i++)
        if (check(adjacentVertices[i]) != 1)
            push(adjacentVertices[i]);
    if (vp < v)
        dfs(v, m);
    else
    {
        printf("Exit to due to limit reach \n\n\n\nFinal dfs:\nVisited array:");
        for (int i = 0; i < vp; i++)
            printf("%d ", visited[i]);
    }
}
void main()
{
    int m[4][4] = {{0, 0, 1, 0}, {1, 0, 1, 1}, {0, 1, 0, 0}, {0, 1, 0, 0}};
    push(0);
    dfs(4, m);
}
