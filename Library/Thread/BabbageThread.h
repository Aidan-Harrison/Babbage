#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include "Babbage.h"

// Definitions do not appear to work <-- check this
class BabbageThread {
    void threadCreate(std::string name); // std::thread
    void delay(int seconds); // 'chrono::seconds()' 
}; 