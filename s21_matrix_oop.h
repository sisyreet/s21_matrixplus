#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H
#include <iostream>
#include <cmath>

class S21Matrix {
    public:
		static const double epsilon;
		
        S21Matrix();
        S21Matrix(int rows, int cols);
        S21Matrix(const S21Matrix& other);
        S21Matrix(S21Matrix&& other);
        ~S21Matrix();

        // getters and setters
        int		GetRows();
        int		GetCols();
        void	SetRows(int rows);
        void	SetCols(int cols);

        // overloads
		S21Matrix	operator+(S21Matrix &other) const;
		S21Matrix	operator-(S21Matrix &other) const;
		S21Matrix	operator*(S21Matrix &other) const;
		bool		operator==(const S21Matrix &other); 
		S21Matrix	&operator=(const S21Matrix &other);
		S21Matrix	&operator+=(S21Matrix &other);
		S21Matrix	&operator-=(S21Matrix &other);
        double 		&operator()(int i, int j) const;
		S21Matrix	&operator=(S21Matrix &&other);

		// member functions
		bool		EqMatrix(const S21Matrix& other);
		void		SumMatrix(const S21Matrix& other);
		void		SubMatrix(const S21Matrix& other);
		void		MulNumber(const double num);
		void		MulMatrix(const S21Matrix& other);
		S21Matrix	Transpose();
		S21Matrix 	CalcComplements();
		double 		Determinant();
		S21Matrix	InverseMatrix();
		S21Matrix	Minor(int rows, int cols) const;
		

	private:
        int 	rows_, cols_;
        double	**matrix_;
};

#endif