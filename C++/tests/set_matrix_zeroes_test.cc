#include "../src/set_matrix_zeroes.hpp"
#include <gtest/gtest.h>

class SetMatrixZeroesTest : public testing::Test {
protected:
  Solution s;
};

TEST_F(SetMatrixZeroesTest, case1) {
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  vector<vector<int>> expected = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
  s.setZeroes(matrix);
  EXPECT_EQ(matrix, expected);
}

TEST_F(SetMatrixZeroesTest, case2_no_zero) {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<vector<int>> expected = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  s.setZeroes(matrix);
  EXPECT_EQ(matrix, expected);
}

TEST_F(SetMatrixZeroesTest, case3_all_zero) {
  vector<vector<int>> matrix = {{0, 0}, {0, 0}};
  vector<vector<int>> expected = {{0, 0}, {0, 0}};
  s.setZeroes(matrix);
  EXPECT_EQ(matrix, expected);
}

TEST_F(SetMatrixZeroesTest, case4_single_element_zero) {
  vector<vector<int>> matrix = {{0}};
  vector<vector<int>> expected = {{0}};
  s.setZeroes(matrix);
  EXPECT_EQ(matrix, expected);
}

TEST_F(SetMatrixZeroesTest, case5_single_element_non_zero) {
  vector<vector<int>> matrix = {{5}};
  vector<vector<int>> expected = {{5}};
  s.setZeroes(matrix);
  EXPECT_EQ(matrix, expected);
}

TEST_F(SetMatrixZeroesTest, case6_large_matrix) {
  vector<vector<int>> matrix = {
      {1, 2, 3, 4}, {5, 0, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  vector<vector<int>> expected = {
      {1, 0, 3, 4}, {0, 0, 0, 0}, {9, 0, 11, 12}, {13, 0, 15, 16}};
  s.setZeroes(matrix);
  EXPECT_EQ(matrix, expected);
}
