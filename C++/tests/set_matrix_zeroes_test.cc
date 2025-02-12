#include "../src/set_matrix_zeroes.hpp"
#include <gtest/gtest.h>

class SetMatrixZeroesTest : public testing::Test {
protected:
  Solution s;

  void runTest(void (Solution::*func)(std::vector<std::vector<int>> &),
               std::vector<std::vector<int>> matrix,
               const std::vector<std::vector<int>> &expected) {
    (s.*func)(matrix);
    EXPECT_EQ(matrix, expected);
  }
};

TEST_F(SetMatrixZeroesTest, case1_setZeroes) {
  runTest(&Solution::setZeroes, {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
          {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}});
}

TEST_F(SetMatrixZeroesTest, case1_setZeroes2) {
  runTest(&Solution::setZeroes2, {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
          {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}});
}

TEST_F(SetMatrixZeroesTest, case2_setZeroes) {
  runTest(&Solution::setZeroes, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
          {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
}

TEST_F(SetMatrixZeroesTest, case2_setZeroes2) {
  runTest(&Solution::setZeroes2, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
          {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
}

TEST_F(SetMatrixZeroesTest, case3_setZeroes) {
  runTest(&Solution::setZeroes, {{0, 0}, {0, 0}}, {{0, 0}, {0, 0}});
}

TEST_F(SetMatrixZeroesTest, case3_setZeroes2) {
  runTest(&Solution::setZeroes2, {{0, 0}, {0, 0}}, {{0, 0}, {0, 0}});
}

TEST_F(SetMatrixZeroesTest, case4_setZeroes) {
  runTest(&Solution::setZeroes, {{0}}, {{0}});
}

TEST_F(SetMatrixZeroesTest, case4_setZeroes2) {
  runTest(&Solution::setZeroes2, {{0}}, {{0}});
}

TEST_F(SetMatrixZeroesTest, case5_setZeroes) {
  runTest(&Solution::setZeroes, {{5}}, {{5}});
}

TEST_F(SetMatrixZeroesTest, case5_setZeroes2) {
  runTest(&Solution::setZeroes2, {{5}}, {{5}});
}

TEST_F(SetMatrixZeroesTest, case6_setZeroes) {
  runTest(&Solution::setZeroes,
          {{1, 2, 3, 4}, {5, 0, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}},
          {{1, 0, 3, 4}, {0, 0, 0, 0}, {9, 0, 11, 12}, {13, 0, 15, 16}});
}

TEST_F(SetMatrixZeroesTest, case6_setZeroes2) {
  runTest(&Solution::setZeroes2,
          {{1, 2, 3, 4}, {5, 0, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}},
          {{1, 0, 3, 4}, {0, 0, 0, 0}, {9, 0, 11, 12}, {13, 0, 15, 16}});
}
