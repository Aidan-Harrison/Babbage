#ifndef BabbageDSA_h
#define BabbageDSA_h

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

namespace bDataStruct {
    template<typename T>
    struct bHash { // ?
        std::vector<std::pair<T,T>> table{};
        bHash() {}
        ~bHash() {}
    };

        // Singly-Linked List
    template<typename T>
    struct SLinkedList {
        SLinkedList() {}
        SLinkedList(SLinkedList<T> *other) 
        {
        }
        struct Node {
            T data;
            Node* next;
            Node() :data(0), next(nullptr) {}
            Node(T x) :data(x), next(nullptr) {}
            Node(T x, Node *n) :data(x), next(n) {}
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

        ~SLinkedList() {}
    };

        // Doubly-Linked List
    template<typename T>
    struct DLinkedList {
        DLinkedList() {}
        DLinkedList(DLinkedList<T> *other) 
        { 
        }

        struct dNode {
            T data;
            dNode* prev;
            dNode* next;
            dNode() :data(0), prev(nullptr), next(nullptr) {}
            dNode(T x) :data(x), prev(nullptr), next(nullptr) {}
            dNode(T x, dNode *p) :data(x), prev(p), next(nullptr) {}
            dNode(T x, dNode *p, dNode *n) :data(x), prev(p), next(n) {}
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
                if(n->prev != nullptr)
                    delete n->prev;
                delete n->data;
                n = n->next;
            }
        }

        ~DLinkedList() {}
    };

    template<typename T>
    struct bStack {
        std::vector<T> items{};
        int top = -1;

        bStack() {}
        bStack(bStack<T> *other)
        {
            while(GetSize() <= other->GetSize())
                Push(other->Pop());
        }

        inline bool IsFull() {
            if(top == items.size()-1)
                return true;
            return false;
        }

        inline bool IsEmpty() {
            if(top == -1)
                return true;
            return false;
        }

        void Push(T data) {
            if(IsFull())
                std::cerr << "Babbage Error: Stack is full!\n";
            else {
                top++;
                items[top] = data;
            }
        }
        T Pop() {
            if(IsEmpty())
                std::cerr << "Babbage Error: Stack is empty!\n";
            else {
                T item = items[top];
                items[top] = 0;
                top--;
                return item;
            }
        }
        inline int GetSize() { return top; }
        inline T Peek() { return items[top]; }

        inline void Print() const {
            for(auto i : items)
                std::cout << i << ", ";
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

            bQueue() {}
            bQueue(const int size) 
            {
                SetMax(size);
            }

            inline bool IsFull() {
                if(rear == MAXSIZE)
                    return true;
                return false;
            }

            bool IsEmpty() {
                if(rear == -1)
                    return true;
                return false;
            };

            void Enqueue(T data) {
                if(IsFull())
                    std::cerr << "Babbage Error: Queue is full!\n";
                else { 
                    rear++;
                    items[rear] = data;
                }
            }
            T Dequeue() {
                if(IsEmpty())
                    std::cerr << "Babbage Error: Queue is empty!\n";
                else {
                    T item = items[rear];
                    items[rear] = 0;
                    rear--;
                    return item;
                }
            }

            inline void SetMax(int size) {
                MAXSIZE = size;
            }

            inline void Print() const {
                for(auto i : items)
                    std::cout << i << ", ";
            }

            ~bQueue() {}
    };

        // Graph & Trees
    template<typename T>
    struct Graph { // Re-do partially! | Check templating!
        int vertexCount = 0;
        std::vector<std::vector<int>> adjMatrix{};
        bool *isVisited;

        Graph(const int vertices) 
            :vertexCount(vertices)
        {
            isVisited = new bool[vertices];
        }

        template<typename V>
        struct Vertex { // Check templating
            V m_Key;
            Vertex(const V key = 'A') :m_Key(key) {}

            void FindVertex(const V input);
            inline void DeleteVertex(Vertex &v) { delete &v; } // Check!

            ~Vertex() {}
        };

        Vertex<T>* AddVertex(T input) {
            Vertex<T> *newVertex =  new Vertex<T>(input);
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

    template<typename T>
    struct treeNode {
        T key_Value;
        treeNode *left;
        treeNode *right;
        treeNode(T value) :key_Value(value) {}
    };

    template<typename T>
    class BSTree {
    private:
        treeNode<T>* root;
        // System level functions
        void destroyTree(treeNode<T>* leaf) { 
            if(leaf != nullptr) { // If leaf exists, remove left and right children, then delete current node
                destroyTree(leaf->left);
                destroyTree(leaf->right);
                delete leaf;
            }
        }

        void insert(T key, treeNode<T>* leaf) {
            if(key < leaf->key_Value) {
                if(leaf->left != nullptr) // If lead does exist, add
                    insert(key, leaf->left);
                else { // Else add leaf
                    leaf->left = new treeNode<T>(key);
                    leaf->left->key_Value = key;
                    leaf->left->left = nullptr;
                    leaf->left->right = nullptr;
                }
            }
            else if(key >= leaf->key_Value) {
                if(leaf->right != nullptr)
                    insert(key, leaf->right);
                else {
                    leaf->right = new treeNode<T>(key);
                    leaf->right->key_Value = key;
                    leaf->right->left = nullptr;
                    leaf->right->right = nullptr;
                }
            }
        } 

        treeNode<T>* search(T key, treeNode<T>* leaf) {
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
        BSTree() {};
        // user functions
        void bTree<T>::insert(T key) {
            if(root != nullptr)
                insert(key, root);
            else {
                root = new treeNode(key);
                root->key_Value = key;
                root->left = nullptr;
                root->right = nullptr;
            }
        }
        treeNode<T>* bTreeSearch(T key) { return search(key, root); }
        void destroyTree() { return destroyTree(root); }

        ~BSTree() { destroyTree(); }
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
                std::cerr << "Babbage:-\n\tNOT PALINDROME\n";
                return false;
            }
            else { p1++; p2--; } // Move pointers regardless
        }
        return true;
    }
    
    bool anag(const std::string &s, const std::string &t) {
        if(s.length() != t.length()) {
            std::cerr << "Babbage Error:-\n\tINVALID STRING LENGTHS OF: " << s.length() << " AND " << t.length() << " FOR |ANAGRAM|"
                      << "Both must be equal in length\n"; 
            return false;
        }
        std::map<char,int> mapS;
        std::map<char,int> mapT;
        for(auto i : s) mapS[i]++;
        for(auto i : t) mapT[i]++;
        if(mapS == mapT) return true; // Check!
        return false;
    }
    
    template<typename T>
    std::vector<T> Reverse(std::vector<T>& arr) {
        int start = 0, end = arr.size()-1;
        while(start < end) {
            int temp = arr[start];
            arr[start++] = arr[end];
            arr[end--] = temp;
        }
        return arr;
    }

    template<typename T>   // Overload for custom start and end
    std::vector<T> Reverse(std::vector<T> &arr, int start, int end) {
        while(start < end) {
            int temp = arr[start];
            arr[start++] = arr[end];
            arr[end--] = temp;
        }
        return arr;
    }

    std::string Reverse(std::string &str) {
        if(str.length() == 0) {
            std::cerr << "Babbage Error: String is empty in 'Reverse(std::string &str)'\n";
            return str;
        }
        int start = 0, end = str.length()-1;
        while(start < end) {
            int temp = str[start];
            str[start++] = str[end];
            str[end--] = temp;
        }
        return str;
    }

    std::string Reverse(std::string &str, int start, int end) {
        while(start < end) {
            char temp = str[start];
            str[start++] = str[end];
            str[end--] = temp;
        }
        return str;
    }

    std::string Rotate(std::string &str, char direction, int amount) {
        if(direction == 'l') {
            for(unsigned int i = 0; i < amount; i++) {
                char temp = str[0];
                for(unsigned int j = 0; j < str.length(); j++) {
                    str[str.length()-1] = temp;
                }
            }
        }
        else if(direction == 'r') {

        }
        else {
            std::cerr << "Babbage Error: Incorrect direction specified in 'Rotate(std::string &str, char direction, int amount)' | Must be either 'L'/'l' or 'R'/'r'\n";
            return "";
        }
    }

    std::vector<int> rotateArray(std::vector<int>& arr, int k) {
        k = k % arr.size();
        Reverse(arr); // Reverse all
        Reverse(arr); // Reverse rotated elements
        Reverse(arr); // Reverse remaining
        return arr;
    }

    template<typename T>
    std::vector<int> getDigits(T number) {
        int digit;
        std::vector<int> result{};
        if(sizeof(number) != sizeof(int) || sizeof(number) != sizeof(float) || sizeof(number) != sizeof(double)) {
            std::cerr << "Babbage Error:-\nINVALID DATATYPE OF: " << typeid(number).name() << '-'
                      << "Must be int, float or double" << std::endl;
            return result;
        }
        else {
            while(number) {
                digit = number % 10; // Get right-most digit
                result.push_back(digit);
                digit = number /= 10; // Move to next digit
            }
        }
        Reverse(number); // Check!
        return result;
    }

    // Sorting
    template<typename T>
    void Swap(T* a, T* b) {
        T temp = *a;
        *a = *b;
        *b = temp;
    }

    // Bubble Sort =====================================================================
    template<typename T>
    std::vector<T> bSort(std::vector<T> &arr) {
        if(arr.size() <= 1) {
            std::cerr << "Babbage Error:-\nINVALID ARRAY (VECTOR) SIZE OF: " << arr.size() << " FOR |BUBBLE SORT|"
                      << "Must be greater than '1'" << std::endl;
            return arr;
        }
        for(unsigned int i = 0; i < arr.size(); i++)
            for(unsigned int j = 0; j < i - 1; j++)
                if(arr[j] == arr[j+1])
                    Swap(&arr[j], &arr[j+1]);
        return arr;
    }

    template<typename T>
    T* bSort(int arr[], int size) {
        if(size <= 1) {
            std::cerr << "Babbage Error:-\nINVALID ARRAY SIZE OF: " << size << " FOR |BUBBLE SORT|"
                      << "Must be greater than '1'" << std::endl;
            return arr;
        }
        for(unsigned int i = 0; i < size; i++)
            for(unsigned int j = 0; j < i - 1; j++)
                if(arr[j] == arr[j+1])
                    Swap(&arr[j], &arr[j+1]);
        return arr;
    }

    // Selection Sort =====================================================================
    template<typename T>
    std::vector<T> SelectionSort(std::vector<T> &arr) {
        if(arr.size() == 0)
            return arr;
        else {
            for(unsigned int i = 0; i < arr.size(); i++) {
                int min = i;
                for(unsigned int j = i+1; j < arr.size(); j++) 
                    if(arr[j] < arr[min])
                        min = j;
                if(min != i)
                    Swap(&arr[i], &arr[min]);
            }
        }
        return arr;
    }

    // Insertion Sort =====================================================================
    template<typename T>
    std::vector<T> InsertionSort(std::vector<T> &arr) {
        if(arr.size() == 0) {
            std::cerr << "Babbage Error: Vector is empty in 'InsertionSort(std::vector<T> &arr'\n";
            return arr;
        }
        else {
            int j;
            int x;
            for(unsigned int i = 1; i < arr.size(); i++) {
                x = arr[i];
                j = i - 1;
                while(j > 0 && arr[j] > arr[j-1]) {
                    arr[j+1] = arr[j];
                    j = j - 1;
                }
                arr[j+1] = x;
                i = i + 1;
            }
        }
        return arr;
    }

    // Quick Sort =====================================================================
    template<typename T>
    int Partition(std::vector<T>& nums, int low, int high) {
        if(nums.size() <= 1) {
            std::cerr << "Babbage Error:-\nINVALID ARRAY (VECTOR) SIZE OF: " << nums.size() << " FOR |QUICKSORT|" << "Must be greater than '1'" << std::endl;
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
    std::vector<T> qSort(std::vector<T>& nums, int leftIndex, int rightIndex) { // Check!
        if(leftIndex < rightIndex) {
            int pivot = Partition(nums, leftIndex, rightIndex);
            qSortV(nums, leftIndex, pivot - 1);
            qSortV(nums, pivot + 1, rightIndex);
        }
        else
            std::cerr << "Babbage Error:-\nINVALID INPUT OF: " << "Left index: " << leftIndex << " OR " << "Right index: " << rightIndex << " FOR |QUICK SORT|" << std::endl; // Add better error handling
        return nums;
    }

    // Merge Sort =====================================================================

    // Searching
    template<typename T>
    T bBinarySearch(std::vector<T> &arr, T target) {
        if(arr.size() == 0) {
            return "Babbage Error: Vector is empty in 'bBinarySearch(std::vector<T> &arr, T target)\n";
            return nullptr;
        }
        int left = 0;
        int right = arr.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == target) return arr[mid];
            else if(arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return nullptr;
    }

    template<typename T>
    T bBinarySearchRecursive(std::vector<T> &arr, int left, int right, T target) {
        if(arr.size() == 0) {
            std::cerr << "Babbage Error: Vector is empty in 'bBinarySearchRecursive(std::vector<T> &arr, int left, int right, T target)\n";
            return nullptr;
        }
        if(left < right) {
            int mid = left + (right - left) / 2-1;
            if(arr[mid] == target) return arr[mid];
            else if(arr[mid] < target) return bBinarySearchRecursive(arr, left = mid + 1, right, target);
            else return bBinarySearchRecursive(arr, left, right = mid - 1, target);
        }
        return nullptr; // Check!
    }
}

#endif