/**
 * @file ex22.cpp
 * @author Salar Farahmand
 * @brief 
 *          Topic: C++ Library > Generic Algorithms
 *          Reference: #45 of u04s04
 * @description
 * Exam's Ecercise

    @proposed-output
        123.456.789-00#1234567890


 * @version 0.1
 * @date 2026-04-04
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#include<iostream>
#include <string>
#include <list>
#include <vector>


int main() {
    auto lambda = []( std::string h )->bool{

        return ( h != "-" && h != "." );
    };

    std::string s("123.456.789-00");
    std::vector<std::string> num;
    for (int i=0; i<static_cast<int>(s.length());i++) {
        num.push_back( s.substr(i, 1) );
    }
    std::cout << s << "#";
    for( auto z : num ) {
        if (lambda(z)) std::cout << z;
    };
    std::cout << '\n';
    return 0;

}