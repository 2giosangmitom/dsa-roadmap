#include "find_all_anagrams_in_string.hpp"
#include <array>
#include <vector>

vector<int> Solution::findAnagrams(string s, string p) {
  int len_s = s.size();
  int len_p = p.size();

  if (len_p > len_s) {
    return {};
  }

  array<int, 26> frequencies;
  array<int, 26> expected_frequencies;
  frequencies.fill(0);
  expected_frequencies.fill(0);

  vector<int> result;

  for (const char &c : p) {
    expected_frequencies[int{c} - int{'a'}]++;
  }

  int left = 0, right = 0;
  while (right < len_s) {
    frequencies[int{s[right]} - int{'a'}]++;

    if (right - left + 1 == len_p) {
      if (expected_frequencies == frequencies) {
        result.push_back(left);
      }
      frequencies[int{s[left]} - int{'a'}]--;
      left++;
    }
    right++;
  }

  return result;
}