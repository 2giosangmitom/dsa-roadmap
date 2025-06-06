#include "solutions_79.hpp"

#include <gtest/gtest.h>

class Solutions_79_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<std::vector<char>>, std::string, bool>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_79_Test, ) {
  auto [board, word, expected] = GetParam();
  EXPECT_EQ(solution.exist(board, word), expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_79_Test,
    testing::Values(
        std::make_tuple(std::vector<std::vector<char>>{{'A', 'B', 'C', 'E'},
                                                       {'S', 'F', 'C', 'S'},
                                                       {'A', 'D', 'E', 'E'}},
                        "ABCCED", true),
        std::make_tuple(std::vector<std::vector<char>>{{'A', 'B'}, {'C', 'D'}},
                        "ABCD", false),
        std::make_tuple(std::vector<std::vector<char>>{{'A'}}, "A", true),
        std::make_tuple(std::vector<std::vector<char>>{{'A'}}, "B", false)));