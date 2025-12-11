#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------------
 PROBLEM STATEMENT
------------------------------------------------------------
You have 'n' boxes, each with a number. You want to sort the 
array in non-decreasing order.

BUT: your machine can only reverse a subarray of length 
     at most 'k'.

You must determine if it is possible to sort the array 
using any number of such reverses.

------------------------------------------------------------
 SIMPLE EXPLANATION
------------------------------------------------------------
- You can reverse any continuous subarray BUT its length 
  must be <= k.

- If k == 1:
      You cannot change anything at all.
      So the array must ALREADY be sorted.
      Otherwise answer = NO.

- If k >= 2:
      You can always sort the array.
      Because with small reverses you can move elements around.

      (This is a known fact: if you are allowed to reverse any
       subarray of length >= 2, you can perform any permutation.)

------------------------------------------------------------
 FINAL RULE (Very Important)
------------------------------------------------------------
✔ If k == 1 → check if array is already sorted  
✔ If k >= 2 → always YES

'N' does NOT affect the answer.

------------------------------------------------------------
 ALGORITHM
------------------------------------------------------------
1. Read t test cases.
2. For each test case:
    - Read n, k
    - Read array a[]
    - If k == 1:
         - Check if array is sorted.
           If sorted → print YES
           Else → print NO
      Else:
         - Print YES (because sorting is always possible)

------------------------------------------------------------
 Example:
 Input:
 n = 2, k = 1
 a = [3, 1]

 k = 1 → no operations allowed → array NOT sorted → NO
------------------------------------------------------------
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // Case 1: k == 1 → array must already be sorted
        if (k == 1) {
            if (is_sorted(a.begin(), a.end()))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else {
            // Case 2: k >= 2 → always YES
            cout << "YES\n";
        }
    }

    return 0;
}
