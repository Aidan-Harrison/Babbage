/* Custom C/C++ based library | Babbage
* Mostly Typeless | Using templates | Simplified C++ and useful functions | Common DSA implementations
* Pass by reference for most part to improve performance and memory usage | Careful!
* Implement variable paramater amount for functions
* Find way to remove the need for '()' for certain functions. Low level C?
* Use function prototypes and the header file far more in general
* Use the 'static' keyword for performance reasons (RESEARCH)
* Implement both vector and array versions of functions, with some exceptions
* Compile into a library file along with 'Babbage.h'
* Move to header, follow proper C++ standards.
* Maybe incorporate some x86 Assembly into this for true overriding | MAJOR ADDITION
*/

// Avoid using other headers!! Replace their functions | This where Assembly can come in truly handy
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <typeinfo> // Compare to datatype
// Header
#include "Babbage.h" // Definitions & namespace
// General
// Function prototype
int General::Asize(int array[]) {
    int size = sizeof(array) / sizeof(array[0]);
    return size;
};

// Printing
namespace babbagePrint {
template<typename T>
struct Printing{
        T print(T a) { // Single argument, allow for multiple
            std::cout << a; 
        }

        void nl() {
            std::cout << '\n'; 
        }

        void line(int amount) {
            std::cout << '-' + char(amount, '-') << '\n';
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

// Data Structures and Algorithms (Add overloads for user simplicity)
namespace babbageDSA {
template<typename A>
struct DSA {
        bool findDup(std::vector<A>& array) { // Research this method using unordered_maps | For speed purposes
            std::unordered_map<int,A> map; // Int = key
            for(auto i : array)
                if(map.find(map[i]) == map.end())
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
                else if(tolower(str[p1]) != tolower(str[p2])) {
                    std::cout << "Babbage:-\nNOT PALINDROME!";
                    return false;
                }
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
                std::cout << "Babbage Error:-\nINVALID STRING LENGTHS OF: " << s.length() << " AND " << t.length() << " FOR |ANAGRAM|";
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

        // Reverse String | Could be universal ??? | Do it recursively
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

        // Sorting
        // CHECK THIS NOT WORKING AS INTENDED --------------------------------------------
        // Bubble Sort
        void Swap(int* a, int* b) { // Make universal
            int temp = *a;
            *a = *b;
            *b = temp;
        }

        std::vector<int> bSortV(std::vector<int>& arr) { // Implement recursive version
            if(arr.size() <= 1) {
                std::cout << "Babbage Error:-\nINVALID ARRAY (VECTOR) SIZE OF: " << arr.size() << " FOR |BUBBLE SORT|";
                std::cout << "Must be greater than '1'\n";
                return arr;
            }
            else {
                for(int i = 0; i < arr.size(); i++) // Nested implementation
                    for(int j = 0; j < arr.size() - i - 1; j++)
                        if(arr[j] > arr[j + 1])
                            Swap(&arr[j], &arr[j + 1]);
            }
            return arr;
        }

        void bSortA(A arr[]) { // Find correct return type
            int size = sizeof(arr) / sizeof(arr[0]);
            if(size <= 1) {
                std::cout << "Babbage Error:-\nINVALID ARRAY SIZE OF: " << arr.size() << " FOR |BUBBLE SORT|";
                std::cout << "Must be greater than '1'\n";
            }
            else {
                for(int i = 0; i < size; i++)
                    for(int j = 0; j < size - i - 1; j++)
                        if(arr[j] > arr[j + 1])
                            Swap(&arr[j], &arr[j + 1]);
            }   
            return;
        }

        // Quick Sort (DO A LOT OF WORK AND STUDY ON THIS)
        int Partition(std::vector<A>& arr, int low, int high) {
            int pivot = arr[high];
            int i = arr[low];

            for(int j = low; j < high; j++) {
                if(arr[j] <= pivot)
                    Swap(&arr[i], &arr[j]);
            }
            Swap(&arr[i + 1], &arr[high]); // Move pivot to 1 in front of 'i'
            return (i + 1); // Return pivot
        }

        std::vector<A> qSortV(std::vector<A>& arr, int leftIndex, int rightIndex) { // Allows user input
            if(leftIndex < rightIndex) {
                int pivot = Partition(arr, leftIndex, rightIndex);
                qSortV(arr, leftIndex, pivot - 1);
                aSortV(arr, pivot + 1, rightIndex);
            }
            else {
                std::cout << "Babbage Error:-\nINVALID INPUT OF: " << "Left index: " << leftIndex << " OR " << "Right index: " << rightIndex << " FOR |QUICK SORT|"; // Add better error handling
            }
            return arr;
        }

        // Stack ----------------------------------------------------------------------------------
        // Custom, not using <stack> header
        int stack[0], n = 0, top = -1;
        void stackCreate(int stackSize, int value) {
            stack[stackSize]; // Wrong
            n = stackSize;
            if(top >= n - 1) { 
                std::cout << "Babbage Error:-\nSTACK OVERFLOW!";
                return;
            }
            else {
                top++; // Increment and assign 'value' to each element
                stack[top] = value;
            }
        }

        void popStack() {
            if(top <= - 1) {
                std::cout << "Babbage Error:-\nSTACK UNDERFLOW!";
                return;
            }
            else {
                top--;
            }
        }

        void pushStack(int value) { // Check??
            int sizeOfStack = sizeof(stack) / sizeof(stack[0]);
            stack[sizeOfStack] = value; // ??
        }

        void printStack() {
            int sizeOfStack = sizeof(stack) / sizeof(stack[0]);
            if(top >= 0) {
                for(int i = 0; i < sizeOfStack; i++)
                    std::cout << stack[i] << " "; // No new line for users sake
            }
            else
                std::cout << "Babbage:-\nSTACK IS EMPTY!";
        }
        // End of stack ---------------------------------------------------------------------------
    };
}

// Memory
namespace babbageMem {
template<typename M>
class Memory {
        void memPrint(std::vector<M>& input) { // Print x amount of memory adresses in sequence, possibly have 2D version
            for(int i = 0; i < input; i++)
                std::cout << &input[i] << '\n';
        }

        void memPrint2D(std::vector<std::vector<int>>& input) {
            for(int i = 0; i < input; i++)
                for(int j = 0; j < input; j++)
                    std::cout << &input[i][j];
        }
    };
}

// List Creation
template<typename L>
class SinglyLinkedList {
private:
    struct Node {
        L data; // Allow user to implement custom data of any type
        Node* next;
    };

    void linsert(int key, Node* node);
    void lsearch(int key, Node* node);
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
    head = new Node();
    tail = new Node();

    head->data = 0; // Start (Initialise)
    head->next = tail;

    tail->data = 0;
    tail->next = nullptr; // End

    ~SinglyLinkedList() { // May not need to treat this like a binary tree. Although similair. Study more
        return ldestroyList(); // Add deletion
    }

    void lcreate(L userInput) { // Allow for custom amount of nodes as well custom input per node. Leave head and tail for now
        dataInput = userInput;
        head->data = dataInput;
        tail->data = dataInput;
    }

    void linsert(int key, Node* node) { // Add functionallity, similair to tree implementation
        return;
    }

    void lsearch(int key, Node* node) {
        return;
    }

    void lprint(Node* node) {
        while(node != nullptr) {
            std::cout << node << ", ";
            node = node->next;
        }
    }
};

// Binary Tree ------------------------------------------------------------------------------------------------------------------
// Allow for user input, add template
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

// Complex | Probably going to get rid of this
/*
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

        // These are both pointless
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
*/