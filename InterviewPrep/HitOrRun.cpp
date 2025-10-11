#include <iostream>
using namespace std;

class Coach {
public:
    int coachId;
    Coach* prev;
    Coach* next;

    Coach(int d) {
        coachId = d;
        prev = next = nullptr;
    }
};

class Train {
public:
    Coach* head;
    Coach* tail;

    Train() {
        head = tail = nullptr;
    }

    void insertCoach(int id) {
        Coach* newCoach = new Coach(id);
        if (head == nullptr) {
            head = tail = newCoach;
            return;
        }
        tail->next = newCoach;
        newCoach->prev = tail;
        tail = newCoach;
    }

    void startGame(int target) {
        if (head == nullptr) return;

        Coach* temp = head;
        while (temp != nullptr && temp->coachId != target)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Target not found!" << endl;
            return;
        }

        if (temp->coachId % 2 == 0) {  // even → detach next
            if (temp->next != nullptr) {
                Coach* toDelete = temp->next;
                temp->next = toDelete->next;
                if (toDelete->next != nullptr)
                    toDelete->next->prev = temp;
                else
                    tail = temp;
                delete toDelete;
                cout << "Detached next coach after " << temp->coachId << endl;
            } else {
                cout << "No coach to detach after " << temp->coachId << endl;
            }
        } else {  // odd → insert before
            Coach* newCoach = new Coach(999);
            newCoach->next = temp;
            newCoach->prev = temp->prev;

            if (temp->prev != nullptr)
                temp->prev->next = newCoach;
            else
                head = newCoach; // inserted before head

            temp->prev = newCoach;

            cout << "Inserted 999 before " << temp->coachId << endl;
        }
    }

    void print() {
        Coach* c = head;
        while (c != nullptr) {
            cout << "[" << c->coachId << "]";
            if (c->next != nullptr) cout << " <-> ";
            c = c->next;
        }
        cout << endl;
    }
};

int main() {
    Train t;
    t.insertCoach(12);
    t.insertCoach(6);
    t.insertCoach(8);
    t.insertCoach(9);
    t.insertCoach(10);

    cout << "Original Train: ";
    t.print();

    t.startGame(6);  // even → detach next
    cout << "After operation: ";
    t.print();

    t.startGame(9);  // odd → insert before
    cout << "After operation: ";
    t.print();
}
