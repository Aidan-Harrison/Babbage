#ifndef BabbagePrint_h
#define BabbagePrint_h

#include <vector>
#include <iostream>

namespace bpr{
    template<typename T>
    inline void print(const T a) { 
        std::cout << a;
    }
    inline void prASCII(char a) { 
        std::cout << static_cast<int>(a); 
    }
    void prASCII(std::string &str) { // Check!
        for(int i = 0; i < str.length(); i++)
            std::cout << static_cast<int>(str[i]);
    }
    inline void nl() { 
        putchar('\n'); 
    }
    inline void line(int amount = 1) { 
        std::cout << std::string(amount, '-') << '\n'; 
    }
    void box(const int height, const int width) {
        for(int i = 0; i < height; i++)
            for(int j = 0; j < width; j++)
                putchar('*');
            putchar('\n');
    }
    
    void pyramid(int height, int width) { // Fix | Study
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

    template<typename T>
    void pArray(const T arr[], int size) {
        for(int i = 0; i < size; i++)
            std::cout << arr[i] << ", ";
    }
    template<typename T>
    void pArray(const std::vector<T> &arr) {
        for(int i = 0; i < arr.size(); i++)
            std::cout << arr[i] << ", ";
    }

    template<typename T>
    void pArray2D(const std::vector<std::vector<T>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                std::cout << arr[i][j];
    }
}

#endif