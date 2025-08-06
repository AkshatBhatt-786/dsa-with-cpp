#include <iostream>
using namespace std;

class term {
public:
    int coeff;
    int expo;
    term* next;

    term(int coeff, int expo) {
        this->coeff = coeff;
        this->expo = expo;
        next = nullptr;
    }
};

class poly {

public:
    term* first;

    poly() {
        first = nullptr;
    }

    void insert_term(int coeff, int expo) {
        term* nn = new term(coeff, expo);
        if (first == nullptr) {
            first = nn;
            return;
        }
        term* temp = first;
        while(temp -> next != nullptr) {
            temp = temp -> next;
        }
        temp -> next = nn;
    }

    poly static add_poly(term* ptr1, term* ptr2) {
        poly p3;
        while (ptr1 != nullptr && ptr2 != nullptr) {
            if (ptr1 -> expo > ptr2 -> expo) {
                p3.insert_term(ptr1-> coeff, ptr1 -> expo);
                ptr1 = ptr1 -> next;
            }
            else if (ptr1 -> expo < ptr2 -> expo) {
                p3.insert_term(ptr2 -> coeff, ptr2 -> expo);
                ptr2 = ptr2 -> next;
            }
            else {
                int sum = ptr1 -> coeff + ptr2 -> coeff;
                if (sum != 0) p3.insert_term(sum, ptr1->expo);
                ptr1 = ptr1 -> next;
                ptr2 = ptr2 -> next;
            }
        }
        while(ptr1 != nullptr) {
            p3.insert_term(ptr1 -> coeff, ptr1 -> expo);
            ptr1 = ptr1 -> next;
        }
        while (ptr2 != nullptr) {
            p3.insert_term(ptr2 -> coeff, ptr2 -> expo);
            ptr2 = ptr2 -> next;
        }

        return p3;
    }

    void display() {
        if (first == nullptr) {
            cout << "Linked list does not exists!";
            return;
        }
        term* temp = first;
        while(temp != nullptr) {
            cout << "(" << temp -> coeff << ", " << temp -> expo << ") ";
            temp = temp -> next;
        }
        cout << endl;
    }
};

int main() {
    poly p1, p2, p3;
    p1.insert_term(3, 2);
    p1.insert_term(2, 1);
    p1.insert_term(6, 0);
    p1.display();
    p2.insert_term(4, 2);
    p2.insert_term(1, 1);
    p2.insert_term(7, 0);
    p2.display();
    p3 = p3.add_poly(p1.first, p2.first);
    p3.display();
}
