#ifndef BabbagePrint_h
#define BabbagePrint_h

#include <vector> // Replace with C style arrays
#include <iostream>

// Because of templating may not want to use C style printing
namespace bpr{
    template<typename T>
    inline void print(T a) { 
        printf("%d", a); 
    }
    inline void print(const char* message) { printf("%c", message); }
    template<typename T>
    inline void prASCII(T a) { 
        std::cout << static_cast<int>(a); 
    }
    inline void nl() { putchar('\n'); }
    inline void line(int amount) { 
        std::cout << '-' + std::string(amount, '-') << '\n'; 
    }
    inline const char* convToCStr(std::string message) { return message.c_str(); }
    std::string convToCPlusStr(const char* message) { 
        std::string newMessage = message;
        return newMessage;
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

    template<typename T>
    void pArray(T arr[], int size) {
        for(int i = 0; i < size; i++)
            std::cout << arr[i] << ", ";
    }

    template<typename T>
    std::vector<std::vector<T>> pArray2D(std::vector<std::vector<T>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                printf("%d", arr[i][j]);
            return arr;
    }
}

#endif