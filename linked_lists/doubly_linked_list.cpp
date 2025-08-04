#include <iostream>
using namespace std;

class node {

public:
    int data;
    node* next;
    node* prev;
    
    node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
    
public:
    node* first;

    DoublyLinkedList() {
        first = nullptr;
    }

    void insert_at_begining(int value) {
        node* nn = new node(value);
        if (first == nullptr) {
            first = nn;
        }
        else {
            node* temp = first;
            nn -> next = temp;
            temp -> prev = nn;
            first = nn;
        }
    }

    void insert_at_end(int value) {
        node* nn = new node(value);
        if (first == nullptr) {
            insert_at_begining(value);
        }
        else {
            node* temp = first;
            while (temp -> next != nullptr) {
                temp = temp -> next;
            }
            nn -> prev = temp;
            temp -> next = nn;
        }
    }

    void insert_before(int value, int target) {
        node* nn = new node(value);
        if (first == nullptr || first -> data == target) {
            insert_at_begining(value);
        }
        else {
            node* temp = first;
            while(temp -> next != nullptr && temp -> next -> data != target) {
                temp = temp -> next;
            }
            if (temp -> next == nullptr) {
                cout << "Target not found!" << endl;
                return;
            }
            nn->next = temp->next;
            nn->prev = temp;
            if (temp -> next != nullptr) {
                temp -> next -> prev = nn;
            }
            temp -> next = nn;
        }
    }

    void delete_node(int target) {
        if (first == nullptr) {
            cout << "Linked list does not exist!" << endl;
            return;
        }

        // Case 1: Delete first node
        if (first->data == target) {
            node* to_delete = first;
            first = first->next;
            if (first != nullptr) {
                first->prev = nullptr;
            }
            delete to_delete;
            return;
        }

        // Case 2: Traverse to the node to delete
        node* temp = first->next;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with value " << target << " not found!" << endl;
            return;
        }

        // Case 3: Found the node in middle or end
        temp->prev->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }


    void print() {
        node* temp = first;
        while(temp != nullptr) {
            cout << temp -> data << " "; 
            temp = temp -> next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insert_at_begining(5);
    dll.insert_at_begining(6);
    dll.insert_at_begining(7);
    dll.insert_at_begining(8);
    dll.insert_at_end(4);
    dll.insert_at_end(2);
    dll.insert_before(3, 2);
    dll.delete_node(8);
    dll.print();
    dll.delete_node(3);
    dll.print();   
}