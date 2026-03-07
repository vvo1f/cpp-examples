/**
 * @file ex3.cpp
 * @author Salar Farahmand
 * @brief 
 *          Objective: Cpp basics.
 *          Reference: This example addresses the page#10 of u03s02 C++ Basics slide.
 * @version 0.1
 * @date 2026-03-07
 * 
 * @copyright Copyright (c) 2026
 * 
 */


#include <iostream>


int main(int argc, char** argv) {

    // TODO: Console I/O
    int sum = 0 , value = 0;

    while (std::cin >> value) { // note: press end-of-line (CTRL+z or CTRL+d) to make the condition false and exit the loop.
        sum += value;
        std::cout << "sum: " << sum << std::endl; // note: std::endl => new line then flushes the buffer.
    }

    std::cout << "Final sum: " << sum << std::endl;    


    return 0;
}