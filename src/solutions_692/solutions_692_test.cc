#include "solutions_692.hpp"

#include <gtest/gtest.h>

#include <algorithm>
#include <tuple>

class Solutions_692_Test : public testing::TestWithParam<
                               tuple<vector<string>, int, vector<string>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_692_Test, ) {
    auto [words, k, expected] = GetParam();
    sort(expected.begin(), expected.end());

    auto actual = solutions.topKFrequent(words, k);
    sort(actual.begin(), actual.end());

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_692_Test,
    testing::Values(
        make_tuple(vector<string>{"i", "love", "leetcode", "i", "love",
                                  "coding"},
                   2, vector<string>{"i", "love"}),
        make_tuple(vector<string>{"the", "day", "is", "sunny", "the", "the",
                                  "the", "sunny", "is", "is"},
                   4, vector<string>{"the", "is", "sunny", "day"})));
