/**
 * @file ex6.cpp
 * @author Salar Farahmand
 * @brief 
 *          Objective: Cpp basics.
 *          Reference: This example addresses the page#30 of u03s02 C++ Basics slide.
 * @version 0.1
 * @date 2026-03-07
 * 
 * @copyright Copyright (c) 2026
 * 
 */


#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    // TODO: CV-qualifiers
    const int i = 10; // note: const must be initialized.
    //i = 20; // x ERROR, because i is a constant and cannot be modified after initialization.
    
    int v1 = 5;
    int *const p1 = &v1; // top-level constant.
    float v2 = 3.14;
    const float *p2 = &v2; // low-level constant.
    //const double *const pi = 3.14; // constant pointer to a constant object

    volatile int i = 100;
    while (i == 100) { // note: here compiler avoid optimizations => re-read the value always from memory.
        // do something
    }

    // no volatile
    int j = 200;
    while (j == 200) { // note: here compiler may optimize the code by assuming that j will never change, which can lead to an infinite loop if j is modified by another thread or interrupt.
                        // compiler may be tempted to change the while construct into while(true).
        // do something
    }


    return 0;
}