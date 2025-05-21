#include "solutions_14.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_14_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<std::string>, std::string>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_14_Test, first) {
  auto [strs, expected] = GetParam();

  std::string actual = solution.longestCommonPrefix(strs);

  EXPECT_EQ(actual, expected);
}

TEST_P(Solutions_14_Test, second) {
  auto [strs, expected] = GetParam();

  std::string actual = solution.longestCommonPrefix2(strs);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_14_Test,
    testing::Values(
        make_tuple(std::vector<std::string>{"leetcode", "leets", "leet"},
                   "leet"),
        make_tuple(std::vector<std::string>{"flower", "flow", "flight"}, "fl"),
        make_tuple(std::vector<std::string>{"dog", "racecar", "car"}, ""),
        make_tuple(std::vector<std::string>{"", "b"}, ""),
        make_tuple(std::vector<std::string>{"ab", "a"}, "a")));
