#ifndef BabbageMem_h
#define BabbageMem_h

#include <iostream>
#include <vector>

    // Objects
#include "BMatrix.h"
#include "BVector.h"
#include "BMath.h"

using namespace bmath;
using namespace bmatrix;
using namespace bvector;

// Possibly move printing part into printing header to avoid seperation?
// This will be the lowest level and most complex header next to graphics
// C for the most part
// Replace with C style arrays
// Add object passing

namespace bmem {
    // General
    char NULLTERM() { return putchar('\0'); } // Possibly print instead or as well?
    // Memory allocations

    // Printing
        // Check everything | Possibly change object names to just 'o'
    template<typename T>
    void printMem(T container) { std::cout << "Address: " << &container << '\n'; }
    template<typename T>
    void printMem(T arr[], short size) {
        std::cout << "Contents:\n";
        for(int i = 0; i < size; i++)
            std::cout << '\t' << &arr[i] << '\n';
    }
    template<typename T>
    void printMem(std::vector<T> vector) {
        std::cout << "Contents:\n";
        for(int i = 0; i < vector.size(); i++)
            std::cout << '\t'<< &vector[i] << '\n';
    }
    void printMem(Matrix &m) {
        std::cout << "Object: " << &m << '\n';
        std::cout << "Contents:\n";
        for(int i = 0; i < m.s_Matrix.size(); i++)
            for(int j = 0; j < m.s_Matrix.size(); j++)
                std::cout << '\t' << &m.s_Matrix[i] << '\n';
    }
    void printMem(Point &p)      { std::cout << "Object: " << &p << '\n'; }
    void printMem(Vector1 &v)    { std::cout << "Object: " << &v << '\n'; }
    void printMem(Vector2 &v)    { std::cout << "Object: " << &v << '\n'; }
    void printMem(Vector3 &v)    { std::cout << "Object: " << &v << '\n'; }
    void printMem(Vector4 &v)    { std::cout << "Object: " << &v << '\n'; }
    void printMem(Shape2D &s)    { std::cout << "Object: " << &s << '\n'; }
    void printMem(Shape3D &s)    { std::cout << "Object: " << &s << '\n'; }
    void printMem(Circle &c)     { std::cout << "Object: " << &c << '\n'; }
    void printMem(Triangle &t)   { std::cout << "Object: " << &t << '\n'; }
    void printMem(RTriangle &t)  { std::cout << "Object: " << &t << '\n'; }
    void printMem(ETriangle &t)  { std::cout << "Object: " << &t << '\n'; }
    void printMem(ITriangle &t)  { std::cout << "Object: " << &t << '\n'; }
    void printMem(Quaternion &q) { std::cout << "Object: " << &q << '\n'; }
};
#endif