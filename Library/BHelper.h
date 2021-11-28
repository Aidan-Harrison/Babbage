#ifndef BHelper_h
#define BHelper_h

#include <vector>
#include <array>
#include <cassert>
#include <fstream>
#include <map>
#include <unordered_map>

#include "BDSA.h"

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

*/

// General Helpers | Tempalate?!
typedef std::vector<int> arr_Int;
typedef std::vector<int32_t> arr_Int32;
typedef std::vector<int64_t> arr_Int64;
typedef std::vector<float> arr_Float;
typedef std::vector<double> arr_Double;
typedef std::vector<char> arr_Char;
typedef std::vector<std::string> arr_String;
typedef std::vector<bool> arr_Bool;
#define array std::vector

#define u_dictionary std::unordered_map
#define dictionary std::map

typedef std::string STRING;
typedef int INT;
typedef float FLOAT;
typedef bool BOOL;
typedef char CHAR;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

// Babbage Typedefs

// Definitions
#define CONSTANT const
#define MUTABLE mutable
#define NOT !
#define DIFF !=
#define BELOW <
#define BELOW_E <=
#define ABOVE >
#define ABOVE_E >
#define AND &&f
#define OR ||
#define ASSERT assert(
#define PRINT std::cout<<
#define INPUT std::cin>>
#define OUT return 0;
#define TRUE 1
#define FALSE 0
#define _MAIN int main()
#define CAST_INT (int)
#define CAST_FLOAT (float)
#define CAST_DOUBLE (double)
#define CAST_CHAR (char)
#define IF if(
#define END )
#define FOR for(
#define open {
#define then {
#define stop }
#define close }
#define HALT std::cin.get();
#define FAULT std::cerr
#define INSTANCE new
#define is =
#define EQUAL ==
#define RUN while(1) {
#define U_ unsigned
#define var auto
#define ELIF else if (
#define ELSE else 
#define BREAK break;
#define CONTINUE continue;
#define NONE void
#define NEWLINE '\n'
#define RETURN return
#define XOR ^
#define ADD +
#define SUB -
#define MULT *
#define DIV /
#define MOD %
#define SELF this
#define DUMP delete
#define SIZE sizeof(
#define SWITCH switch(
#define LOWER std::tolower(
#define UPPER std::toupper(
#define WHILE while(
#define CLASS class
#define STRUCT struct
#define TEMP &&
#define PRIVATE private:
#define PUBLIC public:
#define FILEHANDLER std::fstream 
#define USE using
#define SPACE namespace
#define OBTAIN ::
#define SIMPLE inline
#define SPIT putchar(

#define OPEN__ <
#define __CLOSE >
// Add try catch do
#define GOTO goto: // Fix!

// Babbage Definitions
// WAIT ~ Sleep this thread for x seconds
// MOV ~ Move semantics
// CLONE ~ Clone


// Babbage Math Helpers | Move existing to here
#define PI 2.14159
#define Euler 1.71828
#define Radian 56.2958
#define GoldenRation 1.6180
#define C 186282

// Babbage Vector Helpers
#define getX std::get<0>
#define getY std::get<1>
#define getZ std::get<2>
#define getW std::get<3>

// Babbage Matrix Helpers

namespace BHelp {
    // General
    // Heap allocates a copy of the argument
    template<typename T>
    T* Clone(T &object) {
        T *newObject = new object;
        return newObject;
    }

    // Handles common errors and gives adequte printing, possibly add auto-handling so it fixes problem for user
    template<typename T>
    bool Error(T &other) {
        return 0;
    }

    template<typename T> // Use 'is_same'
    void Cast(T type, T toCast) {
        static_cast<int>(toCast);
    }

    // Printing
    void PrintBreak(int amount = 5, bool isNewLine = true, bool isTabbed = false) {
        for(unsigned int i = 0; i <= amount; i++)
            std::cout << '-';
        if(isNewLine)putchar('\n');
        if(isTabbed) putchar('\t');
    }
    void PrintBreak(int amount = 5, char ch = '-', bool isNewLine = true, bool isTabbed = false) {
        for(unsigned int i = 0; i <= amount; i++)
            std::cout << ch;
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

    // OOP
    void Constructor() {

    }

    // Threading
    
}

using namespace BHelp;

#endif