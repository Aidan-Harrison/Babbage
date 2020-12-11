#ifndef BabbageMath_h
#define BabbageMath_h

// Used includes for now to stop errors, remove all afterwards
#include <iostream>
#include <vector>
#include <cmath>

#define PI 3.14159
#define Euler 2.71828
#define Radian 57.2958 // Pointless ???

// Maths library
// Research use of doubles
namespace BabbageMath {
    struct values {
        double x{0}; // Make use of these in functions?
        double y{0};
        double z{0};
    };
    // Overloads

    // Can template now as no longer using classes and seperate files | Test first
    template<typename T>
    // Basic
    T Add(T a, T b) {
        return a + b;
    }
    double Subtract(double a, double b) {
        return a - b;
    }
    double Multiply(double a, double b) {
        return a * b;
    }
    double Divide(double a, double b) {
        return a / b;
    }

    // Comparisons
    const double Max(double a, double b) {
    return a < b ? b : a;
    }
    const double Min(double a, double b) {
        return a > b ? a : b;
    }
    bool Same(double a, double b) {
        if(a == b) return true;
        return false;
    }

    // Conversions
    int toASC(char value) { // Char only? | Try 'char*'
        return (int)value; // Type-cast to int (ASCII)
    }
    // Both of these are probably the wrong formula. Everything else is correct
    double convRadToDeg(double radians) {
        return radians = 180/PI; 
    }
    double convDegToRad(double degrees) {
        return degrees = PI/180;
    }
    // Possibly incorrect
    double convCelToFah(double c) {
        return (c * 9 / 5) + 32;
    }        
    double convFahToCel(double f) {
        return (f - 32) * 5 / 9;
    }

    // Other   
    int random(int range) {
        if(sizeof(range) != sizeof(int) || sizeof(range) != sizeof(float) || sizeof(range) != sizeof(double)) {
            std::cout << "Babbage Error:-\nINVALID DATATYPE OF: " << typeid(range).name() << '\n';
            std::cout << "Both must be; int, float or double\n";
            return -1;
        }
        return rand() % range; // Check if 'rand()' can do more than int
    }
    std::vector<int> getDigits(int number) { // Returns digits of number in vector format
        int digit;
        std::vector<int> result;
        if(sizeof(number) != sizeof(int) || sizeof(number) != sizeof(float) || sizeof(number) != sizeof(double)) { // Check datatypes using 'sizeof' function
            std::cout << "Babbage Error:-\nINVALID DATATYPE OF: " << typeid(number).name() << '\n';
            std::cout << "Both must be; int, float or double\n";
            return result;
        }
        else {
            while(number) { // Flag
                digit = number % 10; // Get right-most digit
                result.push_back(digit); // Get push_front working??
                digit = number /= 10; // Move to next digit
            }
        }
        // Reverse, would have been added right to left (Could also use 'insert' function and decrement) | Insert universal function/s
        int start = 0;
        int end = result.size();
        while(start < end) {
            int temp = result[start];
            result[start] = result[end];
            result[end] = temp;
            start++;
            end--;
        }
        return result;
    }
}

// Vector (Move vector to math library)
// Incorrect arguments for functions
namespace VectorMath { // Implement graphics library into this, properly implement function arguments
    // Vectors
    struct Vector1 {
        float x;
        float vec1[1]{x};
    };

    struct Vector2 {
        float x;
        float y;
        float vec2[2]{x,y};
    };

    struct Vector3 {
        float x;
        float y;
        float z;
        float vec2[3]{x,y,z};
    };

    struct Vector4 {
        float x;
        float y;
        float z;
        float w;
        float vec4[4]{x,y,z,w};
    };

    float vectorInput1, vectorInput2, vectorInput3, vectorInput4; // Used for user creation
    // Vector 2
    float vecMag(Vector2 vec1, Vector2 vec2) { // Magnitude
        float magnitude = sqrt((vec1.x - vec1.y) + (vec2.x - vec2.y)); 
        return magnitude;
    }
    float addVec(Vector2 vec1, Vector2 vec2) { // Works!
        return vec1.x + vec2.x * vec1.y + vec2.y;
    }
    float subVec(Vector2 vec1, Vector2 vec2) {
        return vec1.x + vec2.x * -vec1.y + -vec2.y; // Incorrect formula?
    }
    float dotProd(Vector2 vec1, Vector2 vec2) { // Produces 'scalar'
        return vec1.x * vec2.x + vec1.y * vec2.y;
    }

    // Vector3
    void addVec3() {
        return;
    }
    void crossProd() {

    }
}

namespace MatrixMath {
    std::vector<std::vector<int>> createMatrix(int input, int rows, int columns) {
        std::vector<std::vector<int>> matrix;
        // DO THIS
        return matrix;
    }

    void printMatrix(std::vector<std::vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix.size(); j++)
                std::cout << matrix[i][j] << ", ";
            std::cout << '\n';
        }
    }

    // Work on calculation and return
    std::vector<std::vector<int>> addMatrix(std::vector<std::vector<int>>& matrix1, std::vector<std::vector<int>>& matrix2) {
        if(matrix1.size() != matrix2.size()) {
            std::cout << "Babbage Error:-\nINVALID MATRIX SIZE'S OF: " << matrix1.size() << " AND " << matrix2.size();
            std::cout << "Must be equal\n";
            return matrix1;
        }
        else {
            int sum = 0;
            std::vector<std::vector<int>> result{{}};
            for(int i = 0; i < matrix1.size() - 1; i++) {
                for(int j = 0; j < matrix1.size() - 1; j++) {
                    // DO THIS
                }
            }
        }
        return matrix1;
    }

    std::vector<std::vector<int>> subMatrix(std::vector<std::vector<int>>& matrix);
    std::vector<std::vector<int>> multMatrix(std::vector<std::vector<int>>& matrix);
}

namespace GeometryMath {
    int length;
    int width;
    int height;
    // Overloads
    /*
        GeometryMath operator+ (GeometryMath geo) { // Override + for geo calculations | May only work on volumes | Research overloading more
            GeometryMath newVal;
            newVal.length = length + geo.length; // Last operand equal to right hand side operand
            newVal.width = width + geo.width;
            newVal.height = height + geo.height;
            return newVal;
        }
    */

    // General
    int gPer(int a, int b) { // Square only for now
        return a + b * 2;
    }
    int gVol(int a, int b, int c) {
        return a * b * c;
    }
    int gArea(int a, int b) {
        return a * b;
    }
    int gPythagLong(int a, int b) {
        int c;
        c = a * a + b * b;
        return sqrt(c);
    }
    int gPythagShort(int a, int b) {
        int c;
        c = a * a - b * b;
        return sqrt(c);
    }

    struct CircleTheorem {
        double Circumfrence(double radius) {
        return 2 * PI * radius;
        }
        double CircleArea(double radius) {
            return PI * radius * radius;
        }
    };

    struct Trigonometry  {
        // Possible incorporate some static members | Do it for most classes??
        static double hypotenuse;
        static double opposite;
        static double adjacent;
        double gSin(double opposite, double hypotenuse) {
            return opposite / hypotenuse;
        }
        double gCos(double hypotenuse, double adjacent) {
            return adjacent / hypotenuse;
        }
        double gTan(double opposite, double hypotenuse, double adjacent) {
            return opposite / adjacent; // Continue
        }
    };
    
}

#endif