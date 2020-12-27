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

namespace BabbageMatrixMath {
    struct Matrix {
        unsigned int m_Rows;
        unsigned int m_Columns;
        Matrix(int rows = 0, int columns = 0) {
            m_Rows = rows;
            m_Columns = columns;
        }
        std::vector<std::vector<int>> matrix{{}}; // Template
        Matrix CreateMatrix(int &rows, int &columns);
        void PrintMatrix(Matrix &matrix);
        Matrix AddMatrix(Matrix &m1, Matrix &m2);
        Matrix SubMatrix(Matrix &m1, Matrix &m2);
        Matrix MultMatrix(Matrix &m1, Matrix &m2);
    };

    // Operator Overloads

    Matrix CreateMatrix(int rows, int columns) {
        Matrix m1;
        for(int i = 0; i < rows; i++)
            m1.matrix[rows].push_back(1);
            for(int j = 0; j < columns; j++)
                m1.matrix[columns].push_back(1);
        return m1;
    }

    void PrintMatrix(Matrix &matrix) {
        for(int i = 0; i < matrix.matrix.size(); i++) {
            for(int j = 0; j < matrix.matrix.size(); j++)
                std::cout << matrix.matrix[i][j] << ", ";
            std::cout << '\n';
        }
    }

    // Work on calculation and return | Convert to C array
    Matrix AddMatrix(Matrix &m1, Matrix &m2) {
        Matrix resultMatrix{{}};
        if(m1.matrix.size() != m2.matrix.size()) {
            std::cerr << "Babbage Error:-\nINVALID MATRIX SIZE'S OF: " << m1.matrix.size() << " AND " << m2.matrix.size();
            std::cerr << "Must be equal\n";
            return m1;
        }
        else {
            int sum = 0;
            for(int i = 0; i < m1.matrix.size(); i++) {
                for(int j = 0; j < m1.matrix.size(); j++) { // Incorrect but close
                    std::vector<int> newColumn;
                    resultMatrix.matrix.push_back(newColumn);
                    sum = m1.matrix[i][j] + m2.matrix[i][j];
                    resultMatrix.matrix.at(i).push_back(sum);
                }
            }
        }
        return resultMatrix;
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

    struct Triangle {
        static double m_Angle1;
        static double m_Angle2;
        static double m_Angle3;
        Triangle() = default;
        Triangle(double angle1, double angle2, double angle3) {
            m_Angle1 = angle1;
            m_Angle2 = angle2;
            m_Angle3 = angle3;
        }
    };

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

    struct CircleTheorem {
        inline double Circumfrence(double radius) {
            return 2 * PI * radius;
        }
        inline double CircleArea(double radius) {
            return PI * radius * radius;
        }
    };

    struct Trigonometry  {
        double hypotenuse;
        double opposite;
        double adjacent;
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

    // Add angle struct
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

    Quaternion QuatMult(Quaternion &q1, Quaternion &q2) { // Quat mulitplication
        Quaternion resultQuat;
        resultQuat.i = q1.i * q2.w + q1.k * q2.k - q1.k * q2.j + q1.w * q2.i;
        resultQuat.j = q1.i * q2.k + q1.w * q2.w + q1.k * q2.i + q1.w * q2.j;
        resultQuat.k = q1.i * q2.j - q1.i * q2.i + q1.k * q2.w + q1.w * q2.k;
        resultQuat.w = q1.i * q2.j - q1.j * q2.j - q1.k * q2.k + q1.w * q2.w;
        return resultQuat;
    }
}

#endif