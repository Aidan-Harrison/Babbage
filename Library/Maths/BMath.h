#ifndef BabbageMath_h
#define BabbageMath_h

#include <iostream>
#include <vector> 
#include <tuple>
#include <cmath>
#include <cassert>
#include <unordered_map>
#include <map>
#include <limits>

#include "BMatrix.h"
#include "BVector.h"

#define PI 3.14159
#define Euler 1.71828
#define Radian 56.2958
#define GoldenRatio 1.6180
#define C 186282

// Remove non-chainable??

namespace bmath {
    // Basic
    template<typename T> 
        inline T add(const T a, const T b) { return a + b; }
    template<typename T>
        inline T sub(const T a, const T b) { return a - b; }
    template<typename T>
        inline T mult(const T a, const T b){ return a * b; }
    template<typename T>
        inline T div(const T a, const T b) { return a / b; }
    template<typename T>
        inline T bSqr(const T a) { return a * a; }
    template<typename T>
        inline T bCub(const T a) { return a * a * a; }

    template<typename T>
    T mode(std::vector<T> & data) {
        int max = INT_MIN;
        std::unordered_map<T,int> m;
        for(auto i : data) {
            m[i]++;
            if(m[i] > data)
                max = i;
        }
        return max;
    }
    int avg(std::vector<int> & data) {
        int sum = 0;
        for(int i : data)
            sum += i;
        return sum / data.size();
    }

    // Advanced 
    inline int   floor(float value)  { return static_cast<int>(value); } // Mark all as const?
    inline short Sfloor(float value) { return static_cast<int>(value); }
    inline int   floor(double value) { return static_cast<int>(value); }

    inline int ceil(float value) {return -1;}
    // Do
    template<typename T>
    float round(T value, float roundTo) { // 'roundTo' refers to the the digit to round to, similar to floor but with user control
        return 0.0f;
    }

    template<typename T>
    T clamp(T value, const int min, const int max) {
        value = std::min(std::max(value, min), max);
        return value;
    }

    void FastDiv(int m) {}

    template<typename T>    
    bvector::Vector2f distance(T &obj1, T&obj2) { // Takes two objects and gets the distance away from each other
        bvector::Vector2f dist;
        dist.x = obj1.translation.x - obj2.translation.x;
        dist.y = obj1.translation.y - obj2.translation.y;
        return dist;
    }

    // Comparisons | Have to specify type when writing! Change!
    template<typename T>
        inline T Max(const T a, const T b) { return (a < b) ? b : a; }
    template<typename T>
        inline T Min(const T a, const T b) { return (a > b) ? a : b; }

    // Conversions -------------------------------------------------
    inline int asc(const char value) { return static_cast<int>(value); }

    std::vector<int> asc(const std::string && string) { 
        int charNum = 0;
        std::vector<int> numbers = {};
        for(unsigned int i = 0; i < string.length(); i++) {
            charNum = static_cast<int>(string[i]);
            numbers.push_back(charNum);
        }
        return numbers;
    }

    std::string asc(std::string & str, bool overWrite = true) { // If not overWrite, returns a new copy of ASCII values instead
        std::string newStr = "";
        for(unsigned int i = 0; i < str.length(); i++) {
            if(overWrite) {
                int curChar = static_cast<int>(str[i]);
                newStr.push_back(static_cast<char>(curChar));
            }
        }
        if(overWrite)
            return newStr;
        return str;
    }

        /* Angles/Rotation */
            // Degrees
    inline float convDegToRad(const float deg)     { return deg * PI / 180; }
    inline float convDegToGrad(const float deg)    { return deg * 200/ 180; }
    inline float convDegToMinArc(const float deg)  { return deg * 60;  }
    inline float convDegToSecArc(const float deg)  { return deg * 3600;  }
            // Radians
    inline float convRadToDeg(const float rad)     { return rad * 180 / PI; }
    inline float convRadToGrad(const float rad)    { return rad * 200 / PI; }
    inline float convRadToMinArc(const float rad)  { return rad * (60 * 180) / PI; }
    inline float convRadToSecArc(const float rad)  { return rad * (3600 * 180) / PI; }
        /* Temperature */
            // Celsius
    inline float convCelToFah(const float c)       { return c * 9 / 5 + 32; }
    inline float convCelToKel(const float c)       { return c + 273.15; }
            // Fahrenheit               
    inline float convFahToCel(const float f)       { return f - 32 * 5 / 9; }
    inline float convFahToKel(const float f)       { return f - 32 * 5 / 9 + 263.15; }
        /* Distance */
            // Metres & Centi
    inline float convCMtoMicro(const float centi)  { return centi  * 10000; }
    inline float convCMtoInch(const float centi)   { return centi  / 2.54;  }
    inline float convCMtoMem(const float centi)    { return centi  / 100;   }
    inline float convMemtoMM(const float meters)   { return meters * 1000;  }
    inline float convMemtoCM(const float meters)   { return meters * 100;   }
    inline float convMemtoKM(const float meters)   { return meters / 1000;  }
    inline float convMemtoMile(const float meters) { return meters / 1609;  }
    inline float convMemtoYard(const float meters) { return meters * 1.094; }
    inline float convMemtoInch(const float meters) { return meters * 39.97; }
    inline float convMemtoNMile(const float meters){ return meters / 1852;  }
            // Kilometers
    inline float convKMtoCM(const float km)        { return km * 10000;   }      
    inline float convKMtoMem(const float km)       { return km * 1000;    }      
    inline float convKMtoMile(const float km)      { return km * 0.6214;  }
    inline float convKMtoYard(const float km)      { return km * 1093.61; }
    inline float convKMtoFoot(const float km)      { return km * 3208.84; }
    inline float convKMtoInch(const float km)      { return km * 39370;   }
    inline float convKMtoNMile(const float km)     { return km / 1.852;   }
            // Miles
    inline float convMiletoCM(const float miles)   { return miles * 160934;  }
    inline float convMiletoM(const float miles)    { return miles * 1609.34; }
    inline float convMiletoKM(const float miles)   { return miles * 1.60934; }
    inline float convMiletoYard(const float miles) { return miles * 1760;    }
    inline float convMiletoFoot(const float miles) { return miles * 5280;    }
    inline float convMiletoInch(const float miles) { return miles * 63360;   }
    inline float convMiletoNMile(const float miles){ return miles / 1.151;   }
        /* Time */
            // Seconds
    inline float convSectoMilli(const float sec)   { return sec * 1000;   }      
    inline float convSectoMin(const float sec)     { return sec / 60;     }      
    inline float convSectoHour(const float sec)    { return sec / 3600;   }      
    inline float convSectoDay(const float sec)     { return sec / 86400;  }      
    inline float convSectoWeek(const float sec)    { return sec / 604800; }
            // Minutes
    inline float convMintoMilli(const float sec)   { return sec * 60000; } 
    inline float convMintoSec(const float sec)     { return sec * 60;    } 
    inline float convMintoHour(const float sec)    { return sec / 60;    } 
    inline float convMintoDay(const float sec)     { return sec / 1440;  } 
    inline float convMintoWeek(const float sec)    { return sec / 10080; } 
    inline float convMintoMonth(const float sec)   { return sec / 43800; } 
            // Hours
    inline float convHourtoMin(const float sec)    { return sec * 60;   } 
    inline float convHourtoSec(const float sec)    { return sec * 3600; } 
    inline float convHourtoDay(const float sec)    { return sec * 24;   } 
    inline float convHourtoDayDiv(const float sec) { return sec / 168;  } // Check! ?? Pointless?
    inline float convHourtoMonth(const float sec)  { return sec / 730;  } 
    inline float convHourtoYear(const float sec)   { return sec / 8760; } 
        /* Energy */
            // Joules
    inline float convJtoKJ(const float joule)      { return joule / 1000;  } 
    inline float convJtoWattHr(const float joule)  { return joule / 3600;  } 
    inline float convJtoCal(const float joule)     { return joule / 4.184; } 
    inline float convJtoKCal(const float joule)    { return joule / 4184;  } 
            // Calories
    inline float convCaltoJ(const float cal)       { return cal * 4.184; }
    inline float convCaltoKJ(const float cal)      { return cal / 239;   }
    inline float convCaltoKCal(const float cal)    { return cal / 1000;  }
    inline float convCaltoWattHr(const float cal)  { return cal / 860;   }
            // Wattage
    inline float convAVtoWatt(const float amps, const float volts) { return amps * volts; }

    // Graphics and Geometry
        // Replace with custom data structures
    class Pointi { 
    private:
        int pos[2] = {0,0};
    public:   
        Pointi() {}
        Pointi(const int xPos = 0, const int yPos = 0) 
        {
            pos[0] = xPos;
            pos[1] = yPos;
        }
        Pointi(Pointi & p) 
            :pos[0](p.pos[0]), pos[1](p.pos[1])
        {
        }
        inline int x() const { return pos[0]; }
        inline int y() const { return pos[1]; }
        std::vector<int> GetPosAsVector() const {
            std::vector<int> position;
            position.push_back(pos[0]);
            position.push_back(pos[1]);
            return position;
        }
        std::pair<int,int> GetPosAsPair() const {
            std::pair<int,int> position;
            position.first = pos[0];
            position.second = pos[1];
            return position;
        }

        inline void set(const int x, const int y) { 
            pos[0] = x; 
            pos[1] = y;
        }
        inline void setX(const int x) { pos[0] = x;}
        inline void setY(const int y) { pos[1] = y;}

        ~Pointi() {}
    };

    class Pointf { // Remove?!
    private:
        float pos[2] = {0,0};
    public:   
        Pointf() {}
        Pointf(const float xPos = 0, const float yPos = 0) 
        {
            pos[0] = xPos;
            pos[1] = yPos;
        }
        Pointf(Pointf & p) 
            :pos[0](p.pos[0]), pos[1](p.pos[1])
        {
        }
        inline float x() const { return pos[0]; }
        inline float y() const { return pos[1]; }
        std::vector<float> GetPosAsVector() const {
            std::vector<float> position;
            position.push_back(pos[0]);
            position.push_back(pos[1]);
            return position;
        }
        std::pair<float,float> GetPosAsPair() const {
            std::pair<float,float> position;
            position.first = pos[0];
            position.second = pos[1];
            return position;
        }

        inline void set(const float x, const float y) { 
            pos[0] = x; 
            pos[1] = y;
        }
        inline void setX(const float x) { pos[0] = x; }
        inline void setY(const float y) { pos[1] = y; }

        ~Pointf() {}
    };

    struct Line {
        float m_Length = 1.0f;
        std::tuple<float, float> localRotation;
        Point* points[2];
        Line(const float length = 1.0f) 
            :m_Length(length)
        {
            assert(length < std::numeric_limits<float>::max()); // Check!
        }

        Line(Line &&line) noexcept 
            :m_Length(line.m_Length)
        {
            points[0] = line.points[0];
            points[1] = line.points[1];
        }

        inline float getLength() const {return m_Length;}
        inline Point* getFPoint() const {return points[0];}
        inline Point* getSPoint() const {return points[1];}
        inline std::tuple<Point, Point> GetPoints() {
            std::tuple<Point, Point> pointsTup;
            std::get<0>(pointsTup) = *points[0];
            std::get<1>(pointsTup) = *points[1];
            return pointsTup;
        }

        ~Line() {}
    };

    class Triangle { // Standard tri with total freedom (Scalene)
    private:
        float m_a, m_b, m_c; // Compress below? Might be nice to keep
        float sides[3];
        float rotation[2], translation[2], scale[2];
        float m_AngleA, m_AngleB, m_AngleC; // Do angle calculation
        float angles[3];
        uint8_t type = 0;
        enum TYPE{EQUILATERAL, ISCOCLES, SCALENE, RIGHT};
    public:
        void check() { // Checks what type of triangle it is
            if(m_a == m_b && m_a == m_c) type = EQUILATERAL;
            else if(m_a == m_b || m_a == m_c || m_b == m_c) type = ISCOCLES;
            else if(m_a == 90.0 || m_b == 90.0 || m_c == 90.0) type = RIGHT;
            else type = SCALENE;
        } 

        Triangle(const float a = 1, const float b = 1, const float c = 1)
            : m_a(a), m_b(b), m_c(c)
        {
            sides[0] = m_a;
            sides[1] = m_b;
            sides[2] = m_c;
            assert(m_a <= 0 && m_b <= 0 && m_c <= 0);
            check();
        }

        Triangle(Triangle & other) 
            :m_a(other.m_a), m_b(other.m_b), m_c(other.m_c)
        {
            sides[0] = m_a;
            sides[1] = m_b;
            sides[2] = m_c;
            angles[0] = other.angles[0];
            angles[1] = other.angles[1];
            angles[2] = other.angles[2];
        }
        Triangle(Triangle && b) noexcept
        {
        }

        void calcAngles() {
            switch(type) {
                case EQUILATERAL: {
                    m_AngleA = 60.0;
                    m_AngleB = 60.0;
                    m_AngleC = 60.0;
                    break;
                }
                case ISCOCLES:
                    break;
                case RIGHT:
                    break;
                case SCALENE:
                    break;
            }
        }

        inline float calcMedianA() { return sqrt(2 * m_b * m_b + 2 * m_c * m_c - m_a * m_a / 4); }
        inline float calcMedianB() { return sqrt(2 * m_a * m_a + 2 * m_c * m_c - m_b * m_b / 4); }
        inline float calcMedianC() { return sqrt(2 * m_a * m_a + 2 * m_b * m_b - m_c * m_c / 4); }
        float inradius() {
            return 0.0f;
        }

        void setRotation(const float x, const float y) {
            std::get<0>(rotation) = x;
            std::get<1>(rotation) = y;
        }
        void setTranslation(const float x, const float y) {
            std::get<0>(translation) = x;
            std::get<1>(translation) = y;
        }

        inline float getA() const { return m_a; }
        inline float getB() const { return m_b; }
        inline float getC() const { return m_c; }

        inline void setA(const float a) { m_a = a; }
        inline void setB(const float b) { m_b = b; }
        inline void setC(const float c) { m_c = c; }

        void setAll(const float a, const float b, const float c) {
            sides[0] = a;
            sides[1] = b;
            sides[2] = c;
        }

        std::tuple<float,float,float> getSides() const { // Check const!
            std::tuple<float,float,float> sides;
            std::get<0>(sides) = m_a;
            std::get<1>(sides) = m_b;
            std::get<2>(sides) = m_c;
            return sides;
        }

        inline float getAngleA() const { return m_AngleA; }
        inline float getAngleB() const { return m_AngleB; }
        inline float getAngleC() const { return m_AngleC; }
        std::tuple<float,float,float> getAngles() const { // Check const!
            std::tuple<float,float,float> angles;
            std::get<0>(angles) = m_AngleA;
            std::get<1>(angles) = m_AngleB;
            std::get<2>(angles) = m_AngleC;
            return angles;
        }
        bool getType() {
            if(isEquilateral)      return isEquilateral;
            else if(isIsocoles)    return isIsocoles;
            else if(isScalene)     return isScalene;
            else if(isRightAngled) return isRightAngled;
            return false;
        }
        float gamma() { // Calculates angle | Continue | Do standard overload outside this class
            float gamma = sinf(m_a * 2 / m_a * m_b); // Change to custom sin function
            return gamma;
        }
        double TPer() {
            if(m_a + m_b > m_c) return m_a + m_b + m_c;
            else
                std::cerr << "Babbage Error:- Invalid Input: Ensure a + b > c" << std::endl;
            return 0.0;
        }
        double semiTPer() {
            if(m_a + m_b > m_c) return m_a + m_b + m_c / 2;
            else
                std::cerr << "Babbage Error:- Invalid Input: Ensure a + b > c" << std::endl;
            return 0.0;
        }  
        // Chainable Functions

        ~Triangle() {};
    };

    class Shape2D {
    private:
        enum SHAPE_TYPE{SQUARE, TRIANGLE};
        std::vector<Line> m_Edges{};
        std::vector<std::pair<float,float>> vertices{};
        uint8_t type = 0;
    public:
        float m_Width = 0.1f, m_Height = 0.1f;
        std::pair<float, float> rotation;
        std::pair<float, float> translation;
        Shape2D(const int sides = 4, const float width = 1.0f, const float height = 1.0f) 
            :m_Width(width), m_Height(height)
        {
            assert(sides > 2 && m_Width != 0 && m_Height != 0);
            for(unsigned int i = 0; i < sides; i++) {
                Line newLine;
                m_Edges.push_back(newLine);
            } 
            // Vertices:
            switch(type) {
                case SQUARE: {
                    vertices[0].first = -width; vertices[0].second = -height; // Top-left
                    vertices[1].first = width; vertices[1].second = -height; // Top-Right
                    vertices[2].first = -width; vertices[2].second = height; // Bot-left
                    vertices[3].first = width; vertices[3].second = height; // Bot-Right
                    break;
                }
                case TRIANGLE: { // Defaults to equlatrial
                    vertices[0].first = width/2; vertices[0].second = -height; // Top
                    vertices[1].first = -width; vertices[1].second = height; // Bot-left
                    vertices[2].first = width; vertices[2].second = height; // Bot-Right
                    break;
                }
            }
            // Handle triangle creation
        }
        // Move Constructor | Fix
        Shape2D(Shape2D &&shape) noexcept
            :m_Width(shape.m_Width), m_Height(shape.m_Height), m_Edges(shape.m_Edges) // Check edges!
        {
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

        inline float sideCount() { return m_Edges.size(); }
        inline float width()  const { return m_Width; }
        inline float height() const { return m_Height; }
        inline float per()    const {return m_Width + m_Width + m_Height + m_Height;} // Quad only | Change
        inline float area()   const {return (m_Width * 2) + (m_Height * 2); }

        void setRotation(const float x, const float y) {
            rotation.first = x;
            rotation.second = y;
        }

        std::vector<Line> GetEdges() const { // Returns edges in vector format | Pointer?
            return m_Edges;
        }

        // Chainable functions
        Shape2D& getPerC() {m_Width + m_Width + m_Height + m_Height; return *this; }
        Shape2D& getAreaC() {m_Width * 2 + m_Height; return *this; }
        Shape2D& changeSideCount(const int sides) {
            int size = m_Edges.size();    
            return *this; 
        } // Add safety?

        ~Shape2D() {} // Virtual?
    };

        // Overload
    Shape2D operator+(Shape2D &s1, Shape2D &s2) { return Shape2D(s1.m_Height + s2.m_Height + s1.m_Width + s2.m_Width); }
    Shape2D operator-(Shape2D &s1, Shape2D &s2) { return Shape2D(s1.m_Height - s2.m_Height - s1.m_Width - s2.m_Width); }
    Shape2D operator*(Shape2D &s1, Shape2D &s2) { return Shape2D(s1.m_Height * s2.m_Height * s1.m_Width * s2.m_Width); }

    namespace Transform2D {
        template<typename T>
        void reflect(T & object, bool vertLine = false) {
            if(!vertLine) {
                for(std::pair<int,int> v : object.vertices; i++) {
                    if(v.second > 0)
                        v.second *= -1;
                    else
                        fabs(v.second);
                }
                return;
            }
            for(std::pair<int,int> v : object.vertices; i++) {
                if(v.first > 0)
                    v.first *= -1;
                else
                    fabs(v.first);
            }
        }

        template<typename T>
        void rotate(T & object) {
            
        }

        template<typename T>
        void translate(T & object, const float x, const float y, float z = 0.0f) {
            for(std::pair<int,int> v : object.vertices) {
                v.first += x;
                v.second += y;
            }
            // Add 3D!
        }

        template<typename T>
        void scale(T & object, const float scaleFactor) {

        }
    }

    class Shape3D {
    private:
        int numberOfFaces = 0;
        bool isPrism = false; // Alters formulas
        bool isPyramid = false; // (Right-Rectangular Pyramid only!) | Allow for tri based?
        float volume;
    public:
        float m_Width, m_Height, m_Depth;
        Shape3D() {}
        Shape3D(const int width = 1, const int height = 1, const int depth = 1, int nFaces = 6, const std::string &type = "Default") 
            :m_Width(width), m_Height(height), m_Depth(depth), numberOfFaces(nFaces)
        {
            assert(m_Width <= 0 && m_Height <= 0 && m_Depth <= 0 && numberOfFaces != 0);
            if(type == "prism")
                isPrism = true;
            else if(type == "pyramid")
                isPyramid = true;
        }
        Shape3D(Shape3D &&shape) noexcept 
            :m_Width(shape.m_Width), m_Height(shape.m_Height), m_Depth(shape.m_Depth)
        {
        }
        Shape3D& operator=(Shape3D &&shape) noexcept {
            if(&shape == this)
                return *this;
            delete &m_Width;
            delete &m_Height;
            delete &m_Depth;
            m_Width = shape.m_Width;
            m_Height = shape.m_Height;
            m_Depth = shape.m_Depth;
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

        inline int getFaceCount() const { return numberOfFaces; }
        inline void setFaceCount(int faces) { numberOfFaces = faces; }

        // Take into account shapes (Prism, pyramid etc.)
        inline float getWidth() const { return m_Width; }
        inline float getHeight()const { return m_Height; }
        inline float getDepth() const { return m_Depth; }

        inline void setWidth(const float val) { m_Width = val; }
        inline void setHeight(const float val) { m_Height = val; }
        inline void setDepth(const float val) { m_Depth = val; }

        inline float getPer() const { return m_Width + m_Width + m_Height + m_Height; } 
        inline float getArea() const {
            if(isPrism)
                return 0.0f;
            else if(isPyramid)
                return m_Width * m_Depth + m_Width * pow(sqrt((m_Depth / 2)), 2) + pow(m_Height,2) + m_Depth; // Check!
            else 
                return m_Height * m_Width; 
        }
        inline float getVol() const { 
            if(isPrism)
                return 0.0f;
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
                volume = m_Width * m_Height * m_Depth / 3;
            else
                volume = m_Width * m_Height * m_Depth; 
            return *this; 
        }
        inline Shape3D& getPerC() { m_Width + m_Width + m_Height + m_Height; return *this; } 

        std::vector<float> getALL() {
            std::vector<float> data;
            data.push_back(m_Width);
            data.push_back(m_Height);
            data.push_back(m_Depth);
            data.push_back(getPer());
            data.push_back(getArea());
            return data;
        }

        ~Shape3D() {};
    };
    Shape3D operator+(Shape3D &s1, Shape3D &s2) { return Shape3D(s1.m_Height + s2.m_Height + s1.m_Width + s2.m_Width + s1.m_Depth + s2.m_Depth); }
    Shape3D operator*(Shape3D &s1, Shape3D &s2) { return Shape3D(s1.m_Height * s2.m_Height * s1.m_Width * s2.m_Width * s1.m_Depth * s2.m_Depth); }
    Shape3D operator-(Shape3D &s1, Shape3D &s2) { return Shape3D(s1.m_Height - s2.m_Height - s1.m_Width - s2.m_Width - s1.m_Depth - s2.m_Depth); }

    // General | Object Independent
    inline int   genArea(int a, int b)       { return (a * a) + (b * b); } // Only certain shapes
    inline float genArea(float a, float b)   { return (a * a) + (b * b); }
    inline float genArea(double a, double b)   { return (a * a) + (b * b); }
    inline int   genPer(int a, int b, int c = 0, int d = 0) { return a + b + c + d; } // Check!
    inline float genPer(float a, float b)    { return a + a + b + b; }
    inline float genPer(double a, double b)    { return a + a + b + b; }
    inline int   genVol(int a, int b, int c) { return a * b * c; }
    inline float genVol(float a, float b, float c) { return a * b * c; }
    inline float genVol(double a, double b, double c) { return a * b * c; }

    // Circle Math ================================================================================================
    class Circle {
    private:
        float m_Radius, m_Circumfrence;
    public:
        Circle() {}
        Circle(float radius = 1.0f)
            :m_Radius(radius),  m_Circumfrence(2 * PI * radius)
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

        std::vector<float> GetALL() {
            std::vector<float> data;
            data.push_back(m_Radius);        
            data.push_back(m_Circumfrence);
            data.push_back(getArea());        
            data.push_back(getDiameter());        
            return data;
        }

        inline void setRadius(const float rad) {
            m_Radius = rad;
            m_Circumfrence = 2 * PI * m_Radius; // Saves a function call
        }

        // Chainable functions
        Circle& getAreaC() {m_Radius *= m_Radius * PI; return *this; }
        Circle& getDiameterC() {m_Radius *= 2; return *this; }
        Circle& getCircumfrenceC() {m_Radius *= 2 * PI; return *this; }
        Circle& getRadiusC() {m_Circumfrence /= 2 * PI; return *this; }

        ~Circle() {};
    };

    class Ellipse : public Circle {
    private:
        Point first_Foci, second_Foci;
    public:
        Ellipse(const int radius = 1)
            :Circle(radius) 
        {
            assert(radius > 0);
        }
        // ADD FUNCTIONS | MARK BASE AS VIRTUAL!
        virtual ~Ellipse() {};
    };

    // General, object independent | Fix returns!?
    template<typename T>
    double* circArea(T radius) {
        // if(sizeof(radius) != int8_t)
            // std::cerr << "Not int!\n";
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
            return 0.0f;
        }
        inline float getBase() const { return m_Base; }
        inline float getHeight() const { return m_Height; }
        double TArea() { return m_Base * m_Height * 2 / 2; } // Check!
        double TPer(bool stateError = true) { // Overload for Isosceles
            if(m_Height < m_Base) return m_Height * 2 + m_Base;
            else
                if(stateError)
                    std::cerr << "Babbage Error:- Invalid Input: Ensure b < 2 x a" << std::endl;
            return 0.0;
        }
        double semiTPer(bool stateError = true) {
            if(m_Height < m_Base) return m_Height * 2 + m_Base / 2;
            else
                if(stateError)
                    std::cerr << "Babbage Error:- Invalid Input: Ensure b < 2 x a" << std::endl;
            return 0.0;
        }

        std::vector<float> GetALL() {
            std::vector<float> data;
            data.push_back(m_Base);        
            data.push_back(m_Height);
            data.push_back(TArea());        
            data.push_back(TPer());        
            return data;
        }

        ~ITriangle() {};
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
        // Add other two angles
    public:
        RTriangle() = default;
        RTriangle(float oppSize, float adjSize, float hypSize)
            :m_Opposite(oppSize), m_Adjacent(adjSize), m_Hypotenuse(hypSize)
        {
            assert(m_Opposite <= 0 && m_Adjacent <= 0 && m_Hypotenuse <= 0);
        }
        float calcAngles(RTriangle &t) {
            return 0.0f;
        }
        inline float getOpp() const { return m_Opposite; }
        inline float getAdj() const { return m_Adjacent; }
        inline float getHyp() const { return m_Hypotenuse; }
        std::tuple<float,float,float> getSides() const {
            std::tuple<float,float,float> sides;
            std::get<0>(sides) = m_Opposite;
            std::get<1>(sides) = m_Adjacent;
            std::get<2>(sides) = m_Hypotenuse;
            return sides;
        }
        // Add etAngles()
        double calcSize() { return m_Opposite * m_Adjacent * m_Hypotenuse; } // Check!
        float pythag(const char side = 's') { // Object overload
            switch(side) {
                case 's': { float c = m_Opposite * m_Opposite + m_Adjacent * m_Adjacent; return sqrt(c); break; }
                case 'l': { float d = m_Opposite * m_Opposite - m_Adjacent * m_Adjacent; return sqrt(d); break; }
            }
            if(side != 's' || side != 'l')
                std::cerr << "Babbage Error:- Invalid dictation of side to find, must be either: 's' (int) or 'l' (long) (Defaults to int)" << std::endl;
            return 0.0f;
        }
        inline double sin() { return m_Opposite / m_Hypotenuse; }
        inline double cos() { return m_Adjacent / m_Hypotenuse; }
        inline double tan() { return m_Opposite / m_Adjacent; }

        ~RTriangle() {};
    };

    // General | Object Independent
        // Perimeter
    double tPer(double a, double b, double c) {
        if(a + b > c) 
            return a + b + c;
        else
            std::cerr << "Babbage Error:- Invalid Input: Ensure a + b > c" << std::endl;
        return 0.0;
    }
        // Semi-Perimeter
    double semiTPer(double a, double b, double c) {
        if(a + b > c) 
            return a + b + c / 2;
        else
            std::cerr << "Babbage Error:- Invalid Input: Ensure a + b > c" << std::endl; // Check need for exit status!
        return 0.0;
    }
        // Area
    double tArea(double height, double base) { 
        height *= base / 2;
        return height; 
    }
    double tArea(double a) {
        a = sqrt(3) / 4 * a * a;
        return a;                     
    } // Equilateral without object
    // Pythagoras
    float pythag(float a, float b, char side = 's') {
        switch(side) {
            case 's': { float c = a * a + b * b; return sqrt(c); break; }
            case 'l': { float d = a * a - b * b; return sqrt(d); break; }
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
        float magnitude = 0.0f;
    public:
        float i{0.0f}, j{0.0f}, k{0.0f}, w{0.0f}; 
        Quaternion(float a = 0.0f, float b = 0.0f, float c = 0.0f, float d = 0.0f)
            :i(a), j(b), k(c), w(d)
        { // Assert all elements exist
        }

        // Move constructor
        Quaternion(Quaternion && quat) noexcept
            :i(quat.i), j(quat.j), k(quat.k), w(quat.w)
        {    
        } 

        std::array<float,4> getQuat() const {
            return {i,j,k,w};
        }

        // Move assignment
        Quaternion& operator=(Quaternion && quat) noexcept {
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

        ~Quaternion() {}
    };

    Quaternion qMult(Quaternion &q1, Quaternion &q2) { // CHeck return (Reference?)
        Quaternion resultQuat;
        resultQuat.i = q1.i * q2.w + q1.k * q2.k - q1.k * q2.j + q1.w * q2.i;
        resultQuat.j = q1.i * q2.k + q1.w * q2.w + q1.k * q2.i + q1.w * q2.j;
        resultQuat.k = q1.i * q2.j - q1.i * q2.i + q1.k * q2.w + q1.w * q2.k;
        resultQuat.w = q1.i * q2.j - q1.j * q2.j - q1.k * q2.k + q1.w * q2.w;
        return resultQuat;
    }
    Quaternion qAdd(Quaternion &q1, Quaternion &q2) { // Check return
        Quaternion resultQuat;
        resultQuat.i = q1.i + q2.w;
        resultQuat.j = q1.j + q2.j;
        resultQuat.k = q1.k + q2.k;
        resultQuat.w = q1.w + q2.w;
        return resultQuat;
    }

    Quaternion operator*(Quaternion &q1, Quaternion &q2) {return qMult(q1,q2); } // Check!
    Quaternion operator+(Quaternion &q1, Quaternion &q2) {return qAdd(q1,q2); }
}

#endif