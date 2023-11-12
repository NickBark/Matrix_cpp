#include "tests.h"

using namespace std;

TEST(TestClass, SubtestInitNull) {
    try {
        S21Matrix mat;
        double tmp[16] = {9, 2, 2, 9, 1, 9, 3, 4, 2, 9, 2, 2, 9, 5, 5, 9};
        ASSERT_EQ(mat.getRows(), 2);
        ASSERT_EQ(mat.getCols(), 2);
        mat.fillMatrixArr(tmp);
        for (int i = 0; i < mat.getRows(); i++) {
            for (int j = 0; j < mat.getCols(); j++) {
                ASSERT_EQ(mat(i, j), tmp[i * mat.getCols() + j]);
            }
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestInitArgs) {
    try {
        S21Matrix mat = S21Matrix(4, 4);
        double tmp[16] = {9, 2, 2, 9, 1, 9, 3, 4, 2, 9, 2, 2, 9, 5, 5, 9};
        ASSERT_EQ(mat.getRows(), 4);
        ASSERT_EQ(mat.getCols(), 4);
        mat.fillMatrixArr(tmp);
        for (int i = 0; i < mat.getRows(); i++) {
            for (int j = 0; j < mat.getCols(); j++) {
                ASSERT_EQ(mat(i, j), tmp[i * mat.getCols() + j]);
            }
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestCopy) {  // error
    try {
        S21Matrix mat = S21Matrix(4, 4);
        double tmp[16] = {9, 2, 2, 9, 1, 9, 3, 4, 2, 9, 2, 2, 9, 5, 5, 9};
        mat.fillMatrixArr(tmp);
        S21Matrix mat2 = S21Matrix(mat);
        ASSERT_EQ(mat.EqMatrix(mat2), true);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestMove) {
    try {
        S21Matrix mat = S21Matrix(4, 4);
        double tmp[16] = {9, 2, 2, 9, 1, 9, 3, 4, 2, 9, 2, 2, 9, 5, 5, 9};
        mat.fillMatrixArr(tmp);
        S21Matrix mat2 = S21Matrix(std::move(mat));
        ASSERT_EQ(mat2.getRows(), 4);
        ASSERT_EQ(mat2.getCols(), 4);
        for (int i = 0; i < mat.getRows(); i++) {
            for (int j = 0; j < mat.getCols(); j++) {
                ASSERT_EQ(mat2(i, j), tmp[i * mat.getCols() + j]);
            }
        }
        ASSERT_EQ(mat.getRows(), 0);
        ASSERT_EQ(mat.getCols(), 0);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestgetRows) {
    try {
        S21Matrix mat = S21Matrix(4, 3);
        ASSERT_EQ(mat.getRows(), 4);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestgetCols) {
    try {
        S21Matrix mat = S21Matrix(3, 4);
        ASSERT_EQ(mat.getCols(), 4);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestsetRows) {
    try {
        S21Matrix mat = S21Matrix(3, 4);
        S21Matrix mat2 = S21Matrix(4, 4);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        double tmp2[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 0, 0, 0};
        mat.fillMatrixArr(tmp);
        mat2.fillMatrixArr(tmp2);
        mat.setRows(4);
        ASSERT_EQ(mat.EqMatrix(mat2), true);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestsetRowsError) {
    try {
        S21Matrix mat = S21Matrix(3, 4);
        ASSERT_THROW(mat.setRows(-1), std::invalid_argument);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestsetCols) {
    try {
        S21Matrix mat = S21Matrix(4, 3);
        S21Matrix mat2 = S21Matrix(4, 4);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        double tmp2[16] = {1, 2, 3, 0, 4, 5, 6, 0, 7, 8, 9, 0, 10, 11, 12, 0};
        mat.fillMatrixArr(tmp);
        mat2.fillMatrixArr(tmp2);
        mat.setCols(4);
        ASSERT_EQ(mat.EqMatrix(mat2), true);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestsetColsError) {
    try {
        S21Matrix mat = S21Matrix(3, 4);
        ASSERT_THROW(mat.setCols(-1), std::invalid_argument);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestGetValue) {
    try {
        S21Matrix mat = S21Matrix(3, 4);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        mat.fillMatrixArr(tmp);
        ASSERT_EQ(mat(0, 0), 1);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestGetValueError) {
    try {
        S21Matrix mat = S21Matrix(3, 4);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        mat.fillMatrixArr(tmp);
        ASSERT_THROW(mat(10, 3), std::out_of_range);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestSetValue) {
    try {
        S21Matrix mat = S21Matrix(3, 4);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        mat.fillMatrixArr(tmp);
        mat(0, 0) = 0;
        ASSERT_EQ(mat(0, 0), 0);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestSetValueError) {
    try {
        S21Matrix mat = S21Matrix(3, 4);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        mat.fillMatrixArr(tmp);
        ASSERT_THROW(mat(10, 3) = 0, std::out_of_range);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestSetCopyMatrix) {  // error
    try {
        S21Matrix mat = S21Matrix(3, 4);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        mat.fillMatrixArr(tmp);
        S21Matrix mat2 = mat;
        ASSERT_EQ(mat.EqMatrix(mat2), true);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestSetMatrix) {  // error
    try {
        S21Matrix mat = S21Matrix(3, 4);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        mat.fillMatrixArr(tmp);
        S21Matrix mat2 = mat;
        ASSERT_EQ(mat.EqMatrix(mat2), true);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestMoveMatrix) {
    try {
        S21Matrix mat = S21Matrix(3, 4);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        mat.fillMatrixArr(tmp);
        S21Matrix mat2 = std::move(mat);
        ASSERT_EQ(mat2.getRows(), 3);
        ASSERT_EQ(mat2.getCols(), 4);
        for (int i = 0; i < mat.getRows(); i++) {
            for (int j = 0; j < mat.getCols(); j++) {
                ASSERT_EQ(mat2(i, j), tmp[i * mat.getCols() + j]);
            }
        }
        ASSERT_EQ(mat.getRows(), 0);
        ASSERT_EQ(mat.getCols(), 0);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestSum) {
    try {
        S21Matrix mat = S21Matrix(3, 3);
        S21Matrix mat2 = S21Matrix(3, 3);
        S21Matrix mat3 = S21Matrix(3, 3);
        S21Matrix mat4 = S21Matrix(3, 3);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        double tmp3[16] = {2,  3,  4,  5,  6,  7,  8,  9,
                           10, 11, 12, 13, 14, 15, 16, 17};
        mat.fillMatrixArr(tmp);
        mat2.fillMatrixArr(tmp2);
        mat3.fillMatrixArr(tmp3);
        mat4 = mat + mat2;
        ASSERT_EQ(mat4.EqMatrix(mat3), true);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestSub) {
    try {
        S21Matrix mat = S21Matrix(3, 3);
        S21Matrix mat2 = S21Matrix(3, 3);
        S21Matrix mat3 = S21Matrix(3, 3);
        S21Matrix mat4 = S21Matrix(3, 3);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        double tmp3[16] = {0, 1, 2,  3,  4,  5,  6,  7,
                           8, 9, 10, 11, 12, 13, 14, 15};
        mat.fillMatrixArr(tmp);
        mat2.fillMatrixArr(tmp2);
        mat3.fillMatrixArr(tmp3);
        mat4 = mat - mat2;
        ASSERT_EQ(mat4.EqMatrix(mat3), true);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestMulNum) {
    try {
        S21Matrix mat = S21Matrix(3, 3);
        S21Matrix mat2 = S21Matrix(3, 3);
        S21Matrix mat3 = S21Matrix(3, 3);
        S21Matrix mat4 = S21Matrix(3, 3);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        // double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        double tmp3[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        mat.fillMatrixArr(tmp);
        // mat2.fillMatrixArr(tmp2);
        mat3.fillMatrixArr(tmp3);
        mat4 = mat * 0;
        ASSERT_EQ(mat4.EqMatrix(mat3), true);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestMulMat) {
    try {
        S21Matrix mat = S21Matrix(3, 3);
        S21Matrix mat2 = S21Matrix(3, 3);
        S21Matrix mat3 = S21Matrix(3, 3);
        S21Matrix mat4 = S21Matrix(3, 3);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        double tmp3[16] = {30, 36, 42, 66, 81, 96, 102, 126, 150};
        mat.fillMatrixArr(tmp);
        mat2.fillMatrixArr(tmp2);
        mat3.fillMatrixArr(tmp3);
        mat4 = mat * mat;
        ASSERT_EQ(mat4.EqMatrix(mat3), true);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestEqTrue) {
    try {
        S21Matrix mat = S21Matrix(3, 3);
        S21Matrix mat2 = S21Matrix(3, 3);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        mat.fillMatrixArr(tmp);
        mat2.fillMatrixArr(tmp);
        ASSERT_EQ(mat == mat2, true);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestEqFalse) {
    try {
        S21Matrix mat = S21Matrix(3, 3);
        S21Matrix mat2 = S21Matrix(3, 3);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        mat.fillMatrixArr(tmp);
        mat2.fillMatrixArr(tmp);
        mat2(0, 0) = 0;
        ASSERT_EQ(mat == mat2, false);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestSumEq) {
    try {
        S21Matrix mat = S21Matrix(3, 3);
        S21Matrix mat2 = S21Matrix(3, 3);
        S21Matrix mat3 = S21Matrix(3, 3);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        double tmp3[16] = {2,  3,  4,  5,  6,  7,  8,  9,
                           10, 11, 12, 13, 14, 15, 16, 17};
        mat.fillMatrixArr(tmp);
        mat2.fillMatrixArr(tmp2);
        mat3.fillMatrixArr(tmp3);
        mat += mat2;
        ASSERT_EQ(mat.EqMatrix(mat3), true);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestSubEq) {
    try {
        S21Matrix mat = S21Matrix(3, 3);
        S21Matrix mat2 = S21Matrix(3, 3);
        S21Matrix mat3 = S21Matrix(3, 3);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        double tmp3[16] = {0, 1, 2,  3,  4,  5,  6,  7,
                           8, 9, 10, 11, 12, 13, 14, 15};
        mat.fillMatrixArr(tmp);
        mat2.fillMatrixArr(tmp2);
        mat3.fillMatrixArr(tmp3);
        mat -= mat2;
        ASSERT_EQ(mat.EqMatrix(mat3), true);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestMulNumEq) {
    try {
        S21Matrix mat = S21Matrix(3, 3);
        S21Matrix mat2 = S21Matrix(3, 3);
        S21Matrix mat3 = S21Matrix(3, 3);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        // double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        double tmp3[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        mat.fillMatrixArr(tmp);
        // mat2.fillMatrixArr(tmp2);
        mat3.fillMatrixArr(tmp3);
        mat *= 0;
        ASSERT_EQ(mat.EqMatrix(mat3), true);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestClass, SubtestMulMatEq) {
    try {
        S21Matrix mat = S21Matrix(3, 3);
        S21Matrix mat2 = S21Matrix(3, 3);
        S21Matrix mat3 = S21Matrix(3, 3);
        double tmp[16] = {1, 2,  3,  4,  5,  6,  7,  8,
                          9, 10, 11, 12, 13, 14, 15, 16};
        // double tmp2[16] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        double tmp3[16] = {30, 36, 42, 66, 81, 96, 102, 126, 150};
        mat.fillMatrixArr(tmp);
        // mat2.fillMatrixArr(tmp2);
        mat3.fillMatrixArr(tmp3);
        mat *= mat;
        ASSERT_EQ(mat.EqMatrix(mat3), true);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}