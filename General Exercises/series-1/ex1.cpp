/**
 * Struct vs Class in C++
 * * MAIN DIFFERENCES:
 * 1. Members: 'struct' members are PUBLIC by default. 'class' members are PRIVATE by default.
 * 2. Inheritance: 'struct' inherits PUBLICLY by default. 'class' inherits PRIVATELY by default.
 */

#include <iostream>
#include <string>

// ==========================================
// 1. DATA MEMBER VISIBILITY
// ==========================================

struct PointStruct {
    // [DEFAULT: PUBLIC]
    int x; 
    int y;
    
    // You can still make things private if you want
private:
    int id; 
};

class PointClass {
    // [DEFAULT: PRIVATE]
    int x; 
    int y;

public:
    // We must explicitly say 'public' to expose methods/data
    void setValues(int a, int b) {
        x = a;
        y = b;
    }
};

// ==========================================
// 2. INHERITANCE VISIBILITY
// ==========================================

class Base {
public:
    int data = 100;
};

// Struct inherits PUBLICLY by default
// Equivalent to: struct DerivedStruct : public Base
struct DerivedStruct : Base {
    // 'data' remains public here
};

// Class inherits PRIVATELY by default
// Equivalent to: class DerivedClass : private Base
class DerivedClass : Base {
    // 'data' becomes private here!
    // It is accessible inside this class, but HIDDEN from main()
};

// ==========================================
// MAIN EXECUTION
// ==========================================

int main() {
    // --- TEST 1: Struct Usage ---
    PointStruct ps;
    ps.x = 10;      // OK: x is public by default
    ps.y = 20;      // OK: y is public by default
    // ps.id = 5;   // ERROR: We explicitly marked 'id' as private

    // --- TEST 2: Class Usage ---
    PointClass pc;
    // pc.x = 10;   // ERROR: x is private by default!
    pc.setValues(10, 20); // OK: setValues is in the 'public' section

    // --- TEST 3: Inheritance ---
    DerivedStruct ds;
    std::cout << "Struct Data: " << ds.data << std::endl; // OK: Inherited publicly

    DerivedClass dc;
    // std::cout << "Class Data: " << dc.data << std::endl; // ERROR: Inherited privately
    
    return 0;
}
