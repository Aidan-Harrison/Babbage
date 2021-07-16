#ifndef BabbageGraphics_h
#define BabbageGraphics_h

#include <windows.h> // Access windows API

// Maths lib
#include "BMath.h"
#include "BMatrix.h"
#include "BVector.h"
#include "BabbageError.h"

using namespace bmath;
using namespace bmatrix;
using namespace bvector;
using namespace bLog;

// Babbage's Graphics library
namespace bgraphics {
        // Built in movement enumeration
        enum direction {STOP = 0, LEFT, RIGHT, FORWARD, BACK};
        direction bDir = STOP;

        // Unicode implementation
        std::wstring symbol; // Check initial
        wchar_t charSym = ' ';

        // Console screen buffer | Using <windows.h>

        // Geomtry creation: Add depth to all these, possibly incorporate custom geo for graphics
            // Check!
        Triangle* cTri(short p1X, short p1Y, short p2X, short p2Y, short p3X, short p3Y) {
            Triangle tri;
            Point p1, p2, p3;
            p1.m_X = p1X; p1.m_Y = p1Y;
            p2.m_X = p2X; p2.m_Y = p2Y;
            p3.m_X = p3X; p3.m_Y = p3Y;
            tri.m_a = p1.m_X + p1.m_Y;
            tri.m_b = p2.m_X + p2.m_Y;
            tri.m_c = p3.m_X + p3.m_Y;
            // Calculate angle size based on vertex positions
            return &tri; // Check return for rendering
        }

        struct Quad {
            Quad() = default;
            Quad(float x, float y) 
            {
                RTriangle t1, t2;
            }
            void setOrigin(float origin);
            ~Quad() = default;
        };

        struct Cube {
            Cube() = default;
            void cCube(float x, float y, float z) { // Origin defaults to 0, 0, 0
                Triangle t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;
            }
            void cCube(float x, float y, float z, float origin) {
                Triangle t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;
            }
            ~Cube() = default;
        };

        // Draw | Add Renderer.h and Renderer.cpp
}

#endif