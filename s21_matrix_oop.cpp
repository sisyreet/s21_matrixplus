#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {

}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {

  if (rows < 1 || cols < 1)
    throw std::invalid_argument("matrix must be minimum 1x1");

  matrix_ = new double*[rows]();
  for (int i = 0; i < rows; i++)
    matrix_[i] = new double[cols]();
    
    //allocateMatrix(&matrix_, rows_, cols_);
}

S21Matrix::S21Matrix(const S21Matrix& other) {

}

S21Matrix::S21Matrix(S21Matrix&& other) {

}

S21Matrix::~S21Matrix() {
  for( int i = 0 ; i < rows_; i++ )
    delete[] matrix_[i]; // delete array within matrix
  // delete actual matrix
    delete[] matrix_;
}

// getters and setter

int S21Matrix::getRows() {
  return this->rows_;
}

int S21Matrix::getCols() {
  return this->cols_;
}

void S21Matrix::setRows(int rows) {
  if (rows < 1)
    throw std::invalid_argument("rows can't be less than 1!");
  if (rows < rows_)
  {
    std::cout << rows << rows_ << std::endl;
    for (int i = rows; i != rows_; i++)
      delete[] matrix_[i];
    rows_ = rows;
  }
  if (rows > rows_)
  {
    
  }
}

void S21Matrix::setCols(int cols) {
  if (cols < 1)
    throw std::invalid_argument("cols can't be less than 1!");
  this->rows_ = cols;
}

// overloads

double &S21Matrix::operator()(int i, int j) const {
  if (i < 0 || j < 0 || i >= rows_ || j >= cols_) {
    throw std::out_of_range("Index outside the matrix");
  }
  return matrix_[i][j];
}