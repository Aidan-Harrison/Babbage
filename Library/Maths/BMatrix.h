#ifndef BMatrix_h
#define BMatrix_h

#include <iostream>
#include <vector>
#include "BVector.h"
namespace bmatrix {
    class Matrix {
    private:
        uint16_t m_Rows; uint16_t m_Columns;
    public:
        Matrix(short rows = 1, short columns = 1)
            :m_Rows(rows), m_Columns(columns)
        {
        }
        ~Matrix() = default;
        // Standard
        std::vector<std::vector<int>> s_Matrix{{}};
        // Creation | Used within vector library
        std::vector<int> mat1(int input[], int size); // Technically columns
        std::vector<std::vector<int>> mat2(int rows, int columns, int input); // Add 2D array input
        std::vector<std::vector<std::vector<int>>> mat3(int input[]);
        Matrix mat4(int input);
        // Math | Object only
        Matrix addmat(Matrix &m1, Matrix &m2);
        Matrix submat(Matrix &m1, Matrix &m2);
        Matrix multmat(Matrix &m1, Matrix &m2);
        Matrix invmat(Matrix &m1); // Inverse
        // Extra
        void pmat(Matrix &matrix);
        inline void delMat(Matrix &matrix);
    };

    /* Main */
    // 1-Dimensional Matrix
    std::vector<int> Matrix::mat1(int input[], int size) { // Check!
        std::vector<int> newMatrix{};
        for(int i = 0; i < size; i++)
            newMatrix.push_back(input[i]);
        return newMatrix;
    }

    // 2-Dimensional Matrix
    std::vector<std::vector<int>> Matrix::mat2(int rows, int columns, int input) {
        std::vector<std::vector<int>> new2DMatrix{{}};
        for(int i = 0; i < rows; i++) {
            new2DMatrix.push_back(std::vector<int>());
            for(int j = 0; j < columns; j++)
                new2DMatrix[i].push_back(input);
        }
        return new2DMatrix;
    }

    // 3-Dimensional Matrix | Fill | Try something other than triple nested for loop
    std::vector<std::vector<std::vector<int>>> Matrix::mat3(int input[]) {
        std::vector<std::vector<std::vector<int>>> new3DMatrix{{{}}};
        return new3DMatrix;
    }

    // 4-Dimensional Matrix (Origin)

    Matrix Matrix::addmat(Matrix &m1, Matrix &m2) {
        Matrix resultMatrix{{}};
        if(m1.s_Matrix.size() != m2.s_Matrix.size()) {
            std::cerr << "Babbage Error:-\nINVALID Matrix SIZE'S OF: " << m1.s_Matrix.size() << " AND " << m2.s_Matrix.size();
            std::cerr << "Must be equal\n";
            return m1;
        }
        else {
            int sum = 0;
            for(int i = 0; i < m1.s_Matrix.size(); i++) {
                for(int j = 0; j < m1.s_Matrix.size(); j++) { // Incorrect but close!
                    std::vector<int> newColumn;
                    resultMatrix.s_Matrix.push_back(newColumn);
                    sum = m1.matrix[i][j] + m2.matrix[i][j];
                    resultMatrix.s_Matrix.at(i).push_back(sum);
                }
            }
        }
        return resultMatrix;
    }

    Matrix Matrix::submat(Matrix &m1, Matrix &m2) {                
    }

    Matrix Matrix::multmat(Matrix &m1, Matrix &m2) {
    }

    void Matrix::pmat(Matrix &matrix) {
        for(int i = 0; i < matrix.s_Matrix.size(); i++) {
            for(int j = 0; j < matrix.s_Matrix.size(); j++)
                std::cout << matrix.s_Matrix[i][j] << ", ";
            std::cout << '\n';
        }
    }

    inline void Matrix::delMat(Matrix &matrix) {
        delete matrix;
    }
}
#endif