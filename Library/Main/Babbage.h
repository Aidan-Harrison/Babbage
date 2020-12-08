#pragma once

// Defintions
// Move to appropiate files?
#define PI 3.14159
#define Euler 2.71828
#define Radian 57.2958 // Pointless ???

// Type definitions


// Constants and variables
int userInput = 0; // Use for switch statemnts mostly
std::string stringInput = "";

// System
#define WAIT std::cin.get()
#define CLEAR system("cls")

// Function Prototypes
// REFER TO UE4 FOR BETTER UNDERSTANDING OF IMPLEMENTATION
// CANNOT HAVE TEMPLATES IN THIS FILE. SPECIFIED ONLY
class General {
private:

public:
    int Asize(int array[]);
};

// Complex
class Complex {
private:

public:
    Complex() { // Construct
        std::cout << "Called Complex"; // Can do heap assignments here
    }

    // Create matrix
    std::vector<std::vector<int>> cMatrix(int rows, int colums, int data);
    std::vector<std::vector<int>> dMatrix(std::vector<std::vector<int>>);

    ~Complex() { // Destruct
        std::cout << "Destroyed Complex";
        // Call deletions of heap assignments here
    }
};