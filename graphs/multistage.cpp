#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;
const int INF = INT_MAX;

void multistageGraph(int graph[MAX][MAX], int stages, int n)
{
    // & cost array to store minimum cost for each vertex to destination
    int cost[MAX] = {0};
    int path[MAX]; // * to store the actual path
    int dest = n; // * destination vertex

    // & initialise the cost of destination as 0
    cost[dest] = 0;

    // & compute costs from last stage to first
    for(int i = n - 1; i >= 1; i--)
    {
        int min = INF;

        // & for each vertex in current stage, find minimum cost to destination
        for(int j = i + 1; j <= n; j++)
        {
            if (graph[i][j] != INF && graph[i][j] + cost[j] < min) {
                min = graph[i][j] + cost[j];
                path[i] = j; // * storing the next vertex in optimal path
            }
        }
        cost[i] = min;
    }
    
    // & printing the results
    cout << "Minimum cost from source to destination: " << cost[1] << endl;

    cout << "Path: 1";
    int vertex = 1;
    while (vertex != dest) {
        cout << " - " << path[vertex];
        vertex = path[vertex];
    }
    cout << endl;
}

int main() {
    int graph[MAX][MAX];
    int n, stages;
    
    // & Initialize graph with infinity
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            graph[i][j] = INF;
    
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of stages: ";
    cin >> stages;
    
    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;
    
    cout << "Enter edges (source destination weight):" << endl;
    for (int i = 0; i < edges; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        graph[s][d] = w;
    }
    
    multistageGraph(graph, stages, n);
    
    return 0;
}