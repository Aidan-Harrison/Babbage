#include "BabbageThread.h"

void BabbageThread::threadCreate(std::string name) {
    std::thread name(); // Figure out custom name, doesn't appear to work
}

void BabbageThread::delay(int seconds) {
    std::chrono::seconds(seconds); // Also not appearing to want to insert parameter | do float and double as well
}