#pragma once
// Maths library
// Research use of doubles
class BabbageMath {
private:
public:
    struct values {
        double x{0}; // Make use of these in functions?
        double y{0};
        double z{0};
    };
    // Overloads

    // Basic
    double Add(double a, double b);
    double Subtract(double a, double b);
    double Divide(double a, double b);
    double Multiply(double a, double b);

    // Comparisons
    const double Max(double a, double b); // Possibly remove const and ref | Most likely
    const double Min(double a, double b);
    bool Same(double a, double b);

    // Conversions
    int toASC(char value);
    double convRadToDeg(double radians);
    double convDegToRad(double degrees);
    double convCelToFah(double c);
    double convFahToCel(double f);

    // Other
    int random(int range);
    std::vector<int> getDigits(int number);
};

// Vector (Move vector to math library)
// Incorrect arguments for functions
class VectorMath { // Implement graphics library into this, properly implement function arguments
private: // Possibly do not have structs in private access
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
public:
        // Vector 2
        float vecMag(Vector2 vec1, Vector2 vec2);
        float addVec(Vector2 vec1, Vector2 vec2);
        float subVec(Vector2 vec1, Vector2 vec2);
        float dotProd(Vector2 vec1, Vector2 vec2);

        // Vector3
        void addVec3();
        void crossProd();
};

class MatrixMath {
private:
    std::vector<std::vector<int>> matrix{{}};
    int rows = 0;
    int columns = 0;
public:
    std::vector<std::vector<int>> fillMatrix(std::vector<std::vector<int>>& matrix, int input);
    std::vector<std::vector<int>> printMatrix(std::vector<std::vector<int>>& matrix);
    std::vector<std::vector<int>> addMatrix(std::vector<std::vector<int>>& matrix);
    std::vector<std::vector<int>> subMatrix(std::vector<std::vector<int>>& matrix);
    std::vector<std::vector<int>> multMatrix(std::vector<std::vector<int>>& matrix);
};

class GeometryMath {
private: // Possibly have some static members
    int length;
    int width;
    int height;
public:
    // Overloads
    GeometryMath operator+ (GeometryMath geo) { // Override + for geo calculations | May only work on volumes | Research overloading more
        GeometryMath newVal;
        newVal.length = length + geo.length; // Last operand equal to right hand side operand
        newVal.width = width + geo.width;
        newVal.height = height + geo.height;
        return newVal;
    }

    GeometryMath operator-(GeometryMath geo) {
        GeometryMath newVal;
        newVal.length = length - geo.length;
        newVal.width = width - geo.width;
        newVal.height = height - geo.height;
        return newVal;
    }

    GeometryMath operator*(GeometryMath geo) {
        GeometryMath newVal;
        newVal.length = length * geo.length;
        newVal.width = width * geo.width;
        newVal.height = height * geo.height;
        return newVal;
    }

    GeometryMath operator/(GeometryMath geo) {
        GeometryMath newVal;
        newVal.length = length / geo.length;
        newVal.width = width / geo.width;
        newVal.height = height / geo.height;
        return newVal;
    }

    // General
    int gPer(int a, int b);
    int gVol(int a, int b, int c);
    int gArea(int a, int b);
    int gPythagLong(int a, int b);
    int gPythagShort(int a, int b);

    struct CircleTheorem {
        double Circumfrence(double radius);
        double CircleArea(double radius);
    };

    class Trigonometry  {
        private:
            // Possible incorporate some static members | Do it for most classes??
            static double hypotenuse;
            static double opposite;
            static double adjacent;
        public:
            double gSin(double opposite, double hypotenuse);
            double gCos(double hypotenuse, double adjacent);
            double gTan(double opposite, double hypotenuse, double adjacent);
    };
    
};