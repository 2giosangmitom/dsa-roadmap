#include "../src/reverse_string.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
using namespace std;

class ReverseStringTest
    : public testing::TestWithParam<tuple<vector<char>, vector<char>>> {
protected:
  Solution solution;
};

TEST_P(ReverseStringTest, ReverseString) {
  vector<char> s;
  vector<char> expected;
  tie(s, expected) = GetParam();

  solution.reverseString(s);

  EXPECT_EQ(s, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , ReverseStringTest,
    testing::Values(make_tuple(vector<char>{'h', 'e', 'l', 'l', 'o'},
                               vector<char>{'o', 'l', 'l', 'e', 'h'}),
                    make_tuple(vector<char>{'H', 'a', 'n', 'n', 'a', 'h'},
                               vector<char>{'h', 'a', 'n', 'n', 'a', 'H'}),
                    make_tuple(vector<char>{'A', 'B', 'C', 'D', 'E'},
                               vector<char>{'E', 'D', 'C', 'B', 'A'}),
                    make_tuple(vector<char>{'a'}, vector<char>{'a'}),
                    make_tuple(vector<char>{}, vector<char>{}),
                    make_tuple(vector<char>{'1', '2', '3', '4', '5'},
                               vector<char>{'5', '4', '3', '2', '1'}),
                    make_tuple(vector<char>{'!', '@', '#', '$', '%'},
                               vector<char>{'%', '$', '#', '@', '!'}),
                    make_tuple(vector<char>{' ', ' ', ' ', ' '},
                               vector<char>{' ', ' ', ' ', ' '}),
                    make_tuple(vector<char>{'a', 'b', ' ', 'c'},
                               vector<char>{'c', ' ', 'b', 'a'})));