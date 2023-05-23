#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};
struct Graph {
    int V, E;
    vector<Edge> edges;
};
struct Subset {
    int parent, rank;
};

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

vector<Edge> kruskalMST(Graph graph) {
    int V = graph.V;
    vector<Edge> result;

    sort(graph.edges.begin(), graph.edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    Subset* subsets = new Subset[V];
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    int e = 0;
    int i = 0;
    while (e < V - 1 && i < graph.E) {
        Edge nextEdge = graph.edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result.push_back(nextEdge);
            unionSets(subsets, x, y);
            e++;
        }
    }
    delete[] subsets;
    return result;
}

int main() {
    int V = 4, E = 5;
    Graph graph;
    graph.V = V;
    graph.E = E;

    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    graph.edges = edges;

    vector<Edge> minimumSpanningTree = kruskalMST(graph);

    cout << endl;
    cout << "Minimum Spanning Tree Edges:\n";
    for (const Edge& edge : minimumSpanningTree)
        cout << edge.src << " -- " << edge.dest << " : " << edge.weight << endl;
}
