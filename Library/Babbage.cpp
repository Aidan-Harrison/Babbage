/* Custom C/C++ based library | Babbage
* Mostly Typeless | Using templates | Simplified C++ and useful functions | Common DSA implementations
* Pass by reference for most part to improve performance and memory usage | Careful!
* Implement variable paramater amount for functions
* Find way to remove the need for '()' for certain functions. Low level C?
* Use function prototypes and the header file far more in general
* Use the 'static' keyword for performance reasons (RESEARCH)
* Compile into a library file along with 'Babbage.h'
*/

// Avoid using other headers!! Replace their functions
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
// Header
#include "Babbage.h" // Definitions & namespaces
#include "BabbageHelp.h" // Help file

// General
namespace babbageGen {
    class General {
        int Asize(int array[]) {
            int size = sizeof(array) / sizeof(array[0]);
            return size;
        }
    };
};

// Geometry
namespace babbageGeo { // May or may not want to use namespaces like this??
template<class G> // int (including variations), float and double
class Geometry {
    private:
        G length;
        G width;
        G height;
    public:
        Geometry operator+ (Geometry geo) { // Overide + for geo calculations
            Geometry newVal;
            newVal.length = length + geo.length; // Last operand equal to right hand side operand
            newVal.width = width + geo.width;
            newVal.height = height + geo.height;
            return newVal;
        }

        G Gper(G a, G b) { // Allow for all shapes, not just squares
            return a + b * 2;
        }

        G Gvol(G a, G b, G c) {
            return a * b * c;
        }

        G GArea(G a, G b) {
            return a * b;
        }

        G GPythagLong(G a, G b) {
            G c;
            c = a * a + b * b;
            return sqrt(c); // Try custom 'sqrt' function for fun | Careful of the <algorithm> header. Can cause major issues
        }

        G PythagShort(G a, G b) {
            G c;
            c = a * a - b * b;
            return sqrt(c);
        }

        // Not sure about nesting these structs
        struct CircleTheorem {
            static double Circumfrence(double radius) { // Test how 'static' affects function
                return 2 * PI * radius;
            }

            double  CircleArea(double radius) {
                return PI * radius * radius;
            }

            // Continue
        };

        struct Trigonometry {
            G GSin(G opposite, G hypotenuse) {
                return opposite / hypotenuse;
            }

            G GCos(G hypotenuse, G adjacent) {
                return adjacent / hypotenuse;
            }

            G GTan(G opposite, G hypotenuse, G adjacent) {
                return opposite / adjacent;
            }
        };
    };
}

// Printing
namespace babbagePrint {
template<typename T>
struct Printing{
        T print(T a) { // Single
            std::cout << a; 
        }

        void nl() {
            std::cout << '\n'; 
        }

        void line(int amount) {
            std::cout << '-' + char(amount, '-') << '\n'; // If 'char' does not work. Use string. Char is less memory
        }

        void box(int height, int width) {
            for(int i = 0; i < height; i++)
                for(int j = 0; j < width; j++)
                    std::cout << '*';
            std::cout << '\n';
        }

        std::vector<T> pArray(std::vector<T>& arr) {
            for(auto i : arr)
                std::cout << arr[i] << ", ";
            return arr;
        }

        std::vector<std::vector<T>> pArray2D(std::vector<std::vector<T>>& arr) {
            int m = arr.size();
            int n = arr[0].size();
            for(int i = 0; i < m; i++)
                for(int j = 0; j < n; j++)
                    std::cout << arr[i][j];
            return arr;
        }
    };
}

// Basic Math Functions
namespace babbageMath {
template<class F>
class MathFunctions {
private:
    F x{0}; // Make use of these in functions?
    F y{0};
    F z{0};
public:
        bool operator== (MathFunctions compar) { // Overide comparrison operator
            if(x == compar.x && y == compar.y)
                return true;
            return false;
        }

        // Basic
        F Add(F a, F b) {
            return a + b;
        }
        F Subtract(F a, F b) {
            return a - b;
        }
        F Divide(F a, F b) {
            return a / b;
        }   
        F Multiply(F a, F b) {
            return a * b;
        }
        // Comparisons
        const F Max(F const& a, F const& b) { // Possibly delete reference
            return a < b ? b : a;
        }

        const F Min(F const& a, const& b) { // ??
            return a > b ? b : a;
        }

        bool Same(F a, F b) {
            if(a == b) return true;
            else return false;
        }

        // Conversions
        int toASC(F value) { // Char only?
            return (int)value; // Type-cast to int (ASCII)
        }

        // Both of these are probably the wrong formula. Everything else is correct
        double convRadToDeg(double radians) {
            return radians = 180/PI; 
        }

        double convDegToRad(double degrees) {
            return degrees PI/180;
        }
    };
}

// Data Structures and Algorithms (Add overloads for user simplicity)
namespace babbageDSA {
template<typename A>
struct DSA {
        bool findDup(std::vector<A>& array) {
            std::unordered_map<A,A> map;
            for(auto i : array)
                if(map.find() == map.end())
                    map[i]++; // Add elements
                else
                    return true;
            return false;
        }

        bool palin(std::string str) { // Only acccepts strings at the moment. Char[] may work
            int p1 = 0;
            int p2 = str.length() - 1;
            while(p1 < p2) {
                if(!isalnum(str[p1]))
                    p1++;
                else if(!isalnum(str[p2]))
                    p2--;
                else if(tolower(str[p1]) != tolower(str[p2]))
                    return false;
                else {
                    p2++;
                    p1--;
                }
            }
            return true;
        }

        bool anag(std::string s, std::string t) {
            int n1 = s.length();
            int n2 = t.length();
            if(n1 != n2) {
                std::cout << "Babbage Error:-\nINVALID STRING LENGTHS OF: " << s.length() << AND << t.length() << " FOR |ANAGRAM|";
                std::cout << "Both must be equal in length\n";
                return false;
            }
            std::map<char,int> mapS; // Two map method (Possibly change)
            std::map<char,int> mapT;
            for(auto i : s)
                mapS[s[i]]++; // Add elements of first string
            for(auto j : t)
                mapT[t[j]]++;
            if(mapS == mapT) return true;
            else return false;
        }

        std::string revStr(std::string str) {
            if(str.length() <= 1) {
                std::cout << "Babbage Error:-\nINVALID STRING LENGTH OF: " << str.length() << " FOR |REVERSE|";
                std::cout << "Must be greater than '1'\n";
                return str;
            }
            int start = str[0];
            int end = str.length()-1;
            while(start < end) {
                int temp = str[start];
                str[start] = str[end];
                str[end] = temp;
                start++;
                end--;
            }
            return str;
        }

        // CHECK THIS NOT WORKING AS INTENDED --------------------------------------------
        // Bubble Sort (Two-Pointer)
        void Swap(int* a, int* b) {
            int temp = *a;
            *a = *b;
            *b = temp;
        }

        std::vector<int> bubbleSort(std::vector<int>& arr) { // Avoid nested for loop
            int p1 = 1;
            if(arr.size() <= 1) {
                std::cout << "Babbage Error:-\nINVALID ARRAY SIZE OF: " << arr.size() << " FOR |SORT|";
                std::cout << "Must be greater than '1'\n";
                return arr;
            }
            else {
                for(int p2 = 0; p2 < arr.size(); p2++) {
                    if(arr[p2] > arr[p1]) {
                        Swap(&arr[p2], &arr[p1]);
                        p1++;
                    }
                    else { // Reset, should work??
                        p1 = 0;
                        p2 = 0;
                    }
                }
            }
            return arr;
        }

        // Stack ----------------------------------------------------------------------------------
        int stack[0], n = 0, top = -1;
        void stackCreate(int stackSize, int value) {
            stack[stackSize]; // Wrong
            n = stackSize;
            if(top >= n - 1) { 
                std::cout << "Stack Overflow!\n";
                return;
            }
            else {
                top++; // Increment and assign 'value' to each element
                stack[top] = value;
            }
        }

        void popStack() {
            if(top <= - 1) {
                std::cout << "Stack Underflow!\n";
                return;
            }
            else {
                top--;
            }
        }

        void printStack() {
            int sizeOfStack = sizeof(stack) / sizeof(stack[0]);
            if(top >= 0) {
                for(int i = 0; i < sizeOfStack; i++)
                    std::cout << stack[i] << " "; // No new line for users sake
            }
            else
                std::cout << "Stack is empty!\n";
        }
        // End of stack ---------------------------------------------------------------------------
    };
}

// Memory
namespace babbageMem {
template<typename M>
class Memory {
        M memPrint(M std::vector<M>& input) { // Print x amount of memory adresses in sequence, possibly have 2D version
            for(int i = 0; i < input; i++)
                std::cout << &input << '\n';
        }
    };
}

// List Creation
namespace babbageList {
template<typename L>
class SinglyLinkedList {
private:
    struct Node {
        L data; // Allow user to implement custom data of any type
        Node* next;
    };

    void Linsert(int key, node* node);
    void lsearch(int key, node* node);
    void lPrint(Node* node);
    void ldestroyList(Node* node);

    L dataInput;
public:
        SinglyLinkedList(); // Constructor
        ~SinglyLinkedList();

        // Possibly add print somewhere
        void linsert(int key);
        void lsearch(int key);
        void ldestroyList(Node* node);

        // Initialise
        Node* head = nullptr; // No idea why this doesn't work
        Node* tail = nullptr;

        // CONTINUE
        head->data = 0; // Start (Initialise)
        head->next = tail;

        tail->data = 0;
        tail->next = nullptr; // End

        SinglyLinkedList::~SinglyLinkedList() { // May not need to treat this like a binary tree. Although similair. Study more
            return ldestroyList(); // Add deletion
        }

        void Lcreate(L userInput) { // Allow for custom amount of nodes as well custom input per node. Leave head and tail for now
            dataInput = userInput;
            head->data = dataInput;
            tail->data = dataInput;
        }

        void Linsert(int key, node* node) { // Add functionallity, similair to tree implementation
            
        }

        void Lsearch(int key, node* node) {

        }

        void lprint(Node* node) {
            while(n != nullptr) {
                std::cout << node << ", ";
                node = node->next;
            }
        }

    };
}

// Binary Tree ------------------------------------------------------------------------------------------------------------------
struct node { // Has to be visible in entire scope for function definitions
    int keyValue;
    node* left;
    node* right;
};

class bTree {
    private:
        void destroyTree(node* leaf);
        void insert(int key, node* leaf);
        node* search(int key, node* leaf);

        node* root;
    public:
        bTree();
        ~bTree();

        void insert(int key);
        node* search(int key);
        void destroyTree();
};

bTree::~bTree() { // Call tree destruction on destructor
    destroyTree();  
}

// System functions
void bTree::destroyTree(node* leaf) { 
    if(leaf != nullptr) {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete leaf;
    }
}

void bTree::insert(int key, node* leaf) {
    if(key < leaf->keyValue) {
        if(leaf->left != nullptr)
            insert(key, leaf->left);
        else {
            leaf->left = new node;
            leaf->left->keyValue = key;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
        }
    }
    else if(key >= leaf->keyValue) {
        if(leaf->right != nullptr)
            insert(key, leaf->right);
        else {
            leaf->right = new node;
            leaf->right->keyValue = key;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
        }
    }
}   

node* bTree::search(int key, node* leaf) {
    if(leaf != nullptr) {
        if(key == leaf->keyValue)
            return leaf;
        if(key < leaf->keyValue)
            return search(key, leaf->left);
        else
            return search(key, leaf->right);
    }
    else return nullptr; // Return nothing if leaf is equal to nothing
}

// User side functions
void bTree::insert(int key) {
    if(root != nullptr)
        insert(key, root);
    else {
        root = new node;
        root->keyValue = key;
        root->left = nullptr;
        root->right = nullptr;
    }
}

node* bTree::search(int key) {
    return search(key, root);
}

void bTree::destroyTree() {
    return destroyTree(root);
}

// End of bTree ------------------------------------------------------------------------------------------------------------------

// Complex
namespace babbageC {
template<typename C>
class Complex {
    private:
    public:
        Complex() {
            std::cout << "Called Complex"; // Can do heap assignments here
        }

        std::vector<std::vector<C>> cMatrix(int rows, int colums, C data) { // Datatype is userinput
            std::vector<std::vector<C>> matrix(rows, std::vector<int>(colums)); // Initialisation (rows, colums)
            for(int i = 0; i < rows; i++)
                for(int j = 0; j < colums; j++)
                    matrix[i][j].push_back(data); // Will not work
            return matrix;
        }

        std::map<C,int> cMap(std::vector<int>& input) {
            std::map<C,int> map;
            for(int i = 0; i < input.size(); i++)
                map[input[i]]++;
            return map;
        }

        std::unordered_map<C,int> cUMap(std::vector<int>& input) {
            std::map<C,int> uMap;
            for(int i = 0; i < input.size(); i++)
                uMap[input[i]]++;
            return uMap;
        }

        ~Complex() {
            std::cout << "Destroyed Complex";
            // Call deletions of heap assignments here
        }
    };
}

// Babbage's Graphics library
namespace babbageG {
template<typename G>
class Graphics {
    private:
        // Built in movement enumeration
        enum direction {STOP = 0, LEFT, RIGHT, FORWARD, BACK};
        direction bDir;
    public:
        // Unicode implementation
        std::wstring symbol; // Used for representing unicode chars
        // Vector components
        int vec4[4], vec3[3], vec2[2], vec1[1]; // Should work?
    };
};