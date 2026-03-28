/**
 * @file ex17.cpp
 * @author Salar Farahmand
 * @brief 
 *          Topic: C++ Basics > class
 *          Reference: #17 of u03s04
 * @version 0.1
 * @date 2026-03-14
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <iostream>
#include <string>

using namespace std;

class Employee {
    private:
        int salary;
    public:
        // setter
        void setSalary(int s) {
            salary = s;
        }
        // getter
        int getSalar() {
            return salary;
        }
};

int main() {
    Employee myObj;
    myObj.setSalary(5000);

    cout << myObj.getSalar() << "\n";


    return 0;   
 }