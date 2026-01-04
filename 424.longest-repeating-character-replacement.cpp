/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
public:
  int characterReplacement(string s, int k) {
    int left = 0;
    int right = 0;
    std::vector<int> freq(26, 0);
    int max_freq = 0;
    int max_length = 0;
    while (right < s.size()) {
      max_freq = std::max(max_freq, ++freq[s[right] - 'A']);
      while (right - left + 1 > k + max_freq) {
        --freq[s[left++] - 'A'];
      }
      max_length = std::max(max_length, right - left + 1);
      ++right;
    }
    return max_length;
  }
};
// @lc code=end

