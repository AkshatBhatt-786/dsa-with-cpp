#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char from, char to, char aux) {
    if (n <= 0) return;              // nothing to move
    hanoi(n - 1, from, aux, to);     // step 1: move n-1 to aux
    cout << from << " -> " << to << "\n"; // step 2: move largest
    hanoi(n - 1, aux, to, from);     // step 3: move n-1 onto largest
}

int main() {
    int n = 3; // try different n
    hanoi(n, 'A', 'C', 'B');
    // Minimum moves = 2^n - 1
    cout << "Total moves: " << ((1LL << n) - 1) << "\n";
    return 0;
}
