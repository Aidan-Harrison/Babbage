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
        inline void deleteMap(map m) { delete &m; } // Check!
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
        inline Node getNode() const { return Node; }
        SLinkedList() = default;
        ~SLinkedList() = default;
        Node addNode(T data, Node *nextNode) {
            Node node;
            node->data = data;
            node->next = nextNode; // Check! Possibly incorrect
        }
        inline void deleteNode(Node *node) { delete node; } // Need to take into account previous node and change next
        inline void deleteList(SLinkedList s) { delete &s; }   
    };

        // Doubly-Linked List
    template<typename T>
    struct DLinkedList {
        struct dNode {
            T data;
            dNode* prev;
            dNode* next;
            dNode(short x)
                :data(x) 
            {
            }
        };
        DLinkedList() = default;
        ~DLinkedList() = default;
        inline dNode getNode() const { return dNode; }
        void addNode(dNode *prevNode, T data, dNode *nextNode) {
            dNode node;
            node->data = data;
            node->prev = prevNode;
            node->next = nextNode;
        }
        void deleteDList() { // Check!
            if(dNode != nullptr) { // Check if node exists
                delete dNode->next;
                delete dNode->data;
                delete dNode;
            }
            deleteDList();
        }
        inline void deleteNode(dNode *node) { delete node; }
    };

    template<typename T>
    struct bStack {
        std::vector<T> m_VStack{};
        bStack() = default;
        ~bStack() = default;
            // Functions
        bStack PushStack(bStack &s, T input) {
            s.m_VStack.push_back(input);
            return s;
        }
        void printStack(T stack[], int size) {
            for(int i = 0; i < size; i++)
                std::cout << stack[i] << ", ";
        }
        void printStack(bStack &s) {
            for(unsigned int i = 0; i < s.m_VStack.size(); i++)
                std::cout << s.m_VStack[i] << ", ";
        }
            // Deletion
        void deleteStack(T stack[]) {
            for(int i = 0; i < stack.size(); i++) {
                stack.erase(stack.begin() + i);
                i--;
            }
        }
        void deleteStack(std::vector<T> stack) {
            for(int i = 0; i < stack.size(); i++) {
                stack.erase(stack.begin() + i);
                i--;
            }
        }
        inline void deleteStack(bStack *stack) { delete stack; }
    };

        // Graph & Trees
    struct Graph { // Re-Do after done with binary tree
        Graph() = default;
        ~Graph() = default;
        struct Vertex { // Character based for now
            char m_Key;
            Vertex(char key = 'A')
                :m_Key(key) 
            {
            }
            ~Vertex() = default;
            Vertex AddVertex(char input) {
                Vertex newVertex;
                newVertex.m_Key = input;
                return newVertex;
            }
            void FindVertex(char input);
            inline void DeleteVertex(Vertex &v) { delete &v; } // Check!
        };
    };

    struct treeNode {
        int key_Value;
        treeNode* left;
        treeNode* right;
        treeNode() = default;
        treeNode(int value)
            :key_Value(value)
        {    
        }
        ~treeNode() = default;
    };

    class bTree {
    private:
        // System level functions
        void destroyTree(treeNode* leaf) { 
            if(leaf != nullptr) { // If leaf exists, remove left and right children, then delete current node
                destroyTree(leaf->left);
                destroyTree(leaf->right);
                delete leaf;
            }
        }

        void insert(int key, treeNode* leaf) {
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

        treeNode* search(int key, treeNode* leaf) {
            if(leaf != nullptr) {
                if(key == leaf->key_Value) return leaf;
                if(key < leaf->key_Value) return search(key, leaf->left);
                else return search(key, leaf->right);
            }
            else return nullptr; // Return nothing if leaf is equal to nothing
        }
        treeNode* root;
    public:
        bTree() = default;
        bTree::~bTree() { destroyTree(); }
        // user functions
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
        treeNode* bTreeSearch(int key) { return search(key, root); }
        void destroyTree() { return destroyTree(root); }
    };
}

namespace bAlgorithms {
    template<typename T>
    bool findDup(std::vector<T> &arr) {
        std::unordered_map<int,T> uMap;
        for(auto i : arr) {
            if(uMap.find(uMap[i]) == uMap.end())
                uMap[arr[i]]++;
            else
                return true;
            return false;
        }
    }

    bool palin(std::string &str) {
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
    
    bool anag(std::string &s, std::string &t) { // Also do number version
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
    
    template<typename T>
    std::vector<T> Reverse(std::vector<T>& arr) {
        short start = 0, end = arr.size()-1;
        while(start < end) {
            int temp = arr[start];
            arr[start++] = arr[end];
            arr[end--] = temp;
        }
        return arr;
    }

     template<typename T>   // Overload for custom start and end
    std::vector<T> Reverse(std::vector<T> &arr, short start, short end) {
        while(start < end) {
            int temp = arr[start];
            arr[start++] = arr[end];
            arr[end--] = temp;
        }
        return arr;
    }

    std::string Reverse(std::string str) { // Try 'sizeof()'
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
    template<typename T>
    std::vector<T> bSortV(std::vector<T> &arr) {
        if(arr.size() <= 1) {
            std::cerr << "Babbage Error:-\nINVALID ARRAY (VECTOR) SIZE OF: " << arr.size() << " FOR |BUBBLE SORT|";
            std::cerr << "Must be greater than '1'\n";
            return arr;
        }
        for(int i = 0; i < arr.size(); i++)
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
    template<typename T>
    int Partition(std::vector<T>& nums, int low, int high) {
        if(nums.size() <= 1) {
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

    template<typename T>
    std::vector<T> qSortV(std::vector<T>& nums, int leftIndex, int rightIndex) {
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