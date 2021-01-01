#ifndef BMatrix_h
#define BMatrix_h

#include <iostream>
#include <vector>

namespace bMatrix {
    class Matrix {
        private:
            uint16_t m_Rows;
            uint16_t m_Columns;
        public:
            Matrix(short rows = 1, short columns = 1)
                :m_Rows(rows), m_Columns(columns)
            {
            }
            // Creation
            std::vector<std::vector<int>> matrix{{}}; // Template
            Matrix cmat(int &rows, int &columns, int input);
            Matrix mat1(int rows = 1, int columns = 1);
            Matrix mat2(int rows = 2, int columns = 2);
            Matrix mat3(int rows = 3, int columns = 3);
            Matrix mat4(int rows = 4, int columns = 4);
            // Math
            Matrix addmat(Matrix &m1, Matrix &m2);
            Matrix submat(Matrix &m1, Matrix &m2);
            Matrix mmat(Matrix &m1, Matrix &m2);
            void pmat(Matrix &Matrix);
    };

    // Operator Overloads
    Matrix cmat(int rows, int columns, int input) {
        Matrix m1;
        for(int i = 0; i < rows; i++)
            m1.matrix[rows].push_back(input);
            for(int j = 0; j < columns; j++)
                m1.matrix[columns].push_back(input);
        return m1; // Should return with updated matrix
    }

    Matrix amat(Matrix &m1, Matrix &m2) {
        Matrix resultMatrix{{}};
        if(m1.matrix.size() != m2.matrix.size()) {
            std::cerr << "Babbage Error:-\nINVALID Matrix SIZE'S OF: " << m1.matrix.size() << " AND " << m2.matrix.size();
            std::cerr << "Must be equal\n";
            return m1;
        }
        else {
            int sum = 0;
            for(int i = 0; i < m1.matrix.size(); i++) {
                for(int j = 0; j < m1.matrix.size(); j++) { // Incorrect but close!
                    std::vector<int> newColumn;
                    resultMatrix.matrix.push_back(newColumn);
                    sum = m1.matrix[i][j] + m2.matrix[i][j];
                    resultMatrix.matrix.at(i).push_back(sum);
                }
            }
        }
        return resultMatrix;
    }

    void pmat(Matrix &Matrix) {
        for(int i = 0; i < Matrix.matrix.size(); i++) {
            for(int j = 0; j < Matrix.matrix.size(); j++)
                std::cout << Matrix.matrix[i][j] << ", ";
            std::cout << '\n';
        }
    }
}
#endif