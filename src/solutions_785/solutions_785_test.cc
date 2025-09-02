#include "solutions_785.hpp"

#include <gtest/gtest.h>

TEST(Solutions785, Test1) {
    Solution s;
    vector<vector<int>> graph = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    EXPECT_EQ(s.isBipartite(graph), true);
}

TEST(Solutions785, Test2) {
    Solution s;
    vector<vector<int>> graph = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
    EXPECT_EQ(s.isBipartite(graph), false);
}

TEST(Solutions785, Test3) {
    Solution s;
    vector<vector<int>> graph = {{},           {2, 4, 6}, {1, 4, 8, 9}, {7, 8},
                                 {1, 2, 8, 9}, {6, 9},    {1, 5, 7},    {3, 6},
                                 {2, 3, 4},    {2, 4, 5}};
    EXPECT_EQ(s.isBipartite(graph), false);
}

TEST(Solutions785, Test4) {
    Solution s;
    vector<vector<int>> graph = {{1, 4}, {0, 2}, {1, 3}, {2, 4}, {0, 3}};
    EXPECT_EQ(s.isBipartite(graph), false);
}

TEST(Solutions785, Test5) {
    Solution s;
    vector<vector<int>> graph = {{1}, {0}, {4}, {4}, {2, 3}};
    EXPECT_EQ(s.isBipartite(graph), true);
}
