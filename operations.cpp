#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) const noexcept {
    if (rows_ != other.rows_ || cols_ != other.cols_) return false;
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            if (matrix_[i][j] - other.matrix_[i][j] > EPS) return false;
        }
    }
    return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
    if (rows_ != other.rows_ || cols_ != other.cols_)
        throw std::invalid_argument("Different matrix dimensions");

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] += other.matrix_[i][j];
        }
    }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
    if (rows_ != other.rows_ || cols_ != other.cols_)
        throw std::invalid_argument("Different matrix dimensions");

    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] -= other.matrix_[i][j];
        }
    }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
    if (cols_ != other.rows_)
        throw std::invalid_argument(
            "The number of columns in the first matrix is not equal to the "
            "number of rows in the second matrix");
    S21Matrix res(rows_, other.cols_);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < other.cols_; j++) {
            for (int k = 0; k < cols_; k++) {
                res.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
            }
        }
    }
    *this = res;
}

void S21Matrix::MulNumber(const double num) noexcept {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] *= num;
        }
    }
}

S21Matrix S21Matrix::Transpose() noexcept {
    S21Matrix tmp(cols_, rows_);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            tmp.matrix_[i][j] = matrix_[j][i];
        }
    }
    return tmp;
}

double S21Matrix::Determinant() {
    if (rows_ != cols_) throw std::invalid_argument("The matrix is not square");
    double result = 1.;
    S21Matrix tmp(*this);
    int sign = 1;
    double mul = 0.;
    for (int i = 0; i < rows_ - 1; i++) {
        for (int j = i + 1; j < rows_; j++) {
            if (!tmp.matrix_[i][i]) {
                sign = -sign;
                int l = j;
                while (l < rows_) {
                    if (tmp.matrix_[l][i]) break;
                    l++;
                }
                for (int k = 0; k < rows_; k++)
                    std::swap(tmp.matrix_[l][k], tmp.matrix_[i][k]);
            }
            // в столбце только нули (нужно тестить)
            if (!tmp.matrix_[i][i]) break;
            //
            mul = -tmp.matrix_[j][i] / tmp.matrix_[i][i];
            for (int k = 0; k < rows_; k++)
                tmp.matrix_[j][k] += tmp.matrix_[i][k] * mul;
        }
    }

    for (int i = 0; i < rows_; i++) result *= tmp.matrix_[i][i];

    return result * sign;
}

S21Matrix S21Matrix::CalcComplements() {
    if (rows_ != cols_) throw std::invalid_argument("The matrix is not square");
    S21Matrix calcComp(rows_, cols_);
    S21Matrix minor(rows_ - 1, cols_ - 1);

    if (rows_ == 1) {
        calcComp.matrix_[0][0] = 1.;
    } else {
        for (int i = 0; i < rows_; i++)
            for (int j = 0; j < cols_; j++)
                calcComp.matrix_[i][j] =
                    ((i + j) % 2 ? -1 : 1) * minorMatrix(i, j).Determinant();
    }

    return calcComp;
}

S21Matrix S21Matrix::minorMatrix(int im, int jm) noexcept {
    S21Matrix minor(rows_ - 1, cols_ - 1);
    int mRow = 0;
    int mCol = 0;
    for (int i = 0; i < rows_; i++) {
        if (i == im) continue;
        mCol = 0;
        for (int j = 0; j < cols_; j++) {
            if (j == jm) continue;
            minor.matrix_[mRow][mCol] = matrix_[i][j];
            mCol++;
        }
        mRow++;
    }
    return minor;
}

S21Matrix S21Matrix::InverseMatrix() {
    double det = Determinant();
    if (!det) throw std::invalid_argument("Matrix determinant is 0");
    return CalcComplements().Transpose() * (1 / det);
}
