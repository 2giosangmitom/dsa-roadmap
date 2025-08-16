#include "solutions_1971.hpp"

#include <gtest/gtest.h>

class Solutions_1971_Test
    : public testing::TestWithParam<
          tuple<int, vector<vector<int>>, int, int, bool>> {
   protected:
    Solution sol;
};

TEST_P(Solutions_1971_Test, ) {
    auto [n, edges, source, destination, expected] = GetParam();

    auto actual = sol.validPath(n, edges, source, destination);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_1971_Test,
    testing::Values(
        make_tuple(3, vector<vector<int>>{{0, 1}, {1, 2}, {2, 0}}, 0, 2, true),
        make_tuple(6,
                   vector<vector<int>>{{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}},
                   0, 5, false)));
