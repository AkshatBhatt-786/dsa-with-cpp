#include <iostream>
using namespace std;

int expo_2(int n) {
    if (n==0) return 1;
    int exp = expo_2(n/2);

    if (n & 1) return 2 * exp * exp;
    else return exp * exp;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << "2 raised to power " << n << ": " << expo_2(n);
}