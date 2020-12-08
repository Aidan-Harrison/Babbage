#pragma once
#include <iostream>
#include <vector>

#include "Babbage.h"

class BabbageDSA {
private:

public:
    // Same as printing, sort generic
    bool findDup(std::vector<int>& arr); // Pick map after understanding | Faster I believe
    bool findDupMap(std::vector<int>& arr);
    bool palin(std::string str);
    bool anag(std::string s, std::string t);
    std::vector<int> rotateArray(std::vector<int>& arr, int k);
    // Reverse String | Could be universal ??? | Do it recursively
    std::string revStr(std::string str);

    // Sorting
    // Bubble Sort
    std::vector<int> bSortV(std::vector<int>& arr);
    int* bSortA(int arr[]);
    // Quick Sort
    std::vector<int> qSortV(std::vector<int>& arr, int leftIndex, int rightIndex);
    // Stack ----------------------------------------------------------------------------------
    struct BabbageStack {
        // int stack[0], n = 0, top = -1; // FIX ERROR
        void stackCreate(int stackSize, int value);
        void popStack();
        void pushStack(int value);
        void printStack();
    };
};

// Linked List (Single)
class BabbageLinkedList { // Numbers only for now
private:
    struct Node {
        int data; // Allow user to implement custom data of any type
        Node* next;
    };

    void linsert(int key, Node* node);
    void lsearch(int key, Node* node);
    void lPrint(Node* node);
    void ldestroyList(Node* node);

    int dataInput;
public:
    BabbageLinkedList(); // Constructor

    // Possibly add print somewhere
    void linsert(int key);
    void lsearch(int key);
    void ldestroyList(Node* node);

    // Initialise
    Node* head = nullptr; // No idea why this doesn't work
    Node* tail = nullptr;

    // UNDERSTAND WHY THIS WAS NOT WORKING


    ~BabbageLinkedList() { // May not need to treat this like a binary tree. Although similair. Study more
        // Add deletion
    }

    // Move to .cpp file
    void lcreate(int userInput) { // Allow for custom amount of nodes as well custom input per node. Leave head and tail for now
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

// Move to .cpp file
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