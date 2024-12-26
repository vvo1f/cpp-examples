#include <iostream>
using namespace std;

class C {
public:
    // Default constructor
    C() {
        cout << "Default constructor called" << endl;
    }

    // Parameterized constructor
    C(int x) {
        cout << "Parameterized constructor called with value " << x << endl;
    }

    // Copy constructor
    C(const C &other) {
        cout << "Copy constructor called" << endl;
    }

    // Move constructor
    C(C &&other) noexcept {
        cout << "Move constructor called" << endl;
    }

    // Destructor
    ~C() {
        cout << "Destructor called" << endl;
    }
};

int main() {
    C obj1;                // Default constructor
    C obj2(10);            // Parameterized constructor
    C obj3 = obj2;         // Copy constructor
    C obj4 = std::move(obj2); // Move constructor

    return 0;
}