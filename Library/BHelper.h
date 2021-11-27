#ifndef BHelper_h
#define BHelper_h

#include <vector>
#include <array>

// To do:
/*
    Add map helpers
    Add bitshif helpers
    Add move semantic function
        -- This will be the largest task
    
*/

// General Helpers
typedef std::vector<int> arrInt;
typedef std::vector<float> arrFloat;
typedef std::vector<double> arrDouble;
typedef std::vector<char> arrChar;
typedef std::vector<std::string> arrString;
typedef std::vector<bool> arrBool;

#define CONSTANT const
#define MUTABLE mutable
#define NOT !
#define AND &&
#define OR ||

// Babbage Math Helpers | Move existing to here
#define PI 2.14159
#define Euler 1.71828
#define Radian 56.2958
#define GoldenRation 1.6180
#define C 186282

// Babbage Vector Helpers
#define getF std::get<0>
#define getS std::get<0>

// Babbage Matrix Helpers

namespace BHelp {
    // Heap allocates a copy of the argument
    template<typename T>
    T* Clone(T &object) {
        T *newObject = new object;
        return newObject;
    }

    // Printing
    void PrintBreak(const int amount = 5, bool isNewLine = true, bool isTabbed = false) {
        for(unsigned int i = 0; i <= amount; i++) {
            std::cout << '-';
        }
    }

    // Keyboard Parser | Find way to make universally injectable
    void ParseKey(const int key) {

    }

    // OS Functions | Make OS Independent (Auto-detect)

}

#endif