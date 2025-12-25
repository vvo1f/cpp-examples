/**
 * System and Device Programming - Map & Vector Exercise
 * * LOGIC TRACE:
 * 1. Initial Map: {101: "A", 103: "B", 104: "A"}
 * * 2. Loop through ID 102:
 * - find(102) fails.
 * - Else block: Insert 102->"C". Print "N".
 * - Map is now: {101:"A", 102:"C", 103:"B", 104:"A"}
 * * 3. Loop through ID 103:
 * - find(103) succeeds.
 * - If block: Print "B".
 * * 4. Loop through ID 101:
 * - find(101) succeeds.
 * - If block: Print "A".
 * * 5. Loop through ID 105:
 * - find(105) fails.
 * - Else block: Insert 105->"C". Print "N".
 * - Map is now: {..., 105:"C"}
 * * 6. Final Print:
 * - Print " " (space)
 * - Print value at 102 ("C")
 * - Print value at 105 ("C")
 * * FINAL OUTPUT STRING: "NBAN CC"
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    std::map<int, std::string> student_grades;

    // Initialization
    student_grades[101] = "A";
    student_grades[103] = "B";
    student_grades[104] = "A";

    std::vector<int> student_ids = {102, 103, 101, 105};

    for (int id : student_ids) {
        // .find() searches without modifying the map
        auto it = student_grades.find(id);

        if (it != student_grades.end()) {
            // Found: Print existing grade
            std::cout << it->second;
        } else {
            // Not Found: Insert default 'C' and print 'N' (New)
            student_grades[id] = "C"; 
            std::cout << "N";
        }
    }

    // Print the values that were dynamically added during the loop
    std::cout << " " << student_grades[102] << student_grades[105];

    return 0;
}
