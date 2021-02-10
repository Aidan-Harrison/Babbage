#ifndef BVector_h
#define BVector_h

#include <cassert>
#include <algorithm>
#include <BMatrix.h> // Check!

namespace bvector {
    struct Vector1 {
        float x;
        float vec1[1]{x};
        Vector1(short cX = 0)
            :x(cX)
        {
            assert(x != sizeof(int));
        }
        ~Vector1() = default;
        inline float getMag() { return sqrt(x * x); }
        Vector1 Normalize(Vector1 &v) {
            if(v.x > 1) v.x = 1;
            else if(v.x < -1) v.x = -1;
            return v;
        }
        inline void deleteVec(Vector1 v) { delete &v; }
    };

    struct Vector2 {
        float x, y;
        float vec2[2]{x,y};
        Vector2(short cX = 0, short cY = 0)
            :x(cX), y(cY)
        {
            assert(x != sizeof(int) && y != sizeof(int));
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
        Vector2 Normalize(Vector2 &v) {
            if(v.x > 1) v.x = 1;
            if(v.y > 1) v.y = 1;
            else if(v.x < -1) v.x = -1;
            else if(v.y < -1) v.y = -1;
            return v;
        }
        inline void deleteVec(Vector2 v) { delete &v; }
    };

    struct Vector3 {
        float x, y, z;
        float vec3[3]{x,y,z};
        Vector3(short cX = 0, short cY = 0, short cZ = 0)
            :x(cX), y(cY), z(cZ)
        {
            assert(x != sizeof(int) && y != sizeof(int) && z != sizeof(int));
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
        Vector3 dotProd3(Vector3 &v1, Vector3 &v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }
        Vector3 crossProd(Vector3 &v1, Vector3 &v2) {
            v1.getMag() * v2.getMag();
        }
        Vector3 Normalize(Vector3 &v) {
            if(v.x > 1) v.x = 1;
            if(v.y > 1) v.y = 1;
            if(v.z > 1) v.z = 1;
            else if(v.x < -1) v.x = -1;
            else if(v.y < -1) v.y = -1;
            else if(v.z < -1) v.z = -1;
            return v;
        }
        inline void deleteVec(Vector3 v) { delete &v; }
    };

    struct Vector4 {
        float x, y, z, w;
        float vec4[4]{x,y,z,w};
        Vector4(short cX = 0, short cY = 0, short cZ = 0, short cW = 0) 
            :x(cX), y(cY), z(cZ), w(cW)
        {
            assert(x != sizeof(int) && y != sizeof(int) && z != sizeof(int) && w != sizeof(int));
        }
        ~Vector4() = default;
        inline float getMag() { return sqrt(x * x + y * y + z * z + w * w); }
        Vector4 Normalize(Vector4 &v) { // Origin ignored
            if(v.x > 1) v.x = 1;
            if(v.y > 1) v.y = 1;
            if(v.z > 1) v.z = 1;
            else if(v.x < -1) v.x = -1;
            else if(v.y < -1) v.y = -1;
            else if(v.z < -1) v.z = -1;
            return v;
        }
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