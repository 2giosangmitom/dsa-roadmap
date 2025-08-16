#pragma once

#include <stack>
#include <vector>
using namespace std;

class Solution {
   private:
    vector<vector<int>> buildAdjList(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n, vector<int>());

        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back((edge[0]));
        }

        return adjList;
    }

   public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        if (source == destination) {
            return true;
        }

        vector<bool> seen(n, false);
        auto adjList = buildAdjList(n, edges);
        stack<int> s;
        s.push(source);
        seen[source] = true;

        while (!s.empty()) {
            auto top = s.top();
            s.pop();

            for (int neighbor : adjList[top]) {
                if (!seen[neighbor]) {
                    if (neighbor == destination) {
                        return true;
                    }
                    s.push(neighbor);
                    seen[neighbor] = true;
                }
            }
        }

        return false;
    }
};
