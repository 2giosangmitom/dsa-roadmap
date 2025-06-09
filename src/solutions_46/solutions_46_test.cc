#include "solutions_46.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_46_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<int>, std::vector<std::vector<int>>>> {
 protected:
  Solution solutions;
};

TEST_P(Solutions_46_Test, ) {
  auto [nums, expected] = GetParam();

  auto actual = solutions.permute(nums);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_46_Test,
    testing::Values(std::make_tuple(std::vector<int>{1, 2, 3},
                                    std::vector<std::vector<int>>{{1, 2, 3},
                                                                  {1, 3, 2},
                                                                  {2, 1, 3},
                                                                  {2, 3, 1},
                                                                  {3, 1, 2},
                                                                  {3, 2, 1}}),
                    std::make_tuple(std::vector<int>{0, 1},
                                    std::vector<std::vector<int>>{{0, 1},
                                                                  {1, 0}})));
