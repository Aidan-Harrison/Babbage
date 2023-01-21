#ifndef BabbageDSA_h
#define BabbageDSA_h

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <array>

#include "Backend.h"

// & or * for vector construction?

// Helper functions
template<typename T>
void swap(T * x, T * y) { 
    T temp = *x;
    *x = *y;
    *y = temp;
}

namespace bst {
    template<typename T>
    class bArray { // Dynamic tuple!
    private:
        int sizeOffset = 5;
        T * arr[];
        uint64_t size{};
        uint64_t maxSize = (int)sizeOffset; // Check cast

        void resize(const int newSize) {
            T * newArr[newSize];
            for(int i = 0; i < size; i++)
                newArr[i] = arr[i];
            size += sizeOffset;
            delete[] arr;
            arr = newArr;
        }

        void push() {
            if(full()) {
                T newVec[maxSize++];
                // Copy contents
                delete[] arr; // Resize above actual size to avoid deletion every call
            }
        }
        
        T pop() {
            T result = arr[size];
            // resize()
            return NULL;
        }
        void slice(T target) { // Splits an array at the given target
            std::vector<int> positions{}; // Swap for bArray!
            for(int i = 0; i < size; i++) {
                if(arr[i] == target) {
                    // Mark position
                    positions = i;
                }
            }
            std::vector<int> result{};
            for(int i = 0; i < positions.size(); i++) {
                for(int j = positions[i]; j < positions[i+1]; j++) {
                    result.push_back(arr[j]);
                }
            }
        }
    public:
        const inline bool full()  const {return size == maxSize; }
        const inline bool empty() const {return size == 0; }
        const unsigned int size() const {return size; }
    };

    struct bStr {
        int size;
        char * str;

        inline int size() const { return size; }
        void resize();
        void clear();

        bStr() {}
        bStr(const char * msg) 
        {
            strcpy(str, msg); // Check!
        }

        bStr operator=(const char * newStr) {
            
        }
        ~bStr() {}
    };

    template<typename...> struct bPair;

    template<typename A, typename B>
    struct bPair<A,B> { // Check!
        T first;
        T second;

        bPair() {}
        bPair(A f, B s) 
            :first(f), second(s)
        {
        }
        bPair(bPair & b) 
            :first(b.first), second(b.second)
        {
        }
        bPair(bPair && b) noexcept
            :first(b.first), second(b.second)
        {
        }

        void clear() {
            // Do values!
            first = nullptr;
            second = nullptr;
        }

        bPair operator=(bPair & b) {
        }

        ~bPair() {}
    };

    template<typename...> struct bHash;

    template<typename A, typename B>
    struct bHash<A,B> {
        std::vector<bPair<A,B>> table{}; // Replace with custom array

        bool contains(A key) const {
            for(unsigned int i = 0; i < table.size(); i++) {
                if(table[i].first == key)
                    return true;
            }
            return false;
        }
        void clear() {
            for(unsigned int i = 0; i < table.size(); i++) {
                table.erase();
            }
        }


        // Write hash function
        void hash() {
        }

        bHash() {}

        inline B operator[](const A index) const {
            // Handle not found!
            return table[index].second;
        }

        ~bHash() {}
    };


        // Set
    template<typename T>
    class set { 
    private:
        T data[2];
        int size = 2, cSize = 0;
        bool hasDuplicate();
    public:
        void append() {
            cSize++;
            if(cSize == size) {
                size += 2;
                T newData[size];
                memcpy(data, newData, sizeof(newData))
            }
        }
        T pop() {}
    };

        // Singly-Linked List
    template<typename T>
    struct SLinkedList {
        struct Node {
            T data;
            Node * next;
            Node() :data(0), next(nullptr) {}
            Node(T x) :data(x), next(nullptr) {}
            Node(T x, Node *n) :data(x), next(n) {}
        };

        Node * head = nullptr;
        Node * tail = nullptr;
        int size = 0;

        SLinkedList() {}
        SLinkedList(SLinkedList<T> *other) 
        {
        }
        SLinkedList(std::vector<T> &vector) 
        {
            std::vector<Node*> tempVector{};
            for(auto i : vector) {
                Node * newNode = new Node(i);
                tempVector.push_back(newNode);
            }
            for(unsigned int i = 0; i < tempVector.size()-1; i++)
                tempVector[i]->next = tempVector[i+1];
        }

        void push(Node * newNode) {
            tail->next = newNode;
            tail = newNode;
        }
        Node * pop() { // Set one previous to tail to null, return tail

        };
        node * peek() const { return tail; };

        void print(std::string sepChar = "->", Node * n = nullptr) const {
            while(n != nullptr) {
                std::cout << n->data << ' ';
                n = n->next;
            }
        }

        Node * addNode(Node* prevNode, T data) {
            Node *newNode = new Node(data);
            newNode->next = prevNode->next;
            prevNode->next = newNode;
            return newNode;
        }

        void delList(node *n) { // Change!
            if(n != nullptr) {
                delete n->data;
                n = n->next;
                if(n->next == nullptr)
                    delete n;
            }
        }

        bool search(T target) const {
            Node * tNode = head;
            while(tNode != nullptr) {
                if(tNode == target)
                    return true;
                tNode = tNode->next;
            }
            return false;
        }

        void getMiddle(node *n) {
            
        }

        inline void deleteNode(Node *n) {
            if(n == nullptr)
                std::cerr << "Babbage Error: 'deleteNode()' was passed an invalid argument of, 'nullptr'\n";
            n->next = n->next->next; 
        }   
        void deleteNodeRAW(Node *n) { // Deletes memory of node as well
            
        }

        ~SLinkedList() {
            delList(head);
        }
    };

    template<typename T>
    struct DLinkedList {
        struct dNode {
            T data;
            dNode * prev;
            dNode * next;
            dNode() :data(0), prev(nullptr), next(nullptr) {}
            dNode(T x) :data(x), prev(nullptr), next(nullptr) {}
            dNode(T x, dNode * n) :data(x), next(n) {}
            dNode(T x, dNode * p) :data(x), prev(p), next(nullptr) {}
            dNode(T x, dNode * p, dNode * n) :data(x), prev(p), next(n) {}
        };

        dNode * head = nullptr;
        dNode * tail = nullptr;

        int size = 0;

        DLinkedList() {}
        DLinkedList(DLinkedList<T> * other) // Do!
        { 
            head = other->head;
            while(other->head != nullptr) {
                other->head = other->head->next;
                addNode(other->head->prev, other->head->data);
            }
        }
        DLinkedList(std::vector<T> & vector) 
        {
            std::vector<dNode*> tempVector{};
            for(auto i : vector) {
                dNode * newNode = new dNode(i);
                tempVector.push_back(newNode);
            }
            for(unsigned int i = 1; i < tempVector.size()-1; i++) {
                tempVector[i]->prev = tempVector[i-1];
                tempVector[i]->next = tempVector[i+1];
            }
            head = tempVector[0];
            tail = tempVector[tempVector.size()-1];
        }
        DLinkedList(const int s) 
            :size(s)
        {
            bool assignedHead = false;
            dNode * hNode = new dNode;
            dNode * tNode = new dNode;
            head = hNode;
            tail = tNode;
            // Assign head node next to first
            for(unsigned int i = 0; i < size; i++) {
                dNode * prevNode = new dNode;
                dNode * curNode = prevNode;
                if(!assignedHead) {
                    head = prevNode;
                    assignedHead = true;
                }
                prevNode->next = curNode;
                curNode->prev = prevNode;
            }
            // Assign last node next to tail
        }

        void push(dNode * newNode) {
            tail->next = newNode;
            tail = newNode;
        }

        dNode * pop() {
            tail->prev->next = nullptr;
            tail = tail->prev;
        }
        dNode * begin() const { return head; }
        dNode * end() const { return tail; }

        void PrintList(dNode * n, char sep = ' ') {
            while(n != nullptr) {
                std::cout << n->data << sep;
                n = n->next;
            }
        }

        dNode * addNode(dNode * prevNode, T data) { // Return?
            dNode * newNode = new dNode(data);
            newNode->next = prevNode->next;
            newNode->prev = prevNode;
            prevNode->next = newNode;
            return newNode;
            size++;
        }

        void delNode(dNode * n) {
            n->prev = n->next;
            size--;
        }

        void delList(dNode * n) { // Check!
            if(n != nullptr) {
                if(n->prev != nullptr)
                    delete n->prev;
                delete n->data;
                n = n->next;
                if(n->next == nullptr)
                    delete n;
            }
        }

        ~DLinkedList() 
        {
            delList(head);
        }
    };

    template<typename T>
    struct bStack {
        std::vector<T> items{}; // Replace with custom vector!
        int top = -1;

        bStack() {}
        bStack(bStack<T> * other)
        {
            while(top <= other->size())
                push(other->pop());
            delete other; // Check!
        }
        bStack(const int size)
        {
            items.resize(size);
        }
        bStack(std::vector<T> & vector) 
        {
            while(!vector.empty())
                push(vector.pop_back());
        }
        bStack(std::vector<T> && vector) 
        {
            while(!vector.empty())
                push(vector.pop_back());
        }

        inline bool full() const { return top == items.size(); }
        inline bool empty() const { return top == -1; }

        void push(T data, bool debugPrint = false) {
            if(full()) {
                if(debugPrint)
                    std::cerr << "Babbage Error: Stack is full!\n";
                return;
            }
            top++;
            items[top] = data;
        }

        T pop() {
            if(empty()) {
                std::cerr << "Babbage Error: Stack is empty!\n";
                return;
            }
            T item = items[top];
            items[top] = -1; // Fix default value!
            top--;
            return item;
        }

        inline int size() const { return top; }
        inline T peek() const { return items[top]; }

        inline void print() const {
            for(auto i : items)
                std::cout << i << ", ";
        }

        ~bStack() {}
    };

    template<typename T>
    class bQueue {
        private:
            int MAXSIZE = 0;
            int rear = -1;
            int front = 0;
            std::vector<T> items{};
        public:
            bQueue() {}
            bQueue(bQueue<T> *other) 
            {
                if(other->MAXSIZE == 0 || other->rear == -1)
                    std::cerr << "Babbage Error: Expected a size greater then 0, got " << other->rear << " instead\n";
                while(GetSize() <= other->GetSize()) {
                    Enqueue(other->Dequeue());
                }
            }
            bQueue(const int size)
            {
                switch (size) { // Test
                    case 0: std::cerr << "Babbage Error: Expected a size greater then 0, got " << size << " instead\n"; break;
                }
                MAXSIZE = size;
            }
            bQueue(std::vector<T> &vector) 
            {
                if(vector.empty())
                    std::cerr << "Babbage Error: Expected a non-empty vector in 'Queue' construction | At address: " << this << '\n';
                while(!vector.empty())
                    Enqueue(vector.pop_back());
            }

            inline bool full() {
                if(rear == MAXSIZE)
                    return true;
                return false;
            }

            bool empty() {
                if(rear == -1)
                    return true;
                return false;
            };

            void push(T data) {
                if(full())
                    std::cerr << "Babbage Error: Queue is full!\n";
                else { 
                    if(front == -1)
                        front++;
                    rear++;
                    items[rear] = data;
                }
            }
            T pop() {
                if(empty())
                    std::cerr << "Babbage Error: Queue is empty!\n";
                else {
                    T element = queue[front];
                    if(front >= rear) {
                        front = -1;
                        rear = -1;
                    }
                    else
                        front++;
                    return element;
                }
                return 0;
            }

            inline auto front() const { return items[front]; }
            inline T rear() const { return items[rear]; }
            inline void SetMax(int size) { MAXSIZE = size; }

            inline void Print() const {
                for(auto i : items)
                    std::cout << i << ", ";
            }

            ~bQueue() {}
    };

        // Graph & Trees
    template<typename T>
    struct Graph { // Re-do partially! | Check templating!
        int vertexCount = 0, edgeCount = 0;
        std::vector<std::vector<T>> graph{};
        std::vector<std::vector<bool>> visited{};

        Graph(const int vertices) 
            :vertexCount(vertices)
        {
            visited.resize(graph.size());
            for(int i = 0; i < graph.size(); i++)
                visited[i].resize(graph[0].size());
        }

        void AddEdge(const int src, const int dest, bool isDirected = false) {
            if(src == dest) {
                std::cerr << "BABBAGE ERROR: Source and destination are the same value\n";
                return;
            }
            else if(graph[src][dest] && isDirected) {
                std::cerr << "BABBAGE ERROR: Vertex already occupies space\n";
                return;
            }
            if(!isDirected)
                graph[dest][src] = 1;
            graph[src][dest] = 1;
        }

        void DeleteEdge(const int src, const int dest) {
            if(graph[src][dest] == 0) {
                std::cerr << "BABBAGE ERROR: No vertex exists!\n";
                return;
            }
            graph[src][dest] = 0;
            if(graph[dest][src] == 1)
                graph[dest][src] == 0
        }
        
        void PrintGraph() {
            for(unsigned int i = 0; i < vertexCount; i++) {
		        for(unsigned int j = 0; j < vertexCount; j++)
		            std::cout << graph[i][j] << ", ";
		        putchar('\n');
	        }
        }
        
        ~Graph() {}
    };

    template<typename T>
    struct wNode {
        T data;
        bool visited = false;
        std::vector<std::pair<wNode*, int>> children{};
    };

    template<typename T>
    class wGraph {
    private:
        wNode * root = nullptr;
        unsigned int size = 0;

        void DFS(bool print = false, char sepChar = '-') {
            bStack<wNode*> s;
            s.push(root);
            root->visited = true;
            if(print)
                std::cout << root->data << sepChar;
            while(!s.empty()) {
                wNode * curNode = s.pop();
                for(std::pair<wNode*,int> n : curNode->children) {
                    if(!n.first->visited) {
                        s.push(n);
                        n.first->visited = true;
                        if(print)
                            std::cout << n.first->data << sepChar;
                    }
                }
            }
        }

        void BFS(bool print = false, char sepChar = '-') {
            bQueue<wNode*> q;
            q.push(root);
            root->visited = true;
            if(print)
                std::cout << root->data << sepChar;
            while(!q.empty()) {
                wNode * curNode = q.pop();
                for(std::pair<wNode*,int> n : curNode->children) {
                    if(!n.first->visited) {
                        q.push(n);
                        n.first->visited = true;
                        if(print)
                            std::cout << n.first->data << sepChar;
                    }
                }
            }
        }
    public:
        void insert(WNode * n, const int data, const int weight) {
            wNode * newNode = new wNode(data);
            if(root == nullptr) {
                root = newNode;
                size++;
                return;
            }
            n->children.push_back({newNode,weight});
            size++;
        }

        // Removes given instance of node
        void remove(wNode * dN, const int instance) { // Check!
            // Add option to fix graph if it becomes disconnected?
            bStack<wNode*> s;
            s.push(root);
            root->visited = true;
            while(!s.empty()) {
                wNode * curNode = s.pop();
                if(curNode == dN) { // Check!
                    delete curNode; // Check!
                    size--;
                    return;
                }
                for(std::pair<wNode*,int> n : curNode->children) {
                    if(n.first == dN) {
                        delete curNode;
                        size--;
                        return;
                    }
                    if(!n.first->visited) {
                        s.push(n);
                        n.first->visited = true;
                    }
                }
            } 
        }

        bool search(const T target) {
            bStack<wNode*> s;
            s.push(root);
            root->visited = true;
            while(!s.empty()) {
                wNode * curNode = s.pop();
                for(wNode * n : curNode->children) {
                    if(n->data == target)
                        return true;
                    if(!n->visited) {
                        s.push(n);
                        n->visited = true;
                    }
                }
            } 
            return false;
        }

        unsigned int size() const { return size; }

        void shortestPath() { // Dijstkas Algorithmn
            std::vector<int> distances{0};
            distances.resize(size());
            for(int i = 1; i < distances.size(); i++)
                distances[i] = INT_MAX;
            wNode * initialNode = root;
            for(std::pair<wNode*,int> n : initialNode->children) {
                int distance = 0;
                distance += n.second;
            }
        }

        void print() const {
            if(root == nullptr) {
                std::cerr << "Attempted to print a weighted graph which does not exist!\n";
                return;
            }
            DFS(true);
        }

        void unvisit() {
            bStack<wNode*> s;
            s.push(root);
            root->visited = false;
            if(print)
                std::cout << root->data << '-';
            while(!s.empty()) {
                wNode * curNode = s.pop();
                for(wNode * n : curNode->children) {
                    if(n->visited) {
                        s.push(n);
                        n->visited = false;
                    }
                }
            } 
        }

        int distance() { // Returns total distance
            int result = 0;
            bStack<wNode*> s;
            s.push(root);
            root->visited = true;
            if(print)
                std::cout << root->data << sepChar;
            while(!s.empty()) {
                wNode * curNode = s.pop();
                for(wNode * n : curNode->children) {
                    if(!n->visited) {
                        
                        s.push(n);
                        n->visited = true;
                        if(print)
                            std::cout << n->data << sepChar;
                    }
                }
            } 
            return result;
        }
    };

    struct wmGraph {
        std::vector<std::vector<int>> graph{};
        std::vector<std::vector<int>> weights{};

        void search() {

        }

        void DFS() {

        }

        void BFS() {

        }

        void print() const {
            for(unsigned int i = 0; i < graph.size(); i++) {
                for(unsigned int j = 0; j < graph[i].size(); j++) 
                    std::cout << graph[i][j] << '|' << weights[i][j] << ',';
                putchar('\n');
            }
        }

        wmGraph() {}
        ~wmGraph() {}
    };

    template<typename T>
    struct wlGraph {
        std::vector<SLinkedList<T>> graph{};
        
        void DFS(const int n) {
            bStack<T> s;
            for(unsigned int i = 0; i < graph.size(); i++) {
                graph[n].visited = true;
                while(!s.empty()) {
                    wNode * curNode = s.pop();
                    wNode * traverseNode = curNode;
                    while(traverseNode != nullptr) {
                        if(!traverseNode->visited) {
                            s.push(traverseNode);
                            traverNode->visisted = true;
                            break;
                        }
                    }
                }
            }
        }

        void BFS(const int n) {
            bQueue<T> q;
            while(!q.empty()) {

            }
        }

        void clear() {

        }

        bool search(T target) const {
            for(unsigned int i = 0; i < graph.size(); i++) {
                if(graph[i].search(T))
                    return true;
            }
            return false;
        }

        void print(std::string sepChar = "->") const {
            for(unsigned int i = 0; i < graph.size(); i++) {
                graph[i].print(sepChar);
            }
        }

        wlGraph() {}
        ~wlGraph() {}
    }; 

    template<typename T>
    struct treeNode {
        T key_Value;
        bool isVisited = false;
        treeNode * left = nullptr;
        treeNode * right = nullptr;
        treeNode(T value) :key_Value(value) {}
    };

    template<typename T>
    class BSTree {
    private:
        treeNode<T> *root;
        // System level functions
        void destroyTree(treeNode<T> *leaf) { 
            if(leaf != nullptr) { // If leaf exists, remove left and right children, then delete current node
                destroyTree(leaf->left);
                destroyTree(leaf->right);
                delete leaf;
            }
        }

        void insert(T key, treeNode<T> * leaf) {
            if(key < leaf->key_Value) {
                if(leaf->left != nullptr) // If leaf does exist, recursivelly call until available slot
                    insert(key, leaf->left);
                else { // Else add leaf
                    leaf->left = new treeNode(key); // '<T>'?
                }
            }
            else if(key >= leaf->key_Value) {
                if(leaf->right != nullptr)
                    insert(key, leaf->right);
                else {
                    leaf->right = new treeNode(key);
                }
            }
        } 

        treeNode<T> * search(T key, treeNode<T>* leaf) {
            if(leaf != nullptr) {
                if(key == leaf->key_Value) return leaf;
                if(key < leaf->key_Value) return search(key, leaf->left);
                else 
                    return search(key, leaf->right);
            }
            else 
                return nullptr;
        }

    public:
        BSTree() {};
        void insert(T key) {
            if(root != nullptr)
                insert(key, root);
            else
                root = new treeNode(key);
        }
        treeNode<T>* bTreeSearch(T key) { return search(key, root); }
        void destroyTree() { return destroyTree(root); }

        void deleteNode(treeNode * target) { // Check!
            delete Search(target); 
        }

        void Print(treeNode *leaf) {
            if(leaf != nullptr) {
                std::cout << leaf->key_value << '-';
                Print(leaf->left);
                Print(leaf->right);
            }
        }

        void DFS() {
            bStack<treeNode*> s;
            s.push(root);
            root->isVisited = true;
            while(!s.empty()) {
                treeNode * curNode s.pop();
                if(treeNode->left != nullptr && !treeNode->left->visited) {
                    
                }
            }
        }
        void BFS() {}

        ~BSTree() 
        {
            destroyTree(root); 
        }
    };

    class bTrie { // Currently only strings/characters
    private:
    public:
        struct trieNode {
            char data = 'a';
            bool terminal = false;

            std::array<trieNode*, 26> children;

            trieNode(const char ch) : data(ch) 
            {
                for(unsigned int i = 0; i < children.size(); i++)
                    children[i] = nullptr;
            }
            ~trieNode() {}
        };

        trieNode *root;

        bTrie() 
        {
            root = new trieNode('0');
        }

        trieNode* CreateNode(const char c) {
            trieNode *newNode = new trieNode(c);
            return newNode;
        }

        void Insert(const std::string &str) {
            if(root == nullptr)
                root = CreateNode('0');
            trieNode *tempNode = root;
            for(unsigned int i = 0; i < str.length(); i++) {
                if(tempNode->children[i] == nullptr) {
                    tempNode->children[i] = CreateNode('0');
                }
                tempNode = tempNode->children[i];
            }
        }

        ~bTrie() {}
    };

    class rBuffer { // template!
    public:
        int rear = 0;
        int front = -1;
        int size = 10;
        int elementCount = 0;

        int size() const { return elementCount; } 
        inline bool full() const { return elementCount == size ? true : false; }
        inline bool empty() const { return elementCount == 0 ? true : false; }

        void push(const int data) {
            if(full())
                return;
            queue[rear] = data;
            rear = (rear + 1) % size;
            elementCount++;            
        }
        int pop() {
            if(empty())
                return INT_MIN;
            int result = queue[front];
            front = (front + 1) % size;
            elementCount--;
            return result;
        }

        rBuffer(rBuffer & r) 
            :elementCount(r.elementCount), rear{r.rear}, front(r.front)
        {
        }
        rBuffer(rBuffer && r) noexcept 
            :elementCount(r.elementCount), rear{r.rear}, front(r.front)
        {
        }
        rBuffer& operator=(rBuffer && r) noexcept 
        {
            if(&r == this)
                return;
            delete &rear;
            delete &front;
            front = r.front;
            rear = r.rear;
            return *this;
        }
    private:
        std::vector<int> queue;
    };

    template<typename T>
    struct bHeap {
        std::vector<int> heap{};
        int size{};
        bHeap(const int size) 
            :heap.resize(size)
        {
            heap[0] = NULL; // check!
        }

        T parent(uint32_t i) { return i>>1; }
        T left(unit32_t i) { return i<<1; }
        T right(unit32_t i) { return (i<<1) + 1; }

        T getParent(const uint32_t i) const { return heap[(i-1)/2]; }
        T getLeft(const uint32_t index) const{ return heap[2*i+1]; }
        T getLeft(const uint32_t index) const{ return heap[2*i+2]; }

        void peek() {
            return heap[1];
        }

        void constructMax(std::vector<int> & data) { 
            for(int i = 0; i < data.size(); i++) {
                heap.push_back(data[i]);
                if(heap[i-1/2] > heap[i])
                    swap(&heap[i-1/2], heap[i]);
            }
        }

        void heapify() {
            int largest = heap[heap.size()-1];
            for(int i = heap.size(); i >= 0; i--) {
                if(heap[i-1/2] > largest)
                    largest = i-1/2;
                else if()
                    largest = 2*i+2;
            }
        }

        ~heap() {}
    };
}

namespace bAlgorithms {
    template<typename T>
    bool findDup(std::vector<int> &arr) { // Add support for object of any-type
        std::unordered_map<int,int> uMap;
        for(int i = 0; i < arr.size(); i++)
            uMap.insert(std::pair<int,int>(i, arr[i]));
        for(auto &value : uMap)
            if(value.second > 1)
                return true;
        return false;
    }

    bool palin(std::string &str, bool stateError = false) { // Re-do
        int p1 = 0, p2 = str.length()-1;
        while(p1 < p2) {
            if(!isalnum(str[p1])) p1++; // Ignore symbols
            else if(!isalnum(str[p2])) p2--;
            else if(tolower(str[p1]) != tolower(str[p2])) { // Ignore case
                if(stateError)
                    std::cerr << "Babbage:-\n\tNOT PALINDROME\n";
                return false;
            }
            else { p1++; p2--; } // Move pointers regardless
        }
        return true;
    }
    
    bool anag(const std::string &s, const std::string &t, bool stateError = false) {
        if(s.length() != t.length()) {
            if(stateError)
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
    std::vector<T> Reverse(std::vector<T>& arr, unsigned int start = 0, unsigned int end = 0) {
        if(end != 0) {
            end = end;
        else
            end = arr.size()-1;
        while(start < end) {
            int temp = arr[start];
            arr[start++] = arr[end];
            arr[end--] = temp;
        }
        return arr;
    }

    std::string capitalise(std::string str) {
        for(char c : str)
            toupper(c);
        return str;
    }

    std::string lowerise(std::string str) {
        for(char c : str)
            tolower(c);
        return str;
    }

    std::string Reverse(std::string &str, unsigned int start = 0, unsigned int end = 0) {
        if(str.length() == 0 || str.length() == 1) {
            std::cerr << "Babbage Error: String is empty in 'Reverse(std::string &str)'\n";
            return str;
        }
        if(end != 0)
            end = end;
        else
            end = str.length()-1;
        while(start < end) {
            int temp = str[start];
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

    template<typename T>
    void VisualiseSort(std::vector<T> &arr, const int left, const int right, char character = '|') {
        std::vector<std::string> visual{};
        for(unsigned int i = 0; i < arr.size(); i++)
            visual.push_back(std::string(arr[i]/10, character));
        for(int i = 0; i < visual.size(); i++) {
            std::cout << visual[i];
            if(i == left) {
                std::cout << "\t<----L\n";
                continue;
            }
            if(i == right) {
                std::cout << "\t<----R\n";
                continue;
            }
            else
                putchar('\n');
        }
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
                    swap(&arr[j], &arr[j+1]);
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
                    swap(&arr[j], &arr[j+1]);
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
                    swap(&arr[i], &arr[min]);
            }
        }
        return arr;
    }

    // Insertion Sort =====================================================================
    template<typename T>
    std::vector<T> InsertionSort(std::vector<T> &arr) {
        if(arr.size() == 0) {
            if(flags::DEBUG_STATE)
                std::cerr << "Babbage Error: Vector is empty in 'InsertionSort(std::vector<T> &arr)'\n";
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
                    j--;
                }
                arr[j+1] = x;
                i++;
            }
        }
        return arr;
    }

    // Quick Sort =====================================================================
    template<typename T>
    int Partition(std::vector<T>& nums, int low, int high) {
        if(nums.size() <= 1) {
            if(flags::DEBUG_STATE)
                std::cerr << "Babbage Error:-\nINVALID ARRAY (VECTOR) SIZE OF: " << nums.size() << " FOR |QUICKSORT|" << "Must be greater than '1'" << std::endl;
            return -1;
        }
        int pivot = nums[high];
        int i = nums[low];
        for(int j = low; j < high; j++)
            if(nums[j] <= pivot)
                swap(&nums[i], &nums[j]);
        swap(&nums[i + 1], &nums[high]);
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
    void MergeSort() {

    }

    // Heap Sort =====================================================================
    void HeapSort() {

    }

    // Radix Sort =====================================================================

    // Counting Sort =====================================================================

    // Bucket Sort =====================================================================

    // Searching
    template<typename T>
    T bSearch(std::vector<T> &arr, const T target, bool sort = false) {
        if(arr.size() == 0 || arr.size() == 1) {
            if(flags::DEBUG_STATE)
                std::cerr << "Babbage Error: Vector is empty in 'bBinarySearch(std::vector<T> &arr, const T target, bool sort)\n";
            return -1;
        }
        int left = 0, right = arr.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == target) return arr[mid];
            else if(arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return arr[0];
    }

    // Graph Algorithms
    template<typename T>
    void DFS(bst::Graph<T> &g, int x = 0, int y = 0) {
        int w = g.graph[0].size();
        int h = g.graph.size();
        std::vector<BDataStruct::bPair> directions{}; // Do with custom!
        std::vector<std::vector<bool>> visited{};
        auto inside =[&](int x, int y) { return 0 <= x && x <= w && 0 <= y && y <= h; };
        for(int row = 0; row < g.graph.size(); row++) {
            for(int col = 0; col < g.graph[0].size(); col++) {
                if(g.graph[row][col] == 1) {
                    BDataStruct::bStack stack;
                    BDataStruct::bPair initial(row, col);
                    stack.push(initial);
                    visited[row][col] = true;
                    while(!stack.empty()) {
                        BDataStruct::bPair pos = stack.pop();
                        for(BDataStruct::bPair dir : directions) {
                            int new_row = row + dir.first;
                            int new_col = col + dir.second;
                            if(!visited[new_row][new_col] && inside(new_row, new_col) && g.graph[new_row][new_col] == 1) {
                                stack.push(BDataStruct::bPair new(new_row,new_col));
                                visited[new_row][new_col] = true;
                            }
                        }
                    }
                }
            }
        }
    }

    template<typename T>
    void BFS(bst::Graph<T> &g) {
        int w = g.graph[0].size();
        int h = g.graph.size();
        std::vector<BDataStruct::bPair> directions{}; // Do with custom!
        std::vector<std::vector<bool>> visited{};
        auto inside =[&](int x, int y) { return 0 <= x && x <= w && 0 <= y && y <= h; };
        for(int row = 0; row < g.graph.size(); row++) {
            for(int col = 0; col < g.graph[0].size(); col++) {
                if(g.graph[row][col] == 1) {
                    BDataStruct::bQueue queue;
                    BDataStruct::bPair initial(row, col);
                    queue.push(initial);
                    visited[row][col] = true;
                    while(!stack.empty()) {
                        BDataStruct::bPair pos = stack.pop();
                        for(BDataStruct::bPair dir : directions) {
                            int new_row = row + dir.first;
                            int new_col = col + dir.second;
                            if(!visited[new_row][new_col] && inside(new_row, new_col) && g.graph[new_row][new_col] == 1) {
                                stack.push(BDataStruct::bPair new(new_row,new_col));
                                visited[new_row][new_col] = true;
                            }
                        }
                    }
                }
            }
        } 
    }

    void AStar(bst::wGraph & wG) {
    }
    void AStar(bst::wmGraph & wG) {
    }
    void AStar(bst::wlGraph & wG) {
    }
}

#endif