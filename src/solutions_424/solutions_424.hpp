#pragma once

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int characterReplacement(string s, int k) {
    unordered_map<char, int> freq;
    size_t left = 0, right = 0;
    int max_len = 0, max_freq = 0;

    while (right < s.size()) {
      freq[s[right]]++;
      max_freq = max(max_freq, freq[s[right]]);

      int num_chars_to_replace = right - left + 1 - max_freq;

      if (num_chars_to_replace > k) {
        freq[s[left++]]--;
      }

      max_len = right - left + 1;
      right++;
    }

    return max_len;
  }
};
