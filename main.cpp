#include <iostream>
#include "2019/Matrix/Matrix.hpp"
int main() {
    Matrix<int> testa(2,3);
    testa.setAt(1,1,5);
    testa.setAt(1,2,3);
    testa.setAt(2,1,4);
    testa.setAt(2,2,1);
    testa.setAt(3,1,5);
    testa.setAt(3,2,3);


    Matrix<int>e;
    e= testa;
    e.transpose();
    e.print();
    return 0;
}
