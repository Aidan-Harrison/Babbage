#ifndef BVector_h
#define BVector_h

#include <algorithm>

namespace bvector {
    struct Vector1 {
        float x;
        float vec1[1]{x};
        Vector1(short cX = 0)
            :x(cX)
        {
        }
    };

    struct Vector2 {
        float x;
        float y;
        float vec2[2]{x,y};
        Vector2(short cX = 0, short cY = 0)
            :x(cX), y(cY)
        {
        }
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
    };

    // Vector creation (User functions) | Check return
    Vector1 CVec1(float vecIn1) {
        Vector1 vec;
        vec.vec1[0] = vecIn1;
        return vec;
    }
    Vector2 CVec2(float vecIn1, float vecIn2) {
        Vector2 vec;
        vec.vec2[0] = vecIn1;
        vec.vec2[1] = vecIn2;
        return vec;
    }
    Vector3 CVec3(float vecIn1, float vecIn2, float vecIn3) {
        Vector3 vec;
        vec.vec3[0] = vecIn1;
        vec.vec3[1] = vecIn2;
        vec.vec3[2] = vecIn3;
        return vec;
    }
    Vector4 CVec4(float vecIn1, float vecIn2, float vecIn3, float vecIn4) {
        Vector4 vec;
        vec.vec4[0] = vecIn1;
        vec.vec4[1] = vecIn2;
        vec.vec4[2] = vecIn3;
        vec.vec4[3] = vecIn4;
        return vec;
    }

    // Vector 2 Math | Possibly incorporate operator overloads
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
}

#endif