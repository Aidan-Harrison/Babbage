#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

#include "Babbage.h"
#include "BabbageDSA.h"

// Prototypes
void Swap(int* a, int* b);
std::vector<int> Reverse(std::vector<int>& arr, int start, int end);
int Partition(std::vector<int>& nums, int low, int high);

// General
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

bool BabbageDSA::findDup(std::vector<int>& arr) { // Change to map for speed
    if(arr.size() <= 1) return false; // Invalid
    std::sort(arr.begin(), arr.end()); // Use own sort function
    for(int i = 0; i < arr.size() - 1; i++)
        if(arr[i] == arr[i + 1]) return true;
    return false;
}

bool BabbageDSA::findDupMap(std::vector<int>& arr) {
    std::unordered_map<int,int> map;
    for(int i : arr) {
        if(map.find(i) == map.end())
            map[i]++; // Add to map
        else
            return true;
    }
    return false;
}

bool BabbageDSA::findDupMap(std::vector<int>& arr) {
    std::unordered_map<int,int> uMap;
    for(auto i : arr) {
        if(uMap.find(uMap[i]) == uMap.end())
            uMap[arr[i]]++;
        else
            return true;
        return false;
    }
}

bool BabbageDSA::palin(std::string str) {
    int p1 = 0; // Two pointer technique
    int p2 = str.length() -1;
    while(p1 < p2) {
        if(!isalnum(str[p1])) // Ignore symbols
            p1++;
        else if(!isalnum(str[p2]))
            p2--;
        else if(tolower(str[p1]) != tolower(str[p2])) { // Ignore case
            std::cout << "Babbage:-\nNOT PALINDROME\n";
            return false;
        }
        else { // Move pointers regardless
            p1++;
            p2--;
        }
    }
    return true;
}

bool BabbageDSA::anag(std::string s, std::string t) { // Also do number version
    int n = s.length();
    int m =  t.length();
    if(n != m) {
        std::cout << "Babbage Error:-\nINVALID STRING LENGTHS OF: " << s.length() << " AND " << t.length() << " FOR |ANAGRAM|";
        std::cout << "Both must be equal in length\n"; 
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

std::string BabbageDSA::revStr(std::string str) {
    // Reverse | Possibly replace with sorting algorithm
    if(str.length() <= 1) {
        std::cout << "Babbage Error:-\nINVALID STRING LENGTH OF: " << str.length() << " FOR |REVERSE|";
        std::cout << "Must be greater than '1'\n";
        return false;
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

std::vector<int> BabbageDSA::rotateArray(std::vector<int>& arr, int k) {
    k = k % arr.size();
    Reverse(arr, 0, arr.size() - 1); // Reverse all
    Reverse(arr, 0, k - 1); // Reverse rotated elements
    Reverse(arr, k, arr.size() -1); // Reverse remaining
    return arr;
}

// Sorting
// Should not have to prototype this as header already has definition
void Swap(int* a, int*b) { // Pointer based | Use references in sorting algorithms
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort-
std::vector<int> bSortV(std::vector<int>& arr) {
    if(arr.size() <= 1) {
        std::cout << "Babbage Error:-\nINVALID ARRAY (VECTOR) SIZE OF: " << arr.size() << " FOR |BUBBLE SORT|";
        std::cout << "Must be greater than '1'\n";
        return arr;
    }
    for(int i = 0; i < arr.size(); i++) // Still not entirely sure about this
        for(int j = 0; j < i - 1; j++)
            if(arr[j] == arr[j + 1])
                Swap(&arr[j], &arr[j + 1]);
    return arr;
}

int* bSortA(int arr[]) { // Return by address
    int size = sizeof(arr) / sizeof(arr[0]);
    if(size <= 1) {
        std::cout << "Babbage Error:-\nINVALID ARRAY SIZE OF: " << size << " FOR |BUBBLE SORT|";
        std::cout << "Must be greater than '1'\n";
        return;
    }
    for(int i = 0; i < size; i++)
        for(int j = 0; j < i - 1; j++)
            if(arr[j] == arr[j + 1])
                Swap(&arr[j], &arr[j + 1]);
    // Do return
    return arr;
}

// Quick Sort-
int Partition(std::vector<int>& nums, int low, int high) {
    if(nums.size() <= 1) { // Too small
        std::cout << "Babbage Error:-\nINVALID ARRAY (VECTOR) SIZE OF: " << nums.size() << " FOR |QUICKSORT|";
        std::cout << "Must be greater than '1'\n";
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
        std::cout << "Babbage Error:-\nINVALID INPUT OF: " << "Left index: " << leftIndex << " OR " << "Right index: " << rightIndex << " FOR |QUICK SORT|"; // Add better error handling
    return nums;
}
// Stack