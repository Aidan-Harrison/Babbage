#ifndef BabbageThread_h
#define BabbageThread_h

#include <iostream>
#include <thread>
#include <chrono>

// Heavy overriding of headers necessary
namespace bthread {
    std::thread bThread() {
        return std::thread();
    }
}

#endif