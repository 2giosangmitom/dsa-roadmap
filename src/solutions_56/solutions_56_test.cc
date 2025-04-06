#include "solutions_56.hpp"
#include <gtest/gtest.h>
#include <tuple>

class Solutions_56_Test : public testing::TestWithParam<
                              tuple<vector<vector<int>>, vector<vector<int>>>> {
protected:
  Solution solutions;
};

TEST_P(Solutions_56_Test, ) {
  auto [intervals, expected] = GetParam();

  auto actual = solutions.merge(intervals);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_56_Test,
    testing::Values(
        make_tuple(vector<vector<int>>{{1, 3}, {2, 6}, {8, 10}, {15, 18}},
                   vector<vector<int>>{{1, 6}, {8, 10}, {15, 18}}),
        make_tuple(vector<vector<int>>{{1, 4}, {4, 5}},
                   vector<vector<int>>{{1, 5}}),
        make_tuple(vector<vector<int>>{{5, 6}, {1, 3}},
                   vector<vector<int>>{{1, 3}, {5, 6}}),
        make_tuple(vector<vector<int>>{{1, 4}, {2, 3}},
                   vector<vector<int>>{{1, 4}})));
