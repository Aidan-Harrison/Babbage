#include "BMatrix.h"
#include "BMath.h"

using namespace bmatrix;
using namespace bmath;

int main() {
    std::vector<std::vector<int>> data{{1,2},
                                       {5,6},
                                       {7,4}};

    Matrix<int> m1(3,2, data);
    Matrix<int> m2(3,2, data);

    m1.PrintMatrix();
    m2.PrintMatrix();

    Matrix<int> *m3 = AddMatrix(m1, m2);    
    m3->PrintMatrix();

    MultMatrix(m1, m2);

    std::cout << circumfrence(4.5f);

    return 0;
}