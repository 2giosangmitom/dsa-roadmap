#pragma once

#include <vector>
using namespace std;

class Solution {
   private:
    int find_insert_pos(vector<int>& res, int target) {
        int left = 0;
        int right = res.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (res[mid] == target) {
                return mid;
            }

            if (target < res[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (res.empty() || res.back() < nums[i]) {
                res.push_back(nums[i]);
            } else {
                res[find_insert_pos(res, nums[i])] = nums[i];
            }
        }
        return res.size();
    }
};
