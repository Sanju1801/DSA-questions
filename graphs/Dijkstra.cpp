/*
Graph Representation:

The graph is represented as an adjacency list, where graph[u] contains pairs {v, w} indicating an edge from node u to node v with weight w.
Distance Initialization:

A dist array is initialized with INT_MAX for all nodes, except the source node which is set to 0.
Priority Queue:

A min-heap priority queue is used to process nodes in increasing order of their current shortest distance. This ensures efficiency.
Edge Relaxation:

For each neighbor v of the current node u, if the path through u provides a shorter distance to v, update dist[v] and push it into the priority queue.
Output:

The function returns the shortest distances from the source node to all other nodes. Nodes that remain unreachable will have INT_MAX as their distance.


*/


#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& graph, int src) {
    // Initialize distances to all nodes as infinite
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Min-heap priority queue: stores pairs of (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src}); // Start from the source node

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        // If the distance is outdated, skip processing
        if (d > dist[u]) continue;

        // Relax all neighbors of node u
        for (const auto& [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w; // Update the distance
                pq.push({dist[v], v}); // Push the updated distance to the queue
            }
        }
    }

    return dist;
}
