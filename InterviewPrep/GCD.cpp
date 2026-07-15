// You are given an integer n. Your task is to compute the GCD (greatest common divisor) of two values:
// sumOdd: the sum of the smallest n positive odd numbers.
// sumEven: the sum of the smallest n positive even numbers.
// Return the GCD of sumOdd and sumEven.

#include <iostream>
using namespace std;

long long gcd(int n) {
    long long sumOdd = n * n;
    long long sumEven = n * (n + 1);
    while (b) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    long long n;
    if (!(cin >> n)) return 0;
    long long sumOdd = n * n;
    long long sumEven = n * (n + 1);
    cout << gcd(sumOdd, sumEven);
    return 0;
}
