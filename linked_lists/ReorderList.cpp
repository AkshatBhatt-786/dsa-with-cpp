#include <iostream>
using namespace std;

/*
    Problem: Reorder List
    Given a singly linked list, reorder it as:
    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...

    Input: 1 → 2 → 3 → 4 → 5
    Output: 1 → 5 → 2 → 4 → 3

    Approach:
    1. Find middle node (slow/fast pointer)
    2. Reverse the second half
    3. Merge both halves alternately
*/

class node {
public:
    int data;
    node* next;

    node(int x) {
        data = x;
        next = nullptr;
    }
};

class Solution {
public:
    node* head;
    node* tail;

    Solution() {
        head = tail = nullptr;
    }

    void insert(int x) {
        node* nn = new node(x);
        if (head == nullptr) {
            head = tail = nn;
            return;
        }
        tail->next = nn;
        tail = nn;
    }

    void print() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reorder_list() {
        if (!head || !head->next || !head->next->next) return;

        // Step 1: Find middle
        node* slow = head;
        node* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        node* prev = nullptr;
        node* curr = slow->next;
        while (curr) {
            node* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }

        slow->next = nullptr; // break the list into two

        // Step 3: Merge both halves
        node* first = head;
        node* second = prev;
        while (second) {
            node* temp1 = first->next;
            node* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};

int main() {
    Solution s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    cout << "Before Reordering:\n";
    s.print();

    s.reorder_list();

    cout << "After Reordering:\n";
    s.print();

    return 0;
}
