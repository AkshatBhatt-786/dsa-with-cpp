#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int s, int e) 
{
    int pivot = arr[s];
    int cnt = 0;

    for(int i=s+1; i<=e; i++) {
        if (arr[i] <= pivot)
            cnt++;
    }

    int pivotIndex = cnt + s;
    swap(arr[pivotIndex], arr[s]);

    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex) 
    {
        while(arr[i] <= pivot) i++;
        while(arr[j] > pivot) j--;

        if (i < pivotIndex && j > pivotIndex) 
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quickSort(vector<int>& arr, int s, int e)
{
    if (s >= e) return;

    int p = partition(arr, s, e);

    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main() 
{
    vector<int> arr;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int temp;
        cout << "Enter element " << i << ": ";
        cin >> temp;
        arr.push_back(temp);
    }

    quickSort(arr, 0, n-1);

    cout << "Sorted array: ";
    for (int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;
}
