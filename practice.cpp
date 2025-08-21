#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph 
{
public:

    unordered_map< int, list<int> > adjList;

    void connectEdges(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void print() 
    {
        for(auto i: adjList)
        {
            cout << i.first << "-> ";
            for (auto j : i.second) {
                cout << j << ", ";
            }
        }
    }
};

int main() 
{
    int nodes, edges;
    cout << "Enter number of nodes: ";
    cin >> nodes;

    cout << "Enter number of edges: ";
    cin >> edges;

    Graph g;

    for(int i=0; i<edges; i++) {
        int u, v;
        cout << "Enter vertices :";
        cin >> u >> v;
        g.connectEdges(u, v);
    }
    g.print();
}