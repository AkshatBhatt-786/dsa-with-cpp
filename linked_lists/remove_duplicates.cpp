#include <iostream>
using namespace std;

/*
    🔹 Problem: Remove Duplicates from Sorted Linked List
    Given a sorted singly linked list, remove duplicates such that each element appears only once.
*/

class node {
public:
    int data;
    node* next;
    node(int d) {
        data = d;
        next = nullptr;
    }
};

class Solution {
public:
    node* first;
    
    Solution() {
        first = nullptr;
    }

    void insert(int x) {
        node* nn = new node(x);
        if (first == nullptr) {
            first = nn;
            return;
        }
        node* temp = first;
        int count = 1;
        while(temp->next != nullptr) {
            temp = temp->next;
            count++;
        }
        if (count < 100) {
            temp->next = nn;
        } else {
            cout << "Linked list is full!" << endl;
        }
    }

    void remove_duplicates() {
        node* temp = first;
        while(temp && temp->next) {
            if (temp->data == temp->next->data) {
                temp->next = temp->next->next; // Skip duplicate
            } else {
                temp = temp->next;
            }
        }
    }

    void print() {
        node* temp = first;
        int count = 0;
        if (!temp) {
            cout << "Linked list is empty!" << endl;
            return;
        }
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
            count++;
        }
        cout << "\nSize: " << count << endl;
    }
};

int main() {
    Solution s;
    s.insert(10);
    s.insert(20);
    s.insert(20);
    s.insert(25);
    s.insert(28);
    s.insert(28);
    s.insert(30);

    cout << "Original List:\n";
    s.print();

    s.remove_duplicates();

    cout << "After Removing Duplicates:\n";
    s.print();

    return 0;
}
