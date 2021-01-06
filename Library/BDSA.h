#ifndef BabbageDSA_h
#define BabbageDSA_h

#include <iostream>
#include <vector> // Replace with C style arrays
#include <algorithm>
#include <unordered_map>
#include <map>

namespace bDataStruct {
        // Hash Table (Map)
    template<typename M>
    struct map {
        M m_Key;
        M m_Value;
        map() = default;
        map(short key)
            :m_Key(key) 
        {
        }
        ~map() = default;
    };

        // Singly-Linked List
    template<typename T>
    struct SLinkedList {
        struct Node {
            T data;
            Node* next;
            Node(int x)
                :data(x) 
            {
            }
        };
        SLinkedList() = default;
        ~SLinkedList() = default;
        Node addNode(T data, Node *nextNode) {
            Node node;
            node->data = data;
            node->next = nextNode; // Check! Possibly incorrect
        }
        inline void deleteNode(Node *node) { delete node; } // Need to take into account previous node and change next
    };

        // Doubly-Linked List
    template<typename T>
    struct DLinkedList {
        struct dNode {
            T data;
            dNode* prev;
            dNode* next;
            dNode(short x) // Defaults to number 
                :data(x) 
            {
            }
        };
        DLinkedList() = default;
        ~DLinkedList() = default;
        void addNode(dNode *prevNode, T data, dNode *nextNode) {
            dNode node;
            node->data = data;
            node->prev = prevNode;
            node->next = nextNode;
        }
        inline void deleteNode(dNode *node) { delete node; }
    };

    template<typename T>
    struct bStack { // Try to avoid using vector | Check!
        // C array stack
        short m_StackSize;
        T m_Stack[m_StackSize];
        // Vector stack
        std::vector<T> m_VStack{}; // Template?
        bStack() = default;
        ~bStack() = default;
        bStack(short stackData = 1)
            :m_Stack[m_stackSize](stackData) 
        {
        }
            // Functions
        T* stackCreate(int stackSize, T value) {
            T stack[stackSize];
            return stack;
        }
        void PopStack(T stack[]) { // Delete last value
            int size = sizeof(stack) / sizeof(stack[0]); // Does not work
        }
        void PushStack(T stack[]) {
        }
        void printStack(T stack[], int size) {
            for(int i = 0; i < size; i++)
                std::cout << stack[i] << ", ";
        }
        void printStack(T stack[]) { // Non-size argument overload
            int size = sizeof(stack) / sizeof(stack[0]); // Does not work
            for(int i = 0; i < size; i++)
                std::cout << stack[i] << ", ";
        }
            // Deletion
        void bStack::deleteStack(T stack[]) {
            for(int i = 0; i < stack.size(); i++) {
                stack.erase(stack.begin() + i);
                i--;
            }
        }

        void bStack::deleteStack(std::vector<T> stack) {
            for(int i = 0; i < stack.size(); i++) {
                stack.erase(stack.begin() + i);
                i--;
            }
        }
        inline void bStack::deleteStack(bStack *stack) { delete stack; }
    };

        // Graph & Trees
    struct Graph {
        int data;
        Graph() = default;
        ~Graph() = default;
    };

    struct treeNode {
        int key_Value;
        treeNode* left;
        treeNode* right;
        // Check need!
        treeNode() = default;
        treeNode(int value)
            :key_Value(value) 
        {    
        }
    };

    class bTree {
    private:
        // System level functions
        void destroyTree(treeNode* leaf);
        void insert(int key, treeNode* leaf);
        treeNode* search(int key, treeNode* leaf);

        treeNode* root;
    public:
        bTree();
        ~bTree();

        // user functions
        void insert(int key);
        treeNode* search(int key);
        void destroyTree();
    };

    // Call tree destruction on destructor
    bTree::~bTree() { destroyTree(); }

    // System functions
    void bTree::destroyTree(treeNode* leaf) { 
        if(leaf != nullptr) { // If leaf exists, remove left and right children, the delete current node
            destroyTree(leaf->left);
            destroyTree(leaf->right);
            delete leaf;
        }
    }

    void bTree::insert(int key, treeNode* leaf) {
        if(key < leaf->key_Value) {
            if(leaf->left != nullptr) // If lead does exist, add
                insert(key, leaf->left);
            else { // Else add leaf
                leaf->left = new treeNode;
                leaf->left->key_Value = key;
                leaf->left->left = nullptr;
                leaf->left->right = nullptr;
            }
        }
        else if(key >= leaf->key_Value) {
            if(leaf->right != nullptr)
                insert(key, leaf->right);
            else {
                leaf->right = new treeNode;
                leaf->right->key_Value = key;
                leaf->right->left = nullptr;
                leaf->right->right = nullptr;
            }
        }
    }   

    treeNode* bTree::search(int key, treeNode* leaf) {
        if(leaf != nullptr) {
            if(key == leaf->key_Value)
                return leaf;
            if(key < leaf->key_Value)
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
            root = new treeNode;
            root->key_Value = key;
            root->left = nullptr;
            root->right = nullptr;
        }
    }

    treeNode* bTree::search(int key) { return search(key, root); }
    void bTree::destroyTree() { return destroyTree(root); }
}

// Algorithms
namespace bAlgorithms {
    bool findDup(std::vector<int>& arr) { // Check!
        std::unordered_map<int,int> uMap;
        for(auto i : arr) {
            if(uMap.find(uMap[i]) == uMap.end())
                uMap[arr[i]]++;
            else
                return true;
            return false;
        }
    }

    bool palin(std::string str) {
        int p1 = 0, p2 = str.length()-1;
        while(p1 < p2) {
            if(!isalnum(str[p1])) p1++; // Ignore symbols
            else if(!isalnum(str[p2])) p2--;
            else if(tolower(str[p1]) != tolower(str[p2])) { // Ignore case
                std::cerr << "Babbage:-\nNOT PALINDROME\n";
                return false;
            }
            else { p1++; p2--; } // Move pointers regardless
        }
        return true;
    }
    
    bool anag(std::string s, std::string t) { // Also do number version
        int n = s.length(), m = t.length();
        if(n != m) {
            std::cerr << "Babbage Error:-\nINVALID STRING LENGTHS OF: " << s.length() << " AND " << t.length() << " FOR |ANAGRAM|";
            std::cerr << "Both must be equal in length\n"; 
            return false;
        }
        std::map<char,int> mapS;
        std::map<char,int> mapT;
        for(int i : s) mapS[s[i]]++; // Add to map
        for(int i : t) mapT[t[i]]++;
        if(mapS == mapT) return true;
        return false;
    }
    
    // Template?
    std::vector<int> Reverse(std::vector<int>& arr) {
        short start = 0, end = arr.size()-1;
        while(start < end) {
            int temp = arr[start];
            arr[start++] = arr[end];
            arr[end--] = temp;
        }
        return arr;
    }

        // Overload for custom start and end
    std::vector<int> Reverse(std::vector<int>& arr, short start, short end) {
        while(start < end) {
            int temp = arr[start];
            arr[start++] = arr[end];
            arr[end--] = temp;
        }
        return arr;
    }

    std::string Reverse(std::string str) {
        short start = 0, end = str.length()-1;
        while(start < end) {
            int temp = str[start];
            str[start++] = str[end];
            str[end--] = temp;
        }
        return str;
    }

    std::vector<int> rotateArray(std::vector<int>& arr, int k) {
        k = k % arr.size();
        Reverse(arr); // Reverse all
        Reverse(arr); // Reverse rotated elements
        Reverse(arr); // Reverse remaining
        return arr;
    }
    
        // Reverse String
    std::string revStr(std::string str) {
        if(str.length() <= 1) {
            std::cerr << "Babbage Error:-\nINVALID STRING LENGTH OF: " << str.length() << " FOR |REVERSE|";
            std::cerr << "Must be greater than '1'\n";
            return str;
        }
        Reverse(str);
        return str;
    }

    template<typename T>
    std::vector<int> getDigits(T number) {
        short digit;
        std::vector<int> result{};
        if(sizeof(number) != sizeof(int) || sizeof(number) != sizeof(float) || sizeof(number) != sizeof(double)) {
            std::cerr << "Babbage Error:-\nINVALID DATATYPE OF: " << typeid(number).name() << '-';
            std::cerr << "Must be int, float or double\n";
            return result;
        }
        else {
            while(number) { // Flag
                digit = number % 10; // Get right-most digit
                result.push_back(digit);
                digit = number /= 10; // Move to next digit
            }
        }
        Reverse(number); // Check!
        return result;
    }

    // Sorting
    void Swap(int* a, int* b) { // Pointer based | Use references in sorting algorithms
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    // Bubble Sort
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

    int* bSortA(int arr[], int size) { // Return by address | Overload version without size
        if(size <= 1) {
            std::cerr << "Babbage Error:-\nINVALID ARRAY SIZE OF: " << size << " FOR |BUBBLE SORT|";
            std::cerr << "Must be greater than '1'\n";
            return arr;
        }
        for(int i = 0; i < size; i++)
            for(int j = 0; j < i - 1; j++)
                if(arr[j] == arr[j + 1])
                    Swap(&arr[j], &arr[j + 1]);
        return arr;
    }
        // Quick Sort
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
}

#endif