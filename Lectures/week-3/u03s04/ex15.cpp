/**
 * @file ex15.cpp
 * @author Salar Farahmand
 * @brief 
 *          Objective: C++ Basics > class
 *          Reference: #15 of u03s04
 * @version 0.1
 * @date 2026-03-14
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <iostream>
#include <string>

using namespace std;

class Car {
    public:
        string brand;
        string model;
        int year;
};


 int main() {
    Car car1;
    car1.brand = "BMW";
    car1.model = "X5";
    car1.year = 1999;
    Car car2;
    car2.brand = "Ford";
    car2.model = "Mustang";
    car2.year = 1969;

    cout << car1.brand << " " << car1.model << " " << car1.year << "\n";
    cout << car2.brand << " " << car2.model << " " << car2.year << "\n";

    return 0;   
 }