#include <limits.h>
#define V 6 // Number of intersections (vertices)
// Function to find the vertex with minimum distance
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
// Function to print distances
void printSolution(int dist[]) {
    printf("Intersection\tShortest Traffic Time from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t\t%d\n", i, dist[i]);
}
// Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];    // Shortest distances from source
    int visited[V]; // Visited intersections
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSolution(dist);
}
int main() {
    // Traffic network graph (weights = traffic time in minutes)
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };
    int source = 0; // Starting intersection
    printf("Urban Traffic Management - Shortest Paths from Intersection %d\n", source);
    dijkstra(graph, source);
    return 0;
}
