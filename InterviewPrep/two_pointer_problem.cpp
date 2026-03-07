#include <iostream>
#include <algorithm>
using namespace std;

int findPlatforms(int arr[], int dep[], int n) {

    sort(arr, arr + n);
    sort(dep, dep + n);

    int plat_needed = 1, maxPlat = 1;
    int i = 1, j = 0;

    while(i < n && j < n) {

        if(arr[i] <= dep[j]) {
            plat_needed++;
            i++;
        }
        else {
            plat_needed--;
            j++;
        }

        maxPlat = max(maxPlat, plat_needed);
    }

    return maxPlat;
}

int main() {
    int arr[] = {900,940,950,1100,1500,1800};
    int dep[] = {910,1200,1120,1130,1900,2000};
    int n = 6;

    cout << findPlatforms(arr, dep, n);
}