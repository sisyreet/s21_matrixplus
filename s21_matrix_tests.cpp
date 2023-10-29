#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

// CONSTRUCTORS //

TEST(Constructors, DefaultConstructor) {
  S21Matrix m;
  EXPECT_EQ(m.GetCols(), 1);
  EXPECT_EQ(m.GetRows(), 1);
  EXPECT_EQ(m(0, 0), 0.0);
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
  S21Matrix m(5, 5);
  for (int i = 0; i < m.GetRows(); i++) {
    for (int j = 0; j < m.GetCols(); j++) {
      m(i, j) =
          static_cast<double>(rand()) / (static_cast<double>(RAND_MAX / 100));
    }
  }
  S21Matrix n(m);
  for (int i = 0; i < n.GetRows(); i++) {
    for (int j = 0; j < n.GetCols(); j++) {
      EXPECT_EQ(n(i, j), m(i, j));
    }
  }
}

TEST(Constructors, MoveConstructor) {
  S21Matrix m(30, 30);
  for (int i = 0; i < m.GetRows(); i++) {
    for (int j = 0; j < m.GetCols(); j++) {
      m(i, j) = (rand() % 100);
    }
  }
  S21Matrix n(std::move(m));
	EXPECT_EQ(n.GetRows(), 30);
  EXPECT_EQ(n.GetCols(), 30);
  EXPECT_EQ(m.GetRows(), 0);
  EXPECT_EQ(m.GetCols(), 0);
}

// ACCESSORS (GETTERS) AND MUTATORS (SETTERS) //

TEST(AccessorsMutators, Get) {
  S21Matrix m(12, 12);
  EXPECT_EQ(m.GetRows(), 12);
  EXPECT_EQ(m.GetCols(), 12);
}

TEST(AccessorsMutators, RowsSetMore) {
  int old_rows = 3;
  int old_cols = 3;
  int new_rows = 5;
  S21Matrix m(old_rows, old_cols);
  double matrix[3][3] = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}, {7.7, 8.8, 9.9}};

  for (int i = 0; i < m.GetRows(); i++) {
    for (int j = 0; j < m.GetCols(); j++) {
      m(i, j) = matrix[i][j];
    }
  }
  // set new amount of rows
  m.SetRows(new_rows);
  // check that amount of rows has been changed (rows_ variable)
  EXPECT_EQ(m.GetRows(), new_rows);
  // check that old values kept in place
  for (int i = 0; i < old_rows; i++) {
    for (int j = 0; j < old_cols; j++) {
      EXPECT_EQ(m(i, j), matrix[i][j]);
    }
  }
  // check that new cells are filled with 0.0
  for (int i = old_rows; i < new_rows; i++) {
    for (int j = 0; j < old_cols; j++) {
      EXPECT_EQ(m(i, j), 0.0);
    }
  }
}

TEST(AccessorsMutators, RowsSetLess) {
  int old_rows = 3;
  int old_cols = 3;
  int new_rows = 2;
  S21Matrix m(old_rows, old_cols);
  double matrix[3][3] = {
      {1.11, 2.22, 3.33}, {4.44, 5.55, 6.66}, {7.77, 8.88, 9.99}};

  for (int i = 0; i < m.GetRows(); i++) {
    for (int j = 0; j < m.GetCols(); j++) {
      m(i, j) = matrix[i][j];
    }
  }
  // set new amount of rows
  m.SetRows(new_rows);
  // chech that amount of rows has been changed (rows_ variable)
  EXPECT_EQ(m.GetRows(), new_rows);
  // check that old values kept in place
  for (int i = 0; i < new_rows; i++) {
    for (int j = 0; j < old_cols; j++) {
      EXPECT_EQ(m(i, j), matrix[i][j]);
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
      EXPECT_EQ(m(i, j), n(i, j));
    }
  }
}

TEST(AccessorsMutators, ColsSetMore) {
  int old_rows = 3;
  int old_cols = 3;
  int new_cols = 5;
  S21Matrix m(old_rows, old_cols);
  double matrix[3][3] = {{1.1, 2.2, 3.3}, {4.4, 5.5, 6.6}, {7.7, 8.8, 9.9}};

  for (int i = 0; i < m.GetRows(); i++) {
    for (int j = 0; j < m.GetCols(); j++) {
      m(i, j) = matrix[i][j];
    }
  }
  // set new amount of cols
  m.SetCols(new_cols);
  // check that amount of cols has been changed (cols_ variable)
  EXPECT_EQ(m.GetCols(), new_cols);
  // check that old values kept in place
  for (int i = 0; i < old_rows; i++) {
    for (int j = 0; j < old_cols; j++) {
      EXPECT_EQ(m(i, j), matrix[i][j]);
    }
  }
  // check that new cells are filled with 0.0
  for (int i = 0; i < old_rows; i++) {
    for (int j = old_cols; j < new_cols; j++) {
      EXPECT_EQ(m(i, j), 0.0);
    }
  }
}

TEST(AccessorsMutators, ColsSetLess) {
  int old_rows = 3;
  int old_cols = 3;
  int new_cols = 2;
  S21Matrix m(old_rows, old_cols);
  double matrix[3][3] = {
      {1.11, 2.22, 3.33}, {4.44, 5.55, 6.66}, {7.77, 8.88, 9.99}};

  for (int i = 0; i < m.GetRows(); i++) {
    for (int j = 0; j < m.GetCols(); j++) {
      m(i, j) = matrix[i][j];
    }
  }
  // set new amount of cols
  m.SetCols(new_cols);
  // chech that amount of cols has been changed (cols_ variable)
  EXPECT_EQ(m.GetCols(), new_cols);
  // check that old values kept in place
  for (int i = 0; i < old_rows; i++) {
    for (int j = 0; j < new_cols; j++) {
      EXPECT_EQ(m(i, j), matrix[i][j]);
    }
  }
}

TEST(AccessorsMutators, ColsSetSame) {
  int old_rows = 3;
  int old_cols = 3;
  int new_cols = old_cols;
  S21Matrix m(old_rows, old_cols);
  double matrix[3][3] = {
      {1.11, 2.22, 3.33}, {4.44, 5.55, 6.66}, {7.77, 8.88, 9.99}};

  S21Matrix n(m);
  n.SetCols(new_cols);
  EXPECT_EQ(n.GetRows(), old_cols);
  for (int i = 0; i < m.GetRows(); i++) {
    for (int j = 0; j < m.GetCols(); j++) {
      EXPECT_EQ(m(i, j), n(i, j));
    }
  }
}

TEST(AccessorsMutators, RowsSetWrong) {
  S21Matrix m(3, 3);
  EXPECT_THROW(m.SetRows(0), std::invalid_argument);
  EXPECT_THROW(m.SetRows(-115), std::invalid_argument);
}

TEST(AccessorsMutators, ColsSetWrong) {
  S21Matrix m(3, 3);
  EXPECT_THROW(m.SetCols(0), std::invalid_argument);
  EXPECT_THROW(m.SetCols(-115), std::invalid_argument);
}

// MEMBER FUNCTIONS //

TEST(MemberFunctions, EqMutrixEqual) {
  double matrix[4][4] = {{0.1, 4.12, 3.128, 5.87},
                         {8.12, 4.59, 2.91, 3.28},
                         {4.22, 3.82, 67.12, 192.233},
                         {1.123, 233.01, 6879.12, 2.07}};
  S21Matrix a(4, 4);
  S21Matrix b(4, 4);
  for (int i = 0; i < a.GetRows(); i++) {
    for (int j = 0; j < a.GetCols(); j++) {
      a(i, j) = matrix[i][j];
    }
  }
  for (int i = 0; i < b.GetRows(); i++) {
    for (int j = 0; j < b.GetCols(); j++) {
      b(i, j) = matrix[i][j];
    }
  }
  EXPECT_TRUE(a.EqMatrix(b));
}

TEST(MemberFunctions, EqMutrixUnequal) {
  double matrix[4][4] = {{0.1, 4.12, 3.128, 5.87},
                         {8.12, 4.59, 2.91, 3.28},
                         {4.22, 3.82, 67.12, 192.233},
                         {1.123, 233.01, 6879.12, 2.07}};
  S21Matrix a(4, 4);
  S21Matrix b(4, 4);
  S21Matrix c(4, 4);
  S21Matrix d(3, 3);
  for (int i = 0; i < a.GetRows(); i++) {
    for (int j = 0; j < a.GetCols(); j++) {
      a(i, j) = matrix[i][j];
    }
  }

  EXPECT_FALSE(a.EqMatrix(b));  // unequal by values
  EXPECT_FALSE(c.EqMatrix(d));  // unequal be amount of rows or cols
}

TEST(MemberFunctions, SumMatrix) {
  double matrix[4][4] = {{0.1, 4.12, 3.128, 5.87},
                         {8.12, 4.59, 2.91, 3.28},
                         {4.22, 3.82, 67.12, 192.233},
                         {1.123, 233.01, 6879.12, 2.07}};
  double sum_matrix[4][4];
  S21Matrix a(4, 4);
  S21Matrix b(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      a(i, j) = matrix[i][j];
      b(i, j) = matrix[i][j];
      sum_matrix[i][j] = matrix[i][j] * 2;
    }
  }
  a.SumMatrix(b);
  for (int i = 0; i < a.GetRows(); i++) {
    for (int j = 0; j < a.GetCols(); j++) {
      EXPECT_EQ(a(i, j), sum_matrix[i][j]);
    }
  }
}

TEST(MemberFunctions, SumMatrixThrowDiffSize) {
  S21Matrix a(4, 3);
  S21Matrix b(3, 4);
  EXPECT_ANY_THROW(a.SumMatrix(b));
}

TEST(MemberFunctions, SuBMatrix) {
  double matrix[4][4] = {{0.1, 4.12, 3.128, 5.87},
                         {8.12, 4.59, 2.91, 3.28},
                         {4.22, 3.82, 67.12, 192.233},
                         {1.123, 233.01, 6879.12, 2.07}};
  S21Matrix a(4, 4);
  S21Matrix b(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      a(i, j) = matrix[i][j];
      b(i, j) = matrix[i][j];
    }
  }
  a.SubMatrix(b);
  for (int i = 0; i < a.GetRows(); i++) {
    for (int j = 0; j < a.GetCols(); j++) {
      EXPECT_EQ(a(i, j), 0.0);
    }
  }
}

TEST(MemberFunctions, SubMatrixThrowDiffSize) {
  S21Matrix a(4, 3);
  S21Matrix b(3, 4);
  EXPECT_ANY_THROW(a.SubMatrix(b));
}

TEST(MemberFunctions, MulNumber) {
  double matrix[4][4] = {{0.1, 4.12, 3.128, 5.87},
                         {8.12, 4.59, 2.91, 3.28},
                         {4.22, 3.82, 67.12, 192.233},
                         {1.123, 233.01, 6879.12, 2.07}};
  double multiplier = 2.1;
  double mul_matrix[4][4];
  S21Matrix a(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      a(i, j) = matrix[i][j];
      mul_matrix[i][j] = matrix[i][j] * multiplier;
    }
  }
  a.MulNumber(multiplier);
  for (int i = 0; i < a.GetRows(); i++) {
    for (int j = 0; j < a.GetCols(); j++) {
      EXPECT_EQ(a(i, j), mul_matrix[i][j]);
    }
  }
}

TEST(MemberFunctions, MulMatrixSquare) {
  double a[4][4] = {{0.1, 4.1, 3.1, 5.8},
                    {8.1, 4.5, 2.9, 3.2},
                    {4.2, 3.8, 7.1, 1.2},
                    {1.1, 2.0, 9.1, 2.0}};
  double b[4][4] = {{0.2, 3.1, 2.1, 5.7},
                    {8.1, 4.0, 2.1, 3.8},
                    {1.7, 5.6, 6.1, 7.7},
                    {1.3, 5.1, 4.2, 5.7}};
  double c[4][4] = {{46.04, 63.65, 52.09, 73.08},
                    {47.16, 75.67, 57.59, 103.84},
                    {45.25, 74.1, 65.15, 99.89},
                    {34.49, 72.57, 70.42, 95.34}};
  S21Matrix ma(4, 4);
  S21Matrix mb(4, 4);
  S21Matrix mc(4, 4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ma(i, j) = a[i][j];
      mb(i, j) = b[i][j];
      mc(i, j) = c[i][j];
    }
  }
  ma.MulMatrix(mb);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      EXPECT_DOUBLE_EQ(ma(i, j), mc(i, j));
    }
  }
}

TEST(MemberFunctions, MulMatrixRectangle) {
  double a[3][4] = {
      {0.1, 4.1, 3.1, 5.8}, {8.1, 4.5, 2.9, 3.2}, {4.2, 3.8, 7.1, 1.2}};
  double b[4][3] = {
      {0.2, 3.1, 2.1}, {8.1, 4.0, 2.1}, {1.7, 5.6, 6.1}, {1.3, 5.1, 4.2}};
  double c[4][4] = {
      {46.04, 63.65, 52.09}, {47.16, 75.67, 57.59}, {45.25, 74.1, 65.15}};
  S21Matrix ma(3, 4);
  S21Matrix mb(4, 3);
  S21Matrix mc(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      ma(i, j) = a[i][j];
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      mb(i, j) = b[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mc(i, j) = c[i][j];
    }
  }
  ma.MulMatrix(mb);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      EXPECT_DOUBLE_EQ(ma(i, j), mc(i, j));
    }
  }
}

TEST(MemberFunctions, MulMatrixWrongSize) {
  S21Matrix a(3, 3);
  S21Matrix b(4, 4);
  S21Matrix c(4, 5);
  S21Matrix d(4, 5);
  EXPECT_ANY_THROW(a.MulMatrix(b));
  EXPECT_ANY_THROW(c.MulMatrix(d));
}

TEST(MemberFunctions, Transpose) {
  double a[3][4] = {
      {0.1, 4.1, 3.1, 5.8}, {8.1, 4.5, 2.9, 3.2}, {4.2, 3.8, 7.1, 1.2}};
  double at[4][3] = {
      {0.1, 8.1, 4.2}, {4.1, 4.5, 3.8}, {3.1, 2.9, 7.1}, {5.8, 3.2, 1.2}};
  S21Matrix ma(3, 4);
  S21Matrix mt(4, 3);
  for (int i = 0; i < ma.GetRows(); i++) {
    for (int j = 0; j < ma.GetCols(); j++) {
      ma(i, j) = a[i][j];
    }
  }
  for (int i = 0; i < mt.GetRows(); i++) {
    for (int j = 0; j < mt.GetCols(); j++) {
      mt(i, j) = at[i][j];
    }
  }
  S21Matrix mb(ma.Transpose());
  EXPECT_EQ(mb.GetRows(), ma.GetCols());
  EXPECT_EQ(mb.GetCols(), ma.GetRows());
  for (int i = 0; i < mb.GetRows(); i++) {
    for (int j = 0; j < mb.GetCols(); j++) {
      EXPECT_DOUBLE_EQ(mb(i, j), mt(i, j));
    }
  }
}

TEST(MemberFunctions, CalcComplementsMatrix1x1) {
  S21Matrix a(1, 1);
  S21Matrix b(1, 1);

  a(0, 0) = 0.0;
  S21Matrix comp1 = a.CalcComplements();
  EXPECT_EQ(comp1.GetRows(), 1);
  EXPECT_EQ(comp1.GetCols(), 1);
  EXPECT_EQ(comp1(0, 0), 1.0);

  b(0, 0) = 100.0;
  S21Matrix comp2 = b.CalcComplements();
  EXPECT_EQ(comp2.GetRows(), 1);
  EXPECT_EQ(comp2.GetCols(), 1);
  EXPECT_EQ(comp2(0, 0), 1.0);
}

TEST(Memberfunctions, CalcComplementsMatrix2x2) {
  double a[2][2] = {{-2.1, 3.6}, {4.0, 7.9}};
  double ca[2][2] = {{7.9, -4.0}, {-3.6, -2.1}};
  S21Matrix ma(2, 2);
  S21Matrix mc(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ma(i, j) = a[i][j];
      mc(i, j) = ca[i][j];
    }
  }
  S21Matrix mb(ma.CalcComplements());
  EXPECT_TRUE(mc == mb);
}

TEST(Memberfunctions, CalcComplementsMatrix3x3) {
  double a[3][3] = {{-2.1, 3.6, 4.9}, {4.0, 7.9, -8.1}, {1.6, -6.2, 3.0}};
  double ca[3][3] = {{-26.52, -24.96, -37.44},
                     {-41.18, -14.14, -7.26},
                     {-67.87, 2.59, -30.99}};
  S21Matrix ma(3, 3);
  S21Matrix mc(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ma(i, j) = a[i][j];
      mc(i, j) = ca[i][j];
    }
  }
  S21Matrix mb(ma.CalcComplements());
  EXPECT_TRUE(mc == mb);
}

TEST(Memberfunctions, CalcComplementsMatrix5x5) {
  double a[5][5] = {{-2.1, 3.6, 4.9, -5.1, 1.3},
                    {4.0, 7.9, -8.1, -2.6, 6.3},
                    {1.6, -6.2, 3.0, 5.1, -3.4},
                    {6.1, 4.2, -4.1, 7.9, 1.1},
                    {8.6, -11.4, 23.1, 6.1, -1.7}};
  double ca[5][5] = {{-3903.14, -1690.8, 238.551, 3171.31, 6213.9},
                     {-2927.92, -356.171, 544.23, 2289.06, 3185.44},
                     {-7164.4, -1632.39, 1158.25, 5555.95, 10377.9},
                     {507.241, -438.966, -216.117, -825.853, -390.301},
                     {821.738, 367.851, -257.076, -738.176, -1618.18}};
  S21Matrix ma(5, 5);
  S21Matrix mc(5, 5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      ma(i, j) = a[i][j];
      mc(i, j) = ca[i][j];
    }
  }
  S21Matrix mb(ma.CalcComplements());
  EXPECT_TRUE(mc == mb);
}

TEST(Memberfunctions, CalcComplementsMatrixWrongSize) {
  double a[4][5] = {{-2.1, 3.6, 4.9, -5.1, 1.3},
                    {4.0, 7.9, -8.1, -2.6, 6.3},
                    {1.6, -6.2, 3.0, 5.1, -3.4},
                    {6.1, 4.2, -4.1, 7.9, 1.1}};
  double ca[3][3] = {{-26.52, -24.96, -37.44},
                     {-41.18, -14.14, -7.26},
                     {-67.87, 2.59, -30.99}};
  S21Matrix ma(4, 5);
  S21Matrix mc(3, 3);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) {
      ma(i, j) = a[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mc(i, j) = ca[i][j];
    }
  }
  EXPECT_THROW(S21Matrix mb(ma.CalcComplements()), std::invalid_argument);
}

TEST(Memberfunctions, DeterminantMatrix1x1) {
  double a[1][1] = {12.6};
  S21Matrix ma(1, 1);
  ma(0, 0) = a[0][0];
  EXPECT_EQ(ma.Determinant(), a[0][0]);
}

TEST(Memberfunctions, DeterminantMatrix2x2) {
  double a[2][2] = {{-2.1, 3.6}, {4.0, 7.9}};
  double det = 0.0;
  S21Matrix m(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      m(i, j) = a[i][j];
    }
  }
  det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
  EXPECT_EQ(det, m.Determinant());
}

TEST(Memberfunctions, DeterminantMatrix5x5) {
  double a[5][5] = {{-2.1, 3.6, 4.9, -5.1, 1.3},
                    {4.0, 7.9, -8.1, -2.6, 6.3},
                    {1.6, -6.2, 3.0, 5.1, -3.4},
                    {6.1, 4.2, -4.1, 7.9, 1.1},
                    {8.6, -11.4, 23.1, 6.1, -1.7}};
  double det = 0.0;
  S21Matrix m(5, 5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      m(i, j) = a[i][j];
    }
  }
  det = -4816.97616;
  EXPECT_NEAR(det, m.Determinant(), 1e-08);
}

TEST(Memberfunctions, DeterminantWrongSize) {
  S21Matrix m(4, 5);
  EXPECT_THROW(m.Determinant(), std::invalid_argument);
}

TEST(Memberfunctions, InverseMatrix1x1) {
  S21Matrix a(1, 1);
  S21Matrix bi(1, 1);
  a(0, 0) = 109.12;
  bi(0, 0) = 0.0091642;
  EXPECT_TRUE(bi == a.InverseMatrix());
}

TEST(Memberfunctions, InverseMatrix3x3) {
  double a[3][3] = {{-2.1, 3.6, 4.9}, {4.0, 7.9, -8.1}, {1.6, -6.2, 3.0}};
  double ai[3][3] = {{0.121863, 0.189228, 0.311873},
                     {0.114695, 0.064975, -0.011901},
                     {0.172043, 0.033360, 0.142404}};
  S21Matrix ma(3, 3);
  S21Matrix mai(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ma(i, j) = a[i][j];
      mai(i, j) = ai[i][j];
    }
  }
  S21Matrix mb(ma.InverseMatrix());
  EXPECT_TRUE(mb == mai);
}

TEST(Memberfunctions, InverseMatrixWrongSize) {
  double a[3][3] = {{0.0, 3.6, 4.9}, {0.0, 7.9, -8.1}, {0.0, -6.2, 3.0}};
  S21Matrix ma(3, 3);
  S21Matrix mb(5, 4);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ma(i, j) = a[i][j];
    }
  }
  EXPECT_THROW(ma.InverseMatrix(), std::invalid_argument);  // det = 0.0
  EXPECT_THROW(mb.InverseMatrix(), std::invalid_argument);  // not square
}

TEST(OperatorOverloads, OperatorPlus) {
  double a[2][2] = {{-2.1, 3.6}, {4.0, 7.9}};
  double b[2][2] = {{7.9, -4.0}, {-3.6, -2.1}};
  double sum[2][2] = {0.0};
  S21Matrix ma(2, 2);
  S21Matrix mb(2, 2);
  S21Matrix msum(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      sum[i][j] = a[i][j] + b[i][j];
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ma(i, j) = a[i][j];
      mb(i, j) = b[i][j];
      msum(i, j) = sum[i][j];
    }
  }
  EXPECT_TRUE(msum == (ma + mb));
}

TEST(OperatorOverloads, OperatorPlusDiffSize) {
  S21Matrix ma(6, 6);
  S21Matrix mb(5, 6);
  S21Matrix mc(6, 7);

  EXPECT_THROW(ma + mb, std::invalid_argument);
  EXPECT_THROW(ma + mc, std::invalid_argument);
}

TEST(OperatorOverloads, OperatorMinus) {
  double a[12][10] = {0.0};
  double b[12][10] = {0.0};
  double sub[12][10] = {0.0};
  S21Matrix ma(12, 10);
  S21Matrix mb(12, 10);
  S21Matrix msub(12, 10);
  for (int i = 0; i < ma.GetRows(); i++) {
    for (int j = 0; j < ma.GetCols(); j++) {
      a[i][j] = i * 1.5 + j * 0.5;
      b[i][j] = j * 2.0 + i * 1.7;
      msub(i, j) = a[i][j] - b[i][j];
      ma(i, j) = i * 1.5 + j * 0.5;
      mb(i, j) = j * 2.0 + i * 1.7;
    }
  }
  EXPECT_TRUE(msub == (ma - mb));
}

TEST(OperatorOverloads, OperatorMinusDiffSize) {
  S21Matrix ma(12, 10);
  S21Matrix mb(12, 11);
  S21Matrix mc(11, 10);

  EXPECT_THROW(ma - mb, std::invalid_argument);
  EXPECT_THROW(ma - mc, std::invalid_argument);
}

TEST(OperatorOverloads, OperatorMultiplyingSquare) {
  double a[3][4] = {
      {0.1, 4.1, 3.1, 5.8}, {8.1, 4.5, 2.9, 3.2}, {4.2, 3.8, 7.1, 1.2}};
  double b[4][3] = {
      {0.2, 3.1, 2.1}, {8.1, 4.0, 2.1}, {1.7, 5.6, 6.1}, {1.3, 5.1, 4.2}};
  double c[4][4] = {
      {46.04, 63.65, 52.09}, {47.16, 75.67, 57.59}, {45.25, 74.1, 65.15}};
  S21Matrix ma(3, 4);
  S21Matrix mb(4, 3);
  S21Matrix mc(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      ma(i, j) = a[i][j];
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      mb(i, j) = b[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mc(i, j) = c[i][j];
    }
  }
  EXPECT_TRUE(mc == (ma * mb));
}

TEST(OperatorOverloads, OperatorMultiplyingRectangle) {
  double a[3][4] = {
      {0.1, 4.1, 3.1, 5.8}, {8.1, 4.5, 2.9, 3.2}, {4.2, 3.8, 7.1, 1.2}};
  double b[4][3] = {
      {0.2, 3.1, 2.1}, {8.1, 4.0, 2.1}, {1.7, 5.6, 6.1}, {1.3, 5.1, 4.2}};
  double c[4][4] = {
      {46.04, 63.65, 52.09}, {47.16, 75.67, 57.59}, {45.25, 74.1, 65.15}};
  S21Matrix ma(3, 4);
  S21Matrix mb(4, 3);
  S21Matrix mc(3, 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      ma(i, j) = a[i][j];
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      mb(i, j) = b[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mc(i, j) = c[i][j];
    }
  }
  EXPECT_TRUE(mc == (ma * mb));
}

TEST(OperatorOverloads, OperatorMultiplyingWrongSize) {
  S21Matrix ma(3, 4);
  S21Matrix mb(2, 4);
  S21Matrix mc(5, 3);

  EXPECT_THROW(ma * mb, std::invalid_argument);
  EXPECT_THROW(ma * mc, std::invalid_argument);
}

TEST(OperatorOverloads, OperatorEquals) {
  S21Matrix ma(12, 12);
  S21Matrix mb(12, 12);
  EXPECT_TRUE(ma == mb);
  EXPECT_TRUE(mb == ma);

  for (int i = 0; i < ma.GetRows(); i++) {
    for (int j = 0; j < ma.GetCols(); j++) {
      ma(i, j) = i * 1.4 + j * 2.23;
      mb(i, j) = i * 1.4 + j * 2.23;
    }
  }
  EXPECT_TRUE(ma == mb);
  EXPECT_TRUE(mb == ma);
}

TEST(OperatorOverloads, OperatorEqualsDiffSize) {
  S21Matrix ma(12, 11);
  S21Matrix mb(12, 12);
  EXPECT_FALSE(ma == mb);
  EXPECT_FALSE(mb == ma);
}

TEST(OperatorOverloads, OperatorEqualsFalse) {
  S21Matrix ma(12, 12);
  S21Matrix mb(12, 12);
  EXPECT_TRUE(ma == mb);
  EXPECT_TRUE(mb == ma);

  for (int i = 0; i < ma.GetRows(); i++) {
    for (int j = 0; j < ma.GetCols(); j++) {
      ma(i, j) = i * 1.3 + j * 2.21;
      mb(i, j) = i * 1.4 + j * 2.23;
    }
  }
  EXPECT_FALSE(ma == mb);
  EXPECT_FALSE(mb == ma);
}

TEST(OperatorOverloads, OperatorAssignmentSameSize) {
  S21Matrix ma(12, 12);
  S21Matrix mb(12, 12);
  EXPECT_TRUE(ma == mb);
  EXPECT_TRUE(mb == ma);

  for (int i = 0; i < ma.GetRows(); i++) {
    for (int j = 0; j < ma.GetCols(); j++) {
      ma(i, j) = i * 1.3 + j * 2.21;
      mb(i, j) = i * 1.4 + j * 2.23;
    }
  }
  EXPECT_FALSE(ma == mb);
  EXPECT_FALSE(mb == ma);
  ma = mb;
  EXPECT_TRUE(ma == mb);
}

TEST(OperatorOverloads, OperatorAssignmentDiffSize) {
  S21Matrix ma(15, 22);
  S21Matrix mb(71, 13);

  for (int i = 0; i < ma.GetRows(); i++) {
    for (int j = 0; j < ma.GetCols(); j++) {
      ma(i, j) = i * 1.3 + j * 2.21;
    }
  }
  for (int i = 0; i < mb.GetRows(); i++) {
    for (int j = 0; j < mb.GetCols(); j++) {
      mb(i, j) = i * 1.4 + j * 2.23;
    }
  }
  mb = ma;
  EXPECT_TRUE(ma == mb);
}

TEST(OperatorOverloads, OperatorSelfAssignment) {
  S21Matrix ma(12, 12);

  for (int i = 0; i < ma.GetRows(); i++) {
    for (int j = 0; j < ma.GetCols(); j++) {
      ma(i, j) = i * 1.3 + j * 2.21;
    }
  }
  EXPECT_TRUE(ma == (ma = ma));
}

TEST(OperatorOverloads, OperatorPlusEquals) {
  double a[2][2] = {{-2.1, 3.6}, {4.0, 7.9}};
  double b[2][2] = {{7.9, -4.0}, {-3.6, -2.1}};
  double sum[2][2] = {0.0};
  S21Matrix ma(2, 2);
  S21Matrix mb(2, 2);
  S21Matrix msum(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      sum[i][j] = a[i][j] + b[i][j];
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ma(i, j) = a[i][j];
      mb(i, j) = b[i][j];
      msum(i, j) = sum[i][j];
    }
  }
  EXPECT_TRUE(msum == (ma += mb));
}

TEST(OperatorOverloads, OperatorPlusEqualsDiffSize) {
  S21Matrix ma(6, 6);
  S21Matrix mb(5, 6);
  S21Matrix mc(6, 7);

  EXPECT_THROW(ma += mb, std::invalid_argument);
  EXPECT_THROW(ma += mc, std::invalid_argument);
}

TEST(OperatorOverloads, OperatorMinusEquals) {
  double a[12][10] = {0.0};
  double b[12][10] = {0.0};
  double sub[12][10] = {0.0};
  S21Matrix ma(12, 10);
  S21Matrix mb(12, 10);
  S21Matrix msub(12, 10);
  for (int i = 0; i < ma.GetRows(); i++) {
    for (int j = 0; j < ma.GetCols(); j++) {
      a[i][j] = i * 1.5 + j * 0.5;
      b[i][j] = j * 2.0 + i * 1.7;
      msub(i, j) = a[i][j] - b[i][j];
      ma(i, j) = i * 1.5 + j * 0.5;
      mb(i, j) = j * 2.0 + i * 1.7;
    }
  }
  EXPECT_TRUE(msub == (ma -= mb));
}

TEST(OperatorOverloads, OperatorMinusEqualsDiffSize) {
  S21Matrix ma(12, 10);
  S21Matrix mb(12, 11);
  S21Matrix mc(11, 10);

  EXPECT_THROW(ma -= mb, std::invalid_argument);
  EXPECT_THROW(ma -= mc, std::invalid_argument);
}

TEST(OperatorOverloads, OperatorIndex) {
  double a[3][4] = {
      {0.1, 4.1, 3.1, 5.8}, {8.1, 4.5, 2.9, 3.2}, {4.2, 3.8, 7.1, 1.2}};

  S21Matrix ma(3, 4);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      ma(i, j) = a[i][j];
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      EXPECT_EQ(ma(i, j), a[i][j]);
    }
  }
}

TEST(OperatorOverloads, OperatorIndexWrong) {
  S21Matrix m(5, 5);
  EXPECT_THROW(m(3, 5) = 1.0, std::out_of_range);
  EXPECT_THROW(m(5, 3) = 1.0, std::out_of_range);
  EXPECT_THROW(m(-1, 4) = 1.0, std::out_of_range);
  EXPECT_THROW(m(4, -4) = 1.0, std::out_of_range);
  EXPECT_THROW(m(-4, -4) = 1.0, std::out_of_range);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return (RUN_ALL_TESTS());
}