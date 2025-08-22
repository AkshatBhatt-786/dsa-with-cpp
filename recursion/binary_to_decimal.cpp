#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int binary_to_decimal(const string &bin, int index) {
    if (index == bin.size()) 
        return 0;
    return (bin[index] - '0') * pow(2, bin.size() - index - 1) 
           + binary_to_decimal(bin, index + 1);
}

int main() {
    string binary = "1001";
    cout << "Decimal: " << binary_to_decimal(binary, 0) << endl;
    return 0;
}
