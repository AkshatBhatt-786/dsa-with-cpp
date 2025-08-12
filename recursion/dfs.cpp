#include <iostream>
#include <vector>
using namespace std;

void dfs(int v1, vector<vector<int>> &arr, vector<int> &visited, int size) {
    cout << v1 << " ";
    visited[v1] = 1;

    for (int v2 = 0; v2 < size; v2++) {
        if (arr[v1][v2] == 1 && !visited[v2]) {
            dfs(v2, arr, visited, size);
        }
    }
}

void connect(vector<vector<int>> &arr, int v1, int v2) {
    arr[v1][v2] = 1;
    arr[v2][v1] = 1;
}

int main() {
    int size;
    cout << "Enter number of nodes you want to enter: ";
    cin >> size;

    vector<vector<int>> adj_matrix(size, vector<int>(size, 0));
    vector<int> visited(size, 0);

    connect(adj_matrix, 0, 1);
    connect(adj_matrix, 0, 2);
    connect(adj_matrix, 1, 3);
    connect(adj_matrix, 2, 3);
    connect(adj_matrix, 3, 4);

    cout << "DFS traversal: ";
    dfs(0, adj_matrix, visited, size);
}
