#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph 
{
public:
    unordered_map < int, list<int> > adjList;

    void connectEdges(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfs(vector<int> &visited, int startNode)
    {
        cout << startNode << ", ";
        visited[startNode] = 1;

        for(auto i: adjList[startNode])
        {
            if (visited[i] == 0) {
                dfs(visited, i);
            }
        }
    }

    void bfs(int startNode, int size)
    {
        vector<int> visited(size, 0);
        visited[startNode] = 1;
        queue<int> q;
        q.push(startNode);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << ", ";

            for(auto i: adjList[node])
            {
                if(!visited[i]) {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }

    }

    void print()
    {
        for (auto i : adjList)
        {
            cout << i.first << "-> ";
            for(auto j : i.second)
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
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;
    Graph g;
    vector<int> visited(nodes, 0);

    for(int i=0; i<edges; i++)
    {
        int u, v;
        cout << "Enter the node you want to connect (seperate: ' ') : ";
        cin >> u >> v;
        g.connectEdges(u, v);
    }

    int startNode;
    cout << "Enter the start node: ";
    cin >> startNode;
    g.print();
    g.bfs(startNode, nodes);
    cout << endl;
    g.dfs(visited, startNode);

}