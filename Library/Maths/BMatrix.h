#ifndef BMatrix_h
#define BMatrix_h

#include <iostream>
#include <vector>
#include <cassert>
namespace bmatrix {
    template<typename T> // Check!
    class Matrix {
    private:
    public:
        int m_Rows = 0, m_Columns = 0;
        std::vector<std::vector<T>> matrix{};
        Matrix(const int rows = 1, const int columns = 1, T fill = 0)
            :m_Rows(rows), m_Columns(columns)
        {
            assert(rows > 0 && columns > 0);
            matrix.resize(rows);
            matrix[0].resize(rows);
            for(unsigned int i = 0; i <= rows; i++) {
                for(unsigned int j = 0; j <= columns; j++) {
                    matrix[i][j] = fill;
                }
            }
        }
        Matrix(const int rows = 1, const int columns = 1, std::vector<std::vector<T>> &data={}) 
            :m_Rows(rows), m_Columns(columns)
        {
            assert(rows > 0 && columns > 0);
            if((data.size() * data[0].size()) != (m_Rows * m_Columns))
                FillMatrix(data);
        }

        void FillMatrix(std::vector<std::vector<T>> &data);
        void ResizeMatrix();

        void PrintMatrix() const {
            for(unsigned int i = 0; i < m_Rows; i++) {
                for(unsigned int j = 0; j < m_Columns; j++) {
                    std::cout << matrix[i][j] << ", ";
                }
                putchar('\n');
            }
        }
        ~Matrix() {}
    };

    template<typename T>
    void Matrix<T>::FillMatrix(std::vector<std::vector<T>> &data) {
        if((m_Rows * m_Columns) != (data.size() * data[0].size())) {
            std::cerr << "Babbage Error: Data does not match size of matrix! In 'FillMatrix(data)' | CANNOT FILL\n";
            return;
        }
        for(unsigned int i = 0; i < data.size(); i++) {
            for(unsigned int j = 0; j < data[0].size(); j++) {
                matrix[i][j] = data[i][j];
            }
        }
    }

    template<typename T>
    Matrix<T>* AddMatrix(Matrix<T> &m1, Matrix<T> &m2) { // Type check, string + int for example
        Matrix<T> *newMatrix = new Matrix<T>(m1.m_Rows, m1.m_Columns, 0);
        if((m1.m_Rows * m1.m_Columns) != (m2.m_Rows * m2.m_Columns)) {
            std::cerr << "Babbage Error: Matrix sizes do not match! In 'AddMatrix(m1, m2)' | CANNOT ADD\n";
            return newMatrix;
        }
        for(unsigned int i = 0; i < m1.m_Rows; i++) {
            for(unsigned int j = 0; j < m1.m_Columns; j++) {
                newMatrix->matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
            }
        } 
        return newMatrix;
    }

    template<typename T>
    Matrix<T> SubMatrix(Matrix<T> &m1, Matrix<T> &m2) {
        Matrix<T> *newMatrix = new Matrix<T>(m1.m_Rows, m1.m_Columns, 0);
        if((m1.m_Rows * m1.m_Columns) != (m2.m_Rows * m2.m_Columns)) {
            std::cerr << "Babbage Error: Matrix sizes do not match! In 'SubMatrix(m1, m2)' | CANNOT SUBTRACT\n";
            return newMatrix;
        }
        for(unsigned int i = 0; i < m1.m_Rows; i++) {
            for(unsigned int j = 0; j < m1.m_Columns; j++) {
                newMatrix->matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
            }
        } 
        return newMatrix;
    }

    template<typename T>
    Matrix<T> MultMatrix(Matrix<T> &m1, Matrix<T> &m2) { // Check!
        Matrix<T> *newMatrix = new Matrix<T>(m1.m_Rows, m2.m_Columns, 0);
        if(m1.m_Columns == m2.m_Rows) {
            std::cerr << "Babbage Error: Columns of m1 do not match with Rows of m2! In 'MultMatrix(m1, m2)' | CANNOT MULTIPLY\n";
            return newMatrix;
        }
        newMatrix[0][0] = (m1.matrix[1][1] * m2.matrix[1][1]) + (m1.matrix[2][1] * m2.matrix[1][2]);
        for(int i = 0; i < m1.m_Rows; i++) {
            for(int j = 0; j < m2.m_Columns; j++) {
                newMatrix->matrix[i][j] = m1.matrix[i][j] * m2.matrix[i][j];
            }
        }
    }

    // Operator Overloading
    template<typename T>
    Matrix<T> operator+(Matrix<T> &m1, Matrix<T> &m2) { return AddMatrix(m1, m2); }
    template<typename T>
    Matrix<T> operator-(Matrix<T> &m1, Matrix<T> &m2) { return SubMatrix(m1, m2); }
    template<typename T>
    Matrix<T> operator*(Matrix<T> &m1, Matrix<T> &m2) { return MultMatrix(m1, m2); }
}

#endif