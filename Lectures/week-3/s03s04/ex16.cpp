/**
 * @file ex16.cpp
 * @author Salar Farahmand
 * @brief 
 *          Objective: C++ Library > class
 *          Reference: #16 of u03s04
 * @version 0.1
 * @date 2026-03-14
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <iostream>
#include <string>

using namespace std;

class my_class {
    public:
        void my_method();
};

// method definiton outside of the class
void my_class::my_method() {
    cout << "Hello world!";
}


 int main() {
    my_class my_obj;
    my_obj.my_method();


    return 0;   
 }