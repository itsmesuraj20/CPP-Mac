//Krushal Algorithm
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionSet(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};
struct Edge {
    int u, v, weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

void kruskal(int n, vector<Edge>& edges) {
    DisjointSet ds(n);
    sort(edges.begin(), edges.end(), compareEdges);
    vector<Edge> mst;

    for (Edge edge : edges) {
        int u = edge.u;
        int v = edge.v;
        if (ds.find(u) != ds.find(v)) {
            ds.unionSet(u, v);
            mst.push_back(edge);
        }
    }

    cout << "Minimum Spanning Tree:\n";
    for (Edge edge : mst) {
        cout << edge.u << " -- " << edge.v << " == " << edge.weight << endl;
    }
}

int main() {
    int n = 4; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(n, edges);
    return 0;
}
//         count++;
//         token = strtok(nullptr, s);
//     }
//     delete[] temp;
//     return count;
// }

