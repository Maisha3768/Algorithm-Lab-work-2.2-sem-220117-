#include <iostream>
#include <vector>

using namespace std;

const int MAX_NODES = 1005;
vector<int> adj[MAX_NODES];
bool visited[MAX_NODES];


void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    cout << "Enter edges (u v format):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fill(visited, visited + nodes, false);

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    cout << "DFS Traversal: ";
    dfs(start);
    cout << endl;

    return 0;
}
