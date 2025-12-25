/**
 * System and Device Programming - Vector Erase_If Exercise
 * * LOGIC TRACE:
 * 1. Initial Vector: {1, 5, 2, 6, 3}
 * * 2. erase_if Processing:
 * - Element 1: 1 > 3? False. (Keep)
 * - Element 5: 5 > 3? True. (Add 5 to sum, Remove) -> Sum=5
 * - Element 2: 2 > 3? False. (Keep)
 * - Element 6: 6 > 3? True. (Add 6 to sum, Remove) -> Sum=11
 * - Element 3: 3 > 3? False. (Keep)
 * * 3. Final State:
 * - removed_sum = 11
 * - data vector = {1, 2, 3}
 * * OUTPUT: "11 1 2 3 "
 */

#include <iostream>
#include <vector>

// Note: std::erase_if for vectors requires C++20
// If compiling on older standards, this might need <algorithm> and remove_if pattern
int main() {
    std::vector<int> data = {1, 5, 2, 6, 3};
    int removed_sum = 0;

    // std::erase_if erases elements from the vector based on the predicate
    // The lambda captures 'removed_sum' by reference [&] to modify it
    std::erase_if(data,
        [&removed_sum](int n) {
            if (n > 3) {
                removed_sum += n; // Side effect: update sum
                return true;      // Signal to erase this element
            }
            return false;         // Signal to keep this element
        });

    // Output the calculated sum
    std::cout << removed_sum << " ";

    // Output the remaining elements in the vector
    for (int val : data) {
        std::cout << val << " ";
    }

    return 0;
}
