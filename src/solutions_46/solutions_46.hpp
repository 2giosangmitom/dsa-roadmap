#pragma once

#include <unordered_set>
#include <vector>

class Solution {
   private:
    void solve(const std::vector<int>& nums,
               std::vector<std::vector<int>>& result,
               std::vector<int>& candidate, std::unordered_set<int>& used) {
        if (candidate.size() == nums.size()) {
            result.push_back(candidate);
            return;
        }

        for (const int& num : nums) {
            if (!used.contains(num)) {
                candidate.push_back(num);
                used.insert(num);
                solve(nums, result, candidate, used);
                candidate.pop_back();
                used.erase(num);
            }
        }
    }

   public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> candidate;
        std::unordered_set<int> used;

        solve(nums, result, candidate, used);

        return result;
    }
};
