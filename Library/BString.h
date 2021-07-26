#ifndef BString_h
#define BString_h

#include <iostream>
#include <string>

namespace bstring {
    inline const char* convToCStr(std::string &message) { return message.c_str(); }
    std::string convToCPlusStr(const char* message) { 
        std::string newMessage = message;
        return newMessage;
    }
    std::string capStr(std::string &message) {
        for(unsigned int i = 0; i < message.length(); i++)
            std::toupper(message[i]);
        return message;
    }
    std::string lowStr(std::string &message) {
        for(unsigned int i = 0; i < message.length(); i++)
            std::tolower(message[i]);
        return message;
    }
}

#endif