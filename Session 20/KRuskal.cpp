#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if(rootA == rootB)
            return;

        if(size[rootA] < size[rootB]) {
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        }
        else {
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
    }
};

void kruskal(int V, vector<Edge>& edges) {

    sort(edges.begin(), edges.end(), cmp);

    DSU dsu(V);

    int totalCost = 0;

    for(auto edge : edges) {

        if(dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.unite(edge.u, edge.v);
            totalCost += edge.weight;
        }
    }

    cout << "Total cost = " << totalCost << endl;
}

int main() {

    int V = 4;

    vector<Edge> edges = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    kruskal(V, edges);

    return 0;
}