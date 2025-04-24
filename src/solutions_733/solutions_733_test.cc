#include "solutions_733.hpp"

#include <gtest/gtest.h>

class Solutions_733_Test
    : public testing::TestWithParam<
          tuple<vector<vector<int>>, int, int, int, vector<vector<int>>>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_733_Test, ) {
  auto [image, sr, sc, color, expected] = GetParam();

  auto actual = solution.floodFill(image, sr, sc, color);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_733_Test,
    testing::Values(
        make_tuple(vector<vector<int>>{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}}, 1, 1,
                   2, vector<vector<int>>{{2, 2, 2}, {2, 2, 0}, {2, 0, 1}}),
        make_tuple(vector<vector<int>>{{0, 0, 0}, {0, 0, 0}}, 0, 0, 2,
                   vector<vector<int>>{{2, 2, 2}, {2, 2, 2}}),
        make_tuple(vector<vector<int>>{{0, 0, 0}, {0, 1, 1}}, 1, 1, 1,
                   vector<vector<int>>{{0, 0, 0}, {0, 1, 1}}),
        make_tuple(vector<vector<int>>{{1, 1, 1}, {1, 1, 0}, {1, 0, 1}}, 0, 0,
                   3, vector<vector<int>>{{3, 3, 3}, {3, 3, 0}, {3, 0, 1}}),
        make_tuple(vector<vector<int>>{{1}}, 0, 0, 2,
                   vector<vector<int>>{{2}})));
