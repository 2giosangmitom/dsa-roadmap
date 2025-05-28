#include "utils.hh"
#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <string>
#include <unordered_map>

class Solution {
public:
  // Time complexity: O(n), where n is the length of the string s.
  // Space complexity: O(k), where k is the size of the character set used in
  // the string.
  int lengthOfLongestSubstring(std::string s) {
    int result = 0;
    size_t i = 0, j = 0;
    size_t n = s.size();

    // Using an unordered_map to store the last seen index of each character
    std::unordered_map<char, size_t> seen;

    while (j < n) {
      auto it = seen.find(s[j]);
      // If the character is already seen and its last index is within the
      // current window update the start index i to the next index after the
      // last seen index of this character This ensures that we do not count the
      // repeating character in the current substring If the character is not
      // seen or its last index is before the current start index i we can
      // safely include it in the current substring
      if (it != seen.end() && it->second >= i) {
        i = it->second + 1;
      }
      seen[s[j]] = j; // Update the last seen index of the character s[j]
      // Calculate the length of the current substring and update the result
      // if it is greater than the previous result
      result = std::max(static_cast<int>(j - i + 1), result);
      j++; // Move the end index j to the right to expand the window
    }

    return result;
  }
};

//-- Test cases for lengthOfLongestSubstring function
struct Data {
  std::string input;
  int expected;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Data, input, expected);

TEST(SolutionTest, LongestSubstringWithoutRepeatingCharacters) {
  auto test_cases = utils::json::loadJsonArray<Data>(TEST_DATA_DIR "/003.json");
  ASSERT_TRUE(test_cases.has_value());

  Solution solution;

  for (auto &tc : test_cases.value()) {
    int actual = solution.lengthOfLongestSubstring(tc.input);
    EXPECT_EQ(actual, tc.expected)
        << std::format("Failed for s: \"{}\"", tc.input);
  }
}
