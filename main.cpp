#include "s21_matrix_oop.h"

void printMatrix(S21Matrix m)
{
    for (int i = 0; i < m.getRows(); i++)
    {
        for (int j = 0; j < m.getCols(); j++) {
            std::cout << m(i,j) << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    S21Matrix m(3,3);
    // printMatrix(m);
    // for (int i = 0; i < m.getRows(); i++)
    // {
    //     for (int j = 0; j < m.getCols(); j++) {
    //         m[i][j] = rand() % 100;
    //     }
    // }
    for (int i = 0; i < m.getRows(); i++)
    {
        for (int j = 0; j < m.getCols(); j++) {
            std::cout << m(i,j) << " ";
        }
        std::cout << std::endl;
    }
    m.setRows(2);    
    for (int i = 0; i < m.getRows(); i++)
    {
        for (int j = 0; j < m.getCols(); j++) {
            std::cout << m(i,j) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}