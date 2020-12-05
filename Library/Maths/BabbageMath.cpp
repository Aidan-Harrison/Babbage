#include <iostream>
#include <vector>

#include "Babbage.h"
#include "BabbageMath.h"

// Maths re-write----------------------------------------------------------------------------------------------
// Figure out namespace implementation, possibly done in header?
BabbageMath bMath; // Initialize objects | Possible future use
VectorMath vMath;
MatrixMath mMath;
GeometryMath gMath;

// Overloading | This will be awkward to implement

// Basic
double BabbageMath::Add(double a, double b) {
    return a + b;
}
double BabbageMath::Subtract(double a, double b) {
    return a - b;
}
double BabbageMath::Multiply(double a, double b) {
    return a * b;
}
double BabbageMath::Divide(double a, double b) {
    return a / b;
}

// Comparrisons
const double BabbageMath::Max(double a, double b) {
    return a < b ? b : a;
}
const double BabbageMath::Min(double a, double b) {
    return a > b ? a : b;
}
bool BabbageMath::Same(double a, double b) {
    if(a == b) return true;
    return false;
}

// Conversions
int BabbageMath::toASC(char value) { // Char only? | Try 'char*'
    return (int)value; // Type-cast to int (ASCII)
}
// Both of these are probably the wrong formula. Everything else is correct
double BabbageMath::convRadToDeg(double radians) {
    return radians = 180/PI; 
}
double BabbageMath::convDegToRad(double degrees) {
    return degrees = PI/180;
}
// Possibly incorrect
double BabbageMath::convCelToFah(double c) {
    return (c * 9 / 5) + 32;
}        
double BabbageMath::convFahToCel(double f) {
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

std::vector<int> BabbageMath::getDigits(int number) { // Returns digits of number in vector format
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
            result.push_back(digit);
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

// Vector Math | Come back to this
// Vector 2
/*
float VectorMath::vecMag(Vector2 vec1, Vector2 vec2) { // Magnitude
    float magnitude = sqrt((vec1.vecX - vec1.vecY) + (vec2.vecX - vec2.vecY)); // Check!
    return magnitude;
}

void VectorMath::addVec(Vector2 vec1, Vector2 vec2) {
    return (vec1.vecX + vec2.vecX), (vec1.vecY + vec2.vecY); // Will ',' work?
}

void VectorMath::subVec() {
    return;
}

int VectorMath::dotProd(Vector2 vec1, Vector2 vec2) { // Produces 'scalar'
    return vec1.vecX * vec2.vecX + vec1.vecY * vec2.vecY;
}

void crossProd() { // Produces 'vector'
    return;
}

// Vector3
void addVec3() {
    return;
}
*/

// Matrix Math
std::vector<std::vector<int>> MatrixMath::fillMatrix(std::vector<std::vector<int>>& matrix, int input) {
    int m = matrix.size();
    int n = matrix[0].size();

    // FIGURE THIS OUT
    return matrix;
}

// Geometry
int GeometryMath::gPer(int a, int b) { // Square only for now
    return a + b * 2;
}
int GeometryMath::gVol(int a, int b, int c) {
    return a * b * c;
}
int GeometryMath::gArea(int a, int b) {
    return a * b;
}
int GeometryMath::gPythagLong(int a, int b) {
    int c;
    c = a * a + b * b;
    return sqrt(c);
}
int GeometryMath::gPythagShort(int a, int b) {
    int c;
    c = a * a - b * b;
    return sqrt(c);
}

// Geometry: Circle Theorem
double GeometryMath::CircleTheorem::Circumfrence(double radius) {
    return 2 * PI * radius;
}
double GeometryMath::CircleTheorem::CircleArea(double radius) {
    return PI * radius * radius;
}

// Geometry: Trigonometry
double GeometryMath::Trigonometry::gSin(double opposite, double hypotenuse) {
    return opposite / hypotenuse;
}
double GeometryMath::Trigonometry::gCos(double hypotenuse, double adjacent) {
    return adjacent / hypotenuse;
}
double GeometryMath::Trigonometry::gTan(double opposite, double hypotenuse, double adjacent) {
    return opposite / adjacent; // Continue
}