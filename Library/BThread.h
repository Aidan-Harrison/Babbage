#ifndef BabbageThread_h
#define BabbageThread_h

#include <iostream>
#include <thread>
#include <chrono>

void Wait(int value) {
    std::this_thread::sleep_for(std::chrono::seconds(value));
}

#endif