#include <iostream>
#include "rang.hpp"
using namespace std;

class Node {

public:
    int val;
    Node* next;

    Node(int d) {
        val = d;
        next = NULL;
    }
};

class SinglyLinkedList {
    
public:
    Node* head;
    Node* tail;

    SinglyLinkedList() {
        head = tail = NULL;
    }

    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }      
        Node* temp = head;
        newNode -> next = temp;
        head = newNode;
    }

    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        if (tail == NULL && head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void printLinkedList()
    {
        Node* temp = head;
        while(temp != NULL) {
            cout << rang::fg::green << rang::style::bold << temp -> val << rang::style::blink << " | " << rang::style::reset;
            temp = temp -> next;
        }
        cout << endl;
    }
};

int main()
{
    SinglyLinkedList sll;
    sll.insertAtHead(10);
    sll.insertAtTail(20);
    sll.insertAtTail(30);
    sll.insertAtHead(8);
    sll.insertAtHead(5);
    sll.printLinkedList();
}