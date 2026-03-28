/**
 * @file ex19.cpp
 * @author Salar Farahmand
 * @brief 
 *          Objective: C++ Basics > class
 *          Reference: #19 of u03s04
 * @version 0.1
 * @date 2026-03-14
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <iostream>
#include <string>

using namespace std;

class MyClass {
    private:
        int value;
    public:
        MyClass(int value) { // default constructor
            this->value = value; // note: this is a pointer to the class, distinguishable by -> operator than data members.
        }
        MyClass& increment() {
            this->value++;
            return *this; // note: method chaining, meaning that we are referring to current object.
        }
    
};

int main() {
    MyClass obj(10);
    obj.increment().increment(); // output: 12

    return 0;   
 }