#pragma once

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> m;
        int n = edges.size();

        for (auto& edge : edges) {
            ++m[edge[0]];
            ++m[edge[1]];

            if (m[edge[0]] == n) {
                return edge[0];
            }
            if (m[edge[1]] == n) {
                return edge[1];
            }
        }

        return -1;
    }
};
