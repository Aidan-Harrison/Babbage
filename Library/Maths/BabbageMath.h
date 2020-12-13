#ifndef BabbageMath_h
#define BabbageMath_h

// Used includes for now to stop errors, remove all afterwards
#include <iostream>
#include <vector>
#include <cmath>

#define PI 3.14159
#define Euler 2.71828
#define Radian 57.2958

// Maths library
// Research use of doubles
namespace BabbageMath {
    // Definitions | typedef's here

    // Overloads

    template<typename T> // Find way to template namespace
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
        return static_cast<int>(value); // Type-cast to int (ASCII)
    }
    // Both of these are probably the wrong formula
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
            std::cout << "Must be; int, float or double\n";
            return -1;
        }
        return rand() % range; // Check if 'rand()' can do more than int
    }
    std::vector<int> getDigits(int number) { // Returns digits of number in vector format, CHANGE TO ARRAY
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

namespace VectorMath { // Implement graphics library into this, properly implement function arguments
    // Vectors
    struct Vector1 {
        float x;
        float vec1[1]{x};
        Vector1(int cX = 0) {
            x = cX;
        }
    };

    struct Vector2 {
        float x;
        float y;
        float vec2[2]{x,y};
        Vector2(int cX = 0, int cY = 0) {
            x = cX;
            y = cY;
        }
    };

    struct Vector3 {
        float x;
        float y;
        float z;
        float vec3[3]{x,y,z};
        Vector3(int cX = 0, int cY = 0, int cZ = 0) {
            x = cX;
            y = cY;
            z = cZ;
        }
    };

    struct Vector4 {
        float x;
        float y;
        float z;
        float w;
        float vec4[4]{x,y,z,w};
        Vector4(int cX = 0, int cY = 0, int cZ = 0, int cW = 0) {
            x = cX;
            y = cY;
            z = cZ;
            w = cW;
        }
    };

    // Vector creation | Should return using pointers/ref ?
    Vector1 CVec1(float vecIn1) {
        Vector1 vec;
        vec.vec1[0] = vecIn1;
        return vec;
    }
    Vector2 CVec2(float vecIn1, float vecIn2) {
        Vector2 vec;
        vec.vec2[0] = vecIn1;
        vec.vec2[1] = vecIn2;
        return vec;
    }
    Vector3 CVec3(float vecIn1, float vecIn2, float vecIn3) {
        Vector3 vec;
        vec.vec3[0] = vecIn1;
        vec.vec3[1] = vecIn2;
        vec.vec3[2] = vecIn3;
        return vec;
    }
    Vector4 CVec4(float vecIn1, float vecIn2, float vecIn3, float vecIn4) {
        Vector4 vec;
        vec.vec4[0] = vecIn1;
        vec.vec4[1] = vecIn2;
        vec.vec4[2] = vecIn3;
        vec.vec4[3] = vecIn4;
        return vec;
    }

    // Vector 2 Math
    float vecMag(Vector2 vec1) { // Magnitude
        float mag = sqrt(vec1.x * vec1.x + vec1.y * vec1.y); // Do custom sqrt function
        return mag;
    }
    Vector2 addVec(Vector2 vec1, Vector2 vec2) { // Working?
        Vector2 vec;
        vec.x = vec1.x + vec2.x;
        vec.y = vec1.y + vec2.y;
        return vec;
    }
    Vector2 subVec(Vector2 vec1, Vector2 vec2) { // Working
        Vector2 vec;
        vec.x = vec1.x + (-vec2.x);
        vec.y = vec1.y + (-vec2.y);
        return vec;
    }
    float dotProd(Vector2 vec1, Vector2 vec2) { // Produces 'scalar' | Working
        return vec1.x * vec2.x + vec1.y * vec2.y;
    }

    // Vector3 Math
    void addVec3(Vector3 vec1, Vector3 vec2) {
        return;
    }
    void crossProd(Vector3 vec1, Vector3 vec2) {
        return;
    }

    // Vector4 Math
}

namespace MatrixMath {
    struct Matrix {
        int mRows;
        int mColums;

        inline Matrix() = default;

        Matrix(int rows = 0, int columns = 0) {
            mRows = rows;
            mColums = columns;
        }
    };

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

    // Work on calculation and return | Convert to non-vector
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
    struct shape2D {
        static int width;
        static int height;
    };

    struct shape3D {
        static int width;
        static int height;
        static int depth;
    };

    // Overloads

    // General
    int gPer(shape2D s1) { // Square only for now
        return s1.width + s1.width + s1.height + s1.height;
    }
    int gArea(int a, int b) { // Possibly don't do objects for users sake | Overcomplicated
        return a * b;
    }
    int gVol(shape3D s1) {
        return s1.width * s1.height * s1.depth;
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

// Do better with objects. Have struct only be quat itself not functions
struct Quaternion {
    float x;
    float y;
    float z;
    float w;

    inline Quaternion() = default;

    Quaternion(float a, float b, float c, float d) {
        x = a;
        y = b;
        z = c;
        w = d;
    }

    float magnitude() {
        float mag = sqrt(w * w + x * x + y * y + z * z);
        return mag;
    }

    float normailze() {
        float mag = magnitude();
        w /= mag;
        x /= mag;
        y /= mag;
        z /= mag;
        return mag; // ??
    }
};

#endif