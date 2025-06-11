#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int subarraySum(vector<int> &nums, int k) {
        int result = 0;

        unordered_map<int, int> prefix_sum_map = {{0, 1}};
        int current_prefix_sum = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            current_prefix_sum += nums[i];
            int complement = current_prefix_sum - k;

            if (prefix_sum_map.contains(complement)) {
                result += prefix_sum_map[complement];
            }
            prefix_sum_map[current_prefix_sum]++;
        }

        return result;
    }
};
