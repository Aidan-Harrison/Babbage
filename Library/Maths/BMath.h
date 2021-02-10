#ifndef BabbageMath_h
#define BabbageMath_h

#include <iostream>
#include <vector> 
#include <cmath> // Override most functions
#include <cassert>

#include "BMatrix.h"
#include "BVector.h"

// Definitions
    // General
#define PI 3.14159
#define Euler 2.71828
#define Radian 57.2958

namespace bmath {
    // Basic
    template<typename T>
        inline T add(T a, T b)  { return a + b; }
    template<typename T>
        inline T sub(T a, T b)  { return a - b; }
    template<typename T>
        inline T mult(T a, T b) { return a * b; }
    template<typename T>
        inline T div(T a, T b)  { return a / b; }
    template<typename T>
        inline T bSqr(T a) { return a * a; }
    template<typename T>
        inline T bCub(T a) { return a * a * a; }

    // Advanced
    inline int floor(float value)    { return static_cast<int>(value); }
    inline int floor(double value)   { return static_cast<int>(value); }
    template<typename T>
    float round(T value, float roundTo) { // 'roundTo' refers to the the digit to round to, similar to floor but with user control
        switch (roundTo) {
            case 1: static_cast<int>(value); break; // Floors
            case 10:    break;
            case 100:   break;
            case 1000:  break;
        }
    }

    // Comparisons
    template<typename T>
        inline const T Max(T a, T b)  { return (a < b) ? b : a; }
    template<typename T>
        inline const T Min(T a, T b)  { return (a > b) ? a : b; }
    template<typename T>
    inline bool same(T a, T b) {
        if(a == b) return true;
        return false;
    }

    // Conversions -------------------------------------------------
    inline int toASC(char value) { return static_cast<int>(value); }
    inline int toASC(const char* string, short size) {
        for(unsigned int i = 0; i < size; i++)
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
            std::cerr << "Babbage Error:- INVALID DATATYPE OF: " << typeid(range).name() << " - Must be int, float or double\n";
            return -1;
        }
        return rand() % range; // Handle other datatypes
    }

    // Graphics and Geometry
    struct Point { // Pixel based
        static short m_X, m_Y;
        Point(short xPos = 0, short yPos = 0) {
            m_X = xPos;
            m_Y = yPos;
        }
        inline int GetX() const { return m_X; }
        inline int GetY() const { return m_Y; }
        inline int GetPos() const { return m_X && m_Y; } // Check!
        inline void deletePoint(Point p) { delete &p; }
    };

    struct Shape2D { 
        double m_Width, m_Height;
        Shape2D() = default;
        Shape2D(short width = 1, short height = 1) 
            :m_Width(width), m_Height(height)
        {
            assert(m_Width != 0 && m_Height != 0);
        }
        // Move Constructor | Fix
        Shape2D(Shape2D &&shape) noexcept
            :m_Width(shape.m_Width), m_Height(shape.m_Height)
        {
            m_Width = 0, m_Height = 0; // Check!
        }
        // Move assignment | Fix
        Shape2D& operator=(Shape2D &&shape) noexcept {
                // Self detection
            if(&shape == this)
                return *this;
                // Free data
            delete &m_Width;            
            delete &m_Height;            
                // Move values
            m_Width = shape.m_Width;
            m_Height = shape.m_Height;
            return *this;
        }
        inline double GetWidth() const { return m_Width; }
        inline double GetHeight() const { return m_Height; }
        inline void deleteShape2D(Shape2D s) { delete &s; }
    };

    // Overloads | CHECK ALL OF THESE! | both syntatics and formulas
    Shape2D operator+(Shape2D &s1, Shape2D &s2) { return Shape2D(s1.m_Height + s2.m_Height + s1.m_Width + s2.m_Width); }
    Shape2D operator-(Shape2D &s1, Shape2D &s2) { return Shape2D(s1.m_Height - s2.m_Height - s1.m_Width - s2.m_Width); }
    Shape2D operator*(Shape2D &s1, Shape2D &s2) { return Shape2D(s1.m_Height * s2.m_Height * s1.m_Width * s2.m_Width); }

    struct Shape3D {
        double m_Width, m_Height, m_Depth;
        Shape3D() = default;
        Shape3D(short width = 1, short height = 1, short depth = 1) 
            :m_Width(width), m_Height(height), m_Depth(depth)
        {
            assert(m_Width != 0 && m_Height != 0 && m_Depth != 0);
        }
        Shape3D(Shape3D && shape) noexcept 
            :m_Width(shape.m_Width), m_Height(shape.m_Height), m_Depth(shape.m_Depth)
        {
            m_Width = 0, m_Height = 0, m_Depth = 0;
        }
        Shape3D& operator=(Shape3D &&shape) noexcept 
        {
            if(&shape == this)
                return *this;
            delete &m_Width;
            delete &m_Height;
            delete &m_Depth;
            m_Width = shape.m_Width;
            m_Width = shape.m_Height;
            return *this;
        }
        inline double GetWidth() const { return m_Width; }
        inline double GetHeight() const { return m_Height; }
        inline double GetDepth() const { return m_Depth; }
        inline void deleteShape3D(Shape3D s) { delete &s; }
    };

    Shape3D operator+(Shape3D &s1, Shape3D &s2) { return Shape3D(s1.m_Height + s2.m_Height + s1.m_Width + s2.m_Width + s1.m_Depth + s2.m_Depth); }
    Shape3D operator*(Shape3D &s1, Shape3D &s2) { return Shape3D(s1.m_Height * s2.m_Height * s1.m_Width * s2.m_Width * s1.m_Depth * s2.m_Depth); }

    // General
    inline double gPer(Shape2D &s1)   { return s1.m_Width + s1.m_Width + s1.m_Height + s1.m_Height; } // Square only for now
    inline double gArea(int a, int b) { return a * b; }
    inline double gVol(Shape3D &s1)   { return s1.m_Width * s1.m_Height * s1.m_Depth; }

    // Circle Math
    struct Circle {
        double m_Radius, m_Circumfrence;
        Circle() = default;
        Circle(short radius = 1)
            :m_Radius(radius), m_Circumfrence(2 * PI * radius) // Check!
        {
            assert(m_Radius != 0);
        }
        Circle(Circle &&circ) noexcept 
            :m_Radius(circ.m_Radius), m_Circumfrence(circ.m_Circumfrence)
        {
            m_Radius = 0, m_Circumfrence = 0;
        }
        Circle& operator=(Circle &&circ) noexcept 
        {
            if(&circ == this)
                return *this;
            delete &m_Radius;
            delete &m_Circumfrence;
            m_Radius = circ.m_Radius;
            m_Circumfrence = circ.m_Circumfrence;
            return *this;
        }
        inline double GetRad() const { return m_Radius; }
        inline double GetCirc() const { return m_Circumfrence; }
        template<typename T>
        double circArea(T radius) { return PI * radius * radius; }
        double circArea(Circle &c) { return PI * c.m_Radius * c.m_Radius; }
        template<typename T>
        double diameter(T radius) { return radius * 2; }
        double diameter(Circle &c) { return c.m_Radius * 2; }
        template<typename T>
        double circumfrence(T radius) { return 2 * PI * radius; }
        double circumfrence(Circle &c) { return 2 * PI * c.m_Radius; }
        template<typename T>
        double radius(T cir) { return cir / 2 * PI; }
        double radius(Circle &c) { return c.m_Circumfrence / 2 * PI; } // Check!
        inline void deleteCircle(Circle c) { delete &c; }
        ~Circle() = default;
    };

    // Triangle Math
    struct Triangle { // Standard tri with total freedom
        double m_a, m_b, m_c;
        float m_AngleA, m_AngleB, m_AngleC; // Do angle calculation
        bool isEquilateral = false, isIsocoles = false, isScalene = false, isRightAngled = false;
        Triangle() = default;
        Triangle(double a, double b, double c)
            :m_a(a), m_b(b), m_c(c)
        {
            assert(m_a != 0 && m_b != 0 && m_c != 0);
            check(); // Runs initially see to if their is a match
        }
        bool check() { // Checks what type of triangle it is | Add right angle once angle calcs are in
            if(m_a == m_b && m_a == m_c) return isEquilateral = true;
            else if(m_a == m_b || m_a == m_c || m_b == m_c) return isIsocoles = true;
            else if(m_a == 90.0 || m_b == 90.0 || m_c == 90.0) return isRightAngled = true;
            else return isScalene = true;
        } 
        inline double GetA() const { return m_a; }
        inline double GetB() const { return m_b; }
        inline double GetC() const { return m_c; }
        inline double getAngleA() const { return m_AngleA;}
        inline double getAngleB() const { return m_AngleB;}
        inline double getAngleC() const { return m_AngleC;}
        float gamma(Triangle &t) { // Calculates angle | Continue | Do standard overload outside this class
            float gamma = sinf(m_a * 2 / m_a * m_b); // Change to custom sin function
            return gamma;
        }
        inline void deleteTri(Triangle t) { delete &t; }
        ~Triangle() = default;
    };

    struct ITriangle { // Isosceles
        double m_Height, m_Base; // Height = equal sides
        float m_AngleA, m_AngleB, m_AngleC;
        ITriangle(short height = 1, short base = 1)
            :m_Height(height), m_Base(base)
        {
            assert(m_Height != 0 && m_Base != 0);
        }
        ITriangle() = default;
        inline double GetHeight() const { return m_Height; }
        inline double GetBase() const { return m_Base; }
        inline double getAngleA() const { return m_AngleA; }
        inline double getAngleB() const { return m_AngleB; }
        inline double getAngleC() const { return m_AngleC; }
        inline void deleteITri(ITriangle t) { delete &t; }
        ~ITriangle() = default;
    };

    struct ETriangle { // Equilateral | Angle always = 60
        double m_Size; // In area cm
        const float m_Angle = 60;
        ETriangle(short size = 1) 
            :m_Size(size)
        {
            assert(m_Size != 0);
        }
        inline double GetSize() const { return m_Size; }
        inline double getAngle() const { return m_Angle; }
        inline void deleteETri(ETriangle t) { delete &t; }
        ~ETriangle() = default;
    };

    struct RTriangle {// Right-Angle
        double m_Opposite, m_Adjacent, m_Hypotenuse;
        const float m_RightAngle = 90;
        RTriangle() = default;
        RTriangle(double oppSize, double adjSize, double hypSize)
            :m_Opposite(oppSize), m_Adjacent(adjSize), m_Hypotenuse(hypSize)
        {
            assert(m_Opposite != 0 && m_Adjacent != 0 && m_Hypotenuse != 0);
        }
        inline double GetOpp() const { return m_Opposite; }
        inline double GetAdj() const { return m_Adjacent; }
        inline double GetHyp() const { return m_Hypotenuse; }
        inline void deleteRTri(RTriangle t) { delete &t; }
        ~RTriangle() = default;
    };

        // Perimeter
    double TPer(double a, double b, double c) {
        if(a + b > c) return a + b + c;
        else std::cerr << "Babbage Error:- Invalid Input: Ensure a + b > c\n";
    }
    double TPer(Triangle &t) {
        if(t.m_a + t.m_b > t.m_c) return t.m_a + t.m_b + t.m_c;
        else std::cerr << "Babbage Error:- Invalid Input: Ensure a + b > c\n";
    }
    double TPer(ITriangle &t) { // Overload for Isosceles
        if(t.m_Height > t.m_Base) std::cerr << "Babbage Error:- Invalid Input: Ensure b < 2 x a\n";
        else return t.m_Height * 2 + t.m_Base;
    }
    double TPer(ETriangle &t) { 
        return(t.m_Size * 3); 
    }
        // Semi-Perimeter
    double semiTPer(double a, double b, double c) {
        if(a + b > c) return a + b + c / 2;
        else std::cerr << "Babbage Error:- Invalid Input: Ensure a + b > c\n";
    }
    double semiTPer(Triangle &t) {
        if(t.m_a + t.m_b > t.m_c) return t.m_a + t.m_b + t.m_c / 2;
        else std::cerr << "Babbage Error:- Invalid Input: Ensure a + b > c\n";
    }
    double semiTPer(ITriangle &t) {
        if(t.m_Height > t.m_Base) std::cerr << "Babbage Error:- Invalid Input: Ensure b < 2 x a\n";
        else return t.m_Height * 2 + t.m_Base / 2;
    }
    double semiTPer(ETriangle &t) { return(t.m_Size * 3 / 2); }
        // Area
    double TArea(double height, double base) { return(height * base / 2); }
    double TArea(double a)                   { return(sqrt(3) / 4 * a * a); } // Equilateral without object
    double TArea(ETriangle &t)               { return(sqrt(3) / 4 * t.m_Size * t.m_Size); }
    double TArea(ITriangle &t)               { return t.m_Base * t.m_Height * 2 / 2; } // Check!
    // Pythagoras
    double Pythag(double a, double b, std::string side) {
        if(side == "short") {
            double c = a * a + b * b;
            return sqrt(c);
        }
        else if(side == "long") {
            double c = a * a - b * b;
            return sqrt(c);
        }
        else {
            std::cerr << "Babbage Error:- Invalid dictation of side to find, must be either: 'short' or 'long'\n";
            exit(1);
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
        else {
            std::cerr << "Babbage Error:- Invalid dictation of side to find, must be either: 'short' or 'long'\n";
            exit(1);
        }
        return 0.0;
    }

    // Trigonometry | Fix first three
        // Standard
    inline double sin(double opposite, double hypotenuse) { return opposite / hypotenuse; }
    inline double cos(double hypotenuse, double adjacent) { return adjacent / hypotenuse; }
    inline double tan(double opposite, double adjacent)   { return opposite / adjacent; }
    inline double csc(double hypotenuse, double opposite) { return hypotenuse / opposite; } // Cosecant
    inline double sec(double hypotenuse, double adjacent) { return hypotenuse / adjacent; } // Secant
    inline double cot(double adjacent, double opposite)   { return adjacent / opposite; }   // Cotangent

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
        // Move constructor
        Quaternion(Quaternion &&quat) noexcept
            :i(quat.i), j(quat.j), k(quat.k), w(quat.w)
        {    
        } 
        // Move assignment
        Quaternion& operator=(Quaternion &&quat) noexcept {
                // Self detection
            if(&quat == this)
                return *this;
                // Free data
            delete &i;            
            delete &j;            
            delete &k;            
            delete &w;            
                // Move values
            i = quat.i;
            j = quat.j;
            k = quat.k;
            w = quat.w;
            return *this;
        }
        // Operator Overloads
        // Math
        float QMag(Quaternion &q1) {
            float mag = sqrt(q1.w * q1.w + q1.i * q1.i + q1.j * q1.j + q1.k * q1.k);
            return mag;
        }
        float QNorm(Quaternion &q1) {
            q1.magnitude = QMag(q1);
            q1.w /= q1.magnitude;
            q1.i /= q1.magnitude;
            q1.j /= q1.magnitude;
            q1.k /= q1.magnitude;
            return q1.magnitude;
        }
        Quaternion QMult(Quaternion &q1, Quaternion &q2) {
            Quaternion resultQuat;
            resultQuat.i = q1.i * q2.w + q1.k * q2.k - q1.k * q2.j + q1.w * q2.i;
            resultQuat.j = q1.i * q2.k + q1.w * q2.w + q1.k * q2.i + q1.w * q2.j;
            resultQuat.k = q1.i * q2.j - q1.i * q2.i + q1.k * q2.w + q1.w * q2.k;
            resultQuat.w = q1.i * q2.j - q1.j * q2.j - q1.k * q2.k + q1.w * q2.w;
            return resultQuat;
        }
        Quaternion QAdd(Quaternion &q1, Quaternion &q2) {
            Quaternion resultQuat;
            resultQuat.i = q1.i + q2.w;
            resultQuat.j = q1.j + q2.j;
            resultQuat.k = q1.k + q2.k;
            resultQuat.w = q1.w + q2.w;
            return resultQuat;
        }
        inline void deleteQuat(Quaternion q) { delete &q; }
        ~Quaternion() = default;
    };
}

#endif