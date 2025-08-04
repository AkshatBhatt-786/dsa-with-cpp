#include <iostream>
using namespace std;

class node {

public:
    int data;
    node* next;
    node(int value) {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList {

    node* first;

public:
    SinglyLinkedList() {
        first = nullptr;
    }

    void insert_at_beginning(int value) {
        
        // if linked list does not exists!
        if (first == nullptr) {
            node* first_node = new node(value);
            first = first_node;
            return;
        } // if linked list exists!
        else {
            node* new_node = new node(value);
            new_node -> next = first;
            first = new_node;
        }
    }

    void insert_at_end(int value) {
        // if linked list does not exists!
        if (first == nullptr) {
            insert_at_beginning(value);
            return;
        } else { // if linked list exists!
            // traversing till last node
            node* temp = first;
            node* new_node = new node(value);
            while (temp->next != nullptr) {
                temp = temp -> next;
            }
            temp -> next = new_node;
        }
    }

    void insert_in_between(int value, int target) {
        node* nn = new node(value);
        if (first == nullptr || first -> data == target) {
            insert_at_beginning(value);
            return;
        }
        else{ // linked list exists!
            // traversing list until hitting the target and last node
            node* temp = first;
            while (temp -> next != nullptr && temp -> next -> data != target) {
                temp = temp -> next;
            }
            if (temp -> next == nullptr) {
                cout << target << " not found!" << endl;
                return;
            }
            nn -> next = temp -> next;
            temp -> next = nn;
        }
    }

    void insert_at_position(int value, int pos) {
        if (first == nullptr || pos == 1) {
            insert_at_beginning(value);
            return;
        }
        if (pos <= 0) {
            cout << "Position should be >= 1\n";
            return;
        }
        int curr_pos = 1;
        node* nn = new node(value);
        node* temp = first;
        while(temp != nullptr && curr_pos < pos - 1) {
            temp = temp -> next;
            curr_pos ++;
        }
        nn -> next = temp -> next;
        temp -> next = nn;
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
            delete to_delete;
            return;
        }

        // Case 2: Find node before target
        node* temp = first;
        while (temp->next != nullptr && temp->next->data != target) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Target not found!" << endl;
            return;
        }

        // Case 3: Found node to delete
        node* to_delete = temp->next;
        temp->next = to_delete->next;
        delete to_delete;
    }


    void print(string message="") {
        if (first == nullptr) {
            cout << "Linked List is empty!" << endl;
            return;
        }
        node* temp = first;
        cout << message;
        while(temp != nullptr) {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList sll;
    sll.insert_at_beginning(20);
    sll.print("Insert At Beginning (20): ");
    sll.insert_at_end(30);
    sll.print("Insert At End (30): ");
    sll.insert_at_beginning(10);
    sll.print("Insert At Beginning (10): ");
    sll.insert_in_between(15, 10);
    sll.print("Insert At Between (value=15) at (target=10): ");
    sll.insert_in_between(40, 20);
    sll.print("Insert At Between (value=40) at (target=20): ");
    sll.insert_at_position(17, 3);
    sll.print("Insert At Position (3) (value=17): ");
    sll.delete_node(10);
    sll.print("Deleting node with value (10): ");
    return 0;
}