#include <iostream>
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
            } else return;
        }
    }

    void deleteRootNode()
    {
        if (size == 0)
        {
            cout << "nothing to delete....";
            return;
        }
    
        // Step 1: Move last element to root
        arr[1] = arr[size];
        size--;
    
        // Step 2: Heapify down
        int i = 1;
        while (i <= size)
        {
            int left = 2*i;
            int right = 2*i+1;
            int largest = i;
        
            if (left <= size && arr[left] > arr[largest])
                largest = left;
            if (right <= size && arr[right] > arr[largest])
                largest = right;
        
            if (largest != i)
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else
                break;
        }
    }

    void printHeapArray()
    {
        for(int i=1; i<=size; i++)
            cout << arr[i] << " | ";
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftChildIndex = 2*i;
    int rightChildIndex = 2*i+1;

    if (leftChildIndex <= n && arr[largest] < arr[leftChildIndex])
        largest = leftChildIndex;
    if (rightChildIndex <= n && arr[largest] < arr[rightChildIndex])
        largest = rightChildIndex;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

int heapSort(int arr[], int n)
{
    int size = n;

    while(size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }

}

int main()
{
    heap h;
    h.insert(70);
    h.insert(29);
    h.insert(30);
    h.insert(42);
    h.insert(86);
    h.insert(76);
    h.insert(52);
    h.insert(301);
    h.insert(402);
    h.insert(101);
    h.insert(67);
    cout << "\narray 1: ";
    h.printHeapArray();

    heap h2;
    int arr[12] = {
        -1, 70, 29, 30, 42, 86, 76, 52, 301, 402, 101, 67
    };
    int size = 11;
    for (int i = size/2; i > 0; i--) {
        heapify(arr, size, i);
    }
    cout << "\narray 2: ";
    for (int i=1; i<size; i++)
    {
        cout << arr[i] << " | ";
    }
    cout << "\n\nAfter sorting: \n\narray[1]: ";
    heapSort(h.arr, h.size);
    h.printHeapArray();
    heapSort(arr, size);
    cout << "\narray[2]: ";
    for (int i=1; i<=size; i++)
    {
        cout << arr[i] << " | ";
    }
}
