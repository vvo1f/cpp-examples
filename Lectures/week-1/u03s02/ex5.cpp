/**
 * @file ex5.cpp
 * @author Salar Farahmand
 * @brief 
 *          Objective: Cpp basics.
 *          Reference: This example addresses the page#26 of u03s02 C++ Basics slide.
 * @version 0.1
 * @date 2026-03-07
 * 
 * @copyright Copyright (c) 2026
 * 
 */


#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    // TODO: Pointers/References
    int *ptr = nullptr; // note: This is the proper definition with initialization. (avoid segmentation fault by addressing to a invalid memory space e.g. OS)

    int i = 0;
    //int &wrongint_r; // x ERROR, because references require initilizer.
    //int &wrong_r = 10; // x ERROR, because references required object initializer (variables), not literal initializer (values).

    float f;
    //int &rf = f; // x ERROR, because reference type must be matched.
    
    int &r2 = i;
    // &r2 = i; // x ERROR, because reference is an alias for the variable it references, so it cannot be reassigned to reference another variable. 

    return 0;
}