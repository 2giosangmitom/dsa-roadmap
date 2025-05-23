#include "solutions_118.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_118_Test : public testing::TestWithParam<
                               std::tuple<int, std::vector<std::vector<int>>>> {
 protected:
  Solution solutions;
};

TEST_P(Solutions_118_Test, ) {
  auto [numRows, expected] = GetParam();

  auto actual = solutions.generate(numRows);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_118_Test,
    testing::Values(
        std::make_tuple(
            5,
            std::vector<std::vector<int>>{
                {1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}}),
        std::make_tuple(1, std::vector<std::vector<int>>{{1}})));
