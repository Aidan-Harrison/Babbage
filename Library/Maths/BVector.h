#ifndef BVector_h
#define BVector_h

#include <cassert>
#include <algorithm>
#include <BMatrix.h> // Check!

namespace bvector {

    class Vector1i {
    private:
        int x;
    public:
        int vec1[1]{x};
        Vector1i(int cX = 0)
            :x(cX)
        {
            vec1[0] = vec1[0];
        }
        ~Vector1i() = default;
        inline int getMag() { return sqrt(x * x); }
        void Normalize() {
            if(x > 1)       x = 1;
            else if(x < -1) x = -1;
        }
        inline int getVector() const { return vec1[0]; }
        inline void deleteVec() { delete this; }
    };
    class Vector1f {
    private:
        float x;
    public:
        float vec1[1]{x};
        Vector1f(float cX = 0.0f)
            :x(cX)
        {
            assert(x != sizeof(int));
            vec1[0] = vec1[0];
        }
        ~Vector1f() = default;
        inline float getMag() { return sqrt(x * x); }
        void Normalize() {
            if(x > 1)       x = 1;
            else if(x < -1) x = -1;
        }
        inline float getVector() const { return vec1[0]; }
        inline void deleteVec() { delete this; }
    };
    class Vector2i {
    private:
        int x, y;
    public:
        int vec2[2]{x,y};
        Vector2i(int cX = 0, int cY = 0)
            :x(cX), y(cY)
        {
            vec2[0] = x;
            vec2[1] = y;
        }
        ~Vector2i() = default;
        inline int getMag() { return sqrt(x * x + y * y); }
        void Normalize() {
            if(x > 1)       x = 1;
            else if(x < -1) x = -1;
            if(y > 1)       y = 1;
            else if(y < -1) y = -1;
        }
        int* getVector() const {
            int coords[2];
            coords[0] = vec2[0];
            coords[1] = vec2[1];
            return coords;
        }
        inline int getX() const { return vec2[0]; }
        inline int getY() const { return vec2[1]; }
        inline void deleteVec() { delete this; }

        // Change all?
        Vector2i addVec(Vector2i &v1, Vector2i &v2) { // Re-do
            Vector2i vec;
            vec.x = v1.x + v2.x;
            vec.y = v1.y + v2.y;
            return vec;
        }
        Vector2i subVec(Vector2i &v1, Vector2i &v2) {
            Vector2i vec;
            vec.x = v1.x + (-v2.x);
            vec.y = v1.y + (-v2.y);
            return vec;
        }
        int dotProd(Vector2i &v1, Vector2i &v2) { return v1.x * v2.x + v1.y * v2.y; }
    };

    class Vector2f {
    private:
        float x, y;
    public:
        float vec2[2]{x,y};
        Vector2f(float cX = 0.0f, float cY = 0.0f)
            :x(cX), y(cY)
        {
            assert(x != sizeof(int) && y != sizeof(int));
            vec2[0] = x;
            vec2[1] = y;
        }
        ~Vector2f() = default;
        inline float getMag() { return sqrt(x * x + y * y); }
        void Normalize() {
            if(x > 1)       x = 1;
            else if(x < -1) x = -1;
            if(y > 1)       y = 1;
            else if(y < -1) y = -1;
        }
        float* getVector() const {
            float coords[2];
            coords[0] = vec2[0];
            coords[1] = vec2[1];
            return coords;
        }
        inline float getX() const { return vec2[0]; }
        inline float getY() const { return vec2[1]; }
        inline void deleteVec() { delete this; }

        // Change all?
        Vector2f addVec(Vector2f &v1, Vector2f &v2) { // Re-do
            Vector2f vec;
            vec.x = v1.x + v2.x;
            vec.y = v1.y + v2.y;
            return vec;
        }
        Vector2f subVec(Vector2f &v1, Vector2f &v2) {
            Vector2f vec;
            vec.x = v1.x + (-v2.x);
            vec.y = v1.y + (-v2.y);
            return vec;
        }
        float dotProd(Vector2f &v1, Vector2f &v2) { return v1.x * v2.x + v1.y * v2.y; }
    };

    class Vector3i {
    private:
        int x, y, z;
    public:
        int vec3[3]{x,y,z};
        Vector3i(int cX = 0, int cY = 0, int cZ = 0)
            :x(cX), y(cY), z(cZ)
        {
            vec3[0] = x;
            vec3[1] = y;
            vec3[2] = z;
        }
        ~Vector3i() = default;
        inline int getMag() { return sqrt(x * x + y * y + z * z); }
        void Normalize() { // Check! | Optimise?
            if(x > 1)       x = 1;
            else if(x < -1) x = -1;
            if(y > 1)       y = 1;
            else if(y < -1) y = -1;
            if(z > 1)       z = 1;
            else if(z < -1) z = -1;
        }
        int* getVector() const {
            int coords[3];
            coords[0] = vec3[0];
            coords[1] = vec3[1];
            coords[2] = vec3[2];
            return coords;
        }
        inline int getX() const { return vec3[0]; }
        inline int getY() const { return vec3[1]; }
        inline int getZ() const { return vec3[2]; }
        inline void deleteVec() { delete this; }

        // Change all?
        Vector3i addVec3(Vector3i &v1, Vector3i &v2) { // Check! | Incorrect
            Vector3i vec;
            return ((v1.x + v2.x) + (v1.y - v2.y)  + (v1.z - v2.z));
            vec.x = v1.x + v2.x;
            vec.y = v2.y - v2.y;
            vec.z = v1.z = v2.z;
            return vec;
        }
        Vector3i dotProd3(Vector3i &v1, Vector3i &v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }
        Vector3i crossProd(Vector3i &v1, Vector3i &v2) { // Continue
            // return v1.getMag() * v2.getMag();
        }
    };

    class Vector3f {
    private:
        float x, y, z;
    public:
        float vec3[3]{x,y,z};
        Vector3f(float cX = 0.0f, float cY = 0.0f, float cZ = 0.0f)
            :x(cX), y(cY), z(cZ)
        {
            assert(x != sizeof(int) && y != sizeof(int) && z != sizeof(int));
            vec3[0] = x;
            vec3[1] = y;
            vec3[2] = z;
        }
        ~Vector3f() = default;
        inline float getMag() { return sqrt(x * x + y * y + z * z); }
        void Normalize() { // Check! | Optimise?
            if(x > 1)       x = 1;
            else if(x < -1) x = -1;
            if(y > 1)       y = 1;
            else if(y < -1) y = -1;
            if(z > 1)       z = 1;
            else if(z < -1) z = -1;
        }
        float* getVector() const {
            float coords[3];
            coords[0] = vec3[0];
            coords[1] = vec3[1];
            coords[2] = vec3[2];
            return coords;
        }
        inline float getX() const { return vec3[0]; }
        inline float getY() const { return vec3[1]; }
        inline float getZ() const { return vec3[2]; }
        inline void deleteVec() { delete this; }

        // Change all?
        Vector3f addVec3(Vector3f &v1, Vector3f &v2) { // Check! | Incorrect
            Vector3f vec;
            return ((v1.x + v2.x) + (v1.y - v2.y)  + (v1.z - v2.z));
            vec.x = v1.x + v2.x;
            vec.y = v2.y - v2.y;
            vec.z = v1.z = v2.z;
            return vec;
        }
        Vector3f dotProd3(Vector3f &v1, Vector3f &v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z; }
        Vector3f crossProd(Vector3f &v1, Vector3f &v2) { // Continue
            // return v1.getMag() * v2.getMag();
        }
    };

    class Vector4i {
    private:
        int x, y, z, w;
    public:
        int vec4[4]{x,y,z,w};
        Vector4i(int cX = 0, int cY = 0, int cZ = 0, int cW = 0) 
            :x(cX), y(cY), z(cZ), w(cW)
        {
            vec4[0] = x;
            vec4[1] = y;
            vec4[2] = z;
            vec4[3] = w;
        }
        ~Vector4i() = default;
        inline int getMag() { return sqrt(x * x + y * y + z * z + w * w); }
        void Normalize() { // Origin ignored
            if(x > 1)       x = 1;
            else if(x < -1) x = -1;
            if(y > 1)       y = 1;
            else if(y < -1) y = -1;
            if(z > 1)       z = 1;
            else if(z < -1) z = -1;
        }
        int* getVector() const { // Convert to return existing vec array! Don't create new and return!
            int coords[4];
            coords[0] = vec4[0];
            coords[1] = vec4[1]; 
            coords[2] = vec4[2];
            coords[3] = vec4[3];
            return coords;
        }
        inline int getX() const { return vec4[0]; }
        inline int getY() const { return vec4[1]; }
        inline int getZ() const { return vec4[2]; }
        inline int getW() const { return vec4[3]; }
        inline void deleteVec() { delete this; }
    };

    class Vector4f {
    private:
        float x, y, z, w;
    public:
        float vec4[4]{x,y,z,w};
        Vector4f(float cX = 0.0f, float cY = 0.0f, float cZ = 0.0f, float cW = 0.0f) 
            :x(cX), y(cY), z(cZ), w(cW)
        {
            assert(x != sizeof(int) && y != sizeof(int) && z != sizeof(int) && w != sizeof(int)); // Improve?
            vec4[0] = x;
            vec4[1] = y;
            vec4[2] = z;
            vec4[3] = w;
        }
        ~Vector4f() = default;
        inline float getMag() { return sqrt(x * x + y * y + z * z + w * w); }
        void Normalize() { // Origin ignored
            if(x > 1)       x = 1;
            else if(x < -1) x = -1;
            if(y > 1)       y = 1;
            else if(y < -1) y = -1;
            if(z > 1)       z = 1;
            else if(z < -1) z = -1;
        }
        float* getVector() const { // Convert to return existing vec array! Don't create new and return!
            float coords[4];
            coords[0] = vec4[0];
            coords[1] = vec4[1]; 
            coords[2] = vec4[2];
            coords[3] = vec4[3];
            return coords;
        }
        inline float getX() const { return vec4[0]; }
        inline float getY() const { return vec4[1]; }
        inline float getZ() const { return vec4[2]; }
        inline float getW() const { return vec4[3]; }
        inline void deleteVec() { delete this; }
    };
}
#endif