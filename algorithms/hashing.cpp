#include <iostream>
#include <vector>
#include <list>

using namespace std;


int hashFunction(int key, int tableSize) 
{
    int hashValue = key % tableSize;
    cout << "Hash Function: " << hashValue << endl;
    return hashValue;
}


bool searchElement(vector<list<int>> hashTable, int key, int tableSize)
{
    int hashValue = key % tableSize;
    for(int i: hashTable[hashValue])
    {
        if (i == key)
            return true;
    }
    return false; 
}

int main() 
{
    int tableSize = 10;
    vector<list<int>> hashTable(tableSize);

    int keysToInsert[] = {15, 25, 35, 10, 20, 30, 26, 38, 9, 19, 39, 49, 29, 99, 999, 899, 799, 699, 599, 499, 399, 389};
    for (int key : keysToInsert)
     {
        int idx = hashFunction(key, tableSize);
        hashTable[idx].push_back(key);
    }

    int keyToDelete = 25;
    int idx = hashFunction(keyToDelete, tableSize);
    hashTable[idx].remove(keyToDelete);

    cout << "Hash Table contents:\n";
    for (int i = 0; i < tableSize; ++i) 
    {
        cout << "Bucket " << i << ": ";
        for (int val : hashTable[i]) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}