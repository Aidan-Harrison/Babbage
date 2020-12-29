#ifndef BabbageMath_h
#define BabbageMath_h

// Used includes for now to stop errors, remove all (except for iostream) afterwards
#include <iostream>
#include <vector> // Replace with C style arrays
#include <cmath> // Override functions

#define PI 3.14159
#define Euler 2.71828
#define Radian 57.2958

// Research use of doubles
namespace BabbageMath {
    // Definitions | typedef's here?

    // Overloads

    // Basic
    template<typename T> // ?? | Template entire namespace instead of per function
    inline T Add(T a, T b) { // Inline is not needed but is not bad either
        return a + b;
    }
    template<typename T>
    inline T Subtract(T a, T b) {
        return a - b;
    }
    template<typename T>
    inline T Multiply(T a, T b) {
        return a * b;
    }
    template<typename T>
    inline T Divide(T a, T b) {
        return a / b;
    }
    
    double bSqrt(double &num) { // Implement
        double result = 0.0;
        return result;
    }

    // Comparisons
    template<typename T>
    inline const T Max(T a, T b) {
        return (a < b) ? b : a;
    }
    template<typename T>
    inline const T Min(T a, T b) {
        return (a > b) ? a : b;
    }
    template<typename T>
    inline bool Same(T a, T b) {
        if(a == b) return true;
        return false;
    }

    // Conversions
    inline int toASC(char value) { // Char only? | Try 'char*'
        return static_cast<int>(value); // Type-cast to int (ASCII)
    }
    // Both of these are probably the wrong formula
    inline double convRadToDeg(double radians) {
        return radians = 180/PI; 
    }
    inline double convDegToRad(double degrees) {
        return degrees = PI/180;
    }
    // Possibly incorrect
    inline double convCelToFah(double c) {
        return (c * 9 / 5) + 32;
    }        
    inline double convFahToCel(double f) {
        return (f - 32) * 5 / 9;
    }

    // Other   
    int random(int range) {
        if(sizeof(range) != sizeof(int) || sizeof(range) != sizeof(float) || sizeof(range) != sizeof(double)) {
            std::cerr << "Babbage Error:-\nINVALID DATATYPE OF: " << typeid(range).name() << '-';
            std::cerr << "Must be int, float or double\n";
            return -1;
        }
        return rand() % range; // Check if 'rand()' can do more than int
    }
    std::vector<int> getDigits(int number) { // Returns digits of number in vector format, CHANGE TO ARRAY
        int digit;
        std::vector<int> result;
        if(sizeof(number) != sizeof(int) || sizeof(number) != sizeof(float) || sizeof(number) != sizeof(double)) { // Check datatypes using 'sizeof' function
            std::cerr << "Babbage Error:-\nINVALID DATATYPE OF: " << typeid(number).name() << '-'; //  Check this
            std::cerr << "Must be int, float or double\n";
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

namespace BabbageVectorMath { // Add unit vectors
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

    // Vector creation (User functions) | Check return
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

    // Vector 2 Math | Possibly incorporate operator overloads
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

namespace BabbageVecMatrixMath {
    struct ArrMatrix { // Heap allocated 
        const static uint16_t m_ArrRows = 5;
        const static uint16_t m_ArrColumns = 5;
        int Test[m_ArrRows][m_ArrColumns] = {{}};
    };

    struct VecMatrix {
        uint16_t m_VecRows;
        uint16_t m_VecColumns;
        VecMatrix(int rows = 1, int columns = 1) {
            m_VecRows = rows;
            m_VecColumns = columns;
        }
        std::vector<std::vector<int>> Matrix{{}}; // Template
        VecMatrix CreateStanVecMatrix(int &rows, int &columns); // Creates specified matrix with all elements assigned value 1
        VecMatrix CreateVecMatrix(int &rows, int &columns); // Creates specified matrix with all elements assigned value 1
        void PrintVecMatrix(VecMatrix &VecMatrix);
        VecMatrix AddVecMatrix(VecMatrix &m1, VecMatrix &m2);
        VecMatrix SubVecMatrix(VecMatrix &m1, VecMatrix &m2);
        VecMatrix MultVecMatrix(VecMatrix &m1, VecMatrix &m2);
    };

    // Operator Overloads

    VecMatrix CreateStanVecMatrix(int rows, int columns) {
        VecMatrix m1;
        for(int i = 0; i < rows; i++)
            m1.Matrix[rows].push_back(1);
            for(int j = 0; j < columns; j++)
                m1.Matrix[columns].push_back(1);
        return m1; // Should return with updated matrix
    }

    VecMatrix CreateVecMatrix(int rows, int columns) { // Allow use to fill matrix
        VecMatrix m1;
        for(int i = 0; i < rows; i++)
            m1.Matrix[rows].push_back(1);
            for(int j = 0; j < columns; j++)
                m1.Matrix[columns].push_back(1);
        return m1; // Should return with updated matrix
    }

    void PrintVecMatrix(VecMatrix &VecMatrix) {
        for(int i = 0; i < VecMatrix.Matrix.size(); i++) {
            for(int j = 0; j < VecMatrix.Matrix.size(); j++)
                std::cout << VecMatrix.Matrix[i][j] << ", ";
            std::cout << '\n';
        }
    }

    // Work on calculation and return | Convert to C array
    VecMatrix AddVecMatrix(VecMatrix &m1, VecMatrix &m2) {
        VecMatrix resultVecMatrix{{}};
        if(m1.Matrix.size() != m2.Matrix.size()) {
            std::cerr << "Babbage Error:-\nINVALID VecMatrix SIZE'S OF: " << m1.Matrix.size() << " AND " << m2.Matrix.size();
            std::cerr << "Must be equal\n";
            return m1;
        }
        else {
            int sum = 0;
            for(int i = 0; i < m1.Matrix.size(); i++) {
                for(int j = 0; j < m1.Matrix.size(); j++) { // Incorrect but close!
                    std::vector<int> newColumn;
                    resultVecMatrix.Matrix.push_back(newColumn);
                    sum = m1.Matrix[i][j] + m2.Matrix[i][j];
                    resultVecMatrix.Matrix.at(i).push_back(sum);
                }
            }
        }
        return resultVecMatrix;
    }

    VecMatrix AddVecMatrix(VecMatrix &m1, VecMatrix &m2) {
        
    }
}

namespace BabbageGeometryMath {
    struct point { // Pixel based
        static int m_X;
        static int m_Y;
        point(int xPos = 0, int yPos = 0) {
            m_X = xPos;
            m_Y = yPos;
        }
    };

    struct Shape2D { 
        static double m_Width;
        static double m_Height;
        Shape2D() = default;
        Shape2D(double width = 0.0, double height = 0.0) {
            m_Width = width;
            m_Height = height;
        } 
    };

    // Overloads | CHECK ALL OF THESE! | Although they may be correct syntactically the formula's are wrong? | Check middle operator
    Shape2D operator+(Shape2D &s1, Shape2D &s2) {
        return Shape2D(s1.m_Height + s2.m_Height + s1.m_Width + s2.m_Width);
    }

    Shape2D operator-(Shape2D &s1, Shape2D &s2) {
        return Shape2D(s1.m_Height - s2.m_Height - s1.m_Width - s2.m_Width);
    }

    Shape2D operator*(Shape2D &s1, Shape2D &s2) {
        return Shape2D(s1.m_Height * s2.m_Height * s1.m_Width * s2.m_Width);
    }

    struct Shape3D {
        static double m_Width;
        static double m_Height;
        static double m_Depth;
        Shape3D() = default;
        Shape3D(double width = 0.0, double height = 0.0, double depth = 0.0) {
            m_Width = width;
            m_Height = height;
            m_Depth = depth;
        }
    };

    Shape3D operator+(Shape3D &s1, Shape3D &s2) {
        return Shape3D(s1.m_Height + s2.m_Height + s1.m_Width + s2.m_Width + s1.m_Depth + s2.m_Depth);
    }

    Shape3D operator-(Shape3D &s1, Shape3D &s2) { // Change
        return Shape3D(s1.m_Height + s2.m_Height + s1.m_Width + s2.m_Width + s1.m_Depth + s2.m_Depth);
    }

    Shape3D operator*(Shape3D &s1, Shape3D &s2) {
        return Shape3D(s1.m_Height * s2.m_Height * s1.m_Width * s2.m_Width * s1.m_Depth * s2.m_Depth);
    }

    // General
    inline double gPer(Shape2D &s1) { // Square only for now | hence method
        return s1.m_Width + s1.m_Width + s1.m_Height + s1.m_Height;
    }
    inline double gArea(int &a, int &b) { // Possibly don't do objects for users sake | Overcomplicated
        return a * b;
    }
    inline double gVol(Shape3D &s1) {
        return s1.m_Width * s1.m_Height * s1.m_Depth;
    }
    inline double gPythagLong(int a, int b) {
        double c;
        c = a * a + b * b;
        return sqrt(c); // Call own sqrt function when overriden
    }
    inline double gPythagShort(int a, int b) {
        double c;
        c = a * a - b * b;
        return sqrt(c);
    }

    // Circle Math
    struct CircleTheorem {
        inline double Circumfrence(double radius) {
            return 2 * PI * radius;
        }
        inline double CircleArea(double radius) {
            return PI * radius * radius;
        }
    };

    // Triangle Math
    // Possibly add angles
    struct Triangle { // Standard tri with total freedom
        double m_a;
        double m_b;
        double m_c;
        Triangle() = default;
        Triangle(double a, double b, double c) {
            m_a = a;
            m_b = b;
            m_c = c;
        }
    };

    struct ITriangle { // Isosceles
        double m_Height; // The size of the lengths which are equal
        double m_Base;
        ITriangle() = default;
        ITriangle(double height = 1, double base = 1) {
            m_Height = height;
            m_Base = base;
        }
        ITriangle ITriArea(double height, double base);
    };

    struct ETriangle { // Equilateral | Angle always = 60
        double m_Size; // In area cm
        ETriangle() = default;
        ETriangle(double size = 1) {
            m_Size = size;
        }
    };

    struct RTriangle {// Right-Angle
        static double m_Opposite;
        static double m_Adjacent;
        static double m_Hypotenuse;
        RTriangle() = default;
        RTriangle(double oppSize, double adjSize, double hypSize) {
            m_Opposite = oppSize;
            m_Adjacent = adjSize;
            m_Hypotenuse = hypSize;
        }
    };

    // Do function overloading to accomodate triangle structs
    double TriPer(double a, double b, double c) {
        if(a + b > c)
            return(a + b + c);
        else // Do better error handling
            std::cerr << "Babbage Error:- Invalid Input: Ensure a + b > c\n";
    }

    double TriPer(ITriangle &t1) { // Overload for Isosceles
        if(t1.m_Height > t1.m_Base)
            std::cerr << "Babbage Error:- Invalid Input: Ensure b < 2 x a\n";
        else
            return(t1.m_Height * 2 + t1.m_Base);
    }

    double TriPer(ETriangle &t1) { // Overload for Equilateral
        return(t1.m_Size * 3);
    }

    double TriArea(double height, double base) {
        return(height * base / 2);
    }

    double TriArea(double a) { // Equilateral without object
        return(sqrt(3) / 4 * a * a);
    }

    double TriArea(ETriangle &t1) {
        return(sqrt(3) / 4 * t1.m_Size * t1.m_Size);
    }

    double Pythag(double a, double b) { // Right-Angle default
        double c = a * a + b * b;
        return sqrt(c);
    }  

    struct Trigonometry { // Pass in triangles | Possibly remove trig struct
        double hypotenuse;
        double opposite;
        double adjacent;
        inline double gSin(double opposite, double hypotenuse) {
            return opposite / hypotenuse;
        }
        inline double gCos(double hypotenuse, double adjacent) {
            return adjacent / hypotenuse;
        }
        inline double gTan(double opposite, double hypotenuse, double adjacent) {
            return opposite / adjacent; // Continue
        }
    };
}

// Do better with objects. Have struct only be quat itself not functions
namespace BabbageQuatMath {
    struct Quaternion {
        float i;
        float j;
        float k;
        float w;
        float magnitude = 0.0f;
        Quaternion() = default;
        Quaternion(float a, float b, float c, float d) {
            i = a;
            j = b;
            k = c;
            w = d;
        }

        float Magnitude(Quaternion &q1);
        float Normalize(Quaternion &q1);
        Quaternion QuatMult(Quaternion &q1, Quaternion &q2);
    };

    // Operator Overloads

    float Magnitude(Quaternion &q1) {
        float mag = sqrt(q1.w * q1.w + q1.i * q1.i + q1.j * q1.j + q1.k * q1.k);
        return mag;
    }

    float Normailze(Quaternion &q1) {
        q1.magnitude = Magnitude(q1);
        q1.w /= q1.magnitude;
        q1.i /= q1.magnitude;
        q1.j /= q1.magnitude;
        q1.k /= q1.magnitude;
        return q1.magnitude;
    }

    Quaternion QuatMult(Quaternion &q1, Quaternion &q2) {
        Quaternion resultQuat;
        resultQuat.i = q1.i * q2.w + q1.k * q2.k - q1.k * q2.j + q1.w * q2.i;
        resultQuat.j = q1.i * q2.k + q1.w * q2.w + q1.k * q2.i + q1.w * q2.j;
        resultQuat.k = q1.i * q2.j - q1.i * q2.i + q1.k * q2.w + q1.w * q2.k;
        resultQuat.w = q1.i * q2.j - q1.j * q2.j - q1.k * q2.k + q1.w * q2.w;
        return resultQuat;
    }

    Quaternion QuatAdd(Quaternion &q1, Quaternion &q2) {
        Quaternion resultQuat;
        resultQuat.i = q1.i + q2.w;
        resultQuat.j = q1.j + q2.j;
        resultQuat.k = q1.k + q2.k;
        resultQuat.w = q1.w + q2.w;
        return resultQuat;
    }
}

#endif