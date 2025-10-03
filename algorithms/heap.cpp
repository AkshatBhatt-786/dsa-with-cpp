#define _WIN32_WINNT 0x600
#include <iostream>
#include "rang.hpp"
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;

        arr[index] = val;

        while(index > 1)
        {
            int parent = index/2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else return;
        }
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete....";
            return;
        }

        // put last element to first index
        arr[1] = arr[size];
        // remove last elements
        size--;

        // take root node to its correct position
        int i = 1;
        while(i <= size)
        {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            int largest = i;

            if(leftIndex <= size && arr[largest] < arr[leftIndex])
                largest = leftIndex;
            if(rightIndex <= size && arr[largest] < arr[rightIndex])
                largest = rightIndex;
            if(largest != i)
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else    
                return;
        }
    }

    void print()
    {
        for(int i=1; i<=size; i++)
            cout << rang::fg::red << rang::style::bold << arr[i] << rang::fg::cyan << " | " << rang::style::reset;
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left])
        largest = left;
    if(right <= n && arr[largest] < arr[right])
        largest = right;
    
    if(largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;
    while(size > 1)
    {
        // step 1
        swap(arr[size], arr[1]);
        size--;

        // step 2
        heapify(arr, size, 1);
    }
}

int main()
{
    heap *h = new heap();
    h->insert(5);
    h->insert(2);
    h->insert(35);
    h->insert(9);
    h->insert(3);
    h->insert(52);
    h->insert(0);
    h->print();

    // // Test delete operation
    // h->deleteFromHeap();
    // cout << "After deleting root:" << endl;
    // h->print();

    // // Pause for console window (Windows)
    // system("pause");
    return 0;
}