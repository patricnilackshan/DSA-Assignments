#include <iostream>
#include <limits.h>

#define V 6

using namespace std;

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[],int src) {
    cout << "Vertex \t\t Distance from Source "<<src << endl;
    float sum=0;
    for (int i = 0; i < V; i++) {
        sum+=dist[i];
        cout << i << " \t\t " << dist[i] << endl;
    }
    cout << "Average time : "<<sum/5 << endl<<endl;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist,src);
}

int main() {
    int graph[V][V] = {{0,10,0,0,15,5},
                       {10,0,10,30,0,0},
                       {0,10,0,12,5,0},
                       {0,30,12,0,0,20},
                       {15,0,5,0,0,0},
                       {5,0,0,20,0,0}};

    dijkstra(graph, 0);
    dijkstra(graph, 1);
    dijkstra(graph, 2);
    dijkstra(graph, 3);
    dijkstra(graph, 4);
    dijkstra(graph, 5);

    return 0;
}
