#ifndef BabbageMem_h
#define BabbageMem_h

#include <iostream>
#include <vector>

// This will be the lowest level and most complex header next to graphics
// C for the most part
// Replace with C style arrays

namespace BabbageMemory {
    // Do a lot of overloads?
    // Printing
    int* memPrintA(int arr[], int size) { // Fixed arrays cannot have their size found within the function | Does not exist
        size = sizeof(arr) / sizeof(arr[0]); // Alter this, reference based?
        for(int i = 0; i < size; i++)
            printf("%d", &arr[i], '-');
        return arr;
    }

    std::vector<std::vector<int>> memPrint2D(std::vector<std::vector<int>>& input) {
        for(int i = 0; i < input.size(); i++)
            for(int j = 0; j < input.size(); j++)
                printf("%d", &input[i][j]);
        return input;
    }
    // Memory allocations
};
#endif