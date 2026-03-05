// Friend Classes

#include <iostream>

class A {
    private:
        int privData;
    public:
        A(int value) : privData(value) {}
        friend class B;
};

class B {
    public: 
        void accessA(A& obj) { // A& obj is a reference to object of class A
            // Can access obk.privData as B is as friend of A
            std::cout << obj.privData << std::endl;
        }
};

int main() {
    A a(5);
    B b;
    b.accessA(a); // 5
    return 0;
}