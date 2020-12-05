// Help | Allow use to select sections (Interactive menu essentially)
// Questionable usage
// Just convert to comments?
#include <iostream>

void PrintCommands() {
    std::cout << "List of commands: Printing\n";
    std::cout << "print() // Prints input";
    std::cout << "nl() // Creates new line";
    std::cout << "line() // Prints a line of '-' based on input size (amount)";
    std::cout << "box() // Prints a box based on input size (width, height)";
    std::cout << "pArray() // Prints an array (Vector)";
    std::cout << "pArray2D() // Prints a 2D array (Vector)";
}

void MathCommands() {
    std::cout << "List of commands: Maths\n";
}

void Help() {
    int userInput{0};
    std::cout << "Babbage Library Help\n";
    std::cout << "1) General\n";
    std::cout << "2) Printing\n";
    std::cout << "3) Maths\n";
    std::cout << "Enter: "; std::cin >> userInput;
    switch (userInput)
    {
    case 1:
        std::cout << "Babbage is a general purpose, typeless library\n";
        break;
    case 2:
        return PrintCommands();
    case 3:
        return MathCommands();
    }
}