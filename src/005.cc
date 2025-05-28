#include "utils.hh"
#include <gtest/gtest.h>
#include <nlohmann/detail/macro_scope.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include <tuple>

class Solution {
private:
  // Expands around the center to find the longest palindromic substring.
  // Returns the start and end indices of the longest palindromic substring.
  std::tuple<int, int> expandAroundCenter(const std::string &s, int left,
                                          int right) {
    while (left >= 0 && static_cast<size_t>(right) < s.size() &&
           s[left] == s[right]) {
      --left;
      ++right;
    }
    return std::make_tuple(left + 1, right - 1);
  }

public:
  // Time Complexity: O(n^2)
  // Space Complexity: O(1)
  std::string longestPalindrome(std::string s) {
    if (s.empty()) {
      return "";
    }

    int start = 0, end = 0;

    for (size_t i = 0; i < s.size(); ++i) {
      // Odd length palindromes
      auto [left1, right1] = expandAroundCenter(s, i, i);
      if (right1 - left1 > end - start) {
        start = left1;
        end = right1;
      }

      // Even length palindromes
      auto [left2, right2] = expandAroundCenter(s, i, i + 1);
      if (right2 - left2 > end - start) {
        start = left2;
        end = right2;
      }
    }

    return s.substr(start, end - start + 1);
  }
};

//-- Test cases for the longestPalindrome function
struct Data {
  std::string s;
  std::vector<std::string> expected;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Data, s, expected);

TEST(Solution, longestPalindrome) {
  auto test_cases = utils::json::loadJsonArray<Data>(TEST_DATA_DIR "/005.json");
  ASSERT_TRUE(test_cases.has_value());

  Solution solution;

  for (const auto &data : test_cases.value()) {
    auto result = solution.longestPalindrome(data.s);
    EXPECT_TRUE(std::find(data.expected.begin(), data.expected.end(), result) !=
                data.expected.end())
        << std::format("Input: {}, Expected one of: {}, Got: {}", data.s,
                       data.expected, result);
  }
}