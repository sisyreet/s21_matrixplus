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
    S21Matrix m(3,3);
	mRandom(m);
	printMatrix(m);
	std::cout << "---------------------------\n";
	S21Matrix n(3,3);
	mRandom(n);
	printMatrix(n);
	std::cout << "---------------------------\n";
	S21Matrix t;
	S21Matrix p;
	
	n.InverseMatrix();
	
    return 0;
}

// valgrind --leak-check=yes ./s21_matrix