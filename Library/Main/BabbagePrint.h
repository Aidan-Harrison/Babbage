#include <vector>
#include <iostream>

#include "Babbage.h"

class BabbagePrint {
private:

public:
    // Sort out generic returns
    inline void Print(int a); // Sort arguments
    inline void nl();
    inline void line(int amount);
    void box(int height, int width);
    std::vector<int> pArray(std::vector<int>& arr);
    std::vector<std::vector<int>> pArray2D(std::vector<std::vector<int>>& arr);
};