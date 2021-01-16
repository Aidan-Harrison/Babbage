#ifndef BabbageError_h
#define BabbageError_h

#include <cassert>
#include "BMath.h"

// #define ASSERT(x) if(!(x)) __debugbreak(); // Check!

using namespace bmath;

// Make calls to necessary errors | Function overload based
namespace berror {
    template<typename T>
    void errorCheck(T object) { static_assert(object, "Babbage Error: Invalid Input"); } // Check!
}

#endif