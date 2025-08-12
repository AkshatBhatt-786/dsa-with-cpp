/*
    Problem: Check if Array is Sorted (Recursive)

    Given an array of integers, determine whether the array is sorted in
    non-decreasing (ascending) order using a recursive approach.

    Return "YES" if the array is sorted, otherwise return "NO".

    Example 1:
    Input:
    5
    1 2 3 4 5
    Output:
    YES
    Explanation:
    All elements are in ascending order.

    Example 2:
    Input:
    4
    1 3 2 5
    Output:
    NO
    Explanation:
    3 > 2, so the array is not sorted.

    Constraints:
    1 <= n <= 10^5
    -10^9 <= arr[i] <= 10^9
*/

#include <iostream>
using namespace std;

bool is_sorted(int arr[], int n, int index) {
    if (index >= n) return true;
    if (arr[index] < arr[index - 1]) return false;
    return is_sorted(arr, n, index + 1);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (is_sorted(arr, n, 1))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
