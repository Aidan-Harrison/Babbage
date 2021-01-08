#ifndef BMatrix_h
#define BMatrix_h

#include <iostream>
#include <vector>
#include "BVector.h"
namespace bmatrix {
    class Matrix {
    private:
        uint16_t m_Rows, m_Columns;
    public:
        Matrix(short rows = 1, short columns = 1)
            :m_Rows(rows), m_Columns(columns)
        {
        }
        ~Matrix() = default;
        // Standard
        std::vector<std::vector<int>> s_Matrix{{}};
        // Creation | Used within vector library
            // 1-Dimensional Matrix
        template<typename T>
        std::vector<T> mat1(T input[], int size)  { // Check! | Technically columns
            std::vector<T> newMatrix{};
            for(int i = 0; i < size; i++)
                newMatrix.push_back(input[i]);
            return newMatrix;
        }
            // 2-Dimensional Matrix
        template<typename T>
        std::vector<std::vector<T>> mat2(int rows, int columns, T input) {
            std::vector<std::vector<T>> new2DMatrix{{}};
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < columns; j++)
                    new2DMatrix[i][j].push_back(input);
            }
            return new2DMatrix;
        }

        template<typename T>
        std::vector<std::vector<std::vector<T>>> mat3(T input[]) {
            std::vector<std::vector<std::vector<int>>> new3DMatrix{{{}}};
            for(int i = 0; i < new3DMatrix.size(); i++)
                for(int j = 0; j < new3Dmatrix.size(); j++)
                    for(int k = 0; k < new3DMatrix.size(); k++)
                        new3DMatrix[i][j][k].push_back(input[i]);
            return new3DMatrix;
        }

        Matrix mat4(int input);
            // Math | Object only (for now)
        Matrix addmat(Matrix &m1, Matrix &m2);
        Matrix submat(Matrix &m1, Matrix &m2);
        Matrix multmat(Matrix &m1, Matrix &m2);
        Matrix invmat(Matrix &m1); // Inverse
            // Extra
        void pmat(Matrix &matrix) const;
        template<typename T>
        void pmat(std::vector<std::vector<T>> matrix); // Check whether to mark as 'const'
        inline void delMat(Matrix &matrix);
    };

    // 4-Dimensional Matrix (Origin)

    Matrix Matrix::addmat(Matrix &m1, Matrix &m2) {
        if(m1.s_Matrix.size() != m2.s_Matrix.size()) {
            std::cerr << "Babbage Error:-\nINVALID Matrix SIZE'S OF: " << m1.s_Matrix.size() << " AND " << m2.s_Matrix.size();
            std::cerr << "Must be equal\n";
            return m1;
        }
        else {
            Matrix resultMatrix;
            int sum = 0;
            for(int i = 0; i < m1.s_Matrix.size(); i++) {
                for(int j = 0; j < m1.s_Matrix.size(); j++) { // Incorrect but close!
                    std::vector<int> newColumn;
                    resultMatrix.s_Matrix.push_back(newColumn);
                    sum = m1.s_Matrix[i][j] + m2.s_Matrix[i][j];
                    resultMatrix.s_Matrix.at(i).push_back(sum);
                }
            }
        }
        return m1; // Sort proper return
    }

    Matrix Matrix::submat(Matrix &m1, Matrix &m2) {                
    }

    Matrix Matrix::multmat(Matrix &m1, Matrix &m2) {
    }

    void Matrix::pmat(Matrix &matrix) const {
        for(int i = 0; i < matrix.s_Matrix.size(); i++) {
            for(int j = 0; j < matrix.s_Matrix.size(); j++)
                std::cout << matrix.s_Matrix[i][j] << ", ";
            std::cout << '\n';
        }
    }

    void Matrix::pmat(std::vector<std::vector> matrix) { // Vector overload
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix.size(); j++)
                std::cout << matrix[i][j] << ', ';
            std::cout << '\n';
    }
    inline void Matrix::delMat(Matrix &matrix) { delete matrix; } // Check!
}
#endif