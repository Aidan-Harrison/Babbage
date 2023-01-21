#ifndef BInput_h
#define BInput_h

#include <stdio.h>
#include <map> // Replace with custom hash
#include <thread>

namespace BInput {
    struct keyboard {
        int bufferSize{}, size{};
        // Do custom vector

        inline bool full() const;
        inline bool empty() const;

        void input();
        void last() const; // Returns top
        void first() const; // Returns [0]

        void clear();
    };

    inline bool keyboard::full() const { return size == bufferSize; }
    inline bool keyboard::empty() const { return size == 0; }

    void keyboard::input() {
        if(full())
            return;
        size++;
    }

    inline void input(const char * msg, int * inp) {
        printf("%s",msg);
        scanf("%d",inp);
    }
    inline void input(const char * msg, float * inp) {
        printf("%s",msg);
        scanf("%f",inp);
    }
    inline void input(const char * msg, char * inp) {
        printf("%s",msg);
        scanf("%c",inp);
    }
    int input(const char * msg) {
        printf("%s",msg);
        int a;
        scanf("%d", a);
        return a;
    }

    // Re-write
    class Input {
    private:
        bool handling = false;
        int16_t bufferSize = 24; // Temp cyclic ring buffer
        size_t maxStoreSize = 256; // Bulk store
        std::map<std::string, std::vector<int8_t>> inputSet{};
        std::thread inpThread;

        void INPUT_THREAD_EXECUTE() {

        }
    public:
        const std::map<std::string, std::vector<int8_t>> fetch() const { return inputSet; }
        void clear() { inputSet.clear(); }

        void createInput(const std::string && str, const uint8_t keyCode) {
            // Recurse if invalid fetch state
            
        }

        const float getAxis(const std::string && f_inp, const std::string && s_inp) const {
            return 0.0;
        };

        bool is_action_pressed(const int8_t keyCode) const;

        void INPUT_START(const bool debug) { // Start on new thread
            handling = true;
            // Start thread on appropiate functions only
            if(debug) { // Clear screen quadrant
                
            }
            INPUT_THREAD_EXECUTE();
        }

        void INPUT_END() {
            handling = false;
            inpThread.join();
        }
    };
}



#endif