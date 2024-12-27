#include <iostream>
using namespace std;

void incrementByAddress(int *p) {
    (*p)++; // Dereference the pointer and increment the value
}

void incrementByReference(int &r) {
    r++; // Increment the value directly
}

void incrementByValue(int v) {
    v++; // Increment the value
}

int main() {
    int value = 10;
    cout << "Before increment: " << value << endl; // Output: 10

    incrementByAddress(&value); // Pass the address of the variable
    cout << "After increment by address: " << value << endl; 

    incrementByReference(value); // Pass the variable by reference
    cout << "After increment by reference: " << value << endl; 

    incrementByValue(value); // Pass the variable by value
    cout << "After increment by value: " << value << endl;
    
    return 0;
}