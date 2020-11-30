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

    class Vector1 {
        private:
            float x;
        public:
            float vec1[1]{x};
    };

    class Vector2 {
        private:
            float x;
            float y;
        public:
            float vec2[2]{x,y};
    };

    class Vector3 {
        private:
            float x;
            float y;
            float z;
        public:
            float vec3[3]{x,y,z};
    };

    class Vector4 {
        private:
            float x;
            float y;
            float z;
            float w;
        public:
            float vec4[4]{1,2,3,4};
    };  
};

class matrix {
private:
    std::vector<std::vector<int>> matrix{{}};
    int rows;
    int colums;
public:
    std::vector<std::vector<int>> fillMatrix(std::vector<std::vector<int>>& matrix); // Overload AND/OR Type pun, too long
};