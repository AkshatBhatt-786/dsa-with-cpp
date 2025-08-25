#include <iostream>
using namespace std;

// 2 4 1 9 6
int partition(int arr[], int s, int e)
{
    int pivot = arr[s]; // 2
    int cnt = 0;
    for(int i=s+1; i<=e; i++)
    {
        if (arr[i] <= pivot) {
            cnt++;
        }
    }
    // place pivot at right place
    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // left and right wala part smbhal lete hai
    int i = s, j = e;
    while(i<pivotIndex && j > pivotIndex)
    {
        while(arr[i] < pivot)
            i++;

        while(arr[j] > pivot)
            j--;
        
        if (i < pivotIndex && j > pivotIndex) 
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

// 2 4 1 9 6
void quickSort(int arr[], int s, int e)
{
    // base case
    if (s >= e) 
        return;

    // partition
    int p = partition(arr, s, e);

    // left part sort karo
    quickSort(arr, s, p-1);

    // right part sort karo
    quickSort(arr, p+1, e);
}

int main() 
{
    int arr[5] = {2, 4, 1, 9, 6};
    int n = 5;
    quickSort(arr, 0, n-1);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << ", ";
    } cout << endl;
}