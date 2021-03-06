#ifndef BabbageMath_h
#define BabbageMath_h

#include <iostream>
#include <vector> 
#include <tuple> // Utilise
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
    template<typename T> // Improve?
        inline T add(T a, T b) { return a + b; }
    template<typename T>
        inline T sub(T a, T b) { return a - b; }
    template<typename T>
        inline T mult(T a, T b){ return a * b; }
    template<typename T>
        inline T div(T a, T b) { return a / b; }
    template<typename T>
        inline T bSqr(T a) { return a * a; }
    template<typename T>
        inline T bCub(T a) { return a * a * a; }
    template<typename T>
        long bPow(T a, int amount) {
            long newAmount = 0;
            for(unsigned int i = 0; i < amount; i++)
                newAmount *= a * a;
            return newAmount;
        }

    // Advanced
    inline int floor(float value)  { return static_cast<int>(value); }
    inline int floor(double value) { return static_cast<int>(value); }
    // Do
    template<typename T>
    float round(T value, float roundTo) { // 'roundTo' refers to the the digit to round to, similar to floor but with user control
        switch (roundTo) {
            case 1: static_cast<int>(value); break; // Floors
            case 10:    break;
            case 100:   break;
            case 1000:  break;
        }
    }

    template<typename T>
    T clamp(T value, int min, int max) {
        value = std::min(std::max(value, min), max);
        return value;
    }

    void FastDiv(int m) {

    }

    // Comparisons
    template<typename T>
        inline T Max(const T a, const T b) { return (a < b) ? b : a; }
    template<typename T>
        inline T Min(const T a, const T b) { return (a > b) ? a : b; }
    template<typename T>
    inline bool Equal(const T a, const T b) {
        if(a == b) return true;
        return false;
    }
    template<typename T> // Do vector overload?
    inline T* Average(T values[], int size) {
        std::sort(values); // Check!
        int amount = 0;
        for(unsigned int i = 0; i <= size; i++ ) {
            return;
        }
        return;
    }

    // Conversions -------------------------------------------------
    inline int toASC(char value) { 
        return static_cast<int>(value); 
    }
    std::vector<int> toASC(const char* string, const int size) { // Convert to C array for performance | Check const!
        int charNum = 0;
        std::vector<int> numbers = {};
        for(unsigned int i = 0; i < size; i++) {
            charNum = static_cast<int>(string[i]);
            numbers.push_back(charNum);
        }
        return numbers;
    }
    std::vector<int> toASC(std::string string) { // std::string overload | Pass by reference?
        int charNum = 0;
        std::vector<int> numbers = {};
        for(unsigned int i = 0; i < string.length(); i++) {
            charNum = static_cast<int>(string[i]);
            numbers.push_back(charNum);
        }
        return numbers;
    }
        /* Angles/Rotation */
            // Degrees
    inline float convDegToRad(float deg)     { deg * PI / 180; return deg; }
    inline float convDegToGrad(float deg)    { deg * 200/ 180; return deg; }
    inline float convDegToMinArc(float deg)  { deg * 60; return deg; }
    inline float convDegToSecArc(float deg)  { deg * 3600; return deg; }
            // Radians
    inline float convRadToDeg(float rad)     { rad * 180 / PI; return rad; }
    inline float convRadToGrad(float rad)    { rad * 200 / PI; return rad; }
    inline float convRadToMinArc(float rad)  { rad * (60 * 180) / PI; return rad; }
    inline float convRadToSecArc(float rad)  { rad * (3600 * 180) / PI; return rad; }
        /* Temperature */
            // Celsius
    inline float convCelToFah(float c)       { c * 9 / 5 + 32; return c; }
    inline float convCelToKel(float c)       { c + 273.15; return c; }
            // Fahrenheit               
    inline float convFahToCel(float f)       { f - 32 * 5 / 9; return f; }
    inline float convFahToKel(float f)       { f - 32 * 5 / 9 + 263.15; return f; }
        /* Distance */
            // Metres & Centi
    inline float convCMtoMicro(float centi)  { centi * 10000; return centi; }
    inline float convCMtoInch(float centi)   { centi / 2.54;  return centi; }
    inline float convCMtoMem(float centi)    { centi / 100;   return centi; }
    inline float convMemtoMM(float meters)   { meters * 1000; return meters; }
    inline float convMemtoCM(float meters)   { meters * 100;  return meters; }
    inline float convMemtoKM(float meters)   { meters / 1000; return meters; }
    inline float convMemtoMile(float meters) { meters / 1609; return meters; }
    inline float convMemtoYard(float meters) { meters * 1.094;return meters; }
    inline float convMemtoInch(float meters) { meters * 39.97;return meters; }
    inline float convMemtoNMile(float meters){ meters / 1852; return meters; }
            // Kilometers
    inline float convKMtoCM(float km)        { km * 10000;  return km; }      
    inline float convKMtoMem(float km)       { km * 1000;   return km; }      
    inline float convKMtoMile(float km)      { km * 0.6214; return km; }
    inline float convKMtoYard(float km)      { km * 1093.61;return km; }
    inline float convKMtoFoot(float km)      { km * 3208.84;return km; }
    inline float convKMtoInch(float km)      { km * 39370;  return km; }
    inline float convKMtoNMile(float km)     { km / 1.852;  return km; }
            // Miles
    inline float convMiletoCM(float miles)   { miles * 160934; return miles; }
    inline float convMiletoM(float miles)    { miles * 1609.34;return miles; }
    inline float convMiletoKM(float miles)   { miles * 1.60934;return miles; }
    inline float convMiletoYard(float miles) { miles * 1760;   return miles; }
    inline float convMiletoFoot(float miles) { miles * 5280;   return miles; }
    inline float convMiletoInch(float miles) { miles * 63360;  return miles; }
    inline float convMiletoNMile(float miles){ miles / 1.151;  return miles; }
        /* Time */
            // Seconds
    inline float convSectoMilli(float sec)   { sec * 1000;  return sec; }      
    inline float convSectoMin(float sec)     { sec / 60;    return sec; }      
    inline float convSectoHour(float sec)    { sec / 3600;  return sec; }      
    inline float convSectoDay(float sec)     { sec / 86400; return sec; }      
    inline float convSectoWeek(float sec)    { sec / 604800;return sec; }
            // Minutes
    inline float convMintoMilli(float sec)   { sec * 60000;return sec; } 
    inline float convMintoSec(float sec)     { sec * 60;   return sec; } 
    inline float convMintoHour(float sec)    { sec / 60;   return sec; } 
    inline float convMintoDay(float sec)     { sec / 1440; return sec; } 
    inline float convMintoWeek(float sec)    { sec / 10080;return sec; } 
    inline float convMintoMonth(float sec)   { sec / 43800;return sec; } 
            // Hours
    inline float convHourtoMin(float sec)    { sec * 60;  return sec; } 
    inline float convHourtoSec(float sec)    { sec * 3600;return sec; } 
    inline float convHourtoDay(float sec)    { sec * 24;  return sec; } 
    inline float convHourtoDay(float sec)    { sec / 168; return sec; } 
    inline float convHourtoMonth(float sec)  { sec / 730; return sec; } 
    inline float convHourtoYear(float sec)   { sec / 8760;return sec; } 
        /* Energy */
            // Joules
    inline float convJtoKJ(float joule)      { joule / 1000; return joule; } 
    inline float convJtoWattHr(float joule)  { joule / 3600; return joule; } 
    inline float convJtoCal(float joule)     { joule / 4.184;return joule; } 
    inline float convJtoKCal(float joule)    { joule / 4184; return joule; } 
            // Calories
    inline float convCaltoJ(float cal)       { cal * 4.184;return cal; }
    inline float convCaltoKJ(float cal)      { cal / 239;  return cal; }
    inline float convCaltoKCal(float cal)    { cal / 1000; return cal; }
    inline float convCaltoWattHr(float cal)  { cal / 860;  return cal; }
            // Wattage
    inline float convAVtoWatt(float amps, float volts) { return amps * volts; }

    // Other 

    // Graphics and Geometry
    class Point { // Pixel based
    private:
        int pos[2] = {0,0};
        int col[3] = {0,0,0};
    public:
        Point(const int xPos = 0, const int yPos = 0) 
        {
            pos[0] = xPos;
            pos[1] = yPos;
        }
        inline int getX() const { return pos[0]; }
        inline int getY() const { return pos[1]; }
        // DO BOTH RETURN
        void setPos(int x, int y) { 
            pos[0] = x; 
            pos[y] = y;
        }
    };

    class Shape2D { // Allow for more then Quad
    private:
        int amountOfSides = 4; // Defaults to a Quad, if 3 create a triangle object, deletes this | Possibly allow for lines and points
    public:
        float m_Width, m_Height;
        Shape2D(const int sides = 4, const float width = 1.0f, const float height = 1.0f) 
            :amountOfSides(sides), m_Width(width), m_Height(height)
        {
            assert(amountOfSides != 0 && m_Width != 0 && m_Height != 0);
            if(amountOfSides == 3)
                Triangle *t = new Triangle(0.0f, 0.0f, 0.0f);
        }
        // Move Constructor | Fix
        Shape2D(Shape2D &&shape) noexcept
            :m_Width(shape.m_Width), m_Height(shape.m_Height)
        {
            m_Width = 0, m_Height = 0; // Check!
        }
        // Move assignment | Fix!
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
        std::string GetType() const { // Pointless!
            switch(amountOfSides) { 
                case 4: return "Quad"; break;
                case 5: return "Pent"; break;
                case 6: return "Hex";  break;
                case 7: return "Hept"; break;
                case 8: return "Oct";  break;
            }
        }
        inline float getSides()  const { return amountOfSides; }
        inline float getWidth()  const { return m_Width; }
        inline float getHeight() const { return m_Height; }
        inline float getPer()    const {return m_Width + m_Width + m_Height + m_Height;} // Quad only | Change
        inline float getArea()   const {return m_Width * 2 + m_Height * 2; }

        // Chainable functions
        Shape2D& getPerC() {m_Width + m_Width + m_Height + m_Height; return *this; }
        Shape2D& getAreaC() {m_Width * 2 + m_Height; return *this; }
        Shape2D& changeSidesC(int sides) {amountOfSides = sides; return *this; } // Possibly add safety?

        ~Shape2D() {}
    };
        // Overloads | CHECK ALL OF THESE! | both syntatics and formulas | Reference return?
    Shape2D operator+(Shape2D &s1, Shape2D &s2) { return Shape2D(s1.m_Height + s2.m_Height + s1.m_Width + s2.m_Width); }
    Shape2D operator-(Shape2D &s1, Shape2D &s2) { return Shape2D(s1.m_Height - s2.m_Height - s1.m_Width - s2.m_Width); }
    Shape2D operator*(Shape2D &s1, Shape2D &s2) { return Shape2D(s1.m_Height * s2.m_Height * s1.m_Width * s2.m_Width); }

    class Shape3D { // In Meters
    private:
        bool isPrism = false; // Alters formulas
        bool isPyramid = false; // (Right-Rectangular Pyramid only!) | Allow for tri based?
    public:
        float m_Width, m_Height, m_Depth;
        Shape3D(int width = 1, int height = 1, int depth = 1, const std::string &type = "Default") 
            :m_Width(width), m_Height(height), m_Depth(depth)
        {
            assert(m_Width <= 0 && m_Height <= 0 && m_Depth <= 0);
            if(type == "prism")
                isPrism = true;
            else if(type == "pyramid")
                isPyramid = true;
        }
        Shape3D(Shape3D && shape) noexcept 
            :m_Width(shape.m_Width), m_Height(shape.m_Height), m_Depth(shape.m_Depth)
        {
            m_Width = 0, m_Height = 0, m_Depth = 0;
        }
        Shape3D& operator=(Shape3D &&shape) noexcept {
            if(&shape == this)
                return *this;
            delete &m_Width;
            delete &m_Height;
            delete &m_Depth;
            m_Width = shape.m_Width;
            m_Width = shape.m_Height;
            return *this;
        }

        std::string GetType() const {
            if(isPyramid)
                return "Pyramid";
            else if(isPrism)
                return "Prism";
            else
                return "Default";
        }

        // Take into account shapes (Prism, pyramid etc.)
        inline float getWidth() const { return m_Width; }
        inline float getHeight()const { return m_Height; }
        inline float getDepth() const { return m_Depth; }
        inline float getPer()   const { return m_Width + m_Width + m_Height + m_Height; } // Square only for now
        inline float getArea()  const {
            if(isPrism)
                return;
            else if(isPyramid)
                return m_Width * m_Depth + m_Width * pow(sqrt((m_Depth / 2)), 2) + pow(m_Height,2) + m_Depth; // Check!
            else 
                return m_Height * m_Width; 
        }
        inline float getVol() const { 
            if(isPrism)
                return;
            else if(isPyramid)
                return m_Width * m_Height * m_Depth / 3;
            else 
                return m_Width * m_Height * m_Depth;    
        }
        // Chainable functions
        Shape3D& getVolC() {
            if(isPrism)
                return *this; // DO!
            else if(isPyramid)
                m_Width * m_Height * m_Depth / 3;
            else
                m_Width * m_Height * m_Depth; 
            return *this; 
        }

        ~Shape3D() {};
    };
    Shape3D operator+(Shape3D &s1, Shape3D &s2) { return Shape3D(s1.m_Height + s2.m_Height + s1.m_Width + s2.m_Width + s1.m_Depth + s2.m_Depth); }
    Shape3D operator*(Shape3D &s1, Shape3D &s2) { return Shape3D(s1.m_Height * s2.m_Height * s1.m_Width * s2.m_Width * s1.m_Depth * s2.m_Depth); }
    Shape3D operator-(Shape3D &s1, Shape3D &s2) { return Shape3D(s1.m_Height - s2.m_Height - s1.m_Width - s2.m_Width - s1.m_Depth - s2.m_Depth); }

    // General | Object Independent
    inline int   genArea(int a, int b)       { return (a * a) + (b * b); } // Only certain shapes
    inline float genArea(float a, float b)   { return (a * a) + (b * b); }
    inline int   genPer(int a, int b, int c = 0, int d = 0) { return a + b + c + d; } // Check!
    inline float genPer(float a, float b)    { return a + a + b + b; }
    inline int   genVol(int a, int b, int c) { return a * b * c; }
    inline float genVol(float a, float b, float c) { return a * b * c; }
    // Circle Math ================================================================================================
    class Circle {
    private:
        float m_Radius, m_Circumfrence;
    public:
        Circle() = default;
        Circle(int radius = 1)
            :m_Radius(radius),  m_Circumfrence(2 * PI * radius) // Check!
        {
            assert(m_Radius > 0);
        }
        Circle(Circle &&circ) noexcept 
            :m_Radius(circ.m_Radius), m_Circumfrence(circ.m_Circumfrence)
        {
            m_Radius = 0, m_Circumfrence = 0;
        }
        Circle& operator=(Circle &&circ) noexcept {
            if(&circ == this)
                return *this;
            delete &m_Radius;
            delete &m_Circumfrence;
            m_Radius = circ.m_Radius;
            m_Circumfrence = circ.m_Circumfrence;
            return *this;
        }
        inline float getRad() const { return m_Radius; }
        inline float getCirc() const { return m_Circumfrence; }
        // Check below two
        inline float getArea() { return PI * m_Radius * m_Radius; } // Sort returns!
        inline float getDiameter() { return m_Radius * 2; }
        inline float calcCircumfrence() { return 2 * PI * m_Radius; } // Assuming circumfrence has not been initialised | Make better?
        inline float calcRadius() { return m_Circumfrence / 2 * PI; } // Assuming radius has not been initialized | Make better?

        // Chainable functions
        Circle& getAreaC() {m_Radius *= m_Radius * PI; return *this; }
        Circle& getDiameterC() {m_Radius *= 2; return *this; }
        Circle& getCircumfrenceC() {m_Radius *= 2 * PI; return *this; }
        Circle& getRadiusC() {m_Circumfrence /= 2 * PI; return *this; }

        ~Circle() = default;
    };

    class Ellipse : public Circle { // Check!
    private:
        Point first_Foci, second_Foci;
    public:
        Ellipse(const int radius = 1)
            :Circle(radius) 
        {
            assert(radius > 0);
        }
        // ADD FUNCTIONS | MARK BASE AS VIRTUAL!
        ~Ellipse() = default;
    };

    // General, object independent | Fix returns!?
    template<typename T>
    double* circArea(T radius) {
        if(sizeof(radius) != int8_t)
            std::cerr << "Not int!\n";
        radius *= radius * PI;
        return &radius; 
    }
    template<typename T>
    double* circumfrence(T radius) {
        radius *= radius * 2 * PI;
        return &radius;
    }
    template<typename T>
    double* diameter(T radius) { 
        radius *= 2;
        return &radius; 
    }
    template<typename T>
    double* radius(T cir) { 
        cir = cir / 2 * PI;
        return &cir; 
    }

    // Triangle Math ==============================================================================================
    class Triangle { // Standard tri with total freedom (Scalene)
    private:
        float m_a, m_b, m_c;
        float sides[3] = {m_a, m_b, m_c};
        float m_AngleA, m_AngleB, m_AngleC; // Do angle calculation
        bool isEquilateral = false, isIsocoles = false, isScalene = false, isRightAngled = false;
    public:
        Triangle() {}
        Triangle(const float a, const float b, const float c)
            :m_a(a), m_b(b), m_c(c)
        {
            assert(m_a <= 0 && m_b <= 0 && m_c <= 0);
            check(); // Runs initially see to if their is a match
        }
        void check() { // Checks what type of triangle it is
            if(m_a == m_b && m_a == m_c) isEquilateral = true;
            else if(m_a == m_b || m_a == m_c || m_b == m_c) isIsocoles = true;
            else if(m_a == 90.0 || m_b == 90.0 || m_c == 90.0) isRightAngled = true;
            else isScalene = true;
        } 
        float calcAngles() {
            return;
        }
        inline float calcMedianA() { return sqrt(2 * m_b * m_b + 2 * m_c * m_c - m_a * m_a / 4); } // Check all! Then make universal
        inline float calcMedianB() { return sqrt(2 * m_a * m_a + 2 * m_c * m_c - m_b * m_b / 4); }
        inline float calcMedianC() { return sqrt(2 * m_a * m_a + 2 * m_b * m_b - m_c * m_c / 4); }
        float inradius() {
            return;
        }
        inline float getA() const { return m_a; }
        inline float getB() const { return m_b; }
        inline float getC() const { return m_c; }
        float* getSides() const { // Check const!
            float sides[3];
            sides[0] = m_a;
            sides[1] = m_b;
            sides[2] = m_c;
            return sides;
        }
        inline float getAngleA() const { return m_AngleA; }
        inline float getAngleB() const { return m_AngleB; }
        inline float getAngleC() const { return m_AngleC; }
        float* getAngles() const { // Check const!
            float angles[3];
            angles[0] = m_AngleA;
            angles[1] = m_AngleB;
            angles[2] = m_AngleC;
            return angles;
        }
        bool getType() {
            if(isEquilateral)      return isEquilateral;
            else if(isIsocoles)    return isIsocoles;
            else if(isScalene)     return isScalene;
            else if(isRightAngled) return isRightAngled;
        }
        float gamma() { // Calculates angle | Continue | Do standard overload outside this class
            float gamma = sinf(m_a * 2 / m_a * m_b); // Change to custom sin function
            return gamma;
        }
        double TPer() {
            if(m_a + m_b > m_c) return m_a + m_b + m_c;
            else
                std::cerr << "Babbage Error:- Invalid Input: Ensure a + b > c" << std::endl;
        }
        double semiTPer() {
            if(m_a + m_b > m_c) return m_a + m_b + m_c / 2;
            else
                std::cerr << "Babbage Error:- Invalid Input: Ensure a + b > c" << std::endl;
        }
        // Chainable Functions

        ~Triangle() {};
    };

    class ITriangle : public Triangle { // Isosceles
    private:
        float m_Height, m_Base; // Height = equal sides | Change!
    public:
        ITriangle(int height = 1, int base = 1)
            :m_Height(height), m_Base(base)
        {
            assert(m_Height <= 0 && m_Base <= 0);
        }
        float calcAngles(ITriangle &t) {
            return;
        }
        inline float getBase() const { return m_Base; }
        inline float getHeight() const { return m_Height; }
        double TArea() { return m_Base * m_Height * 2 / 2; } // Check!
        double TPer() { // Overload for Isosceles
            if(m_Height < m_Base) return m_Height * 2 + m_Base;
            else
                std::cerr << "Babbage Error:- Invalid Input: Ensure b < 2 x a" << std::endl;
        }
        double semiTPer() {
            if(m_Height < m_Base) return m_Height * 2 + m_Base / 2;
            else
                std::cerr << "Babbage Error:- Invalid Input: Ensure b < 2 x a" << std::endl;
        }
        ~ITriangle() = default;
    };

    class ETriangle : public Triangle { // Equilateral | Angle always = 60
    private:
        float m_Size; // In area (Automatically calculates) | Add!
        const float m_Angle = 60;
    public:
        ETriangle(float size = 1.0f) 
            :m_Size(size)
        {
            assert(m_Size <= 0.0f);
        }
        inline float getSize() const { return m_Size; }
        inline float getAngle() const { return 60.0f; }
        double getPer() { return m_Size * 3; }
        double getSemiPer() { return(m_Size * 3 / 2); }
        double getArea() { return(sqrt(3) / 4 * m_Size * m_Size); }

        // Chainable Functions
        ETriangle& getPerC() {m_Size *= 3; return *this;}
        ETriangle& getSemiPerC() {m_Size *= 3 / 2; return *this;}

        ~ETriangle() = default;
    };

    class RTriangle : public Triangle {
    private:
        float m_Opposite, m_Adjacent, m_Hypotenuse;
        const float m_RightAngle = 90; // Change!
    public:
        RTriangle() = default;
        RTriangle(float oppSize, float adjSize, float hypSize)
            :m_Opposite(oppSize), m_Adjacent(adjSize), m_Hypotenuse(hypSize)
        {
            assert(m_Opposite <= 0 && m_Adjacent <= 0 && m_Hypotenuse <= 0);
        }
        float calcAngles(RTriangle &t) {
            return;
        }
        inline float getOpp() const { return m_Opposite; }
        inline float getAdj() const { return m_Adjacent; }
        inline float getHyp() const { return m_Hypotenuse; }
        float* getSides() const {
            float sides[3];
            sides[0] = m_Opposite;
            sides[1] = m_Adjacent;
            sides[2] = m_Hypotenuse;
            return sides;
        }
        float* getAngles() const {
            float angles[3]; // Possibly change to global?
            angles[0] = m_RightAngle;
            return angles;
        }
        double calcSize() { return m_Opposite * m_Adjacent * m_Hypotenuse; } // Check!
        float pythag(const char side = 's') { // Object overload
            switch(side) {
                case 's': float c = m_Opposite * m_Opposite + m_Adjacent * m_Adjacent; return sqrt(c);
                case 'l': float c = m_Opposite * m_Opposite - m_Adjacent * m_Adjacent; return sqrt(c);
            }
            if(side != 's' || side != 'l')
                std::cerr << "Babbage Error:- Invalid dictation of side to find, must be either: 's' (int) or 'l' (long) (Defaults to int)" << std::endl;
            return 0.0f;
        }
        inline double sin() { return m_Opposite / m_Hypotenuse; }
        inline double cos() { return m_Adjacent / m_Hypotenuse; }
        inline double tan() { return m_Opposite / m_Adjacent; }
        ~RTriangle() = default;
    };

    // General | Object Independent
        // Perimeter
    double tPer(double a, double b, double c) {
        if(a + b > c) 
            return a + b + c;
        else
            std::cerr << "Babbage Error:- Invalid Input: Ensure a + b > c" << std::endl;
    }
        // Semi-Perimeter
    double semiTPer(double a, double b, double c) {
        if(a + b > c) 
            return a + b + c / 2;
        else
            std::cerr << "Babbage Error:- Invalid Input: Ensure a + b > c" << std::endl; // Check need for exit status!
    }
        // Area
    double* tArea(double height, double base) { 
        height *= base / 2;
        return &height; 
    }
    double* tArea(double a) {
        a = sqrt(3) / 4 * a * a;
        return &a;                     
    } // Equilateral without object
    // Pythagoras
    float pythag(float a, float b, char side = 's') {
        switch(side) {
            case 's': float c = a * a + b * b; return sqrt(c);
            case 'l': float c = a * a - b * b; return sqrt(c);
        }
        if(side != 's' || side != 'l')
            std::cerr << "Babbage Error:- Invalid dictation of side to find, must be either: 's' (int) or 'l' (long) (Defaults to int)" << std::endl;
        return 0.0f;
    }

    // Trigonometry | Fix first three | Convert to address return?
        // Standard
    inline double sin(double opposite, double hypotenuse) { return opposite / hypotenuse; }
    inline double cos(double hypotenuse, double adjacent) { return adjacent / hypotenuse; }
    inline double tan(double opposite, double adjacent)   { return opposite / adjacent; }
    inline double csc(double hypotenuse, double opposite) { return hypotenuse / opposite; } // Cosecant
    inline double sec(double hypotenuse, double adjacent) { return hypotenuse / adjacent; } // Secant
    inline double cot(double adjacent, double opposite)   { return adjacent / opposite; }   // Cotangent

    // Do other triangles

    class Quaternion {
    private:
        float i{0.0f}, j{0.0f}, k{0.0f}, w{0.0f}; 
        float magnitude = 0.0f;
    public:
        Quaternion(float a = 0.0f, float b = 0.0f, float c = 0.0f, float d = 0.0f)
            :i(a), j(b), k(c), w(d)
        { // Assert all elements exist
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
        float qMag() {
            float mag = sqrt(w * w + i * i + j * j + k * k);
            return mag;
        }
        float qNorm() {
            magnitude = qMag();
            w /= magnitude;
            i /= magnitude;
            j /= magnitude;
            k /= magnitude;
            return magnitude;
        }
        Quaternion& qMult(Quaternion &q1, Quaternion &q2) { // CHeck return (Reference?)
            Quaternion resultQuat;
            resultQuat.i = q1.i * q2.w + q1.k * q2.k - q1.k * q2.j + q1.w * q2.i;
            resultQuat.j = q1.i * q2.k + q1.w * q2.w + q1.k * q2.i + q1.w * q2.j;
            resultQuat.k = q1.i * q2.j - q1.i * q2.i + q1.k * q2.w + q1.w * q2.k;
            resultQuat.w = q1.i * q2.j - q1.j * q2.j - q1.k * q2.k + q1.w * q2.w;
            return resultQuat;
        }
        Quaternion& qAdd(Quaternion &q1, Quaternion &q2) { // Check return
            Quaternion resultQuat;
            resultQuat.i = q1.i + q2.w;
            resultQuat.j = q1.j + q2.j;
            resultQuat.k = q1.k + q2.k;
            resultQuat.w = q1.w + q2.w;
            return resultQuat;
        }

        ~Quaternion() = default;
    };
}

#endif