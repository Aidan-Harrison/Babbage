#ifndef BabbageThread_h
#define BabbageThread_h

#include <iostream>
#include <thread>
#include <chrono>

// Heavy overriding of headers necessary

// Definitions do not appear to work <-- check this
namespace BabbageThread {
    void threadCreate(std::string name) { 
        std::thread name(); // Figure out custom name, doesn't appear to work
    }
    /*
        void delay(int seconds) {
            std::chrono::seconds(seconds); // Also not appearing to want to insert parameter | do float and double as well
        }
    */
}

#endif