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

S21Matrix something(S21Matrix &&other) {
	S21Matrix temp(other.GetRows(), other.GetCols());
	temp += other;
	return (temp);
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
    double a[4][4] = {{4., 5., 9., 8.}, {4., 1., 2., 3.}, {8., 7., 15., 4.}, {7., 6., 4., 9}};
  	double b[4][4] = {{-145., -169., 109., 177.},
                    {252., -504., 72., 108.},
                    {47., 95., 25., -111.},
                    {24., 276., -132., -36.}};

	S21Matrix ma(4, 4);
	S21Matrix mb(4, 4);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
		ma(i, j) = a[i][j];
		mb(i, j) = b[i][j];
		}
	}
	
	printMatrix(ma);
	std::cout << "- - - - - - - - - - - - - - - - - -\n";
	printMatrix(mb);
	std::cout << "- - - - - - - - - - - - - - - - - -\n";
	std::cout << "- - - - - - - - - - - - - - - - - -\n";
	ma.Transpose();
	ma.CalcComplements();
	ma.InverseMatrix();
	ma.Determinant();


    return 0;
}

// valgrind --leak-check=yes ./s21_matrix