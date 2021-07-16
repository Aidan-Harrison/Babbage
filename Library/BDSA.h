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
        map(int key, int value) :m_Key(key), m_Value(value) {}
    };

        // Singly-Linked List
    template<typename T>
    struct SLinkedList {

        SLinkedList() {}
        struct Node {
            T data;
            Node* next;
            Node() :data(0), next(nullptr) {}
            Node(int x) :data(x), next(nullptr) {}
        };
        void PrintList(Node *n) {
            while(n != nullptr) {
                std::cout << n->data << ' ';
                n = n->next;
            }
        }
        Node* addNode(Node* prevNode, T data) {
            Node *newNode = new Node(data);
            newNode->next = prevNode->next;
            prevNode->next = newNode;
            return newNode;
        }
        inline void deleteNode(Node *n) { 
            n->next = n->next->next; 
        }   
        void delList();

        ~SLinkedList() {}
    };

        // Doubly-Linked List
    template<typename T>
    struct DLinkedList {
        struct dNode {
            T data;
            dNode* prev;
            dNode* next;
            dNode() :data(0), prev(nullptr), next(nullptr) {}
            dNode(short x) :data(x), prev(nullptr), next(nullptr) {}
        };
        void PrintList(dNode *n) {
            while(n != nullptr) {
                std::cout << n->data << ' ';
                n = n->next;
            }
        }
        dNode* addNode(dNode *prevNode, T data) {
            dNode *newNode = new dNode(data);
            newNode->next = prevNode->next;
            newNode->prev = prevNode;
            prevNode->next = newNode;
            return newNode;
        }
        void delNode(dNode *n) {
            n->prev = n->next;
        }
        void delList(dNode *n) {
            if(n != nullptr) {
                delete n->prev;
                delete n->data;
                n = n->next;
            }
            deleteDList(n);
        }
    };

    template<typename T>
    struct bStack {
        std::vector<T> items{};
        int top = -1;
        bStack() {}

        bool IsFull() {
            if(top == items.size()-1)
                return true;
            else
                return false;
        }

        bool IsEmpty() {
            if(top == -1)
                return true;
            else
                return false;
        }

        void Push(T data) {
            if(IsFull())
                std::cerr << "Babbage Error: Stack is full!\n";
            else
                items[top++] = data;
        }
        void Pop() {
            if(IsEmpty())
                std::cerr << "Babbage Error: Stack is empty!\n";
            else {
                items[top] = 0;
                top--;
            }
        }
        inline T Peek() {
            return items[top];
        }

        ~bStack() {}
    };

    template<typename T>
    class bQueue {
        private:
        public:
            std::vector<T> items{};
            int rear = -1;
            int front = 0;
            int MAXSIZE = 0; // Used for re-sizing

            bQueue(const int size) 
            {
                SetMax(size);
            }

            bool IsFull() {
                if(rear == MAXSIZE)
                    return true;
                return 
                    false;
            }
            bool IsEmpty();

            void Enqueue(T data) {
                if(IsFull())
                    std::cerr << "Babbage Error: Queue is full!\n";
                else 
                    items[rear++] = data;
            }
            void Dequeue() {
                if(IsEmpty)
                    std::cerr << "Babbage Error: Queue is empty!\n";
                else {
                    items[rear] = 0;
                    rear--;
                }
            }

            inline void SetMax(int size) {
                MAXSIZE = size;
            }

            ~bQueue() {}
    };

        // Graph & Trees
    struct Graph { // Re-do partially!
        int vertexCount = 0;
        std::vector<std::vector<int>> adjMatrix{};
        bool *isVisited;

        Graph(const int vertices) 
        {
            isVisited = new bool[vertices];
        }
        struct Vertex { 
            char m_Key;
            Vertex(const char key = 'A') :m_Key(key) {}
            void FindVertex(char input);
            inline void DeleteVertex(Vertex &v) { delete &v; } // Check!

            ~Vertex() {}
        };

        Vertex* AddVertex(char input) {
            Vertex *newVertex =  new Vertex(input);
            return newVertex;
        }

        void AddEdge(int src, int dest) {
            adjMatrix[src][dest] = 1;
            adjMatrix[dest][src] = 1;
        }
        
        void PrintGraph() {
            for(unsigned int i = 0; i < vertexCount; i++) {
		        for(unsigned int j = 0; j < vertexCount; j++) {
			        std::cout << adjMatrix[i][j] << ", ";
		        }
		        putchar('\n');
	        }
        }
        
        ~Graph() {}
    };

    struct treeNode {
        int key_Value;
        treeNode *left;
        treeNode *right;
        treeNode(int value) :key_Value(value) {}
    };

    class bTree {
    private:
        treeNode* root;
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
                    leaf->left = new treeNode(key);
                    leaf->left->key_Value = key;
                    leaf->left->left = nullptr;
                    leaf->left->right = nullptr;
                }
            }
            else if(key >= leaf->key_Value) {
                if(leaf->right != nullptr)
                    insert(key, leaf->right);
                else {
                    leaf->right = new treeNode(key);
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
                else 
                    return search(key, leaf->right);
            }
            else 
                return nullptr; // Return nothing if leaf is equal to nothing
        }
    public:
        bTree() {};
        // user functions
        void bTree::insert(int key) {
            if(root != nullptr)
                insert(key, root);
            else {
                root = new treeNode(key);
                root->key_Value = key;
                root->left = nullptr;
                root->right = nullptr;
            }
        }
        treeNode* bTreeSearch(int key) { return search(key, root); }
        void destroyTree() { return destroyTree(root); }

        ~bTree() { destroyTree(); }
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
                std::cerr << "Babbage:-\nNOT PALINDROME" << std::endl;
                return false;
            }
            else { p1++; p2--; } // Move pointers regardless
        }
        return true;
    }
    
    bool anag(std::string &s, std::string &t) {
        int n = s.length(), m = t.length();
        if(n != m) {
            std::cerr << "Babbage Error:-\nINVALID STRING LENGTHS OF: " << s.length() << " AND " << t.length() << " FOR |ANAGRAM|"
                      << "Both must be equal in length" << std::endl; 
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

    std::string Reverse(std::string &str) {
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
    std::string revStr(std::string &str) {
        if(str.length() <= 1) {
            std::cerr << "Babbage Error:-\nINVALID STRING LENGTH OF: " << str.length() << " FOR |REVERSE|"
                      << "Must be greater than '1'" << std::endl;
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
                      << "Must be int, float or double" << std::endl;
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
            std::cerr << "Babbage Error:-\nINVALID ARRAY (VECTOR) SIZE OF: " << arr.size() << " FOR |BUBBLE SORT|"
                      << "Must be greater than '1'" << std::endl;
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
            std::cerr << "Babbage Error:-\nINVALID ARRAY SIZE OF: " << size << " FOR |BUBBLE SORT|"
                      << "Must be greater than '1'" << std::endl;
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
                      << "Must be greater than '1'" << std::endl;
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
            std::cerr << "Babbage Error:-\nINVALID INPUT OF: " << "Left index: " << leftIndex << " OR " << "Right index: " << rightIndex << " FOR |QUICK SORT|" << std::endl; // Add better error handling
        return nums;
    }

    // Searching
    template<typename T>
    T bBinarySearch(std::vector<T> &arr, T target) {
        if(arr.size() == 0)
            return "BABBAGE: Your container is empty"; // Nothing to search
        int left = 0;
        int right = arr.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == target) return arr[mid];
            else if(arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return "BABBAGE: Binary search could not find value"; // Nothing found
    }
}

#endif