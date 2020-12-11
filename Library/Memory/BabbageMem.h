#include <iostream>
#include <vector>

// This will be the lowest level and most complex header next to graphics
// C for the most part

namespace BabbageMemory {
    // Do a lot of overloads?
    // Printing
    std::vector<int> memPrint(std::vector<int>& input) {
        for(int i = 0; i < input.size(); i++)
            std::cout << &input[i] << ", ";
        return input;
    }
    std::vector<std::vector<int>> memPrint2D(std::vector<std::vector<int>>& input) {
        for(int i = 0; i < input.size(); i++)
            for(int j = 0; j < input.size(); j++)
                std::cout << &input[i][j]; // Possibly move to serperate lines
        return input;
    }
    // Memory allocations
};