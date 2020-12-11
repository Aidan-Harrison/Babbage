#include <iostream>

// Babbage's Graphics library
// To-Do-List:
    // Heavily incorporate BabbageMath here for the users sake, do as much raw as possible
    // for performance (system) sake
// Changes:
    // Moved portion to math library
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