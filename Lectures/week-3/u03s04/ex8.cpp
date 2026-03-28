/**
 * @file ex8.cpp
 * @author Salar Farahmand
 * @brief 
 *          Objective: C++ Basics > struct
 *          Reference: #8 of u03s04
 * @version 0.1
 * @date 2026-03-14
 * 
 * @copyright Copyright (c) 2026
 * 
 */

// version 1

 #include <iostream>
 

struct my_class { // Remember: struct and class are almost the same in C++, except that struct members are public by default, while class members are private by default.
    int code;

    int get_code() {
        return (code);
    }

    void print_code();
};

void my_class::print_code() {
    std::cout << code << std::endl;
}

 int main() {
    my_class obj;
    obj.code = 10;
    std::cout << "obj.get_code(): " << obj.get_code() << std::endl;
    obj.print_code();

    return 0;
 }