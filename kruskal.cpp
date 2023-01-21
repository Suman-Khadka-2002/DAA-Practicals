#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int source, destination, weight;
};

bool sortByWeight(Edge edge1, Edge edge2) {
    return edge1.weight < edge2.weight;
}

const int N = 100;
int parents[N];
vector<Edge> allEdges;

int findParent(int vertex) {
    if (parents[vertex] == vertex) return vertex;
    return parents[vertex] = findParent(parents[vertex]);
}

void unionVertices(int vertex1, int vertex2) {
    int parent1 = findParent(vertex1);
    int parent2 = findParent(vertex2);
    parents[parent1] = parent2;
}

vector<Edge> kruskal(int numOfVertices) {
    sort(allEdges.begin(), allEdges.end(), sortByWeight);
    vector<Edge> minimumSpanningTree;
    for (int i = 0; i < numOfVertices; i++) parents[i] = i;
    for (auto edge : allEdges) {
        int source = edge.source, destination = edge.destination, weight = edge.weight;
        if (findParent(source) != findParent(destination)) {
            minimumSpanningTree.push_back(edge);
            unionVertices(source, destination);
        }
    }
    return minimumSpanningTree;
}

int main() {
    int numOfVertices, numOfEdges;
    cout<<"Enter the number of vertices and Edges:  ";
    cin >> numOfVertices >> numOfEdges;
    cout<<"source  destination  weight"<<endl;
    for (int i = 0; i < numOfEdges; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        allEdges.push_back({source, destination, weight});
    }
    vector<Edge> minimumSpanningTree = kruskal(numOfVertices);
    cout<<"the minimum spanning tree : "<<endl;
    for (auto edge : minimumSpanningTree) {
        cout << edge.source << "\t  " << edge.destination << "\t   " << edge.weight << endl;
    }
    return 0;
}
