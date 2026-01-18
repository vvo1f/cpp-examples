/**
 * System and Device Programming - Topic:  Custom Sorting with Lambdas
 * * LOGIC TRACE:
 * 1. Initial Vector: {1, 9, 3, 8, 5}, Target: 8
 * * 2. First Sort by Distance to Target (8):
 * - Distances: |1-8|=7, |9-8|=
 * 1, |3-8|=5, |8-8|=0, |5-8|=3
 * - Sorted Order: {8, 9, 5, 3, 1}
 * * 3. Output After First Sort:
 * - "8 9 5 3 1 "
 * * 4. Change Target to 1
 * * 5. Second Sort by Distance to Target (1):
 * - Distances: |8-1|=7, |9-1|=
 *  8, |5-1|=4, |3-1|=2, |1-1|=0
 * - Sorted Order: {1, 3, 5, 8, 9}
 * * 6. Output After Second Sort:
 * - "1 3 5 8 9 "
 * * OUTPUT:
 * 8 9 5 3 1 - 1 3 5 8 9
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


int main() {
    std::vector<int> points = {1, 9, 3, 8, 5};
    int target = 8;
    
    auto sort_by_distance = [&target](int a, int b) {
        return std::abs(a - target) < std::abs(b - target);
    };
    std::sort(points.begin(), points.end(), sort_by_distance);
    for (int p : points) { std::cout << p << " "; }
    std::cout << "- ";
    target = 1;
    std::sort(points.begin(), points.end(), sort_by_distance);
    for (int p : points) { std::cout << p << " "; }

    return 0;
}