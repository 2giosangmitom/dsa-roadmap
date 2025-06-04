#include "utils.hh"
#include <gtest/gtest.h>
#include <nlohmann/detail/macro_scope.hpp>
#include <numeric>
#include <string>
#include <vector>

class Solution {
public:
  std::string convert(std::string s, int numRows) {
    if (numRows == 1)
      return s;

    std::vector<std::string> rows(numRows);

    int dir = -1;
    int i = 0;
    for (char c : s) {
      if (i == 0 || i == numRows - 1)
        dir *= -1;

      rows[i].push_back(c);

      i += dir;
    }

    return std::accumulate(rows.begin(), rows.end(), std::string{});
  }
};

//-- Tests
struct Data {
  std::string s;
  int numRows;
  std::string expected;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Data, s, numRows, expected);

TEST(SolutionTest, ZigzagConversion) {
  auto test_cases = utils::json::loadJsonArray<Data>(TEST_DATA_DIR "/006.json");
  ASSERT_TRUE(test_cases.has_value());

  Solution solution;

  for (auto &[s, numRows, expected] : test_cases.value()) {
    auto actual = solution.convert(s, numRows);
    EXPECT_EQ(actual, expected);
  }
}
