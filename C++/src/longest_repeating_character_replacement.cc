#include "longest_repeating_character_replacement.hpp"
#include <map>

int Solution::characterReplacement(string s, int k) {
  int highest_freq = 1;
  int max_len = 1;
  int left = 0;
  int right = 0;
  map<char, int> freq;

  while (size_t(right) < s.length()) {
    freq[s[right]]++;
    highest_freq = max(highest_freq, freq[s[right]]);

    int num_chars_to_replace = right - left + 1 - highest_freq;
    if (num_chars_to_replace > k) {
      freq[s[left]]--;
      left++;
    }

    max_len = right - left + 1;
    right++;
  }

  return max_len;
}