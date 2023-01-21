/*
    Create by Aidan Harrison
    Open license
    Babbage - General purpose library
    Version: 0.1 (ALPHA)

    Primary header, contains all other headers
*/

#ifndef BHelper_h
#define BHelper_h

#include <array>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <type_traits>
#include <typeinfo>
#include <utility>
#include <chrono>

#include "BDSA.h"
#include "BMath.h"
#include "BVector.h"
#include "Backend.h"

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
#define and &&
#define or ||
#define ASSERT assert( // Check!
#define PRINT std::cout<<
#define INPUT std::cin>>
#define OUT_S return 0;
#define OUT_F return 1;
#define TRUE 1
#define FALSE 0
#define _MAIN int main()
    // Convert to C style casts
#define cast_INT (int)
#define cast_FLOAT (float)
#define cast_DOUBLE (double)
#define cast_CHAR (char)
#define cast_u8 (uint8_t)
#define cast_u16 (uint16_t)
#define cast_u32 (uint32_t)
#define cast_u64 (uint64_t)
#define IF if(
#define _end )
#define for_ for(
#define __open {
#define close__ };
#define HALT std::cin.get();
#define FAULT std::cerr<<
#define is ==
#define loop while(1)
#define let auto
#define elif else if (
#define NONE nullptr
#define TAB '\t'
#define XOR ^
#define ADD +
#define SUB -
#define MULT *
#define DIV /
#define MOD %
#define self this
#define DUMP delete
#define SIZE sizeof(
#define pack struct
#define default default:
#define private private:
#define public public:
#define use using
#define SPACE namespace
#define READY inline
#define GENERIC typename<
#define OPEN_ <
#define _CLOSE >
#define ___ putchar('\n')
#define spit putchar

// Timing | Check!
#define CLOCK_START std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
#define CLOCK_END std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
#define GET_CLOCK_TIME_MS std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()
#define GET_CLOCK_TIME_NS std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()

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

// Enumerations
enum DIGITS{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN};
enum OPTLEVELS{OPT_LEVEL_0, OPT_LEVEL_1, OPT_LEVEL_2};

namespace bge {
    bool isChar(const char c) {
        for(char i = 'a'; i <= 'z'; i++)
            if(c == i)
                return true;
        for(char i = 'A'; i <= 'Z'; i++)
            if(c == i)
                return true;
        return false;
    }

    float randf(const float val) {
        float remainder = val/10;
        float result = rand() % (int)val;
        result += remainder;
        return result;
    }

    int randi_range(const int a, const int b) {
        int result = rand() % b;
        if(result < a)
            result = a;
        return result;
    }
    float randf_range(const float a, const float b) {
        float result = rand() % (int)b;
        if(result < a)
            result = a;
        return result;
    }

    // Finish
    int random(int range, std::vector<int> && arr) {
        std::vector<int> cullList{};
        for(int i = 0; i < range; i++) {
            bool found = false;
            for(int j = 0; j < arr.size(); j++) {
                if(i == arr[j])
                    found = true;
            }
            if(!found)
                cullList.push_back(i);
        }
    }

    float random(float range, std::vector<float> && arr) {
        std::vector<float> cullList{};
        for(int i = 0; i < range; i++) {
            bool found = false;
            for(int j = 0; j < arr.size(); j++) {
                if(i == arr[j])
                    found = true;
            }
            if(!found)
                cullList.push_back(i);
        }
    }

    // Remove both, move to member function of custom vector
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
    T reverse(std::vector<T> & con, uint32_t str = 0, uint32_t end = INT_MAX) { // Vector overload
        if(end == INT_MAX) { // Type match
            end = con.size()-1;
        }
        while(str < end) {
            T temp = con[str];
            con[str] = con[end];
            con[end] = temp;
            str++;
            end--;
        }
        return con;
    }  

    template<typename T>
    void SemiOrderedIter(std::vector<T> & arr, int entropy = 3) {
    }

    template<typename T>
    std::vector<int> SemiOrderedIter(std::vector<T> & arr, int entropy = 3) {
        std::vector<T> result{};
        
        for(int i = 0; i < arr.size(); i++) {
            int choice = rand() % 2;
            if(choice == 1) {
                for(int j = i; j < i+entropy; j++) {
                    int choice = rand() % 2;
                    if(choice == 1 && markedIndexes[j]) {
                        result.push_back(arr[j]);
                        markedIndexes.push_back(j);
                        break;
                    }
                }
            }
        }
        return result{};
    }

    std::vector<std::string> getFirstChar(const std::string & str, std::vector<char> flagChars = {' '}) {
        std::vector<std::string> result{};
        std::string curFrag = "";
        for(int i = 0; i < str.length(); i++) {
            curFrag += str[i];
            for(int j = 0; j < flagChars.size(); i++) {
                if(str[i] == flagChars[j]) {
                    result.push_back(curFrag);
                    curFrag = "";
                    break;
                }
            }
        }
        return result;
    }

    std::vector<std::string> fragmentString(const std::string & str, std::vector<char> flagChars = {' '}, bool optimisationLevel = 0) {
        std::vector<std::string> result{};
        std::string curFrag = "";
        // Opt level = 0
        if(!optimisationLevel) {
            for(int i = 0; i < str.length(); i++) {
                for(int j = 0; j < flagChars.size(); j++) {
                    if(str[i] == flagChars[j]) {
                        result.push_back(curFrag);
                        curFrag = "";
                        break;
                    }
                    curFrag += str[i];
                }
            }
        }
        else {
            for(char c : flagChars) // Might slow down?
                if(isChar(c))
                    return;
            // Opt level = 1
            for(int i = 0; i < str.length(); i++) {
                if(!isChar(str[i])) {
                    for(int j = 0; j < flagChars.size(); j++) {
                        if(str[i] == flagChars[j]) {
                            result.push_back(curFrag);
                            curFrag = "";
                            break;
                        }
                        curFrag += str[i];
                    }
                }
            }
        }
        return result;
    }

    // Array functions | Conver to custom array
    template<typename T>
    std::vector<T> GenArray(const int size, double lowerDist, double higherDist) {
        std::vector<T> result{};
        for(unsigned int i = 0; i < size; i++)
            result.push_back(rand_range(lowerDist, higherDist));
        return result;
    }

    template<typename T> // Do!
    std::vector<T> GenArray(const int size, T type, bool random = false, int range = 1) {
        std::vector<T> result{};
        switch(T.type) {
            case 0: {
                for(int i = 0; i < size; i++) {
                    if(random)
                        result.push_back(rand() % range);
                    else
                        result.push_back(i);
                }
                break;
            }
        }
        return result;
    }

    std::string upStr(std::string & message) {
        for(unsigned int i = 0; i < message.length(); i++)
            std::toupper(message[i]);
        return message;
    }
    std::string lowStr(std::string & message) {
        for(unsigned int i = 0; i < message.length(); i++)
            std::tolower(message[i]);
        return message;
    }

    // Split an array into two seperate ones given a point
    std::pair<std::string*,std::string*> split(std::vector<std::string> & arr, const char sPoint) {
        std::string * fSplit = new std::string;
        std::string * sSplit = new std::string;
        std::pair<std::string*, std::string*> result = {fSplit,sSplit};
        bool found = false;
        for(int i = 0; i < arr.size(); i++) {
            for(int j = 0; j < arr.size(); j++) {
                if(arr[i].at(j) == sPoint) {
                    int fPointer = i+1, sPointer = i+1;
                    while(fPointer > 0) {
                        fSplit->push_back(arr[i].at(j));
                        fPointer--;
                    }
                    while(sPointer < arr.size()) {
                        sSplit->push_back(arr[i].at(j));
                        sPointer++;
                    }
                    found = true;
                    break;
                }
                if(found)
                    break;
            }    
        }
        return result;
    }

    std::string remove(std::string str, const char ch) {
        std::string result;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] != ch)
                result += str[i];
        }
        return result;
    }

    std::string truncate(std::vector<std::string> & arr, bool wSpace = true) {
        std::string result;
        for(int i = 0; i < arr.size(); i++) {
            result += arr[i];
            if(wSpace)
                result += " ";
        }
        return result;
    }  

    void trim(std::string & str) {
        int counter = str.length()-1;
        while(str[counter] == ' ') {
            str.pop_back();
            counter--;
        }
    }

    void shuffle(std::string & str) { // Randomises a container
        for(unsigned int i = 0; i < str.length(); i++) {
            char curChar = str[i];
            int shufflePos = rand() % str.length();
            while(shufflePos == i) 
                shufflePos = rand() % str.length();
            str[i] = str[shufflePos];
            str[shufflePos] = curChar;
        }
    }

    template<typename T>
    void shuffle(std::vector<T> & con) { // Randomises a container
        for(unsigned int i = 0; i < con.size(); i++) {
            T curEl = con[i];
            int shufflePos = rand() % con.size();
            while(shufflePos == i) 
                shufflePos = rand() % con.size();
            con[i] = con[shufflePos];
            con[shufflePos] = curEl;
        }
    }

    std::vector<int> Merge(std::vector<int> & a1, std::vector<int> & a2, bool inPlace = false) { // Merge two arrays as sorted
        // Modifies a1 if flag false
        std::vector<int> newVec{};
        if(inPlace) {
            for(unsigned int i = 0; i < a2.size(); i++) {
                for(unsigned int j = 0; j < a1.size(); j++) { // Locate position
                    if(a1[i] > a1[j] && a1[i] < a2[j+1])
                        a1.insert(a1.begin()+j, a2[i]);
                }
                // Inject into correct location
            }
        }
        else {
            for(unsigned int i = 0; i < a1.size(); i++)
                newVec.push_back(a1[i]);
            for(unsigned int i = 0; i < a2.size(); i++)
                newVec.push_back(a1[i]);
            std::sort(newVec.begin(), newVec.end()); // Remove and inject elements in order, online sort?
            // Might be faster or slow, maybe add manual toggle
            return newVec;
        }
        return a1;
    }

    // Combines two objects if applicable
    template<typename T>
    auto combine(T & a, T & b, bool n = false) {
        std::vector<T> newObj;
        if(a.size() == 0)
            for(unsigned int i = 0; i b.size(); i++)
                a.push_back(b[i]);
        else
            for(unsigned int i = 0; i a.size(); i++)
                b.push_back(a[i]);
        if(n) {
            int size = a.size() + b.size();
            for(unsigned int i = 0; i < size; i++) {
                if(i < a.size())
                    newObj.push_back(a[i]);
                else
                    newObj.push_back(b[i]);
            }
            return newObj;
        }
        return false;
    }

    // Normalise
    inline const bool boundsCheck(const int lowerBound, const int higherBound, const int a, const int b) {
        return a > lowerBound && b < higherBound;
    }

    std::vector<int> nLargest(std::vector<int> & arr, int n = 1) {
        std::vector<int> result{}, marked{};
        int max = INT_MIN, mPos = 0;
        while(result.size() < n) {
            for(int i = 0; i < arr.size(); i++) {
                bool found = false;
                if(arr[i] > max) {
                    for(int j = 0; j < marked.size(); j++) {
                        if(marked[j] == i) {
                            found = true;
                            break;
                        }
                    }
                    if(found)
                        continue;
                    mPos = i;
                }
            }
            result.push_back(max);
            marked.push_back(mPos);
        }
        std::sort(result.begin(), result.end());
        return result;
    }

    void Normalise(std::vector<int> & arr, float smoothFactor = 0.5f) {
        std::vector<int> qPoints = nLargest(arr);
        for(int i = 1; i < qPoints.size(); i++) {
            int left = qPoints[i]-1, right = qPoints[i+1]+1;
            int mid = qPoints[i+1] - qPoints[i-1];
            if(!boundsCheck(0, qPoints.size(), left, right+2))
                continue;
            while(right < qPoints.size() || right < i+2) {
                arr[right]++;
                right++;
            }
            if(!boundsCheck(0, qPoints.size(), left-2, right))
                continue;
            while(left > 0 || left < i-2) {
                arr[left]++;
                left++;
            }
        }
    }

    template<typename T>
    void swap(T * a, T * b) {
        T temp = *a;
        *a = *b;
        *b = temp;
    }

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

    // Resolves as much of two containers as possible
    std::vector<bool> resolve(std::vector<int> & a1, std::vector<int> & a2, const std::string && op) {
        std::vector<bool> resolutions{};
        int size = a1.size();
        if(a2.size() < a1.size())
            size = a2.size();
        for(unsigned int i = 0; i < size; i++) {
            if(op == ">") {
                if(a1[i] > a2[i]) resolutions.push_back(true);
                else              resolutions.push_back(false);
            } else if(op == "<") {
                if(a1[i] < a2[i]) resolutions.push_back(true);
                else              resolutions.push_back(false);
            } else if(op == "=") {
                if(a1[i] == a2[i]) resolutions.push_back(true);
                else               resolutions.push_back(false);
            } else if(op == "!") {
                if(a1[i] != a2[i]) resolutions.push_back(true);
                else               resolutions.push_back(false);
            }
        }
        return resolutions;
    }

    template<typename T>
    std::vector<bool> resolve(std::vector<T> & a1, std::vector<T> & a2, const std::string && op) {
        std::vector<bool> resolutions{};
        int size = a1.size();
        if(a2.size() < a1.size())
            size = a2.size();
        for(unsigned int i = 0; i < size; i++) {
            if(op == ">") {
                switch(a1[i].type) {
                
                }
            }
        }
    }

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

    // Fix!
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

    // Continue
    void SubtractArray(std::vector<int> & a1, std::vector<int> & a2) {
        int index = 0;
        std::unordered_map<int,int> map;
        for(int i = 0; i < a1.size(); i++)
            map[i] = i;
        for(unsigned int i = 0; i < a2.size(); i++) {
            if(map[a2[i]]) {
                std::cout << "Found!\n";
                // Remove Element
                std::cout << a1[map[a2[i]]-1] << '\n';
                a1[map[a2[i]]-1] = a1[map[a2[i]]];
                //for(int j = i; j < a2.size()-1; j++) {
                    //a1[j] = a1[j+1];
                //}
            }
        }
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

    // Lexer for mini inline assembler
        // - Replace with custom array and string
    template<typename T>
    struct injProj {
        bst::bHash<T,T> variables;
        bst::bHash<T,T> table; // Lexing table | Remove?
        std::vector<T> storage{}; // Global
        std::vector<T> buffer{}; // Temp

        injproj() {}
    };

    template<typename T>
    T STORE_VALUE(const std::string & str, int index) {
        // Obtain value
        // Store apprpiate data
        std::string value;
        for(int k = index; k < str.length(); k++) {
            if(str[k] != ' ')
                value += str[k];
        }
        switch(valCode) {
            case 0: {
                return atoi(value.c_str());
                break;
            }
            case 1: {
                return atof(value.c_str());
                break;
            }
            case 2: {
                return value.c_str(); // Do babbage string conversion before return
                break;
            }
        }
    }

    const int containsType(std::string & str) {
        std::string curType="";
        for(int k = 0; k < str.length(); k++) {
            if(str[k] == '~') { // Found possible type
                int l = k+1;
                while(str[l] != ' ') {
                    curType += str[l];
                    l++;
                }
                switch(INJECT_INSTRUCTIONS::injInstructions[curType]) {
                    case 0: {
                        INJECT_INSTRUCTIONS::valCode = 0;
                        return 0; break; }
                    case 1: {
                        INJECT_INSTRUCTIONS::valCode = 1;
                        return 1; break; }
                    case 2: {
                        INJECT_INSTRUCTIONS::valCode = 2;
                        return 2; break; }
                }
                return -1;
            }
        }
        return -1;
    }

    const bool SearchStorage(const std::string & target) { // Checks both storage and buffer for valid value and returns true or false, uses 'HAS' command
    }

    // Push to hash table
    template<typename T>
    void INJECT(std::vector<std::string> && _inp) noexcept { 
        int marcher{}, top{};
        bst::bHash<T,T> variables;
        bst::bHash<T,T> table; // Lexing table | Remove?
        std::vector<T> storage{}; // Global
        std::vector<T> buffer{}; // Temp
        if(_inp[marcher].find(".data")) {
            while(_inp[marcher].find(".cmd") == std::string::npos) {
                if(INJECT_INSTRUCTIONS::typeTable[containsType(_inp[marcher])] != -1) {
                    int j{};
                    bool stateFlags[2] = {0,0};
                    std::string varName;
                    T value;
                    while(j < _inp[marcher].length()) {
                        if(_inp[marcher].at(j) != ' ' && !stateFlags[0]) {
                            stateFlags[0] = true;
                            varName += _inp[marcher].at(j);
                        }
                        else if(_inp[marcher].at(j) != ' ' && stateFlags[0]) {
                            if(_inp[marcher]at(j) == ',') {
                                stateFlags[1] = true;
                                break;
                            }
                            varName += _inp[marcher].at(j);
                        }
                        j++;
                    }
                    if(stateFlags[1]) {
                        variables[varName] = STORE_VALUE(_inp[marcher], j);
                        std::cout << "STORED VAL ADDRESS: " << &variables[varName] << '\n';
                    }
                }
            }
        }
        while(marcher != _inp.size()) {
            if(_inp[marcher].find("STORE") != std::string::npos) {
                int k{};
                std::string valueName{};
                    // Call to hash table
                    // Refer to memory address
                        // Store
                while(k < _inp[marcher].length()) {
                    if(_inp[marcher].at(k) != ' ') {
                        valueName+=_inp[marcher].at(k);
                    }
                    k++;
                }
                if(valueName == "") {
                    if(flags::DEBUG_STATE)
                        std::cout << "INJECT ERROR: Invalid storage name at " << marcher <, '\n'; 
                    continue;
                }
                storage.push_back(valueName);
                top++;
                /*
                for(unsigned int j = _inp[marcher].find("STORE"); j < _inp[marcher].length(); j++) {
                    if(_inp[marcher].at(j) != ' ') { // Allow for appropiate targetted storage
                        storage.push_back(buffer.back());
                        top++;
                    }
                    else {
                        // Search for appropiate variant j{};
                        while(j < _inp[marcher].length()) {
                            if(_inp[marcher].at(j) != ' ') {
                                
                            }
                            j++;
                        }
                        storage.push_back(_inp[marcher].at(j));
                    }
                    if(flags::DEBUG_STATE) {
                        std::cerr << "Address: : " << &_inp[marcher] << '|';  
                        std::cerr << "Size: : " << sizeof(_inp[marcher]);  
                    }
                    std::cout << storage[top] << '\n';
                }
            }
            */
            else if(_inp[marcher].find("DMP!") != std::string::npos) {
                int j{}, dAmt{};
                while(j < _inp[marcher].length()) {
                    if(isdigit(_inp[marcher].at(j)))
                        dAmt = atoi(_inp[marcher].at(j));
                    j++;
                }
                if(flags::DEBUG_STATE)
                    std::cout << "DUMPED!\n";
                for(int i = 0; i < dAmt; i++) {
                    storage[top] == NULL; // Fix!
                    top--;
                    if(flags::DEBUG_STATE) {
                        std::cout << "Address: : " << &_inp[marcher] << '|';  
                        std::cout << "Size: : " << sizeof(_inp[marcher]);  
                    }
                }
            }
            else if(_inp[marcher].find("CLR:") != std::string::npos) {
                if(_inp[marcher].find("b") != std::string::npos)
                    buffer.clear();
                if(_inp[marcher].find("s") != std::string::npos)
                    storage.clear();
            }
            else if(_inp[marcher].find("HAS:") != std::string::npos) {
                SearchStorage("");
            }
            else if(_inp[marcher].find("ADD") != std::string::npos) {
                std::string fVal="", sVal="";
                int j{};
                bool fValFound = false;
                while(j < _inp[marcher].length()) {
                    if(isdigit(_inp[marcher].at(j))) {
                        fVal += _inp[marcher].at(j);
                        if(fValFound)
                            sVal += _inp[marcher].at(j);
                    }
                    else if(_inp[marcher].at(j) == ',') {
                        if(fVal != "")
                            fValFound = true;
                        else {
                            if(flags::DEBUG_STATE) {
                                std::cerr << "ADD: x, y |||| 'x' was invalid\n\t";
                                std::cerr << "INJECT: Operator 'ADD' failed to find appropiate values!\n";
                            }
                            break; 
                        }
                    }
                    j++;
                }
                if(sVal == "") {
                    if(flags::DEBUG_STATE) {
                        std::cerr << "ADD: x, y |||| 'y' was invalid\n\t";
                        std::cerr << "INJECT: Operator 'ADD' failed to find appropiate values!\n";
                    }
                    break;
                }
                std::cout << fVal << ' ' << sVal << '\n';
                buffer.push_back(atoi(fVal.c_str()) + atoi(sVal.c_str()));
            }
            else if(_inp[marcher].find("SUB") != std::string::npos) {
                std::string fVal="", sVal="";
                int j{};
                bool fValFound = false;
                while(j < _inp[marcher].length()) {
                    j++;
                }
                buffer.push_back(atoi(fVal.c_str())  - atoi(sVal.c_str()));
            }
            else if(_inp[marcher].find("MULT") != std::string::npos) {
                std::string fVal="", sVal="";
                int j{};
                bool fValFound = false;
                buffer.push_back(atoi(fVal.c_str())  * atoi(sVal.c_str()));
            }
            else if(_inp[marcher].find("DIV") != std::string::npos) {
                std::string fVal="", sVal="";
                int j{};
                bool fValFound = false;
                buffer.push_back(atoi(fVal.c_str())  / atoi(sVal.c_str()));
            }
            else if(_inp[marcher].find("PRT")) {
                std::cout << storage[top];
            }
            marcher++;
        }
    }

    /*
    INJECT<int>(
        {
            ".data",
                "text ~str, hello world!",
                "x ~int, 5",
                "y ~float, 4.6",

            ".cmd",
                "PRT {Example text}",
                "PRT text",

                "ADD: x, y",
                "STORE",
                "PRT x { + } y { = }",
                "PRT",

                "FOR: 0, TOP, INC",
                    "PRT",
                "DMP!",

                "MULT: 12, 5",
                "STORE",
                "PRT",

                "RUN!",
                "TERMINATE"
        }
    );
    */
}

#endif