// Constructor and destructor

#include <iostream>
using namespace std;

static int count = 0;
class Test {
    public:
        Test() {
            count++;
            cout << "#C: " << count << endl;
        }
        ~Test() {
            cout << "#D: " << count << endl;
            count--;
        }
};

int main() {
    Test t, t1, t2, t3;

    return 0;
}