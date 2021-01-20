#ifndef BVector_h
#define BVector_h

#include <algorithm>
#include <BMatrix.h> // Check!

namespace bvector {
    struct Vector1 {
        float x;
        float vec1[1]{x};
        Vector1(short cX = 0)
            :x(cX)
        {
        }
        ~Vector1() = default;
        inline float getMag() { return sqrt(x * x); }
        inline void deleteVec(Vector1 v) { delete &v; }
    };

    struct Vector2 {
        float x, y;
        float vec2[2]{x,y};
        Vector2(short cX = 0, short cY = 0)
            :x(cX), y(cY)
        {
        }
        ~Vector2() = default;
        inline float getMag() { return sqrt(x * x + y * y); }
        Vector2 addVec(Vector2 &v1, Vector2 &v2) { // Re-do
            Vector2 vec;
            vec.x = v1.x + v2.x;
            vec.y = v1.y + v2.y;
            return vec;
        }
        Vector2 subVec(Vector2 &v1, Vector2 &v2) {
            Vector2 vec;
            vec.x = v1.x + (-v2.x);
            vec.y = v1.y + (-v2.y);
            return vec;
        }
        float dotProd(Vector2 &v1, Vector2 &v2) { return v1.x * v2.x + v1.y * v2.y; }
        inline void deleteVec(Vector2 v) { delete &v; }
    };

    struct Vector3 {
        float x, y, z;
        float vec3[3]{x,y,z};
        Vector3(short cX = 0, short cY = 0, short cZ = 0)
            :x(cX), y(cY), z(cZ)
        {
        }
        ~Vector3() = default;
        inline float getMag() { return sqrt(x * x + y * y + z * z); }
        Vector3 addVec3(Vector3 &v1, Vector3 &v2) { // Check! | Incorrect
            Vector3 vec;
            return ((v1.x + v2.x) + (v1.y - v2.y)  + (v1.z - v2.z));
            vec.x = v1.x + v2.x;
            vec.y = v2.y - v2.y;
            vec.z = v1.z = v2.z;
            return vec;
        }
        Vector3 dotProd3(Vector3 &v1, Vector3 &v2);
        void crossProd(Vector3 &v1, Vector3 &v2); // Change return?
        inline void deleteVec(Vector3 v) { delete &v; }
    };

    struct Vector4 {
        float x, y, z, w;
        float vec4[4]{x,y,z,w};
        Vector4(short cX = 0, short cY = 0, short cZ = 0, short cW = 0) 
            :x(cX), y(cY), z(cZ), w(cW)
        {
        }
        ~Vector4() = default;
        inline float getMag() { return sqrt(x * x + y * y + z * z + w * w); }
        inline void deleteVec(Vector4 v) { delete &v; }
    };
    
    /* Operator Overloads */

    // Vector creation
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
}

#endif