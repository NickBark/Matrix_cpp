#include "tests.h"

TEST(TestOptional, SubtestInverse) {
    try {
        S21Matrix mat(4, 4);
        S21Matrix res(4, 4);
        S21Matrix rew(4, 4);
        double arr[16] = {22, 11,  -33, 14, 45, -26, 47, 38,
                          19, -31, 13,  33, 23, -15, 15, 16};

        double rewiew[16] = {
            131. / 19005.,  -1394. / 79821., -1642. / 57015., 37853. / 399105.,
            18. / 905.,     205. / 3801.,    -46. / 2715.,    -2101. / 19005.,
            -209. / 19005., 2195. / 79821.,  -572. / 57015.,  -13967. / 399105.,
            2. / 105.,      22. / 441.,      11. / 315.,      -319. / 2205.};

        mat.fillMatrixArr(arr);
        rew.fillMatrixArr(rewiew);
        res = mat.InverseMatrix();

        ASSERT_EQ(res == rew, true);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

TEST(TestOptional, SubtestInverseErr) {
    try {
        S21Matrix mat(4, 3);
        S21Matrix res(4, 3);
        S21Matrix rew(4, 3);
        double arr[16] = {22, 11,  -33, 14, 45, -26, 47, 38,
                          19, -31, 13,  33, 23, -15, 15, 16};

        double rewiew[16] = {
            131. / 19005.,  -1394. / 79821., -1642. / 57015., 37853. / 399105.,
            18. / 905.,     205. / 3801.,    -46. / 2715.,    -2101. / 19005.,
            -209. / 19005., 2195. / 79821.,  -572. / 57015.,  -13967. / 399105.,
            2. / 105.,      22. / 441.,      11. / 315.,      -319. / 2205.};

        mat.fillMatrixArr(arr);
        rew.fillMatrixArr(rewiew);
        res = mat.InverseMatrix();

        ASSERT_EQ(res == rew, true);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}