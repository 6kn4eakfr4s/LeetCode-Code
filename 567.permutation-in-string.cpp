/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
#include <vector>
class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length()) {
      return false;
    }
    std::vector<int> s1_freq(26, 0);
    std::vector<int> s2_freq(26, 0);
    for (int i = 0; i < s1.size(); ++i) {
      ++s1_freq[s1[i] - 'a'];
      ++s2_freq[s2[i] - 'a'];
    }
    if (s1_freq == s2_freq) {
      return true;
    }
    for (int i = s1.length(); i < s2.length(); ++i) {
      --s2_freq[s2[i - s1.length()] - 'a'];
      ++s2_freq[s2[i] - 'a'];
      if (s1_freq == s2_freq) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
