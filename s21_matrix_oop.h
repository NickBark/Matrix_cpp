#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>

#define EPS 1e-10

class S21Matrix {
   private:
    int rows_, cols_;
    double** matrix_;

    void swap(S21Matrix& other) noexcept;
    S21Matrix minorMatrix(int im, int jm) noexcept;
    void freeMemory() noexcept;

   public:
    S21Matrix();
    explicit S21Matrix(int rows, int cols);
    S21Matrix(const S21Matrix& other);
    S21Matrix(S21Matrix&& other);
    ~S21Matrix();

    // support func
    void printMatrix() noexcept;
    void fillMatrix(double val) noexcept;
    void fillMatrixArr(const double* arr) noexcept;
    void fillMatrix() noexcept;
    double& getElem(int i, int j) const;

    // operations
    bool EqMatrix(const S21Matrix& other) const noexcept;
    void SumMatrix(const S21Matrix& other);
    void SubMatrix(const S21Matrix& other);
    void MulMatrix(const S21Matrix& other);
    void MulNumber(const double num) noexcept;
    S21Matrix Transpose() noexcept;
    double Determinant();
    S21Matrix CalcComplements();
    S21Matrix InverseMatrix();

    // operators
    S21Matrix& operator=(S21Matrix const& other);
    S21Matrix& operator=(S21Matrix&& other);
    S21Matrix operator+(const S21Matrix& other) const;
    S21Matrix operator-(const S21Matrix& other) const;
    S21Matrix& operator+=(const S21Matrix& other);
    S21Matrix& operator-=(const S21Matrix& other);
    S21Matrix operator*(const S21Matrix& other) const;
    S21Matrix operator*(const double num) const;
    S21Matrix& operator*=(const double num);
    S21Matrix& operator*=(const S21Matrix& other);
    bool operator==(const S21Matrix& other) const noexcept;
    double& operator()(int i, int j) const;

    // optional func
    int getRows() const { return rows_; }
    int getCols() const { return cols_; }
    void setRows(int rows);
    void setCols(int cols);
};

inline S21Matrix operator*(const double num, const S21Matrix& m) {
    return m * num;
}

#endif  // S21_MATRIX_OOP_H