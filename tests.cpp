#include <gtest/gtest.h>
#include "s21_matrix_oop.h"
// #include <utility> // ?

// CONSTRUCTORS //

TEST(Constructors, DefaultConstructor) {
	S21Matrix m;
	EXPECT_EQ(m.GetCols(), 1);
	EXPECT_EQ(m.GetRows(), 1);
	EXPECT_EQ(m(0,0), 0.0);
}

TEST(Constructors, InitialiazedConstructor) {
	int rows = 100;
	int cols = 100;
	S21Matrix m(rows, cols);

	EXPECT_EQ(m.GetRows(), rows);
	EXPECT_EQ(m.GetCols(), cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
		EXPECT_EQ(m(i, j), 0.0);
		}
	}
}

TEST(Constructors, CopyConstructor) {
	S21Matrix m(5,5);
	for (int i = 0; i < m.GetRows(); i++) {
		for (int j = 0; j < m.GetCols(); j++) {
			m(i,j) = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/100));
			// std::cout << m(i,j) << ", ";
		}
		// std::cout << std::endl;
	}
	S21Matrix n(m);
	for (int i = 0; i < n.GetRows(); i++) {
		for (int j = 0; j < n.GetCols(); j++) {
			EXPECT_EQ(n(i,j), m(i,j));
		}
	}
}

TEST(Constructors, MoveConstructor) {
	S21Matrix m(30,30);
	for (int i = 0; i < m.GetRows(); i++) {
		for (int j = 0; j < m.GetCols(); j++) {
			m(i,j) = (rand() % 100);
		}
	}
	S21Matrix n(std::move(m));
	EXPECT_EQ(m.GetRows(), n.GetRows());
	EXPECT_EQ(m.GetCols(), n.GetCols());
}

// ACCESSORS (GETTERS) AND MUTATORS (SETTERS) //

TEST(AccessorsMutators, Get) {
	S21Matrix m(12,12);
	EXPECT_EQ(m.GetRows(), 12);
	EXPECT_EQ(m.GetCols(), 12);
}

TEST(AccessorsMutators, RowsSetMore) {
	int old_rows = 3;
	int old_cols = 3;
	int new_rows = 5;
	S21Matrix m(old_rows, old_cols);
	double matrix[3][3] = {{1.1, 2.2, 3.3},
							{4.4, 5.5, 6.6},
							{7.7, 8.8, 9.9}};
	
	for (int i = 0; i < m.GetRows(); i++) {
		for (int j = 0; j < m.GetCols(); j++) {
			m(i,j) = matrix[i][j];
		}
	}
	// set new amount of rows
	m.SetRows(new_rows);
	// check that amount of rows has been changed (rows_ variable)
	EXPECT_EQ(m.GetRows(), new_rows);
	// check that old values kept in place
	for (int i = 0; i < old_rows; i++) {
		for (int j = 0; j < old_cols; j++) {
			EXPECT_EQ(m(i,j), matrix[i][j]);
		}
	}
	// check that new cells are filled with 0.0
	for (int i = old_rows; i < new_rows; i++) {
		for (int j = 0; j < old_cols; j++) {
			EXPECT_EQ(m(i,j), 0.0);
		}
	}
}

TEST(AccessorsMutators, RowsSetLess) {
	int old_rows = 3;
	int old_cols = 3;
	int new_rows = 2;
	S21Matrix m(old_rows, old_cols);
	double matrix[3][3] = {{1.11, 2.22, 3.33},
							{4.44, 5.55, 6.66},
							{7.77, 8.88, 9.99}};
	
	for (int i = 0; i < m.GetRows(); i++) {
		for (int j = 0; j < m.GetCols(); j++) {
			m(i,j) = matrix[i][j];
		}
	}
	// set new amount of rows
	m.SetRows(new_rows);
	// chech that amount of rows has been changed (rows_ variable)
	EXPECT_EQ(m.GetRows(), new_rows);
	// check that old values kept in place
	for (int i = 0; i < new_rows; i++) {
		for (int j = 0; j < old_cols; j++) {
			EXPECT_EQ(m(i,j), matrix[i][j]);
		}
	}
}

TEST(AccessorsMutators, RowsSetSame) {
	int old_rows = 3;
	int old_cols = 3;
	int new_rows = old_rows;
	S21Matrix m(old_rows, old_cols);

	S21Matrix n(m);
	n.SetRows(new_rows);
	EXPECT_EQ(n.GetRows(), old_rows);
	for (int i = 0; i < new_rows; i++) {
		for (int j = 0; j < new_rows; j++) {
			EXPECT_EQ(m(i,j), n(i,j));
		}
	}
}

TEST(AccessorsMutators, ColsSetMore) {
	int old_rows = 3;
	int old_cols = 3;
	int new_cols = 5;
	S21Matrix m(old_rows, old_cols);
	double matrix[3][3] = {{1.1, 2.2, 3.3},
							{4.4, 5.5, 6.6},
							{7.7, 8.8, 9.9}};
	
	for (int i = 0; i < m.GetRows(); i++) {
		for (int j = 0; j < m.GetCols(); j++) {
			m(i,j) = matrix[i][j];
		}
	}
	// set new amount of cols
	m.SetCols(new_cols);
	// check that amount of cols has been changed (cols_ variable)
	EXPECT_EQ(m.GetCols(), new_cols);
	// check that old values kept in place
	for (int i = 0; i < old_rows; i++) {
		for (int j = 0; j < old_cols; j++) {
			EXPECT_EQ(m(i,j), matrix[i][j]);
		}
	}
	// check that new cells are filled with 0.0
	for (int i = 0; i < old_rows; i++) {
		for (int j = old_cols; j < new_cols; j++) {
			EXPECT_EQ(m(i,j), 0.0);
		}
	}
}

TEST(AccessorsMutators, ColsSetLess) {
	int old_rows = 3;
	int old_cols = 3;
	int new_cols = 2;
	S21Matrix m(old_rows, old_cols);
	double matrix[3][3] = {{1.11, 2.22, 3.33},
							{4.44, 5.55, 6.66},
							{7.77, 8.88, 9.99}};
	
	for (int i = 0; i < m.GetRows(); i++) {
		for (int j = 0; j < m.GetCols(); j++) {
			m(i,j) = matrix[i][j];
		}
	}
	// set new amount of cols
	m.SetCols(new_cols);
	// chech that amount of cols has been changed (cols_ variable)
	EXPECT_EQ(m.GetCols(), new_cols);
	// check that old values kept in place
	for (int i = 0; i < old_rows; i++) {
		for (int j = 0; j < new_cols; j++) {
			EXPECT_EQ(m(i,j), matrix[i][j]);
		}
	}
}

TEST(AccessorsMutators, ColsSetSame) {
	int old_rows = 3;
	int old_cols = 3;
	int new_cols = old_cols;
	S21Matrix m(old_rows, old_cols);
	double matrix[3][3] = {{1.11, 2.22, 3.33},
							{4.44, 5.55, 6.66},
							{7.77, 8.88, 9.99}};

	S21Matrix n(m);
	n.SetCols(new_cols);
	EXPECT_EQ(n.GetRows(), old_cols);
	for (int i = 0; i < m.GetRows(); i++) {
		for (int j = 0; j < m.GetCols(); j++) {
			EXPECT_EQ(m(i,j), n(i,j));
		}
	}
}

TEST (AccessorsMutators, RowsSetWrong) {
	S21Matrix m(3,3);
	EXPECT_THROW(m.SetRows(0), std::out_of_range);
	EXPECT_THROW(m.SetRows(-115), std::out_of_range);
}

TEST (AccessorsMutators, ColsSetWrong) {
	S21Matrix m(3,3);
	EXPECT_THROW(m.SetCols(0), std::out_of_range);
	EXPECT_THROW(m.SetCols(-115), std::out_of_range);
}

TEST(MemberFunctions, EqMutrixEqual) {
	double matrix[4][4] = {{0.1, 4.12, 3.128, 5.87},
							{8.12, 4.59, 2.91, 3.28},
							{4.22, 3.82, 67.12, 192.233},
							{1.123, 233.01, 6879.12, 2.07}};
	S21Matrix a(4,4);
	S21Matrix b(4,4);
	for (int i = 0; i < a.GetRows(); i++) {
		for (int j = 0; j < a.GetCols(); j++) {
			a(i,j) = matrix[i][j];
		}
	}
	for (int i = 0; i < b.GetRows(); i++) {
		for (int j = 0; j < b.GetCols(); j++) {
			b(i,j) = matrix[i][j];
		}
	}
	EXPECT_TRUE(a.EqMatrix(b));
}

TEST(MemberFunctions, EqMutrixUnequal) {
	double matrix[4][4] = {{0.1, 4.12, 3.128, 5.87},
							{8.12, 4.59, 2.91, 3.28},
							{4.22, 3.82, 67.12, 192.233},
							{1.123, 233.01, 6879.12, 2.07}};
	S21Matrix a(4,4);
	S21Matrix b(4,4);
	S21Matrix c(4,4);
	S21Matrix d(3,3);
	for (int i = 0; i < a.GetRows(); i++) {
		for (int j = 0; j < a.GetCols(); j++) {
			a(i,j) = matrix[i][j];
		}
	}
	
	EXPECT_FALSE(a.EqMatrix(b)); //unequal by values
	EXPECT_FALSE(c.EqMatrix(d)); // unequal be amount of rows or cols
}

// MEMBER FUNCTIONS //

TEST(MemberFunctions, SumMatrix) {
	double matrix[4][4] = {{0.1, 4.12, 3.128, 5.87},
							{8.12, 4.59, 2.91, 3.28},
							{4.22, 3.82, 67.12, 192.233},
							{1.123, 233.01, 6879.12, 2.07}};
	double sum_matrix[4][4];
	S21Matrix a(4,4);
	S21Matrix b(4,4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a(i,j) = matrix[i][j];
			b(i,j) = matrix[i][j];
			sum_matrix[i][j] = matrix[i][j] * 2;
		}
	}
	a.SumMatrix(b);
	for (int i = 0; i < a.GetRows(); i++) {
		for (int j = 0; j < a.GetCols(); j++) {
			EXPECT_EQ(a(i,j), sum_matrix[i][j]);
		}
	}
}

TEST(MemberFunctions, SumMatrixThrowDiffSize) {
	S21Matrix a(4,3);
	S21Matrix b(3,4);
	EXPECT_ANY_THROW(a.SumMatrix(b)); 
}

TEST(MemberFunctions, SuBMatrix) {
	double matrix[4][4] = {{0.1, 4.12, 3.128, 5.87},
							{8.12, 4.59, 2.91, 3.28},
							{4.22, 3.82, 67.12, 192.233},
							{1.123, 233.01, 6879.12, 2.07}};
	S21Matrix a(4,4);
	S21Matrix b(4,4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a(i,j) = matrix[i][j];
			b(i,j) = matrix[i][j];
		}
	}
	a.SubMatrix(b);
	for (int i = 0; i < a.GetRows(); i++) {
		for (int j = 0; j < a.GetCols(); j++) {
			EXPECT_EQ(a(i,j), 0.0);
		}
	}
}

TEST(MemberFunctions, SubMatrixThrowDiffSize) {
	S21Matrix a(4,3);
	S21Matrix b(3,4);
	EXPECT_ANY_THROW(a.SubMatrix(b)); 
}

TEST(MemberFunctions, MulNumber) {
	double matrix[4][4] = {{0.1, 4.12, 3.128, 5.87},
							{8.12, 4.59, 2.91, 3.28},
							{4.22, 3.82, 67.12, 192.233},
							{1.123, 233.01, 6879.12, 2.07}};
	double multiplier = 2.1;
	double mul_matrix[4][4];
	S21Matrix a(4,4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a(i,j) = matrix[i][j];
			mul_matrix[i][j] = matrix[i][j] * multiplier;
		}
	}
	a.MulNumber(multiplier);
	for (int i = 0; i < a.GetRows(); i++) {
		for (int j = 0; j < a.GetCols(); j++) {
			EXPECT_EQ(a(i,j), mul_matrix[i][j]);
		}
	}
}

int main(int argc, char **argv) {

	S21Matrix a(3,2);
	S21Matrix b(2,3);
	S21Matrix c;

	for (int i = 0; i < a.GetRows(); i++) {
		for (int j = 0; j < a.GetCols(); j++) {
			a(i,j) = (rand() % 100);
			std::cout << a(i,j) << ", ";
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < b.GetRows(); i++) {
		for (int j = 0; j < b.GetCols(); j++) {
			b(i,j) = (rand() % 100);
			std::cout << b(i,j) << ", ";
		}
		std::cout << std::endl;
	}
	a.MulMatrix(b);
	for (int i = 0; i < a.GetRows(); i++) {
		for (int j = 0; j < a.GetCols(); j++) {
			std::cout << a(i,j) << ", ";
		}
		std::cout << std::endl;
	}
	// testing::InitGoogleTest(&argc, argv);

	// return (RUN_ALL_TESTS());
}