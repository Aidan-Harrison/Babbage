#ifndef BabbageGraphics_h
#define BabbageGraphics_h

#include "BabbageMath.h" // Heavily uses custom math library

// Babbage's Graphics library
class Graphics {
    private:
        // Built in movement enumeration
        enum direction {STOP = 0, LEFT, RIGHT, FORWARD, BACK};
        direction bDir;
    public:
        // Unicode implementation
        std::wstring symbol; // Used for representing unicode chars
        wchar_t charSym; // Used for unicode as well??
};

#endif