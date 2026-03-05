/*
    Mutex
*/

#include <mutex>
#include <iostream>
#include <vector>
#include <thread>

std::mutex m;

void safe_print (int i) {
    m.lock();
    std::cout << i << std::endl;
    m.unlock();
}


int main() {
    std::vector<std::thread> threadPool;

    for (int i = 1; i <= 9; ++i) {
        threadPool.emplace_back([i] { safe_print(i); }); // Analysis: This line is creating a new thread and adding it to the threadPool vector.
                                                         // [i] { safe_print(i); }: This is a lambda function. 
                                                         // It's a function without a name that you can define right in place where you use it. 
                                                         // The [i] part is a capture list. It specifies that the lambda function should capture the current value of i from the surrounding scope. 
                                                         // The { safe_print(i); } part is the body of the lambda function. It calls the safe_print function with the captured value of i.
    }

    for (auto& t: threadPool) { // NOTE:  This is a range-based for loop that iterates over each element in threadPool. 
                                // Each element is a reference to a thread object, which is why auto& t is used instead of auto t.
        t.join();               // NOTE: calls the join method on the thread object t. 
                                // The join method blocks the current thread (i.e., the thread that's executing this code) until the thread t has finished executing. 
                                // If t has already finished executing, join returns immediately.
    }
}

// ex result without mutex:
/* 
1
2
43

5
6
7
8
9
*/

// withou mutext lock:
/*
1
2
3
4
5
6
7
8
9
*/