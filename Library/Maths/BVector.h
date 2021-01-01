#ifndef BVector_h
#define BVector_h

#include <algorithm>
#include <BMatrix.h>

namespace bvector {
    struct Vector1 {
        float x;
        float vec1[1]{x};
        Vector1(short cX = 0)
            :x(cX)
        {
        }
        ~Vector1() = default;
    };

    struct Vector2 {
        float x;
        float y;
        float vec2[2]{x,y};
        Vector2(short cX = 0, short cY = 0)
            :x(cX), y(cY)
        {
        }
        ~Vector2() = default;
    };

    struct Vector3 {
        float x;
        float y;
        float z;
        float vec3[3]{x,y,z};
        Vector3(short cX = 0, short cY = 0, short cZ = 0)
            :x(cX), y(cY), z(cZ)
        {
        }
        ~Vector3() = default;
    };

    struct Vector4 {
        float x;
        float y;
        float z;
        float w;
        float vec4[4]{x,y,z,w};
        Vector4(short cX = 0, short cY = 0, short cZ = 0, short cW = 0) 
            :x(cX), y(cY), z(cZ), w(cW)
        {
        }
        ~Vector4() = default;
    };
    
    /* Operator Overloads */

    // Vector creation (User functions)
    Vector1 CVec1(float x) {
        Vector1 vec;
        vec.vec1[0] = x;
        return vec;
    }
    Vector2 CVec2(float x, float y) {
        Vector2 vec;
        vec.vec2[0] = x;
        vec.vec2[1] = y;
        return vec;
    }

    Vector3 CVec3(float x, float y, float z) {
        Vector3 vec;
        vec.vec3[0] = x;
        vec.vec3[1] = y;
        vec.vec3[2] = z;
        return vec;
    }
    Vector4 CVec4(float x, float y, float z, float w) {
        Vector4 vec;
        vec.vec4[0] = x;
        vec.vec4[1] = y;
        vec.vec4[2] = z;
        vec.vec4[3] = w;
        return vec;
    }

    // Vector 2 Math | Incorporate operator overloads
    float vecMag(Vector2 vec1) { // Magnitude
        float mag = sqrt(vec1.x * vec1.x + vec1.y * vec1.y); // Do custom sqrt function
        return mag;
    }
    Vector2 addVec(Vector2 vec1, Vector2 vec2) { // Working?
        Vector2 vec;
        vec.x = vec1.x + vec2.x;
        vec.y = vec1.y + vec2.y;
        return vec;
    }
    Vector2 subVec(Vector2 vec1, Vector2 vec2) { // Working
        Vector2 vec;
        vec.x = vec1.x + (-vec2.x);
        vec.y = vec1.y + (-vec2.y);
        return vec;
    }
    float dotProd(Vector2 vec1, Vector2 vec2) { // Produces 'scalar' | Working
        return vec1.x * vec2.x + vec1.y * vec2.y;
    }

    // Vector3 Math
    void addVec3(Vector3 vec1, Vector3 vec2) {
        return;
    }
    void crossProd(Vector3 vec1, Vector3 vec2) {
        return;
    }

    // Vector4 Math
}

#endif