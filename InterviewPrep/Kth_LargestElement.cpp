#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Function to find the Kth largest element using a min-heap (priority_queue)
int KthLargestElement(vector<int>& nums, int k) {
    // Min-heap to store the k largest elements
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);
        // If heap size exceeds k, remove the smallest element
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    // The root of the heap is the kth largest element
    return minHeap.top();
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    cout << "The " << k << "th largest element is " << KthLargestElement(nums, k) << endl;
    return 0;
}