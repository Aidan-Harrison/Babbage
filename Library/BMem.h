#ifndef BabbageMem_h
#define BabbageMem_h

#include <iostream>
#include <vector>

// This will be the lowest level and most complex header next to graphics
// C for the most part
// Replace with C style arrays

namespace bmem {
    // Printing
    template<typename T>
    T* memPrintA(T arr[], int size) {
        for(int i = 0; i < size; i++)
            printf("%d", &arr[i], '-');
        return arr;
    }

    template<typename T>
    std::vector<std::vector<T>> memPrint2D(std::vector<std::vector<T>>& input) {
        for(int i = 0; i < input.size(); i++)
            for(int j = 0; j < input.size(); j++)
                printf("%d", &input[i][j]);
        return input;
    }

    char NULLTERM() {
        return putchar('\0');
    }
    
    // Memory allocations
};
#endif