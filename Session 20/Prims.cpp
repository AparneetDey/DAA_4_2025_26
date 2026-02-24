#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int V, E;
    cin>>V>>E;

    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<bool> visited(V);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // (vertex, weight)
    pq.push({0, 0});
    int minCost = 0;

    while(!pq.empty()) {
        int w = pq.top().second;
        int u = pq.top().first;

        pq.pop();

        visited[u] = true;
        minCost += w;
        for(auto nev: adj[u]) {
            int v = nev.first;
            if(!visited[v]) {
                pq.push({v, nev.second});
            }
        }
    }

    cout<<minCost<<endl;
}