#ifndef BabbageDSA_h
#define BabbageDSA_h

#include <iostream>
#include <vector> // Replace with C style arrays
#include <algorithm>
#include <unordered_map>
#include <map>

// Data Structure definitions
// Hash Table (Map)
template<typename M>
struct map {
    M key;
    M value;
};

namespace bdsa {
    // Implement generic
    // Pick map after understanding | Faster I believe

    // Pick one -------------------------------------------------------------
    bool findDup(std::vector<int>& arr) { // Change to map for speed
        if(arr.size() <= 1) return false; // Invalid
        std::sort(arr.begin(), arr.end()); // Use own sort function
        for(int i = 0; i < arr.size() - 1; i++)
            if(arr[i] == arr[i + 1]) return true;
        return false;
    }
    bool findDupMap(std::vector<int>& arr) {
        std::unordered_map<int,int> map;
        for(int i : arr) {
            if(map.find(i) == map.end())
                map[i]++; // Add to map
            else
                return true;
        }
        return false;
    }
    bool findDupMap2(std::vector<int>& arr) {
        std::unordered_map<int,int> uMap;
        for(auto i : arr) {
            if(uMap.find(uMap[i]) == uMap.end())
                uMap[arr[i]]++;
            else
                return true;
            return false;
        }
    }
    //----------------------------------------------------------------------
    bool palin(std::string str) {
        int p1 = 0; // Two pointer technique
        int p2 = str.length() -1;
        while(p1 < p2) {
            if(!isalnum(str[p1])) // Ignore symbols
                p1++;
            else if(!isalnum(str[p2]))
                p2--;
            else if(tolower(str[p1]) != tolower(str[p2])) { // Ignore case
                std::cerr << "Babbage:-\nNOT PALINDROME\n";
                return false;
            }
            else { // Move pointers regardless
                p1++;
                p2--;
            }
        }
        return true;
    }
    
    bool anag(std::string s, std::string t) { // Also do number version
        int n = s.length();
        int m =  t.length();
        if(n != m) {
            std::cerr << "Babbage Error:-\nINVALID STRING LENGTHS OF: " << s.length() << " AND " << t.length() << " FOR |ANAGRAM|";
            std::cerr << "Both must be equal in length\n"; 
            return false;
        }
        std::map<char,int> mapS;
        std::map<char,int> mapT;
        for(int i : s)
            mapS[s[i]]++; // Add to map
        for(int i : t)
            mapT[t[i]]++;
        if(mapS == mapT) return true;
        return false;
    }
    
    // Make universal?
    std::vector<int> Reverse(std::vector<int>& arr, int start, int end) { // Have strings as well
        while(start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
        return arr;
    }

    std::vector<int> rotateArray(std::vector<int>& arr, int k) {
        k = k % arr.size();
        Reverse(arr, 0, arr.size() - 1); // Reverse all
        Reverse(arr, 0, k - 1); // Reverse rotated elements
        Reverse(arr, k, arr.size() -1); // Reverse remaining
        return arr;
    }
    
    // Reverse String | Could be universal ??? | Do it recursively
    std::string revStr(std::string str) {
        // Reverse | Possibly replace with sorting algorithm
        if(str.length() <= 1) {
            std::cerr << "Babbage Error:-\nINVALID STRING LENGTH OF: " << str.length() << " FOR |REVERSE|";
            std::cerr << "Must be greater than '1'\n";
            return str;
        }
        int start = 0;
        int end = str.length() -1;
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
    void Swap(int* a, int*b) { // Pointer based | Use references in sorting algorithms
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    // Bubble Sort
    // Bubble Sort-
    std::vector<int> bSortV(std::vector<int>& arr) {
        if(arr.size() <= 1) {
            std::cerr << "Babbage Error:-\nINVALID ARRAY (VECTOR) SIZE OF: " << arr.size() << " FOR |BUBBLE SORT|";
            std::cerr << "Must be greater than '1'\n";
            return arr;
        }
        for(int i = 0; i < arr.size(); i++) // Still not entirely sure about this
            for(int j = 0; j < i - 1; j++)
                if(arr[j] == arr[j + 1])
                    Swap(&arr[j], &arr[j + 1]);
        return arr;
    }

    int* bSortA(int arr[]) { // Return by address
        int size = sizeof(arr) / sizeof(arr[0]); // Fix
        if(size <= 1) {
            std::cerr << "Babbage Error:-\nINVALID ARRAY SIZE OF: " << size << " FOR |BUBBLE SORT|";
            std::cerr << "Must be greater than '1'\n";
            return arr;
        }
        for(int i = 0; i < size; i++)
            for(int j = 0; j < i - 1; j++)
                if(arr[j] == arr[j + 1])
                    Swap(&arr[j], &arr[j + 1]);
        // Do return
        return arr;
    }
    // Quick Sort
    // Quick Sort-
    int Partition(std::vector<int>& nums, int low, int high) {
        if(nums.size() <= 1) { // Too small
            std::cerr << "Babbage Error:-\nINVALID ARRAY (VECTOR) SIZE OF: " << nums.size() << " FOR |QUICKSORT|";
            std::cerr << "Must be greater than '1'\n";
            return -1;
        }
        int pivot = nums[high];
        int i = nums[low];
        for(int j = low; j < high; j++)
            if(nums[j] <= pivot)
                Swap(&nums[i], &nums[j]);
        Swap(&nums[i + 1], &nums[high]);
        return (i + 1); // Return pivot
    }

    std::vector<int> qSortV(std::vector<int>& nums, int leftIndex, int rightIndex) {
        if(leftIndex < rightIndex) {
            int pivot = Partition(nums, leftIndex, rightIndex);
            qSortV(nums, leftIndex, pivot - 1);
            qSortV(nums, pivot + 1, rightIndex);
        }
        else
            std::cerr << "Babbage Error:-\nINVALID INPUT OF: " << "Left index: " << leftIndex << " OR " << "Right index: " << rightIndex << " FOR |QUICK SORT|"; // Add better error handling
        return nums;
    }

    // Stack ----------------------------------------------------------------------------------
    struct BabbageStack {
        // int stack[0], n = 0, top = -1; // FIX ERROR
        void stackCreate(int stackSize, int value);
        void popStack();
        void pushStack(int value);
        void printStack();
    };

// Review everything extensively
    struct Node {
        int data; // Allow user to implement custom data of any type
        Node* next;
        Node(int x) : data(x), next(nullptr) {} // Initialization list
    };

    void lcreate(int userInput) { // Allow for custom amount of nodes as well custom input per node. Leave head and tail for now
        return;
    }
    void linsert(int key, Node* node) { // Add functionallity, similair to tree implementation
        
        return;
    }
    Node* lsearch(int key, Node* node) {
        if(key == node->data)
            return node;
        else {
            std::cerr << "Babbage Error:-\nSpecified value does not exist in list";
            Node* empty; return empty; // Return null node
        }
    }
    void ldelete(Node* node) {
        // Review this?
        Node* del = node->next;
        node->data = node->next->data;
        node->next = node->next->next;
        delete del;
    }
    void lprint(Node* node) {
        while(node != nullptr) {
            std::cout << node << ", ";
            node = node->next;
        }
    }

    // Deconstructor instead??? | Or both??
    void ldestroyList(Node* node);

    struct Node {
        int data;
        Node* previous;
        Node* next;
    };

    // Binary Tree
    struct node { // Has to be visible in entire scope for function definitions
        int keyValue;
        node* left;
        node* right;
    };

    class bTree {
        private:
            // System level functions
            void destroyTree(node* leaf);
            void insert(int key, node* leaf);
            node* search(int key, node* leaf);

            node* root;
        public:
            bTree();
            ~bTree();

            // user functions
            void insert(int key);
            node* search(int key);
            void destroyTree();
    };

    bTree::~bTree() { // Call tree destruction on destructor
        destroyTree();  
    }

    // System functions
    void bTree::destroyTree(node* leaf) { 
        if(leaf != nullptr) { // If leaf exists, remove left and right children, the delete current node
            destroyTree(leaf->left);
            destroyTree(leaf->right);
            delete leaf;
        }
    }

    void bTree::insert(int key, node* leaf) {
        if(key < leaf->keyValue) {
            if(leaf->left != nullptr) // If lead does exist, add
                insert(key, leaf->left);
            else { // Else add leaf
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
}
#endif