/**
 * @file ex42.cpp
 * @author Salar Farahmand
 * @brief 
 *          Topic: C++ Library > Sequential containers
 *          Reference: #42 of u04s02
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
    std::vector<std::string> v = {"one","two","three","four"}; // note: we have 4 strings in the vector, meaning that the size of the vector is 4, and the indices of the elements are 0, 1, 2, and 3.

    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << "current it: " << *it << "\n";
        cout << "current it size: " << it->size() << "\n";
        // note: It means that we are checking the size of the string that the iterator is pointing to, and if it is equal to 3, we insert "foo" before it.
        if (it->size() == 3) {  // note: it->size()==3 is indicating elements: "one" and "two", which are the first and second elements of the vector, respectively.
                                // note: we enter this if statement twice, once for "one" and once for "two", and we insert "foo" before each of them, meaning that we will have two "foo" strings in the vector after the loop.
            it = v.insert(it,"foo");
            cout << "current it after insert: " << *it << "\n";
            // it now points to the newly inserted element
            ++it;
        }
    }

    cout << "=> v after first loop: "; // output: {"foo", "one", "foo", "two", "three", "four"}
    for (const auto& str : v) {
        cout << str << " ";
    }
    cout << "\n";


    for (auto it = v.begin(); it != v.end(); ++it) {
        if (it->size() == 3) { // note: point a breadkpoint here for clear debugging the problem.
            cout << "current it before erase: " << *it << "\n";
            it = v.erase(it);
            cout << "current it after erase: " << *it << "\n";
            // *** IMPORTANT ***
            // erase returns a new, valid iterator
            // pointing to the next element

            // * workflow:
            // - first iteration, it points to "foo"
            // 1. check the size of string, "foo" enters the condition.
            // 2. erase "foo" and the new iterator will point to "one"
            // - second iteration, it points to second "foo" in v (remember: we have ++it in the structure of loop state)
            // 1. check the size of string, "foo" enters the condition.
            // 2. erase "foo" and the new iterator will point to "two"
            // - third iteration, ++it will point to "three", which does not enter the condition, so we just move to the next iteration.
            // - fourth iteration, ++it will point to "four", which does not enter the condition, so we just move to the next iteration.
            // - fifth iteration, ++it will point to the end of the vector, and the loop will terminate.
            // done.
            // final v = {"one", "two", "three", "four"}
            // * GOLDEN KEY: ++it in the for loop.
        }
    }

    cout << "v after second loop: "; /// output: {"one", "two", "three", "four"}
    for (const auto& str : v) {
        cout << str << " ";
    }
    cout << "\n";
    
    return 0;   
 }