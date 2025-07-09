#pragma once

#include <numeric>
#include <vector>

using std::vector;

class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> dis(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i - 1] < ratings[i]) {
                dis[i] = dis[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i + 1] < ratings[i]) {
                // If current child already has more candies than their
                // right-side neighbor, keep higher amount
                dis[i] = std::max(dis[i], dis[i + 1] + 1);
            }
        }

        return std::accumulate(dis.begin(), dis.end(), 0);
    }
};
