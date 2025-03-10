#include <gtest/gtest.h>

#include <unordered_map>
#include <vector>

#include "solutions_528.hpp"

class Solutions_528_Test : public testing::TestWithParam<vector<int>> {
 protected:
  void check_distribution(vector<int>& weights) {
    int numSimulations = 100000;
    Solution sol(weights);

    unordered_map<int, int> counts;
    counts.reserve(weights.size());
    for (int i = 0; i < numSimulations; i++) {
      int idx = sol.pickIndex();
      EXPECT_GE(idx, 0);
      EXPECT_LT(idx, weights.size());
      counts[idx]++;
    }

    int totalWeight = 0;
    for (int w : weights) {
      totalWeight += w;
    }

    // Check if distribution is close to expected
    for (size_t i = 0; i < weights.size(); i++) {
      double expected_probability =
          static_cast<double>(weights[i]) / totalWeight;
      double actual_probability =
          static_cast<double>(counts[i]) / numSimulations;

      EXPECT_NEAR(expected_probability, actual_probability, 0.05)
          << "Index " << i << " with weight " << weights[i] << " occurred "
          << counts[i] << " times out of " << numSimulations;
    }
  }
};

TEST_P(Solutions_528_Test, ) {
  auto w = GetParam();
  check_distribution(w);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_528_Test,
                         testing::Values(vector<int>{1, 4},
                                         vector<int>{1, 2, 5, 20},
                                         vector<int>{3, 4, 5, 6, 7},
                                         vector<int>{1, 2, 3, 4},
                                         vector<int>{1, 1, 1, 1, 1}));
