#include "solutions_6.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_6_Test
    : public testing::TestWithParam<std::tuple<std::string, int, std::string>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_6_Test, ) {
    auto [s, numRows, expected] = GetParam();

    auto actual = solutions.convert(s, numRows);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_6_Test,
    testing::Values(std::make_tuple("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"),
                    std::make_tuple("PAYPALISHIRING", 4, "PINALSIGYAHRPI"),
                    std::make_tuple("A", 1, "A"),
                    std::make_tuple("LUFFYSTRAWHAT", 3, "LYATUFSRWAFTH")));