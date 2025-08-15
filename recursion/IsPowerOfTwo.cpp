#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n == 1) return true;      // Base case: 2^0 = 1
    if (n <= 0 || n % 2 != 0) return false;
    return isPowerOfTwo(n / 2);   // Recursive step
}

int main() {
    cout << boolalpha << isPowerOfTwo(16) << endl; // true
    cout << boolalpha << isPowerOfTwo(18) << endl; // false
    return 0;
}
