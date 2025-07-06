#pragma once

#include <numeric>
#include <vector>

using std::vector;

class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (std::accumulate(gas.begin(), gas.end(), 0) <
            std::accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }

        int n = gas.size();
        int start = 0;
        int tank = 0;

        for (int i = 0; i < n; i++) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        return start;
    }
};
