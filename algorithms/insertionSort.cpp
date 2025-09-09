#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    int i = 1;
    while (i < n) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        i++;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = 5;

    cout << "Array before sorting: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Array after sorting: ";
    printArray(arr, n);

    return 0;
}   