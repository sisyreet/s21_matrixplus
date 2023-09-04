#include "s21_matrix_oop.h"

int main()
{
    std::cout << "Hello world" << std::endl;
    double **matriks;
    int cols = 3;
    int rows = 3;

    matriks = new double*[rows];
    for (int i = 0; i < rows; i++)
        matriks[i] = new double[cols];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) {
            matriks[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) {
            std::cout << matriks[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}