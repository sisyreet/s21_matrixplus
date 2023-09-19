#include "s21_matrix_oop.h"

// void printMatrix(S21Matrix m)
// {
//     for (int i = 0; i < m.GetRows(); i++)
//     {
//         for (int j = 0; j < m.GetCols(); j++) {
//             std::cout << m(i,j) << " ";
//         }
//         std::cout << std::endl;
//     }
// }

int main()
{
    S21Matrix m(3,3);
    

	// printMatrix(m);
    for (int i = 0; i < m.GetRows(); i++)
    {
        for (int j = 0; j < m.GetCols(); j++) {
            m(i,j) = rand() % 100;
        }
    }
    for (int i = 0; i < m.GetRows(); i++)
    {
        for (int j = 0; j < m.GetCols(); j++) {
            std::cout << m(i,j) << " ";
        }
        std::cout << std::endl;
    }
	S21Matrix n(m);
	for (int i = 0; i < n.GetRows(); i++)
    {
        for (int j = 0; j < n.GetCols(); j++) {
            std::cout << n(i,j) << " ";
        }
        std::cout << std::endl;
    }
    // m.setRows(2);    
    // for (int i = 0; i < m.GetRows(); i++)
    // {
    //     for (int j = 0; j < m.GetCols(); j++) {
    //         std::cout << m(i,j) << " ";
    //     }
    //     std::cout << std::endl;
    // }
    // return 0;
}
