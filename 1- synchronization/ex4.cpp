/*
    Shared Mutex
*/

#include <shared_mutex>
#include <iostream>
#include <thread>
#include <vector>

int value = 0;
std::shared_mutex sm;

std::vector<std::thread> tv;

int main() {
    /*
        Reader Threads
        shared the CS
    */
    for (int i = 0; i < 5; i++) {
        tv.emplace_back([&] { // NOTE: .emplace_back() constructs the object in place, so no need to use std::move
            sm.lock_shared();
            // use value
            sm.unlock_shared();
        });
    }

    /*
        Writer Threads
        exclusive access to the CS
    */
    for (int i = 0; i < 5; ++i) {
        tv.emplace_back([&] {
            sm.lock();
            // modify value
            ++value;
            sm.unlock();
        });
    }
}
