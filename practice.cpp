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
    cout << "Heap Array: ";
    cout << endl;
    h.printHeapArray();
    cout << "\nAfter deleting root node: ";
    cout << endl;
    h.deleteRootNode();
    h.printHeapArray();
}
