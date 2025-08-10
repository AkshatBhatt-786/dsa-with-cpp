#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int findEvenNumbers(vector<int>& digits) {
        set<int> numbers; // store unique valid numbers
        
        int n = digits.size();
        for (int i = 0; i < n; i++) {           // hundreds
            if (digits[i] == 0) continue;      // no leading zero
            for (int j = 0; j < n; j++) {       // tens
                if (j == i) continue;           // can't reuse same digit index
                for (int k = 0; k < n; k++) {   // units
                    if (k == i || k == j) continue; // all indices distinct
                    if (digits[k] % 2 != 0) continue; // must be even
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    numbers.insert(num);
                }
            }
        }
        return numbers.size();
    }
};

int main() {
    Solution sol;
    vector<int> digits;
    int n;
    
    cout << "Enter number of digits: ";
    cin >> n;
    digits.resize(n);
    cout << "Enter digits: ";
    for (int i = 0; i < n; i++) cin >> digits[i];

    cout << "Distinct even 3-digit numbers: " << sol.findEvenNumbers(digits) << endl;
    return 0;
}
