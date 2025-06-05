#include "solutions_1.hpp"

#include <gtest/gtest.h>

#include <tuple>
#include <vector>

class Solutions_1_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<int>, int, std::vector<int>>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_1_Test, ) {
  auto [nums, target, expected] = GetParam();

  auto actual = solution.twoSum(nums, target);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_1_Test,
    testing::Values(
        make_tuple(std::vector<int>{2, 7, 11, 15}, 9, std::vector<int>{0, 1}),
        make_tuple(std::vector<int>{3, 2, 4}, 6, std::vector<int>{1, 2}),
        make_tuple(std::vector<int>{1, 5, -3, -2}, -5, std::vector<int>{2, 3}),
        make_tuple(std::vector<int>{-10, 7, 8, 2, 12}, 20,
                   std::vector<int>{2, 4}),
        make_tuple(std::vector<int>{-6, 1, -7, 3, 8}, -13,
                   std::vector<int>{0, 2}),
        make_tuple(std::vector<int>{}, 0, std::vector<int>{}),
        make_tuple(std::vector<int>{0, 4, 1, 2}, 9, std::vector<int>{})));
