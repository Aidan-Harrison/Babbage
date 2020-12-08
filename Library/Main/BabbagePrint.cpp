#include "BabbagePrint.h"

inline void BabbagePrint::Print(int a) { // Single argument, allow for multiple
    std::cout << a; 
}
inline void BabbagePrint::nl() {
    std::cout << '\n'; 
}
inline void BabbagePrint::line(int amount) {
    std::cout << '-' + std::string(amount, '-') << '\n';
}

void BabbagePrint::box(int height, int width) {
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            std::cout << '*';
        std::cout << '\n';
}

std::vector<int> BabbagePrint::pArray(std::vector<int>& arr) {
    for(auto i : arr)
        std::cout << arr[i] << ", ";
    return arr;
}

std::vector<std::vector<int>> BabbagePrint::pArray2D(std::vector<std::vector<int>>& arr) {
    int m = arr.size();
    int n = arr[0].size();
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            std::cout << arr[i][j];
        return arr;
}