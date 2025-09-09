#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
#include<list>
#include<climits>

using namespace std;

vector<int> algo(unordered_map<int, list<pair<int, int>>> adjList, int nodes, int edges, int source)
{
    vector<int> dist(nodes, INT_MAX);
    set<pair<int, int>> st;

    dist[source] = 0;
    st.insert(make_pair(0, source));

    while(!st.empty())
    {
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        st.erase(st.begin());

        for (auto neighbour: adjList[topNode])
        {
            if (nodeDistance + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                if (record != st.end())
                    st.erase(record);
        
                dist[neighbour.first] = nodeDistance + neighbour.second;
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
}

// here u and v are nodes, d represents distance between u and v
void connectNodes(unordered_map<int, list<pair<int, int>>> adj, int u, int v, int d)
{
    adj[u].push_back(make_pair(v, d));
    adj[v].push_back(make_pair(u, d)); // for unidirectional graph
}

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    unordered_map<int, list<pair<int, int>>> adj;

    for(int i=0; i<edges; i++)
    {
        int u, v, d;
        cout << "Enter data: ";
        cin >> u >> v >> d;
        connectNodes(adj, u, v, d);
    }
    int source;
    cout << "Enter from where do you want to start: ";
    cin >> source;

    vector<int> dijsktra = algo(adj, nodes, edges, source);
    cout << "Shortest distances from source " << source << ":\n";
    for (int i=0; i<nodes; i++) {
        cout << i << " -> " << dijsktra[i] << endl;
    }
}