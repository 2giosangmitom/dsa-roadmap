#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <utils.hh>
#include <vector>

class Solution {
public:
  // Overall time complexity is O(n) where n is the number of elements in the
  // input vector. The space complexity is also O(n) due to the hash map used to
  // store the numbers and their indices.
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    // Create a hash map to store the numbers and their indices
    std::unordered_map<int, int> num_map;
    size_t n = nums.size();

    for (size_t i = 0; i < n; ++i) {
      // Calculate the complement of the current number
      // that would sum up to the target
      int complement = target - nums[i];
      auto it = num_map.find(complement);

      // If the complement exists in the map, we found a solution
      if (it != num_map.end()) {
        return {it->second, static_cast<int>(i)};
      }
      // Otherwise, store the current number and its index in the map.
      // We can access the index later in O(1) time.
      num_map[nums[i]] = static_cast<int>(i);
    }

    return {}; // Return an empty vector if no solution is found
  }
};

//-- Test cases for the twoSum function
struct Data {
  std::vector<int> nums;
  int target;
  std::vector<int> expected;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Data, nums, target, expected);

TEST(SolutionTest, TwoSum) {
  auto test_cases = utils::json::loadJsonArray<Data>(TEST_DATA_DIR "/001.json");
  ASSERT_TRUE(test_cases.has_value());

  Solution solution;

  for (auto &item : test_cases.value()) {
    auto result = solution.twoSum(item.nums, item.target);
    EXPECT_EQ(result, item.expected);
  }
}
