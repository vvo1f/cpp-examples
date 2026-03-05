/*
    Recursive Mutex
*/

#include <mutex>
#include <iostream>
#include <thread>

std::recursive_mutex rm;

void f2 () {
    rm.lock();
    std::cout << "Bar" << std::endl;
    rm.unlock();
}

int main() {
    rm.lock();
    std::cout << "Foo" << std::endl;
    f2();
    rm.unlock();   
}
