#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adj;

    void insertEdge(int u, int v, bool directed) {
        adj[u].push_back(v);
        if (!directed) adj[v].push_back(u);
    }

    void printAdjList() {
        for (auto &i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    vector<int> performBfs(int start, int size) {
        vector<int> bfs;
        vector<int> visited(size, 0);
        queue<int> q;
        visited[start] = 1;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

int main() {
    int n, m;
    cout << "Enter the number of Nodes: ";
    cin >> n;
    cout << "Enter the number of Edges: ";
    cin >> m;

    Graph g;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.insertEdge(u, v, false);
    }

    g.printAdjList();

    vector<int> bfs = g.performBfs(0, n);
    cout << "BFS Traversal: ";
    for (auto i : bfs) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
