//Bellman ford algorithm

#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (from to weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].weight;
    }

    int source;
    cout << "Enter source vertex: ";
    cin >> source;

    const int INF = 1000000000;
    vector<int> distance(V, INF);
    distance[source] = 0;

    // Step 1: Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].from;
            int v = edges[j].to;
            int w = edges[j].weight;

            if (distance[u] != INF && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Step 2: Check for negative weight cycle
    bool negativeCycle = false;
    for (int j = 0; j < E; j++) {
        int u = edges[j].from;
        int v = edges[j].to;
        int w = edges[j].weight;

        if (distance[u] != INF && distance[u] + w < distance[v]) {
            negativeCycle = true;
            break;
        }
    }

    // Output
    if (negativeCycle) {
        cout << "Negative weight cycle detected!\n";
    } else {
        cout << "Shortest distances from source:\n";
        for (int i = 0; i < V; i++) {
            if (distance[i] == INF)
                cout << "Vertex " << i << ": Not reachable\n";
            else
                cout << "Vertex " << i << ": " << distance[i] << endl;
        }
    }

    return 0;
}



