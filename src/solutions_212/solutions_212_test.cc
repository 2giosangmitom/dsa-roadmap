#include "solutions_212.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_212_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<std::vector<char>>, std::vector<std::string>,
                     std::vector<std::string>>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_212_Test, ) {
  auto [board, words, expected] = GetParam();

  auto actual = solution.findWords(board, words);

  std::sort(actual.begin(), actual.end());
  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_212_Test,
    testing::Values(
        std::make_tuple(std::vector<std::vector<char>>{{'o', 'a', 'a', 'n'},
                                                       {'e', 't', 'a', 'e'},
                                                       {'i', 'h', 'k', 'r'},
                                                       {'i', 'f', 'l', 'v'}},
                        std::vector<std::string>{"oath", "pea", "eat", "rain"},
                        std::vector<std::string>{"eat", "oath"}),
        std::make_tuple(std::vector<std::vector<char>>{{'a'}},
                        std::vector<std::string>{"a"},
                        std::vector<std::string>{"a"}),
        std::make_tuple(std::vector<std::vector<char>>{{'a', 'b'}, {'c', 'd'}},
                        std::vector<std::string>{"abcb"},
                        std::vector<std::string>{})));
