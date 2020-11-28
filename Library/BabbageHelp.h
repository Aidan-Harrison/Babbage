// Help | Allow use to select sections (Interactive menu essentially)
#include <iostream>

void Commands() {
    std::cout << "List of commands:\n";
    std::cout << "print() // Prints input";
    std::cout << "nl() // Creates new line";
    std::cout << "line() // Prints a line of '-' based on input size (amount)";
    std::cout << "box() // Prints a box based on input size (width, height)";
}

void Help() {
    int userInput{0};
    std::cout << "Babbage Library Help\n";
    std::cout << "1) General\n";
    std::cout << "2) Commands\n";
    std::cout << "Enter: "; std::cin >> userInput;
    switch (userInput)
    {
    case 1:
        std::cout << "Babbage is a general purpose, typeless library to be used for learning purposes\n";
        break;
    case 2:
        return Commands();
    }
}