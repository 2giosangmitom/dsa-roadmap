#pragma once

#include <algorithm>
#include <vector>

using std::pair;
using std::vector;

class Solution {
   private:
    vector<pair<int, int>> twoSum(vector<int>& nums, int left, long target) {
        int right = nums.size() - 1;
        vector<pair<int, int>> result;

        while (left < right) {
            long sum = 1L * nums[left] + nums[right];

            if (sum == target) {
                result.push_back({nums[left], nums[right]});

                int leftVal = nums[left];
                int rightVal = nums[right];
                while (left < right && nums[left] == leftVal) left++;
                while (left < right && nums[right] == rightVal) right--;

            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return result;
    }

   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;  // skip duplicates for i

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;  // skip duplicates for j

                long twoSumTarget =
                    static_cast<long>(target) - nums[i] - nums[j];
                auto pairs = twoSum(nums, j + 1, twoSumTarget);

                for (auto& p : pairs) {
                    res.push_back({nums[i], nums[j], p.first, p.second});
                }
            }
        }

        return res;
    }
};
