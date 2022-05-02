#ifndef BError_h
#define BError_h

#include <iostream>
#include <type_traits>

namespace bError {
    template<typename T>
    const bool Error(T &obj) {
        std::cerr << "ERROR: ";
    }

    // Agnostic assert
    template<typename T>
    const bool Assume(T &obj) {
    }
}

#endif