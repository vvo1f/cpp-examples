/*
    RAII Wrapper
*/

#include <mutex>
#include <iostream>
#include <thread>


std::mutex m1;
std::mutex m2;

void update(int num) {
    // don't actually take the locks on m1 and m2
    std::unique_lock lock1 {m1, std::defer_lock};
    std::unique_lock lock2 {m2, std::defer_lock};

    // NOTE: std::lock(lock1, lock2) lock both unique locks without deadlock due to the order
    std::lock(lock1);
    std::lock(lock2);

    num += (int) rand();

    return; // m1 and m2 are automatically unlocked.
}

int main() {
    update(10);
}
