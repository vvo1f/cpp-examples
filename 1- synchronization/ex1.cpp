/*
    binary semaphore
*/

#include <iostream>
#include <chrono>
#include <semaphore>
#include <thread>

using namespace std::literals::chrono_literals;
std::binary_semaphore m2t{0}, t2m{0}; // Counters are set to 0 (non-signaled state)

void tf() {
    m2t.acquire();
    std::cout << "[thread] Got signal\n";
    std::this_thread::sleep_for(3s);
    std::cout << "[thread] Send signal\n";
    t2m.release();
}

int main() {
    std::thread thr(tf);
    std::cout << "main Send signal\n";
    m2t.release();
    t2m.acquire();
    std::cout << "[main] Got signal\n";
    thr.join();
}

/*
    * Analysis:
        - main tries to create the thr thread using tf function.
        - tf runs and blocks in m2t.acquire() because m2t is 0.
        - main releases m2t semaphore, so tf can continue.
        - tf prints "[thread] Got signal" and sleeps for 3 seconds.
        - main blocks in t2m.acquire() because t2m is 0.
        - tf sends signal to main by releasing t2m semaphore.
        - main prints "[main] Got signal".
        - main joins the thr thread.
*/