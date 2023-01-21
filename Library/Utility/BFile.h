#ifndef BFile_h
#define BFile_h

// Add c file handling

#include <fstream>
#include <string>

namespace bFile {
    struct file {
        std::string path;
    };

    bool open(file & f, const std::string & path, bool debug = false) {
        if(path == " ") {
            if(debug)
                std::cerr << "BABBAGE Error: | BFile | Failed to open path: " << path << "/n/t Suggestion: Add valid file path\n";
            return false;
        }
        fopen(path);
        f.path = path;
        return true;
    }

    bool close(file & f) {
        fclose(f.path);
    }

    int getLineCount(file & f) {
        open(f.path);
    }
}

#endif