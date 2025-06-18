#include "solutions_392.hpp"

#include <gtest/gtest.h>

#include <string>

using namespace std;

struct Tt {
    string s;
    string t;
    bool expected;
};

class Solutions_392_Test : public testing::TestWithParam<Tt> {
   protected:
    Solution sol;
};

TEST_P(Solutions_392_Test, HandlesVariousCases) {
    const auto& param = GetParam();
    EXPECT_EQ(sol.isSubsequence(param.s, param.t), param.expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_392_Test,
    testing::Values(Tt{"abc", "ahbgdc", true}, Tt{"axc", "ahbgdc", false},
                    Tt{"", "ahbgdc", true}, Tt{"abc", "", false},
                    Tt{"abc", "abc", true}, Tt{"abc", "aabbcc", true},
                    Tt{"aec", "abcde", false}, Tt{"aaaaaa", "bbaaaa", false}));
