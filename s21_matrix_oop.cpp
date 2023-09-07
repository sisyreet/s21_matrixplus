#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {

}

S21Matrix::S21Matrix(int rows, int cols) {
    allocateMatrix(&matrix_, rows_, cols_);
}

S21Matrix::S21Matrix(const S21Matrix& other) {

}

S21Matrix::S21Matrix(S21Matrix&& other) {

}

S21Matrix::~S21Matrix() {
    
}

void S21Matrix::allocateMatrix(double*** matrix, int rows, int cols) {
  
  if (rows < 1 || cols < 1)
    throw std::invalid_argument("matrix must be minimum 1x1");

  *matrix = new double*[rows]();

  for (int i = 0; i < rows; i++)
    *matrix[i] = new double[cols]();
}