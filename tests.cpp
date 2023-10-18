#include <gtest/gtest.h>
#include "s21_matrix_oop.h"
// #include <utility> // ?

TEST(ab, bc) {
	S21Matrix m;
	EXPECT_EQ(m.GetRows(), 1);
	EXPECT_EQ(m.GetCols(), 1);
	EXPECT_EQ(m(0,0), 0.0);
}

TEST(MatrixConstructorDestructor, ConvertingConstructorBadRows) {
	EXPECT_THROW(S21Matrix(0, 0), std::invalid_argument);
}

TEST(MatrixConstructorDestructor, ConvertingConstructor) {
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

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return (RUN_ALL_TESTS());
}