#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H
#include <iostream>

class S21Matrix {
    private:
        int rows_, cols_;
        double **matrix_;

    public:
        S21Matrix();
        S21Matrix(int rows, int cols);
        S21Matrix(const S21Matrix& other);
        S21Matrix(S21Matrix&& other);
        ~S21Matrix();

        // getters and setters
        int getRows();
        int getCols();
        void setRows(int rows);
        void setCols(int cols);

        // overloads
        double &operator()(int i, int j) const;
        
};

#endif