#include <iostream>
#include <vector>
#include "Babbage.h"

int General::Asize(int array[]) {
    int size = sizeof(array) / sizeof(array[0]);
    return size;
}

// Complex
std::vector<std::vector<int>> Complex::cMatrix(int rows, int colums, int data) {
std::vector<std::vector<int>> matrix(rows, std::vector<int>(colums)); // Initialisation (rows, colums)
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < colums; j++)
            matrix[i][j].push_back(data); // Will not work
    return matrix;
}