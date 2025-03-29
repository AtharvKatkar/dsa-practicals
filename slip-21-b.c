#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 9

int min_distance(int dist[], bool sptset[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptset[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void printsolution(int dist[])
{
    printf("vertex\t\t distance from source\n");
    for (int i = 0; i < V; i++)

        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptset[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptset[i] = false;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = min_distance(dist, sptset);
        sptset[u] = true;

        for (int v = 0; v < V; v++)

            if (!sptset[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] <= dist)
                dist[v] = dist[u] + graph[u][v];
    }
    printsolution(dist);
}

int main()

{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);
    return 0;
}