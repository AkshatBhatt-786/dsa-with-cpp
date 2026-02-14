#include <iostream>
#include <vector>
#include <list>
#include <set>
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

        for (int i=0; i<edges; i++) 
        {
            // [[source, destination, distance], [source, destination, distance]]
            int u = vec[i][0];
            int v = vec[i][1];
            int w = vec[i][2];

            // node: {destination, distance}
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w)); // undirected
        }

        vector<int> dist(vertices, INT_MAX);

        // set -> pair(distance, node)
        set<pair<int, int>> st;

        // source init
        dist[source] = 0;
        st.insert(make_pair(0, source));

        while(!st.empty()) 
        {
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int topNode = top.second;
            
            st.erase(st.begin());

            // * traverse neighbours
            for (auto neighbour: adj[topNode]) 
            {
                if (nodeDistance + neighbour.second < dist[neighbour.first])
                {
                    auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                    if (record != st.end())
                        st.erase(record);

                    // * distance update
                    dist[neighbour.first] = nodeDistance + neighbour.second;

                    st.insert(make_pair(dist[neighbour.first], neighbour.first));
                } 
            }
        }
        return dist;
    }
};

int main()
{
    Graph g;
    vector<vector<int>> edges = {
        {0,1,1},
        {0,3,7},
        {1,2,7},
        {2,4,4},
        {2,3,5}
    };
    
    int vertices = 5, e = 5, source = 0;

    vector<int> dist = g.dijkstra(edges, vertices, e, source);

    cout << "Shortest distances from source " << source << ":\n";
    for (int i=0; i<vertices; i++) {
        cout << i << " -> " << dist[i] << endl;
    }
}