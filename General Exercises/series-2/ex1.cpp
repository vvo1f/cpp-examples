/**
 * System and Device Programming - Topic: Function Parameter Passing
 * * LOGIC TRACE:
 * 1. Initial Values:
 * - v1=10, v2=20, v3=30
 * - vec1={1,2,3}, vec2={10,20,30
 * * 2. Function Call f(v1, &v2, v3, &vec1, vec2):
 * - v1 passed by value: local copy modified to 100 (no effect outside)
 * - v2 passed by pointer: value at address modified to 200
 * - v3 passed by reference: modified to 300
 * - vec1 passed by pointer: first element modified to 400, 401 appended
 * - vec2 passed by reference: first element modified to 500, 501 appended
 * * 3. Final Values After f():
 * - v1=10 (unchanged)
 * - v2=200 (modified via pointer)
 * - v3=300 (modified via reference)
 * - vec1={400,2,3,401} (first element changed, new
 * element added)
 * - vec2={500,20,30,501} (first element changed, new
 * element added)
 * * OUTPUT:
 * 1: 10
 * 2: 200
 * 3: 300
 * 4: 400
 * 5: 4
 * 6: 500
 * 7: 4
**/

#include <iostream>
#include <vector>


void f (int v1, int *v2, int &v3, std::vector<int> *vec1, std::vector<int> &vec2) {
    v1 = 100;
    if (v2 != nullptr) {
        *v2 = 200;
    }
    v3 = 300;
    if (vec1 != nullptr) {
        if (!vec1->empty()) {
            (*vec1)[0] = 400;
        }
        vec1->push_back(401);
    }
    if (!vec2.empty()) {
        vec2[0] = 500;
    }
        vec2.push_back(501);
    return;
}

int main() {
    int v1 = 10;
    int v2 = 20;
    int v3 = 30;
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {10, 20, 30};
    f (v1, &v2, v3, &vec1, vec2);
    std::cout << "1: " << v1 << std::endl;
    std::cout << "2: " << v2 << std::endl;
    std::cout << "3: " << v3 << std::endl;
    std::cout << "4: " << vec1[0] << std::endl;
    std::cout << "5: " << vec1.size() << std::endl;
    std::cout << "6: " << vec2[0] << std::endl;
    std::cout << "7: " << vec2.size() << std::endl;
    return 0;
}