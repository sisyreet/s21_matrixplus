#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
	rows_ = 1;
  	cols_ = 1;
	matrix_ = new double*[rows_]();
	
	for (int i = 0; i < rows_; i++) {
		matrix_[i] = new double[cols_]();
	}
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {

	if (rows < 1 || cols < 1)
    	throw std::invalid_argument("matrix must be minimum 1x1");
	matrix_ = new double*[rows_]();
	
	for (int i = 0; i < rows_; i++) {
		matrix_[i] = new double[cols_]();
	}
}

S21Matrix::S21Matrix(const S21Matrix& other) {
	rows_ = other.rows_;
  	cols_ = other.cols_;
	matrix_ = new double*[rows_]();
	
	for (int i = 0; i < rows_; i++) {
		matrix_[i] = new double[cols_]();
	}
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			matrix_[i][j] = other.matrix_[i][j];
		}
	}
}

S21Matrix::S21Matrix(S21Matrix&& other) {
	// rows_ = other.rows_;
	// cols_ = other.cols_;
	// matrix_ = other.matrix_;
	// other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
	for( int i = 0 ; i < rows_; i++ ) {	
		delete[] matrix_[i];
	}
	delete[] matrix_;
}

// getters and setter

int S21Matrix::GetRows() {
  return this->rows_;
}

int S21Matrix::GetCols() {
  return this->cols_;
}

void S21Matrix::SetRows(int rows) {
	if (rows < 1) {
		throw std::out_of_range("Number of rows must be positive!");
	}
	double **temp = new double*[rows]();
	for (int i = 0; i < rows; i++) {
		temp[i] = new double[cols_]();
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols_; j++) {
			if (i < rows_) {
				temp[i][j] = matrix_[i][j];
			}
		}
	}
	for( int i = 0 ; i < rows_; i++ ) {	
		delete[] matrix_[i];
	}
	delete[] matrix_;
	rows_ = rows;
	matrix_ = temp;
}

void S21Matrix::SetCols(int cols) { // leaks!
	if (cols < 1) {
		throw std::out_of_range("Number of cols must be positive!");
	}
	double **temp = new double*[rows_]();
	for (int i = 0; i < rows_; i++) {
		temp[i] = new double[cols]();
	}
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols; j++) {
			if (j < cols_) {
				temp[i][j] = matrix_[i][j];
			}
		}
	}
	for( int i = 0 ; i < rows_; i++ ) {	
		delete[] matrix_[i];
	}
	delete matrix_;
	cols_ = cols;
	matrix_ = temp;
}

// overloads

double &S21Matrix::operator()(int i, int j) const {
  if (i < 0 || j < 0 || i >= rows_ || j >= cols_) {
    throw std::out_of_range("Index is outside the matrix");
  }
  return matrix_[i][j];
}

bool S21Matrix::operator==(const S21Matrix &other) {
	bool result = true;
	if ((this->cols_ == other.cols_) && (this->rows_ == other.rows_)) {
		for (int i = 0; i < rows_; i++) {
			for (int j = 0; j < cols_; j++) {
				if (this->matrix_[i][j] != other.matrix_[i][j]) {
					result = false;
				}
			}
		}
	}
	else {
		result = false;
	}
	return result;
}

S21Matrix& S21Matrix::operator=(const S21Matrix &other) { // принимает объект по константной ссылке
	// if this != other
	if (*this == other)	{
		return *this;
	}
	for( int i = 0 ; i < rows_; i++ ) {	
		delete[] matrix_[i];
	}
	delete[] matrix_;
	this->rows_ = other.rows_;
	this->cols_ = other.cols_;
	matrix_ = new double*[rows_]();
	for (int i = 0; i < rows_; i++) {
		matrix_[i] = new double[cols_]();
	}
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			matrix_[i][j] = other.matrix_[i][j];
		}
	}
	return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix &&other) const {
	
}

// operations with matrices

bool S21Matrix::EqMatrix(const S21Matrix& other) {
	bool result = true;
	if ((this->cols_ == other.cols_) && (this->rows_ == other.rows_)) {
		for (int i = 0; i < rows_; i++) {
			for (int j = 0; j < cols_; j++) {
				if (this->matrix_[i][j] != other.matrix_[i][j]) {
					result = false;
				}
			}
		}
	}
	else {
		result = false;
	}
	return result;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
	if (rows_ != other.rows_ && cols_ != other.cols_) {
		throw std::out_of_range("Matrices must be the same size");
	}
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			matrix_[i][j] += other.matrix_[i][j];
		}
	}
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
	if (rows_ != other.rows_ && cols_ != other.cols_) {
		throw std::out_of_range("Matrices must be the same size");
	}
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			matrix_[i][j] -= other.matrix_[i][j];
		}
	}
}

void S21Matrix::MulNumber(const double num) {
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			matrix_[i][j] *= num;
		}
	}
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
	if (cols_ != other.rows_) {
		throw std::out_of_range("Matrices's rows vs cols must be the same size");
	}
	int size = 0;
	if (cols_ < rows_) {
		size = cols_;
	} 
	else {
		size = rows_;
	}
	double **temp = new double*[size]();
	for (int i = 0; i < size; i++) {
		temp[i] = new double[size]();
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				temp[i][j] += (matrix_[i][k] * other.matrix_[k][j]);
			}
		}
	}
	for( int i = 0 ; i < rows_; i++ ) {	
		delete[] matrix_[i];
	}
	delete[] matrix_;
	this->rows_ = size;
	this->cols_ = size;
	matrix_ = new double*[size]();
	for (int i = 0; i < size; i++) {
		matrix_[i] = new double[size]();
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix_[i][j] = temp[i][j];
		}
	}
	for( int i = 0 ; i < size; i++ ) {	
		delete[] temp[i];
	}
	delete[] temp;
}

S21Matrix S21Matrix::Transpose() {
	S21Matrix temp(rows_, cols_);
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			temp.matrix_[j][i] = matrix_[i][j];
		}
	}
	return (temp);
}