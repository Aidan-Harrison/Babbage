#include "BabbageMem.h"

// Printing
std::vector<int> BabbageMemory::memPrint(std::vector<int>& input) {
    for(int i = 0; i < input.size(); i++)
        std::cout << &input[i] << ", ";
    return input;
}

std::vector<std::vector<int>> BabbageMemory::memPrint2D(std::vector<std::vector<int>>& input) {
    for(int i = 0; i < input.size(); i++)
        for(int j = 0; j < input.size(); j++)
            std::cout << &input[i][j]; // Possibly move to serperate lines
    return input;
}

// Memory allocations (Use malloc, calloc, realloc and free) | C based