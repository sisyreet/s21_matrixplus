#include "s21_matrix_oop.h"

const double S21Matrix::epsilon = 1.0e-6;

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
	rows_ = other.rows_;
	cols_ = other.cols_;
	matrix_ = other.matrix_;
	other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
	if (matrix_ != nullptr)
	{
		for( int i = 0 ; i < rows_; i++ ) {	
			delete[] matrix_[i];
		}
		delete[] matrix_;
	}
}

// ----- GETTERS, SETTERS ----- //

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
	matrix_ = nullptr;
	rows_ = rows;
	matrix_ = temp;
}

void S21Matrix::SetCols(int cols) {
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
	matrix_ = nullptr;
	cols_ = cols;
	matrix_ = temp;
}

// ----- OVERLOADS ----- //

S21Matrix S21Matrix::operator+(S21Matrix &other) const {
	S21Matrix temp(*this);
	temp.SumMatrix(other);
	return (temp);
}

S21Matrix S21Matrix::operator-(S21Matrix &other) const {
	S21Matrix temp(*this);
	temp.SubMatrix(other);
	return (temp);
}

S21Matrix S21Matrix::operator*(S21Matrix &other) const {
	S21Matrix temp(*this);
	temp.MulMatrix(other);
	return (temp);
}

bool S21Matrix::operator==(const S21Matrix &other) {
	return (EqMatrix(other));
}

S21Matrix& S21Matrix::operator=(const S21Matrix &other) { // принимает объект по константной ссылке
	// if this != other
	if (*this == other)	{
		return (*this);
	}
	for( int i = 0 ; i < rows_; i++ ) {	
		delete[] matrix_[i];
	}
	delete[] matrix_;
	matrix_ = nullptr;

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
	return (*this);
}

S21Matrix &S21Matrix::operator+=(S21Matrix &other) {
	SumMatrix(other);
	return (*this);
}

S21Matrix &S21Matrix::operator-=(S21Matrix &other) {
	SubMatrix(other);
	return (*this);
}

S21Matrix	&S21Matrix::operator=(S21Matrix &&other) {
	if (this == &other) {
		return (*this);
	}
	for( int i = 0 ; i < rows_; i++ ) {	
		delete[] matrix_[i];
	}
	delete matrix_;
	matrix_ = nullptr;

	rows_ = other.rows_;
	cols_ = other.cols_;
	matrix_ = other.matrix_;
	other.matrix_ = nullptr;

	return (*this);
}


double &S21Matrix::operator()(int i, int j) const {
	if (i < 0 || j < 0 || i >= rows_ || j >= cols_) {
		throw std::out_of_range("Index is outside the matrix");
	}
	return (matrix_[i][j]);
}

// ----- MEMBER FUNCTIONS ----- //

bool S21Matrix::EqMatrix(const S21Matrix& other) {
	bool result = true;
	if ((cols_ == other.cols_) && (rows_ == other.rows_)) {
		for (int i = 0; i < rows_; i++) {
			for (int j = 0; j < cols_; j++) {
				if (abs(matrix_[i][j] - other.matrix_[i][j]) > epsilon) {
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
	if (rows_ != other.rows_ || cols_ != other.cols_) {
		throw std::invalid_argument("Matrices must be the same size");
	}
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			matrix_[i][j] += other.matrix_[i][j];
		}
	}
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
	if (rows_ != other.rows_ || cols_ != other.cols_) {
		throw std::invalid_argument("Matrices must be the same size");
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

void S21Matrix::MulMatrix(const S21Matrix& other) { //fix leaks
	if (cols_ != other.rows_) {
		throw std::invalid_argument("Matrices's rows vs cols must be the same size");
	}
	S21Matrix temp(rows_, other.cols_);
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < other.cols_; j++) {
			for (int k = 0; k < cols_; k++) {
				temp(i,j) += matrix_[i][k] * other.matrix_[k][j];
			}
		}
	}
	matrix_ = temp.matrix_;
	temp.matrix_ = nullptr;
	rows_ = temp.rows_;
	cols_ = temp.cols_;
}


S21Matrix S21Matrix::Transpose() {
	S21Matrix temp(cols_, rows_);
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {
			temp.matrix_[j][i] = matrix_[i][j];
		}
	}
	return (temp);
}

S21Matrix S21Matrix::CalcComplements() {
	//  Aij = (-1)^j+i * Mij
	if (rows_ != cols_) {
		throw std::invalid_argument("Matrix must be square!");
	}
	S21Matrix complements(rows_, cols_);
	double sign = 1.0;
	if (rows_ == 1) {
		complements.matrix_[0][0] = 1.0;
	} else {
		for (int i = 0; i < rows_; i++) {
			for (int j = 0; j < cols_; j++) {
				if ((i + j) % 2 == 0) {
					sign = 1.0;
				} else {
					sign = -1.0;
				}
				complements.matrix_[i][j] = sign * Minor(i, j).Determinant();
			}
		}
	}
	return (complements);
}

double S21Matrix::Determinant() {
	if (rows_ != cols_) {
		throw std::invalid_argument("Matrix must be square!");
	}
	double det = 0.0;
	if (rows_ == 1) {
		det = matrix_[0][0];
	} else if (rows_ == 2) {
		det = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
	// } else if (rows_ == 3) {
	// 	det = matrix_[0][0] * matrix_[1][1] * matrix_[2][2] +
	// 		  matrix_[0][1] * matrix_[1][2] * matrix_[2][0] +
	// 		  matrix_[1][0] * matrix_[0][2] * matrix_[2][1] -
	// 		  matrix_[0][2] * matrix_[1][1] * matrix_[2][0] - 
	// 		  matrix_[1][0] * matrix_[0][1] * matrix_[2][2] - 
	// 		  matrix_[0][0] * matrix_[1][2] * matrix_[2][1];
	} else {
		for (int i = 0; i < cols_; i++) {
			double sign;
			if (i % 2 == 0) {
				sign = 1.0;
			} else {
				sign = -1.0;
			}
			det += sign * matrix_[0][i] * Minor(0, i).Determinant();
		}
	}
	return (det);
}

S21Matrix S21Matrix::InverseMatrix() {
	// A^-1 = 1/det.A * ~A^t
	if (rows_ != cols_) {
		throw std::invalid_argument("Matrix should be square!");
	}
	S21Matrix temp(CalcComplements());
	double det = Determinant();	
	if (det != 0.0) {
		temp.Transpose();
		for (int i = 0; i < rows_; i++) {
			for (int j = 0; j < cols_; j++) {
				temp.matrix_[i][j] *= (1 / det);
			}
		}
	} else {
		throw std::invalid_argument("Determinant should not be equal 0");
	}
  	return (temp);
}

S21Matrix S21Matrix::Minor(int rows, int cols) const {
	S21Matrix minor(rows_ - 1, cols_ - 1);
	int i, j, k, l;

	for (i = 0, k = 0; i < rows_ - 1; i++, k++) {
		for (j = 0, l = 0; j < cols_ - 1; j++, l++) {
			if (k == rows) {
				k++;
			}
			if (l == cols) {
				l++;
			}
			minor.matrix_[i][j] = matrix_[k][l];
		}
	}
  	return (minor);
}