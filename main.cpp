#include "s21_matrix_oop.h"

void printMatrix(S21Matrix &m)
{
    for (int i = 0; i < m.GetRows(); i++)
    {
        for (int j = 0; j < m.GetCols(); j++) {
            std::cout << m(i,j) << "	";
        }
        std::cout << std::endl;
    }
}

void mRandom(S21Matrix &a) {
	for (int i = 0; i < a.GetRows(); i++)
    {
        for (int j = 0; j < a.GetCols(); j++) {
            a(i,j) = rand() % 10;
        }
    }
}

int main()
{
    S21Matrix m(4,4);
	mRandom(m);
	printMatrix(m);
	std::cout << "---------------------------\n";
	S21Matrix n(3,3);
	mRandom(n);
	printMatrix(n);
	std::cout << "---------------------------\n";
	S21Matrix t;
	S21Matrix p;
	
	// m.SumMatrix(n);
	// printMatrix(m);
	// std::cout << "---------------------------\n";

	// m += n;
	// printMatrix(m);
	// std::cout << "---------------------------\n";


	// m.SubMatrix(n);

	// m.SubMatrix(n);
	// std::cout << "---------------------------\n";
	// printMatrix(m);
	std::cout << m.Determinant() << std::endl;
	// printMatrix(n);
	// std::cout << "---------------------------\n";
	// m.SubMatrix(n);
	// m.Transpose();
	// t = m * n;
	// std::cout << "---------------------------\n";
	// printMatrix(t);

	// std::cout << "---------------------------\n";
	// std::cout << "---------------------------\n";

	// m.MulMatrix(n);
	
	// printMatrix(m);

	// printMatrix(m);
	// std::cout << "---------------------------\n";
    // printMatrix(n);
	// std::cout << "---------------------------\n";
   	
    // m.SetRows(4);
	// std::cout << "---------------------------\n";
	// printMatrix(m);
	// std::cout << "---------------------------\n";
	// m.SetCols(4);
	// printMatrix(m);
	// if (m == n) {
	// 	std::cout << "They're equal! :D" << std::endl;
	// }
	// else {
	// 	std::cout << "They're unequal! D:" << std::endl;
	// }
    return 0;
}

// valgrind --leak-check=yes ./s21_matrix