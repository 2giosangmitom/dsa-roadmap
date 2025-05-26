#include "solutions_219.hpp"

#include <gtest/gtest.h>

class Solutions_219_Test
    : public testing::TestWithParam<std::tuple<std::vector<int>, int, bool>> {
 protected:
  Solution solutions;
};

TEST_P(Solutions_219_Test, ) {
  auto [nums, k, expected] = GetParam();

  bool actual = solutions.containsNearbyDuplicate(nums, k);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_219_Test,
    testing::Values(std::make_tuple(std::vector<int>{1, 2, 3, 1}, 3, true),
                    std::make_tuple(std::vector<int>{1, 0, 1, 1}, 1, true),
                    std::make_tuple(std::vector<int>{1, 2, 3, 1, 2, 3}, 2,
                                    false)));
