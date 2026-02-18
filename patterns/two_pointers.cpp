// * sorted array: [1, 2, 3, 5, 8, 10]
// * target: 12

#include <iostream>
#include <vector>
using namespace std;

bool pairSum(vector<int> &arr, int target)
{
    int l=0, r=arr.size() - 1;
    while(l < r)
    {
        int sum = arr[l] + arr[r];
        if (sum == target) return true;
        else if (sum < target) l++;
        else r--;
    }
    return false;
}

int main()
{
    vector<int> arr = {1, 2, 3, 5, 8, 10};
    int target = 16;
    cout << "Ans: " << pairSum(arr, target);
}