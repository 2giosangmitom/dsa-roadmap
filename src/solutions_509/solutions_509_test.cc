#include "solutions_509.hpp"

#include <gtest/gtest.h>

struct Tt {
    int input;
    int expected;
};

class Solutions_509_Test : public ::testing::TestWithParam<Tt> {
   protected:
    Solution sol;
};

TEST_P(Solutions_509_Test, BottomUp) {
    Tt tc = GetParam();
    EXPECT_EQ(sol.fib(tc.input), tc.expected);
}

TEST_P(Solutions_509_Test, TopDown) {
    Tt tc = GetParam();
    EXPECT_EQ(sol.fib2(tc.input), tc.expected);
}

INSTANTIATE_TEST_SUITE_P(FibTests, Solutions_509_Test,
                         testing::Values(Tt{0, 0}, Tt{1, 1}, Tt{2, 1}, Tt{3, 2},
                                         Tt{4, 3}, Tt{5, 5}, Tt{10, 55},
                                         Tt{15, 610}, Tt{20, 6765},
                                         Tt{30, 832040}));
