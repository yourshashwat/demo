#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<climits>
using namespace std;

// Structure to represent a pair of (node, weight)
typedef pair<int, char> Pair;

// Dijkstra's Algorithm function to find the shortest path
void dijkstra(unordered_map<char, vector<Pair>>& adjList, char start, int n) {
    unordered_map<char, int> dist;
    unordered_map<char, char> prev;
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

    // Initialize distances
    for (auto& pair : adjList) {
        dist[pair.first] = INT_MAX;  // Set all distances to infinity initially
    }
    dist[start] = 0;
    pq.push({0, start});  // Push start node with distance 0

    while (!pq.empty()) {
        char u = pq.top().second;  // Node with the smallest distance
        pq.pop();

        // Visit all neighbors of u
        for (auto& neighbor : adjList[u]) {
            char v = neighbor.second;  // Neighbor node
            int weight = neighbor.first;  // Edge weight

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;  // Update predecessor
                pq.push({dist[v], v});
            }
        }
    }

    // Output the shortest distances and paths
    for (auto& pair : dist) {
        cout << "Shortest distance from " << start << " to " << pair.first << " is: " << pair.second << endl;
        
        // Reconstruct the path
        cout << "Path: ";
        char node = pair.first;
        vector<char> path;
        while (node != start) {
            path.push_back(node);
            node = prev[node];
        }
        path.push_back(start);
        
        // Print the path in reverse order
        for (int i = path.size() - 1; i >= 0; --i) {
            cout << path[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "How many nodes you have: ";
    cin >> n;

    unordered_map<char, vector<Pair>> adjList;

    // Create the graph (adjacency list)
    cout << "Creating graph..." << endl;
    for (int i = 0; i < n; ++i) {
        char node;
        int edges;
        cout << "Enter the node character: ";
        cin >> node;
        cout << "How many neighbors does node " << node << " have? ";
        cin >> edges;

        for (int j = 0; j < edges; ++j) {
            char neighbor;
            int weight;
            cout << "Enter the neighbor's character: ";
            cin >> neighbor;
            cout << "Enter the weight of the edge: ";
            cin >> weight;

            adjList[node].push_back({weight, neighbor});  // Add the neighbor and its weight
        }
    }

    // Ask the user for the starting node
    char start;
    cout << "Enter the starting node: ";
    cin >> start;

    // Call Dijkstra's algorithm
    dijkstra(adjList, start, n);

    return 0;
}

