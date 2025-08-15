#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head; // Base case
    ListNode* first = head;
    ListNode* second = head->next;

    first->next = swapPairs(second->next); // Recursively swap next pairs
    second->next = first;                  // Swap current pair

    return second; // New head
}

int main() {
    // Creating linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    head = swapPairs(head);

    // Printing swapped list
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    // Output: 2 1 4 3
}
