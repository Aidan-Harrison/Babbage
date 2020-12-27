#ifndef BabbageGraphics_h
#define BabbageGraphics_h

#include <windows.h> // Access windows API for custom graphics

#include "BabbageMath.h" // Heavily uses custom math library
using namespace BabbageGeometryMath;

// Babbage's Graphics library
namespace Graphics {
        // Built in movement enumeration
        enum direction {STOP = 0, LEFT, RIGHT, FORWARD, BACK};
        direction bDir = STOP;

        // Unicode implementation
        std::wstring symbol; // Check initial
        wchar_t charSym = ' ';

        // Console screen buffer | Using <windows.h>

        // Geomtry creation: Add depth to all these, possibly incorporate custom geo for graphics
        Triangle* cTri(int &p1X, int &p1Y, int &p2X, int &p2Y, int &p3X, int &p3Y) {
                Triangle tri;
                point p1; point p2; point p3;
                p1.m_X = p1X; p1.m_Y = p1Y;
                p2.m_X = p2X; p2.m_Y = p2Y;
                p3.m_X = p3X; p3.m_Y = p3Y;
                // Calculate angle size based on vertex positions
                return &tri; // Check return for rendering
        }

        Shape2D cQuad(double &x, double &y, double &z) {
                
        }

        // Draw | Add Renderer.h and Renderer.cpp
}

#endif