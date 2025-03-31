#include <stdio.h>
int queue[100], front = -1, rear = -1, visited[100], vp = 0;
void enqueue(int data){
    if (front == -1)
        front = 0;
    queue[++rear] = data;
}
int dequeue(){
    if (front == -1)
        return -1;
    int data = queue[front];
    if (front == rear)
        front = -1, rear = -1;
    else
        front++;
    return data;
}
int check(int data){
    int found = 0;
    for (int i = 0; i < rear; i++)
        if (data == queue[i] && found != 1)
            found = 1;
    for (int i = 0; i < vp; i++)
        if (data == visited[i] && found != 1)
            found = 1;
    return found;
}
void dfs(int v, int m[v][v]){
    int vertex = dequeue();
    if (vertex == -1){
        if (vp < v)
            vertex = vertex + 1;
        return;
    }
    visited[vp] = vertex;
    vp = vp + 1;
    int adjacentVertices[v], ap = 0;
    for (int i = 0; i < v; i++)
        if (m[vertex][i] == 1){
            adjacentVertices[ap] = i;
            ap = ap + 1;
        }
    for (int i = 0; i < ap; i++)
        if (check(adjacentVertices[i]) != 1)
            enqueue(adjacentVertices[i]);
    if (vp < v)
        dfs(v, m);
    else{
        printf("Exit to due to limit reach \n\n\n\nFinal dfs:\nVisited array:");
        for (int i = 0; i < vp; i++)
            printf("%d ", visited[i]);
    }
}
void main(){
    int m[4][4] = {{0, 0, 1, 0}, {1, 0, 1, 1}, {0, 1, 0, 0}, {0, 1, 0, 0}};
    enqueue(0);
    dfs(4, m);
}
