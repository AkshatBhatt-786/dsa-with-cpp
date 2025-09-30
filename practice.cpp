#include <iostream>
#include <list>
#include <vector>

using namespace std;

int hashFunction(int key, int tableSize)
{
    return key % tableSize;
}

bool searchElement(vector<list<int>> &hashTable, int data, int tableSize)
{
    int key = hashFunction(data, tableSize);
    for(int search: hashTable[key])
    {
        if (search == data)
            return true;
    }
    return false;
}

void insertElement(vector<list<int>> &hashTable, int data, int tableSize)
{
    int key = hashFunction(data, tableSize);
    hashTable[key].push_back(data);
}

bool deleteElement(vector<list<int>> &hashTable, int data, int tableSize)
{
    int key = hashFunction(data, tableSize);
    int target = data;
    for(int idx: hashTable[key])
    {
        if (idx == target)
            hashTable[key].remove(target);
            return true;
    }
    return false;
}

void printElements(vector<list<int>> &hashTable, int tableSize)
{
    for(int i=0; i<tableSize; i++)
    {
        cout << "Bucket " << i << ": ";
        for(int el : hashTable[i])
        {
            cout << el << " ";
        }
        cout << endl;
    }
}

int main()
{
    int tableSize = 7;
    vector<list<int>> hashTable(tableSize);
    insertElement(hashTable, 21, tableSize);
    insertElement(hashTable, 12, tableSize);
    insertElement(hashTable, 10, tableSize);
    insertElement(hashTable, 9, tableSize);
    insertElement(hashTable, 128, tableSize);
    insertElement(hashTable, 242, tableSize);
    printElements(hashTable, tableSize);
    cout << "20 : " << (searchElement(hashTable, 20, tableSize) ? "present" : "not present") << endl;
    cout << "242 : " << (searchElement(hashTable, 242, tableSize) ? "present" : "not present") << endl;
    cout << "242 : " << (deleteElement(hashTable, 242, tableSize) ? "deleted successfully" : "not found.") << endl;
    printElements(hashTable, tableSize);
}