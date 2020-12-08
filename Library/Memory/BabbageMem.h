#pragma once
#include <iostream>
#include <vector>
#include "Babbage.h"

class BabbageMemory {
private:
    // Add extras here
public:
    // Do a lot of overloads?
    // Printing
    std::vector<int> memPrint(std::vector<int>& input);
    std::vector<std::vector<int>> memPrint2D(std::vector<std::vector<int>>& input);

    // Memory allocations
};