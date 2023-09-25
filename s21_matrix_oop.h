#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H
#include <iostream>

class S21Matrix {
    private:
        int 	rows_, cols_;
        double	**matrix_;
		void	CreateMatrix(int rows, int cols);

    public:
        S21Matrix();
        S21Matrix(int rows, int cols);
        S21Matrix(const S21Matrix& other);
        // S21Matrix(S21Matrix&& other);
        ~S21Matrix();

        // getters and setters
        int		GetRows();
        int		GetCols();
        void	SetRows(int rows);
        void	SetCols(int cols);

        // overloads
        double 		&operator()(int i, int j) const;
		S21Matrix	operator+(S21Matrix &other) const;
		S21Matrix	operator-(S21Matrix &other) const;
		S21Matrix	operator*(S21Matrix &other) const;
		bool		operator==(const S21Matrix &other); 
		S21Matrix	&operator=(const S21Matrix &other);
		S21Matrix	&operator+=(S21Matrix &other);
		
		//S21Matrix & operator=(S21Matrix &&other) const;

		// member functions
		bool		EqMatrix(const S21Matrix& other);
		void		SumMatrix(const S21Matrix& other);
		void		SubMatrix(const S21Matrix& other);
		void		MulNumber(const double num);
		void		MulMatrix(const S21Matrix& other);
		S21Matrix	Transpose();

		//additional functions
        
};

#endif