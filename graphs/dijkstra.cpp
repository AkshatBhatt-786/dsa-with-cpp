#include <iostream>
#include <set>
#include <list>
#include <vector>
#include <unordered_map>
#include <utility>
#include <climits> // for INT_MAX
using namespace std;

class Graph 
{
public: 
    vector<int> dijkstra(vector<vector<int>> vec, int vertices, int edges, int source) 
    {
        unordered_map<int, list<pair<int, int>>> adj;

        // build adjacency list
        for (int i=0; i<edges; i++) 
        {
            int u = vec[i][0];
            int v = vec[i][1];
            int w = vec[i][2];

            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w)); // undirected
        }

        // distance array with infinity
        vector<int> dist(vertices, INT_MAX);

        // set -> (distance, node)
        set<pair<int, int>> st;

        // source init
        dist[source] = 0;
        st.insert(make_pair(0, source));

        while(!st.empty()) 
        {
            // fetch top record
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int topNode = top.second;
            
            // remove top record now
            st.erase(st.begin());

            // traverse neighbours
            for (auto neighbour: adj[topNode]) 
            {
                if (nodeDistance + neighbour.second < dist[neighbour.first])
                {
                    auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                    if (record != st.end())
                        st.erase(record);

                    // distance update
                    dist[neighbour.first] = nodeDistance + neighbour.second;

                    // push record to set
                    st.insert(make_pair(dist[neighbour.first], neighbour.first));
                } 
            }
        }

        return dist;
    }
};

int main() {
    Graph g;
    vector<vector<int>> edges = {
        {0,1,4},
        {0,2,1},
        {2,1,2},
        {1,3,1},
        {2,3,5}
    };
    
    int vertices = 4, e = 5, source = 0;

    vector<int> dist = g.dijkstra(edges, vertices, e, source);

    cout << "Shortest distances from source " << source << ":\n";
    for (int i=0; i<vertices; i++) {
        cout << i << " -> " << dist[i] << endl;
    }
}
