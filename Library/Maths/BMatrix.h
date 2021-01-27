#ifndef BMatrix_h
#define BMatrix_h

#include <iostream>
#include <vector>
#include <cassert>
#include "BVector.h"
namespace bmatrix {
    class Matrix {
    private:
        uint16_t m_Rows, m_Columns;
    public:
        Matrix(short rows = 1, short columns = 1)
            :m_Rows(rows), m_Columns(columns)
        {
            assert(m_Rows != 0 && m_Columns != 0); // Matrix can be empty but must be at least 1 x 1
        }
        std::vector<std::vector<int>> s_Matrix{{}}; // Template?

        // Operator Overloads
        Matrix operator+(Matrix &m1, Matrix &m2) {return addmat(m1, m2); } // Check!

        // Creation | Vector Based ---------------------------------------------------------------------------------------------------------------
            // 1-Dimensional Matrix
        template<typename T>
        std::vector<T> mat1(T input, int size) {
            std::vector<T> newMatrix{};
            for(unsigned int i = 0; i < size; i++)
                newMatrix.push_back(input);
            return newMatrix;
        }
        std::vector<T> mat1(T input[], int size) { // C-array overload
            std::vector<T> newMatrix{};
            for(unsigned int i = 0; i < size; i++)
                newMatrix.push_back(input[i]);
            return newMatrix;
        }
            // 2-Dimensional Matrix
        template<typename T>
        std::vector<std::vector<T>> mat2(int rows, int columns, T input) { // Add 2D C-array overload
            std::vector<std::vector<T>> new2DMatrix{{}};
            for(unsigned int i = 0; i < rows; i++) {
                for(unsigned int j = 0; j < columns; j++)
                    new2DMatrix[i][j].push_back(input);
            }
            return new2DMatrix;
        }
            // 3-Dimensional Matrix | 
        template<typename T>
        std::vector<std::vector<std::vector<T>>> mat3(int rows, int columns, int depth, T input[]) {
            std::vector<std::vector<std::vector<T>>> new3DMatrix{{{}}};
            for(unsigned int i = 0; i < rows; i++)
                for(unsigned int j = 0; j < columns; j++)
                    for(unsigned int k = 0; k < depth; k++)
                        new3DMatrix[i][j][k].push_back(input[i]);
            return new3DMatrix;
        }
            // Add 4D matrix
        // -------------------------------------------------------------------------------------------------------------------------------------

            // Math | Vector Based
        template<typename T>
        std::vector<std::vector<T>> addmat(std::vector<std::vector<T>> &m1, std::vector<std::vector<T>> &m2) { // Fix
            std::vector<std::vector<int>> resultMatrix = {{}};
            if(m1.size() != m2.size()) {
                std::cerr << "Babbage Error:-\nINVALID Matrix SIZE'S OF: " << m1.size() << " AND " << m2.size() << " | Must be equal";
                exit(1);
            }
            else {
                int sum = 0;
                for(unsigned int i = 0; i < m1.size(); i++) {
                    for(unsigned int j = 0; j < m1.size(); j++) {
                        sum = m1[i][j] + m2[i][j];
                    }
                }
            }
        }
        template<typename T>
        std::vector<std::vector<T>> addmat(Matrix &m1, Matrix &m2) {
            std::vector<std::vector<int>> resultMatrix = {{}};
            if(m1.size() != m2.size()) {
                std::cerr << "Babbage Error:-\nINVALID Matrix SIZE'S OF: " << m1.size() << " AND " << m2.size() << " | Must be equal";
                exit(1);
            }
            else {
                int sum = 0;
                for(unsigned int i = 0; i < m1.s_Matrix.size(); i++) {
                    for(unsigned int j = 0; j < m1.s_Matrix.size(); j++) {
                    }
                }
            }
        }
        template<typename T>
        std::vector<std::vector<T>> submat(std::vector<std::vector<T>> &m1, std::vector<std::vector<T>> &m2) {
        }
        template<typename T>
        std::vector<std::vector<T>> multmat(std::vector<std::vector<T>> &m1, std::vector<std::vector<T>> &m2) {
        }

            // Math | Object based
        Matrix addmat(Matrix &m1, Matrix &m2);
        Matrix submat(Matrix &m1, Matrix &m2);
        Matrix multmat(Matrix &m1, Matrix &m2);
        Matrix invmat(Matrix &m1); // Inverse

            // Extra
        void pmat(Matrix &matrix) const {
            for(unsigned int i = 0; i < matrix.s_Matrix.size(); i++) {
                for(unsigned int j = 0; j < matrix.s_Matrix.size(); j++)
                    std::cout << matrix.s_Matrix[i][j] << ", ";
                std::cout << '\n';
            }
        }
        template<typename T>
        void pmat(std::vector<std::vector<T>> &m) const { // Check need for const!
            for(unsigned int i = 0; i < m.size(); i++)
                for(unsigned int j = 0; j < m.size(); j++)
                    std::cout << m[i][j] << ", ";
                std::cout << '\n';
        }
        inline void delMat(Matrix m) { delete &m; } // Check!
    };
}
#endif