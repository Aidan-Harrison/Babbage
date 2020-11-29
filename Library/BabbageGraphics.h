#include <iostream>
#include "Babbage.h"

// Babbage's Graphics library
class Graphics {
    private:
        // Built in movement enumeration
        enum direction {STOP = 0, LEFT, RIGHT, FORWARD, BACK};
        direction bDir;
    public:
        // Unicode implementation
        std::wstring symbol; // Used for representing unicode chars
        // Vector components
        static int vec4[4], vec3[3], vec2[2], vec1[1]; // Should work? | Static not needed?
};

class Vector2 {
private:
    float x;
    float y;
public:
    
};