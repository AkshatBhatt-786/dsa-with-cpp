/*
    🔹 Problem: Remove Zero Sum Consecutive Nodes from Linked List

    Input: 1 -> 2 -> 3 -> -3 -> 4
    Output: 1 -> 2 -> 4

    Logic:
    - Traverse the list and keep track of the prefix sum.
    - If the same prefix sum is seen again, it means the nodes between them sum to 0.
    - Remove those nodes.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Solution {
public:
    Node* removeZeroSumSublists(Node* head) {
        Node* dummy = new Node(0);  // dummy node to handle edge cases
        dummy->next = head;

        unordered_map<int, Node*> prefixMap;
        int prefixSum = 0;
        Node* current = dummy;

        // First pass: build prefix sum map
        while (current != nullptr) {
            prefixSum += current->data;
            prefixMap[prefixSum] = current;
            current = current->next;
        }

        // Second pass: reset and skip zero-sum ranges
        prefixSum = 0;
        current = dummy;

        while (current != nullptr) {
            prefixSum += current->data;
            current->next = prefixMap[prefixSum]->next;  // skip zero-sum range
            current = current->next;
        }

        return dummy->next;
    }

    // Utility to print linked list
    void print(Node* head) {
        while (head != nullptr) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }

    // Utility to insert node at end
    Node* insert(Node* head, int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) return newNode;

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
        return head;
    }
};

int main() {
    Solution s;
    Node* head = nullptr;

    head = s.insert(head, 1);
    head = s.insert(head, 2);
    head = s.insert(head, 3);
    head = s.insert(head, -3);
    head = s.insert(head, 4);

    cout << "Original List:\n";
    s.print(head);

    head = s.removeZeroSumSublists(head);

    cout << "After Removing Zero-Sum Sublists:\n";
    s.print(head);

    return 0;
}
