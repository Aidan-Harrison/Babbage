#ifndef Babbage_h
#define Babbage_h

#define WAIT std::cin.get()

// Add general typedefs

// General non-specified header
namespace BabbageGeneral {
    int* Asize(int array[]) {
        int size = sizeof(array) / sizeof(array[0]); // Fix
        return &size;
    }
    extern int userInput;
}

#endif