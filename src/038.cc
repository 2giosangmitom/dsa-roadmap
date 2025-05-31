#include "utils.hh"
#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <sstream>
#include <string>

class Solution {
public:
  std::string countAndSay(int n) {
    if (n == 1)
      return "1";

    auto prev = countAndSay(n - 1);
    std::ostringstream ss;
    size_t prev_len = prev.size(), i = 0, j = 0;

    while (j <= prev_len) {
      if (j == prev_len || prev[i] != prev[j]) {
        ss << j - i << prev[i];
        i = j;
      }
      j++;
    }

    return ss.str();
  }
};

//--- Tests ---
struct Data {
  int n;
  std::string expected;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Data, n, expected);

TEST(SolutionTest, CountAndSay) {
  auto test_cases = utils::json::loadJsonArray<Data>(TEST_DATA_DIR "/038.json");
  ASSERT_TRUE(test_cases.has_value());

  Solution solutions;
  for (auto &tc : test_cases.value()) {
    auto actual = solutions.countAndSay(tc.n);
    EXPECT_EQ(actual, tc.expected);
  }
}
