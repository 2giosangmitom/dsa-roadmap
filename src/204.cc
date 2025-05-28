#include "utils.hh"
#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <vector>

class Solution {
public:
  // Time complexity: O(n log log n), using the Sieve of Eratosthenes
  // Space complexity: O(n) for the sieve array
  int countPrimes(int n) {
    // No prime less than 2
    if (n < 2)
      return 0;

    // Sieve of Eratosthenes
    // Wiki: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
    std::vector<bool> sieve(n, true);
    sieve[0] = sieve[1] = false;

    int result = n - 2;

    for (int prime = 2; prime * prime < n; prime++) {
      if (sieve[prime]) {
        for (int j = prime * prime; j < n; j += prime) {
          if (sieve[j]) {
            sieve[j] = false;
            result--;
          }
        }
      }
    }

    return result;
  }
};

//-- Test cases for countPrimes function
struct Data {
  int n;
  int expected;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Data, n, expected);

TEST(SolutionTest, CountPrimes) {
  auto test_cases = utils::json::loadJsonArray<Data>(TEST_DATA_DIR "/204.json");
  ASSERT_TRUE(test_cases.has_value());

  Solution solution;
  for (auto &tc : test_cases.value()) {
    int actual = solution.countPrimes(tc.n);
    EXPECT_EQ(actual, tc.expected);
  }
}
