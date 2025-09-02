#pragma once

#include <vector>
using namespace std;

class Solution {
   private:
    bool dfs(int i, vector<int>& colors, vector<vector<int>>& graph, int c) {
        colors[i] = c;

        for (int neighbor : graph[i]) {
            if (colors[neighbor] == c) {
                return false;
            }

            if (colors[neighbor] == 0 && !dfs(neighbor, colors, graph, -c)) {
                return false;
            }
        }

        return true;
    }

   public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);

        for (int i = 0; i < n; i++) {
            if (colors[i] == 0 && !dfs(i, colors, graph, 1)) {
                return false;
            }
        }

        return true;
    }
};
