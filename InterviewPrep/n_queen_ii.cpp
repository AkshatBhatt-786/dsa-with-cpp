// File: n_queens_2.cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> col(n, 0), diag1(2*n, 0), diag2(2*n, 0);
        return backtrack(0, n, col, diag1, diag2);
    }
    
    int backtrack(int row, int n,
                  vector<int>& col, vector<int>& diag1, vector<int>& diag2) {
        
        if (row == n) return 1;
        
        int count = 0;
        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row+c] || diag2[row-c+n])
                continue;
            
            col[c] = diag1[row+c] = diag2[row-c+n] = 1;
            count += backtrack(row + 1, n, col, diag1, diag2);
            col[c] = diag1[row+c] = diag2[row-c+n] = 0;
        }
        return count;
    }
};