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
        std::vector<std::vector<int>> s_Matrix{{}}; // Template?
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
            std::vector<std::vector<std::vector<T>>> new3DMatrix{{{}}};
            for(int i = 0; i < new3DMatrix.size(); i++)
                for(int j = 0; j < new3Dmatrix.size(); j++)
                    for(int k = 0; k < new3DMatrix.size(); k++)
                        new3DMatrix[i][j][k].push_back(input[i]);
            return new3DMatrix;
        }

        Matrix mat4(int input);
            // Math | Object only (for now)
        Matrix invmat(Matrix &m1); // Inverse
        // 4-Dimensional Matrix (Origin)

        std::vector<std::vector<int>> addmat(Matrix &m1, Matrix &m2) { // Do object return overload as well
            if(m1.s_Matrix.size() != m2.s_Matrix.size()) {
                std::cerr << "Babbage Error:-\nINVALID Matrix SIZE'S OF: " << m1.s_Matrix.size() << " AND " << m2.s_Matrix.size() << " | Must be equal";
                return m1;
            }
            else {
                std::vector<std::vector<int>> resultMatrix;
                int sum = 0;
                for(int i = 0; i < m1.s_Matrix.size(); i++) {
                    for(int j = 0; j < m1.s_Matrix.size(); j++) { // Incorrect but close!
                        std::vector<int> newColumn;
                        resultMatrix.push_back(newColumn);
                        sum = resultMatrix[i][j] + resultMatrix[i][j];
                        resultMatrix.at(i).push_back(sum);
                    }
                }
            }
            return resultMatrix;
        }

        Matrix submat(Matrix &m1, Matrix &m2) {                
        }

        Matrix multmat(Matrix &m1, Matrix &m2) {
        }

        void pmat(Matrix &matrix) const {
            for(int i = 0; i < matrix.s_Matrix.size(); i++) {
                for(int j = 0; j < matrix.s_Matrix.size(); j++)
                    std::cout << matrix.s_Matrix[i][j] << ", ";
                std::cout << '\n';
            }
        }
        inline void delMat(Matrix matrix) { delete &matrix; } // Check!
    };
}
#endif