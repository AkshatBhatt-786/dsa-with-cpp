#include <iostream>
#include <queue>

using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{
    priority_queue<int> pq;

    // step 1:
    for(int i=0; i<k; i++)
    {
        pq.push(arr[i]);
    }

    // step 2:
    for(int i = k; i <= r; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << "Kth smallest element is " << kthSmallest(arr, 0, n - 1, k) << endl;
}