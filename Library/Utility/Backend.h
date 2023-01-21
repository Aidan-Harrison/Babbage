#ifndef Backend_h
#define Backend_h

// Contains globals

enum MATH_OBJ_TYPES{POINT_I, POINT_F, LINE, TRIANGLE, SHAPE2D, TRANSFORM2D, SHAPE3D, TRANSFORM3D, CIRCLE};
enum DSA_OBJ_TYPES{};

#include "BDSA.h" // ?

// INJECT Assembly
    // Repalce with custom string
namespace INJECT_INSTRUCTIONS {
    bool typeTable[3];
    uint8_t valCode{};
    bst::bHash<std::string, uint8_t> injInstructions;
    bst::bHash<std::string, bool> injTypes;
}

// Move to sep file to avoid multi include
namespace flags {
    bool DEBUG_STATE;
}

// Custom stack frame
struct stackF {
    // Use babbage array
    // Need dynamic tuple!
    int8_t top{};
    inline const bool full();
    inline const bool empty();
};

void _DEBUG_START_FN() {
    // Check stack frame
    flags::DEBUG_STATE = true;
}

void _DEBUG_END_FN() {
    // Stop checking stack frame
    flags::DEBUG_STATE = false;
}

void (*_INIT_BABBAGE)();
void (*_DEBUG_START)();
void (*_DEBUG_END)();

void INIT_BABBAGE() {
    stackF sF;
    _DEBUG_START = &_DEBUG_START_FN;
    _DEBUG_END = &_DEBUG_END_FN;
    // INJECT
    INJECT_INSTRUCTIONS::injInstructions["STORE"] = 0;
}

#endif