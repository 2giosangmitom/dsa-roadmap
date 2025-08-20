#include "solutions_1791.hpp"

#include <gtest/gtest.h>

TEST(SolutionTest, SimpleCase) {
    Solution sol;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
    EXPECT_EQ(sol.findCenter(edges), 2);
}

TEST(SolutionTest, TwoEdges) {
    Solution sol;
    vector<vector<int>> edges = {{1, 2}, {2, 3}};
    EXPECT_EQ(sol.findCenter(edges), 2);
}

TEST(SolutionTest, CenterIsFirstNode) {
    Solution sol;
    vector<vector<int>> edges = {{5, 1}, {5, 2}, {5, 3}, {5, 4}};
    EXPECT_EQ(sol.findCenter(edges), 5);
}

TEST(SolutionTest, CenterIsSecondNode) {
    Solution sol;
    vector<vector<int>> edges = {{7, 10}, {10, 11}, {12, 10}, {13, 10}};
    EXPECT_EQ(sol.findCenter(edges), 10);
}

TEST(SolutionTest, InvalidCase_NoCenter) {
    Solution sol;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}};  // not a star graph
    EXPECT_EQ(sol.findCenter(edges), -1);
}
