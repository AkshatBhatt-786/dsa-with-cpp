// * problem: subarray sum
// & [1, 2, 3, 5, 3, 1]
// & k = 3    total
// 1, 2, 3    6
// 2, 3, 5,   10
// 3, 5, 3    11
// 5, 3, 1    9
// * ans: 11

#include <iostream>
#include <vector>
using namespace std;

int subArraySum(vector<int> &arr, int k)
{
    int sum = 0;
    for(int i=0; i<k; i++)
        sum += arr[i];
    
    int maxSum = sum;
    for(int i=k; i<arr.size(); i++)
    {
        sum += arr[i];
        sum -= arr[i-k];
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {1, 2, 3, 5, 3, 1};
    int k = 3;
    cout << "Ans: " << subArraySum(arr, k);

}