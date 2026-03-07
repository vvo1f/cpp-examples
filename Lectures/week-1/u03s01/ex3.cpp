/**
 * @file ex3.cpp
 * @author Salar Farahmand
 * @brief 
 *          Objective: 
                Example#2
 *          Reference: This example addresses the page#37 of u03s01 Introduction to C++ slide.
 * @version 0.1
 * @date 2026-03-07
 * 
 * @copyright Copyright (c) 2026
 * 
 */


#include <string>
#include <vector>
#include <iostream>


using namespace std;

int main() {
    vector<string> v;
    string s2 = "one";
    v.push_back(s2);
    s2 = "two";
    v.push_back(s2);
    s2 = "three";
    v.push_back(s2);

    for(int i = 0; i < v.size(); ++i) {
        cout << " " << v[i] << endl;
    }

    return 0;
}
    