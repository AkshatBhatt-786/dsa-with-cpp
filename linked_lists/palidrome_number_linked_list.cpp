#include <iostream>
using namespace std;

struct ListNode {   
    int value;
    ListNode *next;
    ListNode(int x) {
        value = x;
        next = nullptr;
    } 
};

class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;

        // Step 1: Find the middle
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Step 3: Compare both halves
        ListNode *firstHalf = head;
        ListNode *secondHalf = prev;
        while (secondHalf) {
            if (firstHalf->value != secondHalf->value) return false;
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};

// Helper function to insert a node at the end
void append(ListNode*& head, int val) {
    if (!head) {
        head = new ListNode(val);
        return;
    }
    ListNode* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new ListNode(val);
}

int main() {
    Solution sol;
    ListNode* head = NULL;

    int n, val;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter list values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        append(head, val);
    }

    if (sol.isPalindrome(head))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
