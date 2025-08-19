#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
using namespace std;

class Graph 
{
public:
    unordered_map<int, list<int>> adj;
    vector<int> visited;
    vector<int> dfs;

    Graph(int nodes) 
    {
        visited.resize(nodes, 0);
    }

    void performDfs(int start) 
    {
        visited[start] = 1;
        dfs.push_back(start);

        for (auto neighbor : adj[start]) 
        {
            if (visited[neighbor] == 0) 
            {
                performDfs(neighbor);
            }
        }
    }

    void insertEdge(int u, int v, bool direction)
    {
        adj[u].push_back(v);
        
        if (direction == 0)  // undirected graph
            adj[v].push_back(u);
    }

    void printAdjList() 
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second) 
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};


int main() 
{
    int n, m;
    cout << "Enter the number of Nodes: ";
    cin >> n;
    cout << "Enter the number of Edges: ";
    cin >> m;

    Graph g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.insertEdge(u, v, false);
    }

    g.printAdjList();

    int start;
    cout << "Enter start node: ";
    cin >> start; 
    
    g.performDfs(start);

    cout << "DFS Traversal: ";
    for (auto i : g.dfs) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
