#ifndef BabbageMath_h
#define BabbageMath_h

#include <iostream>
#include <vector> 
#include <cmath> // Override most functions

#include "BMatrix.h"
#include "BVector.h"

// Definitions
    // General
#define PI 3.14159
#define Euler 2.71828
#define Radian 57.2958

namespace bmath {
    // Basic
    // Not sure about this templating and overloads
    template<typename T> // Template entire namespace instead of per function?
        inline T add(T a, T b)      { return a + b; }
    template<typename T>
        inline T sub(T a, T b)      { return a - b; }
    template<typename T>
        inline T mult(T a, T b)     { return(a * b); }
    template<typename T>
        inline T div(T a, T b)      { return(a / b); }
    
    double bSqrt(double &num) { // Implement
        double result = 0.0;
        return result;
    }

    // Advanced
    inline int floor(float value)    { return static_cast<int>(value); }
    inline int floor(double value)   { return static_cast<int>(value); }
    template<typename T>
    float round(T value, float roundTo) { // 'roundTo' refers to the the digit to round to, similar to floor but with user control
        
    }

    // Comparisons
    template<typename T>
        inline const T Max(T a, T b)     { return (a < b) ? b : a; }
    template<typename T>
        inline const T Min(T a, T b)     { return (a > b) ? a : b; }
    template<typename T>
    inline bool same(T a, T b) {
        if(a == b) return true;
        return false;
    }

    // Conversions -------------------------------------------------
    inline int toASC(char value) { return static_cast<int>(value); }
    inline int toASC(char string[], short size) {
        for(int i = 0; i < size; i++)
            return static_cast<int>(string[i]);
    }
        /* Angles/Rotation */
            // Degrees
    inline double convDegToRad(float deg)       { return deg * PI/180; }
    inline double convDegToGrad(float deg)      { return deg * 200/180; }
    inline double convDegToMinArc(float deg)    { return deg * 60; }
    inline double convDegToSecArc(float deg)    { return deg * 3600; }
            // Radians
    inline double convRadToDeg(float rad)       { return rad * 180/PI; }
    inline double convRadToGrad(float rad)      { return rad * 200/PI; }
    inline double convRadToMinArc(float rad)    { return rad * (60 * 180)/PI; }
    inline double convRadToSecArc(float rad)    { return rad * (3600 * 180)/PI; }
        /* Temperature */
            // Celsius
    inline float convCelToFah(float c)          { return c * 9 / 5 + 32; }
    inline float convCelToKel(float c)          { return c + 273.15; }
            // Fahrenheit               
    inline float convFahToCel(float f)          { return f - 32 * 5 / 9; }
    inline float convFahToKel(float f)          { return f - 32 * 5 / 9 + 273.15; }
        /* Distance */
            // Metres & Centi
    inline float convCMtoMicro(float centi)     { return centi * 10000; }
    inline float convCMtoInch(float centi)      { return centi / 2.54; }
    inline float convCMtoMem(float centi)       { return centi / 100; }
    inline float convMemtoMM(float meters)      { return meters * 1000; }
    inline float convMemtoCM(float meters)      { return meters * 100; }
    inline float convMemtoKM(float meters)      { return meters / 1000; }
    inline float convMemtoMile(float meters)    { return meters / 1609; }
    inline float convMemtoYard(float meters)    { return meters * 1.094; }
    inline float convMemtoInch(float meters)    { return meters * 39.97; }
    inline float convMemtoNMile(float meters)   { return meters / 1852; }
            // Kilometers
    inline float convKMtoCM(float km)           { return km * 10000; }      
    inline float convKMtoMem(float km)          { return km * 1000; }      
    inline float convKMtoMile(float km)         { return km * 0.6214; }
    inline float convKMtoYard(float km)         { return km * 1093.61; }
    inline float convKMtoFoot(float km)         { return km * 3208.84; }
    inline float convKMtoInch(float km)         { return km * 39370; }
    inline float convKMtoNMile(float km)        { return km / 1.852; }
            // Miles
    inline float convMiletoCM(float miles)      { return miles * 160934; }
    inline float convMiletoM(float miles)       { return miles * 1609.34; }
    inline float convMiletoKM(float miles)      { return miles * 1.60934; }
    inline float convMiletoYard(float miles)    { return miles * 1760; }
    inline float convMiletoFoot(float miles)    { return miles * 5280; }
    inline float convMiletoInch(float miles)    { return miles * 63360; }
    inline float convMiletoNMile(float miles)   { return miles / 1.151; }
        /* Time */
            // Seconds
    inline float convSectoMilli(float sec)      { return sec * 1000; }      
    inline float convSectoMin(float sec)        { return sec / 60; }      
    inline float convSectoHour(float sec)       { return sec / 3600; }      
    inline float convSectoDay(float sec)        { return sec / 86400; }      
    inline float convSectoWeek(float sec)       { return sec / 604800; }
            // Minutes
    inline float convMintoMilli(float sec)      { return sec * 60000; } 
    inline float convMintoSec(float sec)        { return sec * 60; } 
    inline float convMintoHour(float sec)       { return sec / 60; } 
    inline float convMintoDay(float sec)        { return sec / 1440; } 
    inline float convMintoWeek(float sec)       { return sec / 10080; } 
    inline float convMintoMonth(float sec)      { return sec / 43800; } 
            // Hours
    inline float convHourtoMin(float sec)       { return sec * 60; } 
    inline float convHourtoSec(float sec)       { return sec * 3600; } 
    inline float convHourtoDay(float sec)       { return sec * 24; } 
    inline float convHourtoDay(float sec)       { return sec / 168; } 
    inline float convHourtoMonth(float sec)     { return sec / 730; } 
    inline float convHourtoYear(float sec)      { return sec / 8760; } 
        /* Energy */
            // Joules
    inline float convJtoKJ(float joule)         { return joule / 1000; } 
    inline float convJtoWattHr(float joule)     { return joule / 3600; } 
    inline float convJtoCal(float joule)        { return joule / 4.184; } 
    inline float convJtoKCal(float joule)       { return joule / 4184; } 
            // Calories
    inline float convCaltoJ(float cal)          { return cal * 4.184; }
    inline float convCaltoKJ(float cal)         { return cal / 239; }
    inline float convCaltoKCal(float cal)       { return cal / 1000; }
    inline float convCaltoWattHr(float cal)     { return cal / 860; }
            // Wattage
    inline float convAVtoWatt(float amps, float volts) { return amps * volts; }

    // Other   
    int random(int range) {
        if(sizeof(range) != sizeof(int) || sizeof(range) != sizeof(float) || sizeof(range) != sizeof(double)) {
            std::cerr << "Babbage Error:-\nINVALID DATATYPE OF: " << typeid(range).name() << '-';
            std::cerr << "Must be int, float or double\n";
            return -1;
        }
        return rand() % range; // Check if 'rand()' can do more than int
    }
    template<typename T>
    std::vector<int> getDigits(T number) { // Returns digits of number in vector format, CHANGE TO ARRAY
        short digit;
        std::vector<int> result{};
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

    struct point { // Pixel based
        static int m_X; // Check!
        static int m_Y;
        point(short xPos = 0, short yPos = 0) {
            m_X = xPos;
            m_Y = yPos;
        }
    };

    struct Shape2D { 
        static double m_Width; // Check!
        static double m_Height;
        Shape2D() = default;
        Shape2D(short width = 1, short height = 1) {
            m_Width = width;
            m_Height = height; 
        }
        ~Shape2D() = default;
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
        Shape3D(short width = 1, short height = 1, short depth = 1) {
            m_Width = width;
            m_Height = height;
            m_Depth = depth;
        }
        ~Shape3D() = default;
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
    inline double gPer(Shape2D &s1)       { return s1.m_Width + s1.m_Width + s1.m_Height + s1.m_Height; } // Square only for now
    inline double gArea(int a, int b)     { return a * b; }
    inline double gVol(Shape3D &s1)       { return s1.m_Width * s1.m_Height * s1.m_Depth; }
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
        struct Circle {
            double m_Radius;
            Circle() = default;
            Circle(short radius = 1)
                :m_Radius(radius)
            {
            }
            ~Circle() = default;
        };
        // Standard
        inline double circum(double radius) { return 2 * PI * radius; }
        inline double circA(double radius)  { return PI * radius * radius; }
        // Object based overloads
        inline double circum(Circle &c)     { return 2 * PI * c.m_Radius; }
        inline double circA(Circle &c)      { return PI * c.m_Radius * c.m_Radius; }
    };

    // Triangle Math | Add angles
    struct Triangle { // Standard tri with total freedom
        double m_a;
        double m_b;
        double m_c;
        Triangle() = default;
        Triangle(double a, double b, double c)
            :m_a(a), m_b(b), m_c(c)
        {
        }
        ~Triangle() = default;
    };

    struct ITriangle { // Isosceles
        double m_Height; // The size of the lengths which are equal
        double m_Base;
        ITriangle(short height = 1, short base = 1)
            :m_Height(height), m_Base(base)
        {
        }
        ITriangle() = default;
        ~ITriangle() = default;
        ITriangle ITriArea(double height, double base);
    };

    struct ETriangle { // Equilateral | Angle always = 60
        double m_Size; // In area cm
        ETriangle(short size = 1) 
            :m_Size(size)
        {
        }
        ~ETriangle() = default;
    };

    struct RTriangle {// Right-Angle
        double m_Opposite;
        double m_Adjacent;
        double m_Hypotenuse;
        RTriangle() = default;
        RTriangle(double oppSize, double adjSize, double hypSize)
            :m_Opposite(oppSize), m_Adjacent(adjSize), m_Hypotenuse(hypSize)
        {
        }
        ~RTriangle() = default;
    };

    // Do function overloading to accomodate triangle structs
    double TPer(double a, double b, double c) {
        if(a + b > c)
            return(a + b + c);
        else // Do better error handling
            std::cerr << "Babbage Error:- Invalid Input: Ensure a + b > c\n";
    }

    double TPer(ITriangle &t1) { // Overload for Isosceles
        if(t1.m_Height > t1.m_Base)
            std::cerr << "Babbage Error:- Invalid Input: Ensure b < 2 x a\n";
        else
            return(t1.m_Height * 2 + t1.m_Base);
    }
    double TPer(ETriangle &t1)               { return(t1.m_Size * 3); } // Overload for Equilateral
    double TArea(double height, double base) { return(height * base / 2); }
    double TArea(double a)                   { return(sqrt(3) / 4 * a * a); } // Equilateral without object
    double TArea(ETriangle &t1)              { return(sqrt(3) / 4 * t1.m_Size * t1.m_Size); }

    // Pythagoras
    double Pythag(double a, double b, std::string side) { // Right-Angle default | Check!
        if(side == "short") {
            double c = a * a + b * b;
            return sqrt(c);
        }
        else if(side == "long") {
            double c = a * a - b * b;
            return sqrt(c);
        }
        else { // Error checking
            std::cerr << "Babbage Error:- Invalid dictation of side to find, must be either: 'short' or 'long'\n";
            return 0.0;
        }
        return 0.0;
    }

    double Pythag(RTriangle &t, std::string side) { // Object based
        if(side == "short") {
            double c = t.m_Opposite * t.m_Opposite + t.m_Adjacent * t.m_Adjacent;
            return sqrt(c);
        }
        else if(side == "long") {
            double c = t.m_Opposite * t.m_Opposite - t.m_Adjacent * t.m_Adjacent;
            return sqrt(c);
        }
        else { // Error checking
            std::cerr << "Babbage Error:- Invalid dictation of side to find, must be either: 'short' or 'long'\n";
            return 0.0;
        }
        return 0.0;
    }

    // Trigonometry
        // Standard
    inline double sin(double opposite, double hypotenuse) { return opposite / hypotenuse; }
    inline double cos(double hypotenuse, double adjacent) { return adjacent / hypotenuse; }
    inline double tan(double opposite, double adjacent)   { return opposite / adjacent; }
        // RTriangle object overloads
    inline double sin(RTriangle &t) { return t.m_Opposite / t.m_Hypotenuse; }
    inline double cos(RTriangle &t) { return t.m_Adjacent / t.m_Hypotenuse; }
    inline double tan(RTriangle &t) { return t.m_Opposite / t.m_Adjacent; }

    struct Quaternion {
        float i; float j;
        float k; float w;
        float magnitude = 0.0f;
        Quaternion(float a = 0.0f, float b = 0.0f, float c = 0.0f, float d = 0.0f)
            :i(a), j(b), k(c), w(d)
        {
        }
        ~Quaternion() = default;
        // Creation | ADD!
        // Math
        float QMag(Quaternion &q1);
        float QNorm(Quaternion &q1);
        Quaternion QAdd(Quaternion &q1, Quaternion &q2);
        Quaternion QMult(Quaternion &q1, Quaternion &q2);
    };

    // Operator Overloads

    float Quaternion::QMag(Quaternion &q1) {
        float mag = sqrt(q1.w * q1.w + q1.i * q1.i + q1.j * q1.j + q1.k * q1.k);
        return mag;
    }

    float Quaternion::QNorm(Quaternion &q1) {
        q1.magnitude = QMag(q1);
        q1.w /= q1.magnitude;
        q1.i /= q1.magnitude;
        q1.j /= q1.magnitude;
        q1.k /= q1.magnitude;
        return q1.magnitude;
    }

    Quaternion Quaternion::QMult(Quaternion &q1, Quaternion &q2) {
        Quaternion resultQuat;
        resultQuat.i = q1.i * q2.w + q1.k * q2.k - q1.k * q2.j + q1.w * q2.i;
        resultQuat.j = q1.i * q2.k + q1.w * q2.w + q1.k * q2.i + q1.w * q2.j;
        resultQuat.k = q1.i * q2.j - q1.i * q2.i + q1.k * q2.w + q1.w * q2.k;
        resultQuat.w = q1.i * q2.j - q1.j * q2.j - q1.k * q2.k + q1.w * q2.w;
        return resultQuat;
    }

    Quaternion Quaternion::QAdd(Quaternion &q1, Quaternion &q2) {
        Quaternion resultQuat;
        resultQuat.i = q1.i + q2.w;
        resultQuat.j = q1.j + q2.j;
        resultQuat.k = q1.k + q2.k;
        resultQuat.w = q1.w + q2.w;
        return resultQuat;
    }
}

#endif