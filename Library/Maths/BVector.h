#ifndef BVector_h
#define BVector_h

#include <cassert>
#include <algorithm>
#include <cmath>
#include <tuple>
// Add printing

namespace bvector {

    struct Vector1i {
        int x;
        int vec1[1]{x};
        Vector1i(int cX = 0)
            :x(cX)
        {
            vec1[0] = vec1[0];
        }
        inline int getMag() { return sqrt(x * x); }
        void Normalize() {
            if(x > 1)       x = 1;
            else if(x < -1) x = -1;
        }
        inline int getVector() const { return vec1[0]; }
        inline void deleteVec() { delete this; }

        ~Vector1i() {};
    };
    struct Vector1f {
        float x;
        float vec1[1]{x};
        Vector1f(float cX = 0.0f)
            :x(cX)
        {
            assert(x != sizeof(int));
            vec1[0] = vec1[0];
        }
        inline float getMag() { return sqrt(x * x); }
        void Normalize() {
            if(x > 1)       x = 1;
            else if(x < -1) x = -1;
        }
        inline float getVector() const { return vec1[0]; }
        inline void deleteVec() { delete this; }

        ~Vector1f() {};
    };
    struct Vector2i {
        int x, y;
        int vec2[2]{x,y};
        Vector2i(int cX = 0, int cY = 0)
            :x(cX), y(cY)
        {
            vec2[0] = x;
            vec2[1] = y;
        }
        inline int getMag() { return sqrt(x * x + y * y); }
        void Normalize() {
            if(x > 1)       x = 1;
            else if(x < -1) x = -1;
            if(y > 1)       y = 1;
            else if(y < -1) y = -1;
        }
        std::tuple<int, int> getVector() const {
            std::tuple<int,int> coords;
            std::get<0>(coords) = vec2[0];
            std::get<1>(coords) = vec2[1];
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

        ~Vector2i() {};
    };

    Vector2i operator+(Vector2i &v1, Vector2i &v2) { return v1.x + v2.x + v1.y + v2.y;} // Check!

    struct Vector2f {
        float x, y;
        float vec2[2]{x,y};
        Vector2f(float cX = 0.0f, float cY = 0.0f)
            :x(cX), y(cY)
        {
            assert(x != sizeof(int) && y != sizeof(int));
            vec2[0] = x;
            vec2[1] = y;
        }
        inline float getMag() { return sqrt(x * x + y * y); }
        void Normalize() {
            if(x > 1)       x = 1;
            else if(x < -1) x = -1;
            if(y > 1)       y = 1;
            else if(y < -1) y = -1;
        }
        std::tuple<float,float>getVector() const {
            std::tuple<float,float> coords;
            std::get<0>(coords) = vec2[0];
            std::get<1>(coords) = vec2[1];
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
        
        ~Vector2f() {};
    };

    Vector2f operator+(Vector2f &v1, Vector2f &v2) { return v1.x + v2.x + v1.y + v2.y; } // Check!

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
        inline int getMag() { return sqrt(x * x + y * y + z * z); }
        void Normalize() { // Check! | Optimise?
            if(x > 1)       x = 1;
            else if(x < -1) x = -1;
            if(y > 1)       y = 1;
            else if(y < -1) y = -1;
            if(z > 1)       z = 1;
            else if(z < -1) z = -1;
        }
        std::tuple<int,int,int> getVector() const {
            std::tuple<int,int,int> coords{};
            std::get<0>(coords) = vec3[0];
            std::get<1>(coords) = vec3[1];
            std::get<2>(coords) = vec3[2];
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
            return *this;
        }
        ~Vector3i() {};
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
        inline float getMag() { return sqrt(x * x + y * y + z * z); }
        void Normalize() { // Check! | Optimise?
            if(x > 1)       x = 1;
            else if(x < -1) x = -1;
            if(y > 1)       y = 1;
            else if(y < -1) y = -1;
            if(z > 1)       z = 1;
            else if(z < -1) z = -1;
        }
        std::tuple<float,float,float> getVector() const {
            std::tuple<float,float,float> coords{};
            std::get<0>(coords) = vec3[0];
            std::get<1>(coords) = vec3[1];
            std::get<2>(coords) = vec3[2];
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
            return *this;
        }
        ~Vector3f() {};
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
        inline int getMag() { return sqrt(x * x + y * y + z * z + w * w); }
        void Normalize() { // Origin ignored
            if(x > 1)       x = 1;
            else if(x < -1) x = -1;
            if(y > 1)       y = 1;
            else if(y < -1) y = -1;
            if(z > 1)       z = 1;
            else if(z < -1) z = -1;
        }
        std::tuple<int,int,int,int> getVector() const { // Convert to return existing vec array! Don't create new and return!
            std::tuple<int,int,int,int> coords;
            std::get<0>(coords) = vec4[0];
            std::get<1>(coords) = vec4[1];
            std::get<2>(coords) = vec4[2];
            std::get<3>(coords) = vec4[3];
            return coords;
        }
        inline int getX() const { return vec4[0]; }
        inline int getY() const { return vec4[1]; }
        inline int getZ() const { return vec4[2]; }
        inline int getW() const { return vec4[3]; }
        inline void deleteVec() { delete this; }

        ~Vector4i() {};
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
        inline float getMag() { return sqrt(x * x + y * y + z * z + w * w); }
        void Normalize() { // Origin ignored
            if(x > 1)       x = 1;
            else if(x < -1) x = -1;
            if(y > 1)       y = 1;
            else if(y < -1) y = -1;
            if(z > 1)       z = 1;
            else if(z < -1) z = -1;
        }
        std::tuple<float,float,float,float> getVector() const { // Convert to return existing vec array! Don't create new and return!
            std::tuple<float,float,float,float> coords;
            std::get<0>(coords) = vec4[0];
            std::get<1>(coords) = vec4[1];
            std::get<2>(coords) = vec4[2];
            std::get<3>(coords) = vec4[3];
            return coords;
        }
        inline float getX() const { return vec4[0]; }
        inline float getY() const { return vec4[1]; }
        inline float getZ() const { return vec4[2]; }
        inline float getW() const { return vec4[3]; }
        inline void deleteVec() { delete this; }

        ~Vector4f() {};
    };
}
#endif