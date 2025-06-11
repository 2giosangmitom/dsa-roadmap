#pragma once

#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   private:
    void heapify(unordered_map<string, int> &freq, vector<string> &keys, int n,
                 int index) {
        int max = index;
        int left_child = index * 2 + 1;
        int right_child = index * 2 + 2;

        auto comp = [&freq, &keys](int a, int b) {
            if (freq[keys[a]] == freq[keys[b]]) {
                return keys[a] < keys[b];
            }
            return freq[keys[a]] > freq[keys[b]];
        };

        if (left_child < n && comp(left_child, max)) {
            max = left_child;
        }

        if (right_child < n && comp(right_child, max)) {
            max = right_child;
        }

        if (max != index) {
            swap(keys[max], keys[index]);
            heapify(freq, keys, n, max);
        }
    }

   public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> freq;

        for (string word : words) {
            freq[word]++;
        }

        vector<string> result(k);
        auto keys = freq | ranges::views::keys | ranges::to<vector<string>>();
        int n = keys.size();

        for (int i = keys.size() / 2; i >= 0; i--) {
            heapify(freq, keys, n, i);
        }

        for (int i = 0; i < k; i++) {
            result[i] = keys[0];
            swap(keys[0], keys[n - 1]);
            n--;
            heapify(freq, keys, n, 0);
        }

        return result;
    }
};
