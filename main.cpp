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
            a(i,j) = rand() % 100;
        }
    }
}

int main()
{
    S21Matrix m(3,3);
	mRandom(m);
	S21Matrix n(4,4);
	mRandom(n);
	
	// m.SubMatrix(n);

	// n = m;

	printMatrix(m);
	
	// m.SubMatrix(n);

	// printMatrix(m);
	
	std::cout << "---------------------------\n";

	m.MulNumber(1232);
	
	printMatrix(m);

	// printMatrix(m);
	// std::cout << "---------------------------\n";
    // printMatrix(n);
	// std::cout << "---------------------------\n";
   	
	// m = n;
	
	// std::cout << "---------------------------\n";
	// printMatrix(m);
    

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
    // return 0;
}

// valgrind --leak-check=yes ./s21_matrix