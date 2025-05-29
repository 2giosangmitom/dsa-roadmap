#include "utils.hh"
#include <cmath>
#include <cstdint>
#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

class Solution {
public:
  // Time complexity: O(log N), where N is the input number
  // Space complexity: O(1)
  bool isPalindrome(int x) {
    // Negative numbers and numbers end with 0 is not a palindrome number
    if (x < 0 || (x % 10 == 0 && x != 0))
      return false;

    // Number with 1 digit is a palindrome number
    if (x < 10)
      return true;

    // Just reverse a half of x
    uint16_t num_digits = log10(x) + 1;
    int n = 0;
    for (uint16_t i = 1; i <= num_digits / 2; i++) {
      n = n * 10 + x % 10;
      x /= 10;
    }

    return n == x || n == x / 10;
  }
};

//-- Test cases
struct Data {
  int x;
  bool expected;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Data, x, expected);

TEST(SolutionTest, PalindromeNumber) {
  auto test_cases = utils::json::loadJsonArray<Data>(TEST_DATA_DIR "/009.json");
  ASSERT_TRUE(test_cases.has_value());

  Solution solution;

  for (auto &tc : test_cases.value()) {
    bool actual = solution.isPalindrome(tc.x);
    EXPECT_EQ(actual, tc.expected) << std::format("Failed for x = {}", tc.x);
  }
}
