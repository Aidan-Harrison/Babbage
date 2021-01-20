#ifndef BabbageError_h
#define BabbageError_h

#include <cassert>
#include <fstream>
#include <sstream>

#include "BMath.h"

// #define ASSERT(x) if(!(x)) __debugbreak(); // Check!

using namespace bmath;

// Make calls to necessary errors | Function overload based
namespace berror {
    template<typename T>
    void errorCheck(T object) { static_assert(object, "Babbage Error: Invalid Input"); } // Check!
}

namespace bLog {
    std::fstream createLog() {
        std::fstream log;
        return log;
    }
    void writeToLog(const char* filepath, std::fstream &log, const char* message) {
        log.open(filepath);
        if(log.fail()) {
            std::cerr << "Babbage Error: Cannot open file, either does not exist or is corrupted\n";
            exit(1);
        }
    }
    void clearLog(); // Clears entire file
}

#endif