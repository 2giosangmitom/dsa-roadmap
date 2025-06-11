#include "solutions_231.hpp"

#include <gtest/gtest.h>
using namespace std;

class Solutions_231_Test : public testing::TestWithParam<tuple<int, bool>> {
   protected:
    Solution solution;
};

TEST_P(Solutions_231_Test, ) {
    auto [input, expected] = GetParam();

    bool actual = solution.isPowerOfTwo(input);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_231_Test,
    testing::Values(
        make_tuple(1, true), make_tuple(2, true), make_tuple(4, true),
        make_tuple(8, true), make_tuple(16, true), make_tuple(32, true),
        make_tuple(64, true), make_tuple(128, true), make_tuple(256, true),
        make_tuple(512, true), make_tuple(1024, true), make_tuple(2048, true),
        make_tuple(4096, true), make_tuple(8192, true), make_tuple(16384, true),
        make_tuple(32768, true), make_tuple(65536, true),
        make_tuple(131072, true), make_tuple(262144, true),
        make_tuple(524288, true), make_tuple(1048576, true),
        make_tuple(2097152, true), make_tuple(4194304, true),
        make_tuple(8388608, true), make_tuple(16777216, true),
        make_tuple(33554432, true), make_tuple(67108864, true),
        make_tuple(134217728, true), make_tuple(268435456, true),
        make_tuple(536870912, true), make_tuple(1073741824, true),
        make_tuple(0, false), make_tuple(-1, false), make_tuple(-2, false),
        make_tuple(3, false), make_tuple(5, false), make_tuple(6, false),
        make_tuple(7, false), make_tuple(9, false), make_tuple(10, false),
        make_tuple(15, false), make_tuple(17, false)));
