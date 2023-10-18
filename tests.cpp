#include <gtest/gtest.h>
#include "s21_matrix_oop.h"
#include <utility> // ?


TEST(MatrixConstructorDestructor, ConvertingConstructor) {
  int rows = 100;
  int cols = 87;
  S21Matrix m(rows, cols);

  EXPECT_EQ(m.GetRows(), rows);
  EXPECT_EQ(m.GetCols(), cols);

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      EXPECT_EQ(m(i, j), 0.0);
    }
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return (RUN_ALL_TESTS());
}