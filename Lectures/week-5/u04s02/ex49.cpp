/**
 * @file ex49.cpp
 * @author Salar Farahmand
 * @brief 
 *          Topic: C++ Library > Sequential containers
 *          Reference: #49 of u04s02
 * @version 0.1
 * @date 2026-03-28
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
    vector<int> vi;
    vector<string> vs;
    string s="foo";

    for (int i=0; i<100; i++) {
        vi.push_back(i);
        vs.push_back(s);
    }

    cout << "final vi elements: ";
    for (const auto& i : vi) {
        cout << i << " ";
    }
    cout << "\n";
    
    cout << "final vs elements: ";
    for (const auto& str : vs) {
        cout << str << " ";
    }

    
    return 0;   
 }