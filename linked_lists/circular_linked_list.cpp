#include <iostream>
using namespace std;

class cnode {
public:
    int data;
    cnode* next;

    cnode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class CircularLinkedList {
    cnode* first;

public:
    CircularLinkedList() {
        first = nullptr;
    }

    void insert_at_beginning(int data) {
        cnode* nn = new cnode(data);
        if (first == nullptr) {
            first = nn;
            nn->next = first;
            return;
        }

        cnode* temp = first;
        while (temp->next != first) {
            temp = temp->next;
        }

        nn->next = first;
        temp->next = nn;
        first = nn;
    }

    void insert_at_end(int data) {
        if (first == nullptr) {
            insert_at_beginning(data);
        }
        else {
            cnode* nn = new cnode(data);
            cnode* temp = first;

            while(temp -> next != first) {
                temp = temp -> next;
            }
            temp -> next = nn;
            nn -> next = first;
        }
    }

    void insert_before(int data, int target) {
        if (first == nullptr) {
            cout << "List is empty. Cannot insert before " << target << endl;
            return;
        }

        cnode* curr = first;
        cnode* prev = nullptr;

        // Case: Insert before first node
        if (first->data == target) {
            insert_at_beginning(data);
        }

        // Case: Insert before a node that is not the first
        do {
            prev = curr;
            curr = curr->next;

            if (curr->data == target) {
                cnode* nn = new cnode(data);
                nn->next = curr;
                prev->next = nn;
                return;
            }
        } while (curr != first);

        cout << "Target " << target << " not found in the list." << endl;
    }


    void insert_after(int data, int target) {
        if (first == nullptr) {
            cout << "List is empty. Cannot insert after " << target << endl;
            return;
        }

        cnode* temp = first;
        do {
            if (temp->data == target) {
                cnode* nn = new cnode(data);
                nn->next = temp->next;
                temp->next = nn;
                return;
            }
            temp = temp->next;
        } while (temp != first);

        cout << "Target " << target << " not found in the list." << endl;
    }


    void display() {
        if (first == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        cnode* temp = first;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != first);
        cout << "(back to start)" << endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insert_at_beginning(30);
    cll.insert_at_beginning(20);
    cll.insert_at_beginning(10);
    cll.insert_at_end(40);
    cll.insert_at_end(50);
    cll.insert_after(35, 30);
    cll.insert_after(25, 20);
    cll.insert_before(45, 50);
    cll.insert_before(15, 20);
    cll.display();

    return 0;
}
