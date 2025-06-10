#include "solutions_39.hpp"

#include <gtest/gtest.h>

#include <tuple>
#include <vector>

class Solutions_39_Test
    : public testing::TestWithParam<
          std::tuple<vector<int>, int, vector<vector<int>>>> {
 protected:
  Solution solutions;
};

TEST_P(Solutions_39_Test, ) {
  auto [candidates, target, expected] = GetParam();

  auto actual = solutions.combinationSum(candidates, target);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_39_Test,
    testing::Values(make_tuple(vector<int>{2, 3, 6, 7}, 7,
                               vector<vector<int>>{{2, 2, 3}, {7}}),
                    make_tuple(vector<int>{2, 3, 5}, 8,
                               vector<vector<int>>{
                                   {2, 2, 2, 2}, {2, 3, 3}, {3, 5}}),
                    make_tuple(vector<int>{2}, 1, vector<vector<int>>{}),
                    make_tuple(vector<int>{1}, 1, vector<vector<int>>{{1}}),
                    make_tuple(vector<int>{3, 4, 5}, 9,
                               vector<vector<int>>{{3, 3, 3}, {4, 5}})));