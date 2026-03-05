/* 
    Objective: Review basic data structures and algorithms in C++.
                Pointers vs. references
    Reference: This example addresses the page#3 of u03s02 C++ Basics slide.
*/

#include <iostream>

using namespace std;

int main() {
    int i = 10;
    int *ptr = &i; // note: pointer to i | equivalent to int* ptr = &i; 
    int& ref = i; // note: reference to i | equivalent to int& ref = i;

    cout << "i: " << i << endl;
    cout << "*ptr: " << *ptr << endl;  // note: here we are dereferencing the ptr pointer to get the value of i.
    cout << "ref: " << ref << endl;  // note: here we are using the reference ref to get the value of i, which is the same as using i directly.
    
    // deeper understanding:
    cout << "ptr: " << ptr << endl;  // note: ptr = address of i in memory => because &i stands for address of i in memory.
    cout << "&i: " << &i << endl;
    cout << "&ref: " << &ref << endl;


    // even deeper:
    *ptr = 20;    
    cout << "i after modifying through ptr: " << i << endl; // note: here we are modifying the value of i through the pointer ptr by dereferencing it and assigning a new value to it.
    cout << "ptr: " << ptr << endl;  // note: ptr still holds the same address of i in memory, but the value at that address has been modified to 20.

    ref = 30; // IMPORTANT: reference stands for alias for it, meaning that ref is just another name for i. So when we assign a new value to ref, it directly modifies i because ref is essentially the same variable as i.
    cout << "i after modifying through ref: " << i << endl;  

    return 0;
}