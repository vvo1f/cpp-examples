/**
 * @file ex14.cpp
 * @author Salar Farahmand
 * @brief 
 *          Topic: C++ Basics > class
 *          Reference: #14 of u03s04
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
        int myNum;
        string myString;
};


 int main() {
    my_class myObj;
    // access atrributes and set values
    myObj.myNum = 15;
    myObj.myString = "Some text";

    // print
    cout << "myObj.myNum: " << myObj.myNum << "\n";
    cout << "myObj.myString: " << myObj.myString;

    return 0;   
 }