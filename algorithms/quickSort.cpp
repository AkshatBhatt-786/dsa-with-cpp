#include <iostream>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int cnt = 0;
    for(int i=s+1; i<=e; i++)
         if(arr[i] <= pivot) cnt++;
    
    int pivotIndex = cnt + s;
    swap(arr[pivotIndex], arr[s]);

    int i=s, j=e;

    while(i < pivotIndex && j > pivotIndex)
    {
        while(arr[i] < pivot) { 
            i++;
        }
        while(arr[j] > pivot) { 
            j--;
        } 
        if(i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
}

void quickSort(int arr[], int s, int e)
{
    if (s >= e)
        return;
    
    int p = partition(arr, s, e);

    // left part array
    quickSort(arr, s, p-1);

    // right part array
    quickSort(arr, p+1, e);
}

int main()
{
    int n = 5;
    int arr[5] = {3, 4, 5, 2, 1};
    quickSort(arr, 0, n-1);

    for (int i=0; i<n; i++) 
    {
        cout << arr[i] << ", ";
    }
}