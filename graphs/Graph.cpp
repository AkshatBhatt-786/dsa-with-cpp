#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <queue>
using namespace std;

class Graph 
{
public:
    unordered_map < int, list<int> > adj;
    vector<int> visit;

    Graph(int size) 
    {
        visit.resize(size, 0);
    }

    void performDFS(int startNode, int size)
    {
        visit[startNode] = 1;
        cout << startNode << " ";
        
        for(auto i: adj[startNode])
        {
            if (!visit[i])
            {
                performDFS(i, size);
            }
        }  
    }

    void performBFS(int startNode, int size)
    {
        queue<int> q;
        vector<int> visited(size, 0);
        q.push(startNode);
        visited[startNode] = 1;
        cout << "BFS: ";

        while(!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            cout << frontNode << " ";

            for(auto i: adj[frontNode])
            {
                if (!visited[i])
                {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }

    void insertEdge(int u, int v, bool direction) 
    {
        adj[u].push_back(v);

        // for unidirectional graph
        if (direction == 0) adj[v].push_back(u);
    }

    void print() 
    {
        for(auto i: adj) 
        {
            cout << i.first << "-> ";
            for(auto j: i.second) 
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main() 
{
    int nodes, edges;
    cout << "Enter the number of nodes & edges (n v): ";
    cin >> nodes >> edges;
    Graph g(nodes);

    for(int i=0; i<edges; i++) 
    {
        int u, v;
        cout << "Enter the vertices (source destination) : ";
        cin >> u >> v;
        g.insertEdge(u, v, 0);
    }

    g.print();
    int startNode;
    cout << "Enter the start node: ";
    cin >> startNode;
    g.performBFS(startNode, nodes);
    cout << "\nDFS: ";
    g.performDFS(startNode, nodes);
}