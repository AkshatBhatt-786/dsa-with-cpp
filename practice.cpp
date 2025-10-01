#include <iostream>

using namespace std;

// void merge(int arr[], int s, int e)
// {
//     int mid = (s+e)/2;
//     int index1, index2, l1, l2, k;
//     l1 = mid - s + 1;
//     l2 = e - mid;
//     int *first = new int[l1];
//     int *second = new int[l2];

//     k=s;
//     for(int i=0; i<l1; i++)
//     {
//         first[i] = arr[k++];
//     }

//     k=mid+1;
//     for(int i=0; i<l2; i++)
//     {
//         second[i] = arr[k++];
//     }

//     index1 = index2 = 0;
//     k = s;

//     while(index1 < l1 && index2 < l2)
//     {
//         if(first[index1] < second[index2])
//             arr[k++] = first[index1++];
//         else
//             arr[k++] = second[index2++];
//     }

//     while(index1 < l1)
//         arr[k++] = first[index1++];
    
//     while(index2 < l2)
//         arr[k++] = second[index2++];

// }

// void mergeSort(int arr[], int s, int e)
// {
//     // base condition
//     if (s >= e) return;

//     int mid = (s+e)/2;
//     // left part
//     merge(arr, s, mid);
//     // right part
//     merge(arr, mid+1, e);
//     // merge left and right
//     merge(arr, s, e);
// }

// int partition(int arr[], int s, int e)
// {
//     int pivot = arr[s];
//     int cnt=0;
//     for(int i=s+1; i<=e; i++)
//     {
//         if (arr[i] <= pivot)
//             cnt ++;
//     }
//     int pivotIndex = cnt + s;
//     swap(arr[pivotIndex], arr[s]);
//     int i=s, j=e;
//     while(i < pivotIndex && j > pivotIndex)
//     {
//         while(arr[i] <= pivot && i < pivotIndex) i++;
//         while(arr[j] > pivot && j > pivotIndex) j--;

//         if (i < pivotIndex && j > pivotIndex)
//             swap(arr[i++], arr[j--]);
//     }
//     return pivotIndex;
// }  

// void quickSort(int arr[], int s, int e)
// {
//     // base condition
//     if (s >= e)
//         return;
    
//     int p = partition(arr, s, e);
//     // sort for left array
//     quickSort(arr, s, p-1);
//     // sort for right array
//     quickSort(arr, p+1, e);
// }


// void insertionSort(int arr[], int n) {
//     int i = 1;
//     while (i < n) {
//         int key = arr[i];
//         int j = i - 1;

//         while (j >= 0 && arr[j] > key) {
//             arr[j + 1] = arr[j];
//             j--;
//         }
//         arr[j + 1] = key;
//         i++;
//     }
// }

class heap
{
    
}

int main()
{
    int arr[5] = {3, 5, 2, 1, 12};
    int n = 5;

    insertionSort(arr , n);
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}