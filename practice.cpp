#define _WIN32_WINNT 0x0600
#include "rang.hpp"
#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        size = 0;
        arr[size] = '\0';
    }

    void print()
    {
        for(int i=1; i<=size; i++)
        {
            cout << rang::style::bold << rang::fg::green << arr[i] << " | " << rang::fg::reset;
        }
    }

    void insert(int val)
    {
        size += 1;
        int index = size;
        arr[index] = val;

        while(index > 1)
        {
            int parent = index/2;
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            } else return;
        }
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
    cout << rang::fg::magenta << "using insert() : \n" << rang::style::reset;
    h->insert(70);
    h->insert(29);
    h->insert(30);
    h->insert(42);
    h->insert(86);
    h->insert(76);
    h->insert(52);
    h->insert(301);
    h->insert(402);
    h->insert(101);
    h->print();

    cout << rang::fg::blue << "\n\nHeap Array using heapify function:" << rang::style::reset;

    int arr[11] = {-1, 70, 30, 42, 86, 76, 52, 301, 402, 101};
    int n = 11;
    for(int i=n; i>0; i--)
    {
        heapify(arr, n, i);
    }
    cout << endl;
    for(int i=1; i<n; i++)
    {
        cout << rang::fg::green << rang::style::bold << arr[i] << " | " << rang::style::reset;
    }
    cout << endl;
}