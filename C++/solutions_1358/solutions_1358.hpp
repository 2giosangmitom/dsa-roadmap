#pragma once

#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int numberOfSubstrings(string s) {
    int total = 0;
    int len = s.size();

    int left = 0;
    int right = 0;

    vector<int> freq(3, 0);

    while (right < len) {
      freq[s[right] - 'a']++;

      while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
        freq[s[left++] - 'a']--;
        total += len - right;
      }
      right++;
    }

    return total;
  }
};
