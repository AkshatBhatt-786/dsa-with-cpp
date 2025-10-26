#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void swapAlternate(int arr[], int size) {
    for(int i=0; i<size; i+=2)
    {
        if(i+1 < size) {
            swap(arr[i], arr[i+1]);
        }
    }
}

int main()
{
    int even[8] = {1, 6, 2, 4, 5, 3, 2, 1};
    int odd[5] = {11, 23, 12, 53, 23};
    swapAlternate(even, 8);
    swapAlternate(odd, 5);
    printArray(even, 8);
    printArray(odd, 5);
}