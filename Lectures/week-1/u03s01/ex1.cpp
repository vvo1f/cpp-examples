/*
    note: this file has been linked to example of ex1.h file.
*/

#include "ex1.h"


int MyClass::doWork() {
    ptr = new char[100]; // note: here we are allocating memory for a character array of size 100 and assigning the address of the allocated memory to the pointer ptr.
    // do some work with ptr
    delete[] ptr; // note: here we are deallocating the memory => prevent memory leaks.
    return 0;
}