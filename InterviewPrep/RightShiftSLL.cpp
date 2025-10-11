#include <iostream>
using namespace std;

/*
Problem:
A company has a list of employees scheduled to work in a cyclic shift pattern.
At the start of each week, the manager rotates the employee list by k positions
to the right, so that the last k employees now appear at the beginning.

Example:
Employees: A → B → C → D → E
Shift = 2
New Schedule: D → E → A → B → C
*/

class ShiftNode {
public:
    char EmployeeId;
    ShiftNode* nextShift;

    ShiftNode(char val) {
        EmployeeId = val;
        nextShift = nullptr;
    }
};

class CyclicShiftProblem {
private:
    ShiftNode* head;
    int totalEmployees;

public:
    CyclicShiftProblem() {
        head = nullptr;
        totalEmployees = 0;
    }

    void addEmployee(char id) {
        ShiftNode* newEmp = new ShiftNode(id);
        if (head == nullptr) {
            head = newEmp;
        } else {
            ShiftNode* temp = head;
            while (temp->nextShift != nullptr)
                temp = temp->nextShift;
            temp->nextShift = newEmp;
        }
        totalEmployees++;
    }

    void printSchedule() {
        ShiftNode* temp = head;
        while (temp != nullptr) {
            cout << temp->EmployeeId;
            if (temp->nextShift != nullptr) cout << " -> ";
            temp = temp->nextShift;
        }
        cout << endl;
    }

    void rotateRight(int k) {
        if (!head || k == 0 || totalEmployees <= 1)
            return;

        k = k % totalEmployees; // 
        if (k == 0) return;

        // Find the last node (tail)
        ShiftNode* tail = head;
        while (tail->nextShift != nullptr)
            tail = tail->nextShift;

        // Connect tail to head temporarily
        tail->nextShift = head;

        // Find new tail (after totalEmployees - k steps)
        int stepsToNewTail = totalEmployees - k;
        ShiftNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++)
            newTail = newTail->nextShift;

        // Set new head
        head = newTail->nextShift;

        // Break the cycle
        newTail->nextShift = nullptr;
    }
};

int main() {
    CyclicShiftProblem company;

    company.addEmployee('A');
    company.addEmployee('B');
    company.addEmployee('C');
    company.addEmployee('D');
    company.addEmployee('E');

    cout << "Original Schedule: ";
    company.printSchedule();

    int k = 3;
    company.rotateRight(k);

    cout << "After rotating by " << k << " positions: ";
    company.printSchedule();

    return 0;
}
