#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;
const int N = 6; // number of nodes in the graph

vector<pair<int, int>> adj[N]; // adjacency list to store edges and weights
int dist[N]; // distance array to store shortest distances
bool visited[N]; // visited array to keep track of visited nodes

void dijkstra(int start) {
    // initialize distance array and visited array
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[start] = 0;

    // create a priority queue and insert the starting node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        // extract the node with the smallest distance
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        // relax all edges
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}
int main() {
    //initialize edges and weights in the graph
    // adj[0].push_back({1, 3});
    // adj[0].push_back({2, 2});
    // adj[1].push_back({3, 4});
    // adj[2].push_back({4, 5});
    // adj[3].push_back({4, 1});
    // adj[4].push_back({5, 2});

    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 7});
    adj[2].push_back({4, 3});
    adj[3].push_back({5, 1});
    adj[4].push_back({3, 2});
    adj[4].push_back({5, 5});

    //start the algorithm
    dijkstra(0);
    //print the result 
    for (int i = 0; i < N; i++) {
        cout << i << " : " << dist[i] << endl;
    }
    return 0;
}
