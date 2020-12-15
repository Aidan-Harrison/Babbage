#ifndef BabbagePrint_h
#define BabbagePrint_h

#include <vector> // Replace with C style arrays
#include <iostream>

namespace BabbagePrint {
    // Sort out generic returns
    inline void Print(int a) { // Single argument, allow for multiple | Replace with custom print
        printf("%d", a);
    }
    inline void nl() {
        putchar('\n'); 
    }
    inline void line(int amount) {
        std::cout << '-' + std::string(amount, '-') << '\n'; // C print
    }
    void box(int height, int width) {
        for(int i = 0; i < height; i++)
            for(int j = 0; j < width; j++)
                putchar('*');
            putchar('\n');
    }
    void pyramid(int height, int width) { // Fix
        for(int i = 1, k = 0; i <= height; i++, k = 0) {
            for(width = 1; width <= height - i; width++) {
                putchar(' ');
            }
            while(k != 2*i-1) {
                putchar('*');
                k++;
            }
            putchar('\n');
        }
    }
    std::vector<int> pArray(std::vector<int>& arr) { // Replace
        for(auto i : arr)
            printf("&d", arr[i]); putchar('-');
        return arr;
    }
    std::vector<std::vector<int>> pArray2D(std::vector<std::vector<int>>& arr) { // Replace
        int m = arr.size();
        int n = arr[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                printf("%d", arr[i][j]);
            return arr;
    }
}

#endif