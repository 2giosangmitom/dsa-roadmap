#include "solutions_78.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <tuple>
#include <vector>

class Solutions_78_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<int>, std::vector<std::vector<int>>>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_78_Test, ) {
  auto [nums, expected] = GetParam();

  auto actual = solution.subsets(nums);

  std::sort(actual.begin(), actual.end(),
            [](std::vector<int> &a, std::vector<int> &b) {
              if (a.size() != b.size()) {
                return a.size() < b.size();
              }
              return a.front() < b.front() || a.back() < b.back();
            });

  std::sort(expected.begin(), expected.end(),
            [](std::vector<int> &a, std::vector<int> &b) {
              if (a.size() != b.size()) {
                return a.size() < b.size();
              }
              return a.front() < b.front() || a.back() < b.back();
            });

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_78_Test,
    testing::Values(
        std::make_tuple(
            std::vector<int>{1, 2, 3},
            std::vector<std::vector<int>>{
                {}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}}),
        std::make_tuple(std::vector<int>{0},
                        std::vector<std::vector<int>>{{}, {0}})));