#ifndef BHelper_h
#define BHelper_h

#include <vector>
#include <array>
#include <cassert>
#include <fstream>
#include <map>
#include <unordered_map>
#include <type_traits>
#include <typeinfo>
#include <utility>

#include "BDSA.h"
#include "BMath.h"
#include "BVector.h"

// Main Header
// Contains all other headers
// Turns into its own language as well as header

// To do:
/*
    Add file handling system
    Add map helpers
    Add bitshif helpers
    Add move semantic function
        -- This will be the largest task
    Add error handling helpers
    Add OS Functions
    Function pointers?
    More operator overloading
*/

// General Helpers | Template?!
    // Use/Implement custom data structures!!!
#define array std::vector

#define u_dict std::unordered_map
#define dict std::map

typedef std::string String;
typedef int INT;
typedef float FLOAT;
typedef bool BOOL;
typedef char CHAR;
typedef long LONG;
typedef long long LONG_LONG;

typedef unsigned int U_INT;
typedef unsigned long U_L;
typedef unsigned long long U_LL;

typedef int_fast8_t  i8;
typedef int_fast16_t i16;
typedef int_fast32_t i32;
typedef int_fast64_t i64;

typedef const int c_INT;
typedef const float c_FLOAT;
typedef const char c_CHAR;
typedef const long c_LONG;
typedef const long long c_LL;

typedef const uint8_t c_u8;
typedef const uint16_t c_u16;
typedef const uint32_t c_u32;
typedef const uint64_t c_u64;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

// Babbage Typedefs


// Definitions
#define mut mutable
#define NOT !
#define isnt !=
#define fn void
#define BELOW <
#define BELOW_E <=
#define ABOVE >
#define ABOVE_E >=
#define AND &&
#define OR ||
#define intFlag "%d"
#define strFlag "%s"
#define ASSERT assert( // Check!
#define PRINT std::cout<<
#define INPUT std::cin>>
#define OUT_S return 0;
#define OUT_F return 1;
#define TRUE 1
#define FALSE 0
#define _MAIN int main() {
    // Convert to C style casts
#define CAST_INT (int)
#define CAST_FLOAT (float)
#define CAST_DOUBLE (double)
#define CAST_CHAR (char)
#define CAST_u8 (uint8_t)
#define CAST_u16 (uint16_t)
#define CAST_u32 (uint32_t)
#define CAST_u64 (uint64_t)
#define IF if(
#define _end )
#define for_ for(
#define __open {
#define close__ };
#define HALT std::cin.get();
#define FAULT std::cerr
#define is ==
#define loop while(1) {
#define let auto
#define ELIF else if (
#define ELSE else 
#define brk break;
#define cont continue;
#define NONE nullptr
#define NEWLINE '\n'
#define TAB '\t'
#define ret return
#define XOR ^
#define ADD +
#define SUB -
#define MULT *
#define DIV /
#define MOD %
#define bAND &
#define bOR |
#define ADD_E +=
#define SUB_E -=
#define MUL_E *=
#define DIV_E /=
#define self this
#define DUMP delete
#define SIZE sizeof(
#define SWITCH switch(
#define default default:
#define LOWER std::tolower(
#define UPPER std::toupper(
#define WHILE while(
#define pack struct
#define private private:
#define public public:
#define FILEHANDLER std::fstream 
#define use using
#define SPACE namespace
#define READY inline
#define GENERIC typename<
#define OPEN_ <
#define _CLOSE >
#define PAIR std::pair<auto,auto>
#define ___ putchar('\n');
// Add try catch do
#define GOTO goto: // Fix!

// Babbage Definitions
// WAIT ~ Sleep this thread for x seconds
// MOV ~ Move semantics
// CLONE ~ Clone

// Babbage Math Helpers | Move existing to here

// Babbage Vector Helpers
#define getX std::get<0>
#define getY std::get<1>
#define getZ std::get<2>
#define getW std::get<3>

// Babbage Matrix Helpers

namespace bge {
    // General
    float randf(const float val) {
        float remainder = val/10;
        float result = rand() % (int)val;
        result += remainder;
        return result;
    }

    template<typename T>
    inline void prtinp(const std::string & statement, T input) {
        printf("%s", statement);
        std::cin >> input;
    }

    template<typename T>
    inline void prtinp(const std::string && statement, T input) noexcept { // Check!
        printf("%s", statement);
        std::cin >> input;
    }

    int rand_range(const int a, const int b) {
        int result = rand() % b;
        if(result < a)
            result = a;
        return result;
    }
    float rand_range(const float a, const float b) {
        float result = rand() % (int)b;
        if(result < a)
            result = a;
        return result;
    }

    template<typename T>
    T reverse(T con, uint32_t srt = 0, uint32_t end = INT_MAX) { // Remove?
        if(end == INT_MAX) { // Type match
            if(typeid(con) == typeid(std::string))
                end = con.length()-1;
        }
        while(srt < end) {
            T temp = con[srt]; // Check!
            con[srt] = con[end];
            con[end] = temp;
            srt++;
            end--;
        }
        return con;
    } 
    template<typename T>
    T reverse(std::vector<T> & con, uint32_t srt = 0, uint32_t end = INT_MAX) { // Vector overload
        if(end == INT_MAX) { // Type match
            end = con.size()-1;
        }
        while(srt < end) {
            T temp = con[srt];
            con[srt] = con[end];
            con[end] = temp;
            srt++;
            end--;
        }
        return con;
    }  

    template<typename T>
    void swap(T con, const int a, const int b) {
        T temp = con[a];
        con[a] = con[b];
        con[b] = temp;
    }

    

    inline void spit(const char a) { putchar(a); }
    int random(const int val, bool zero = false) { 
        if(zero) return rand() % val; 
        return rand() % val +1; 
    }

    // Move this?
    template<typename T>
    struct bPair {
        T pair[2];

        inline T first() { return pair[0]; } const; 
        inline T second() { return pair[1]; } const; 

        bool Compare() { // Internal comparrison | Add object memory size comparrison
            return (pair[0] > pair[1]) ? true : false;
        }

        bool CompareOther(bPair &otherPair) { // Add object based memory comparrison
            int value = pair[0] + pair[1];
            if(value > otherPair[0] + otherPair[1])
                return true;
            return false;
        }

        void Clear() { // Check!, is heap allocated object, delete!
            pair[0] = 0;
            pair[1] = 0;
        }

        bPair() {}
        // Copy constructor
        bPar(bPair &otherPair) 
            : pair[0](otherPair.first()), pair[1](otherPair.second())
        {
        }
        ~bPair() {}
    };

    // Replace with custom vector! Move down
    template<typename T>
    struct bHash {
        std::vector<bPair> table{};

        void Search(T key) { // Do binary search if size if large enough
            
        }


        bHash() {}
        ~bHash() {}
    };

    template<typename T>
    struct bArray { // Fix!
        int SIZE = 0;
        T array[SIZE];

        void Resize(const int amount, bool _INCREASE = true) {
            T newArray[amount];
            if(_INCREASE) {
                for(unsigned int i = 0; i < SIZE; i++) {
                    newArray[i] = array[i];
                }
            }
            else {
                for(unsigned int i = 0; i < SIZE-1; i++) {
                    newArray[i] = array[i];
                } 
            }
            SIZE = amount;
            
            // Delete old array
        }

        void append(T data) {
            if(array[SIZE] == NULL)
                Resize(SIZE+1);
            array[SIZE] = data;
            SIZE++;
        }

        T remove() {
            T data = array[SIZE];
            Resize(SIZE-1, false);
            SIZE--;
            return data;
        }

        void clear() {
            for(unsigned int i = 0; i < SIZE; i++) {
                array[i] = NULL;
            }
        }

        inline void size() const { return SIZE; }

        bArray() {}
        ~bArray() {}
    };

        // Heap allocates a copy of the argument
        // Heap allocate if large object
    template<typename T>
    T* Clone(T &object) {
        if(std::is_same<object, bvector::Vector1i>) { // Check!
            bvector::CloneVector(object, true);
        }
        T *newObject = new object;
        return newObject;
    }

    // Bulk allocates n objects with specified construction | Handle return with heap and non heap
    // Return currently only handles heap!!
    template<typename T>
    std::vector<T*> BulkAlloc(T type, const int amount, bool _HEAP = false, const int fC = 0, const int sC = 0, const int tC = 0) {
        std::vector<T*> objects{};
        std::string _typeName = typeid(type).name();
        if(_typeName.find("Point")) {
            std::cout << "DEBUG: Point bulk allocation";
            for(int i = 0; i <= amount; i++) {
                if(_HEAP)
                    bmath::Point * newPoint = new bmath::Point(fc, sc);
                    objects.push_back(newPoint);
                else
                    bmath::Point newPoint(fc, sc);
                    objects.push_back(&newPoint);
            }
        }
        else if(_typeName.find("Vector1i")) {
            std::cout << "DEBUG: Vector (int) bulk allocation";
            for(int i = 0; i <= amount; i++) {
                if(_HEAP)
                    bvector::Vector1i * newVec = new bvector::Vector1i(fC);
                    objects.push_back(newVec);
                else
                    bvector::Vector1i newVec(fC);
                    objects.push_back(newVec);
            }
        }
        else if(_typeName.find("Vector1f")) {
            std::cout << "DEBUG: Vector (float) bulk allocation";
            for(int i = 0; i <= amount; i++) {
                if(_HEAP)
                    bvector::Vector1i * newVec = new bvector::Vector1i(fC);
                    objects.push_back(newVec);
                else
                    bvector::Vector1i newVec(fC);
                    objects.push_back(newVec);
            }
        }
        return objects;
    }

    inline void DPrint(const std::string & str, bool _LINE = true) { // Add r_value?
        if(_LINE)
            std::cout << "DEBUG: " << str << '\n';
        else
            std::cout << "DEBUG: " << str;
    }

    template<typename T>
    std::vector<std::vector<T>> MatrixPack(std::vector<T> &arr) { // Implement sorting option!
        int counter = 0;
        std::vector<std::vector<T>> matrix{};
        matrix.resize(arr.size()/2);
        int total = arr.size() + 1;
        int half = arr.size()/2 + 1;
        int rows = total / half+1;
        for(int i = 0; i < rows; i++)
            matrix[i].resize(arr.size()/2);
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[i].size(); j++) {
                matrix[i][j] = arr[counter];
                counter++;
            }
        }
        return matrix;
    } 

    // Handles common errors and gives adequte printing, possibly add auto-handling so it fixes problem for user
    template<typename T>
    bool Error(T &other) {
        return 0;
    }

    template<typename T> // Use 'is_same'
    inline void Cast(T type, T toCast) {
        static_cast<int>(toCast);
    }

    // Printing
    void PrintBreak(const int amount = 5, bool isNewLine = true, bool isTabbed = false) {
        for(uint32_t i = 0; i < amount; i++)
            putchar('-');
        if(isNewLine)putchar('\n');
        if(isTabbed) putchar('\t');
    }
    void PrintBreak(const int amount = 5, const char ch = '-', bool isNewLine = true, bool isTabbed = false) {
        for(uint32_t i = 0; i < amount; i++)
            putchar(ch);
        if(isNewLine)putchar('\n');
        if(isTabbed) putchar('\t');
    }

    // Keyboard Parser | Find way to make universally injectable
    void ParseKey(const int key) {

    }

    // OS Functions | Make OS Independent (Auto-detect) | Detect both function default and function definition
    void OS(const std::string &command = "cls") {
        if(command == "cls")
            system("cls");
        else if(command == "clear")
            system("clear");
    }

    // OOP | ???
    void Constructor() { // ??

    }

    // Threading

}

namespace binj {
    const bool LexString() {

    }

    const bool LexChar(const char ch) {
        switch(ch) {
            case '0': return;
        }
    }

    template<typename T>
    class injStr {
    private:
        std::vector<std::tuple<std::string, T>> s{};    
        uint32_t size = 0;
        void resize(int * newSize) {
            s.resize(newSize);
        }
    public:
        injStr() {}
        injStr(const int _s)
            :size(s)
        {
        }
        ~injStr() = default;
    };

    template<typename T>
    void INJECT(injStr & _inp, bool _DEBUG = false) { 
        int m = 0;
        std::vector<T> storage{};
        while(1) {
            for(unsigned int i = 0; i < _inp.size(); i++) {
                if(_inp[i] == "STR:") { // Store
                    while(_inp[m] != ",") {
                        storage.push_back(_inp[i+1]);
                        if(_DEBUG) {
                            putchar('S');
                            std::cout << "Mem: : " << sizeof(_inp[i+1]);  
                        }
                    }
                }
                else if(_inp == "DMP!") {
                    int CC = LexChar(_inp[i+1]);
                    for(unsigned int i = 0; i < CC; i++) {
                        
                    }
                }
            }
        }
    }
}

#endif