#include <iostream>
using namespace std;

// Function to move disks
void towerOfHanoi(int n, char source, char destination, char helper, int &steps) {
    // If there is only 1 disk, move it directly
    if (n == 1) {
        steps ++;
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    // Step 1: Move (n-1) disks from source to helper
    towerOfHanoi(n - 1, source, helper, destination, steps);

    // Step 2: Move the biggest disk (nth disk) from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // Step 3: Move (n-1) disks from helper to destination
    towerOfHanoi(n - 1, helper, destination, source, steps);
}

int main() {
    int n, steps=1;
    cout << "Enter number of disks: ";
    cin >> n;

    cout << "\nSteps to solve Tower of Hanoi:\n";
    // A = starting rod, C = ending rod, B = helper rod
    towerOfHanoi(n, 'A', 'C', 'B', steps);
    cout << "No of steps required to finish: " << steps;

    return 0;
}
