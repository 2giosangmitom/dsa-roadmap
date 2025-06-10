#include "solutions_51.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_51_Test
    : public testing::TestWithParam<
          std::tuple<int, std::vector<std::vector<std::string>>>> {
 protected:
  Solution solutions;
};

TEST_P(Solutions_51_Test, ) {
  auto [n, expected] = GetParam();

  auto actual = solutions.solveNQueens(n);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_51_Test,
    testing::Values(std::make_tuple(4,
                                    std::vector<std::vector<std::string>>{
                                        {".Q..", "...Q", "Q...", "..Q."},
                                        {"..Q.", "Q...", "...Q", ".Q.."}}),
                    std::make_tuple(1, std::vector<std::vector<std::string>>{
                                           {"Q"}})));