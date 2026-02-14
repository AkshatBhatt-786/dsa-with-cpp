#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

const int MAX = 100;

void printParenthesis(int s[][MAX], int i, int j) {
    if (i == j)
        cout << "A" << i;
    else {
        cout << "(";
        printParenthesis(s, i, s[i][j]);
        cout << " x ";
        printParenthesis(s, s[i][j] + 1, j);
        cout << ")";
    }
}

void matrixChainOrder(int dims[], int n) {
    int m[MAX][MAX] = {0};
    int s[MAX][MAX] = {0};
    
    // Fill tables
    for(int L = 2; L < n; L++) {
        for(int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            
            for (int k = i; k <= j - 1; k++) {
                int cost = m[i][k] + m[k+1][j] + dims[i-1] * dims[k] * dims[j];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
    
    // Print result
    cout << "\nMinimum multiplications: " << m[1][n-1] << endl;
    cout << "Optimal order: ";
    printParenthesis(s, 1, n-1);
    cout << endl;
    
    // Print cost table
    cout << "\nCost Table:" << endl;
    cout << "    ";
    for (int j = 1; j < n; j++) cout << "j=" << j << "\t";
    cout << "\n    ";
    for (int j = 1; j < n; j++) cout << "-----\t";
    cout << endl;
    
    for (int i = 1; i < n; i++) {
        cout << "i=" << i << " |";
        for (int j = 1; j < n; j++) {
            if (i > j) cout << " -\t";
            else cout << " " << m[i][j] << "\t";
        }
        cout << endl;
    }
    
    // Print split table
    cout << "\nSplit Table:" << endl;
    cout << "    ";
    for (int j = 1; j < n; j++) cout << "j=" << j << "\t";
    cout << "\n    ";
    for (int j = 1; j < n; j++) cout << "-----\t";
    cout << endl;
    
    for (int i = 1; i < n; i++) {
        cout << "i=" << i << " |";
        for (int j = 1; j < n; j++) {
            if (i >= j) cout << " -\t";
            else cout << " " << s[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int dims[] = {10, 20, 30, 40, 30};
    int n = sizeof(dims)/sizeof(dims[0]);
    
    matrixChainOrder(dims, n);
    
    return 0;
}