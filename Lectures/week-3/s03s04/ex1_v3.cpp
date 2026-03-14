/**
 * @file ex1_v2.cpp
 * @author Salar Farahmand
 * @brief 
 *          Objective: C++ Library > struct
 *          Reference: #13 of u03s04
 * @version 0.1
 * @date 2026-03-14
 * 
 * @copyright Copyright (c) 2026
 * 
 */

// version 3

 #include <iostream>
 

class my_class { // Remember: struct and class are almost the same in C++, except that struct members are public by default, while class members are private by default.
    // note: by declaring public and private we leverage the encapsulation feature of OOP, which allows us to control the access to the members of the class.
    private:
    int code;

    public:
    int get_code() {
        return (code);
    }

    void print_code();
}; // note: here we end the class definition with a semicolon.

void my_class::print_code() {
    std::cout << code << std::endl;
}

 int main() {
    my_class obj;
    //obj.code = 10; // xxx error: private members are not accessible directly.
    std::cout << "obj.get_code(): " << obj.get_code() << std::endl; // note: here since we didn't initialize the code member, we get strange number of 32767, which is the maximum value of a signed 16-bit integer. 
                                                                    // This is because the code member is not initialized and contains garbage value, 
                                                                    // meaning that it holds whatever value happens to be at that memory location, which in this case is 32767.
                                                                    // note: always get same value of 32767 because the code member is stored in the same memory location every time we run the program, and that memory location happens to contain the value 32767 when we access it without initializing it.
    obj.print_code();

    return 0;
 }