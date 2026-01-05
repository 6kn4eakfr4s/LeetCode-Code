/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <vector>
class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.size() < t.size()) {
      return "";
    }
    const int SIZE = 128;
    std::vector<int> s_freq(SIZE, 0);
    std::vector<int> t_freq(SIZE, 0);
    int required = 0;
    int formed = 0;
    for (int i = 0; i < t.size(); ++i) {
      ++t_freq[t[i]];
      if (t_freq[t[i]] == 1) {
        ++required;
      }
    }
    int r = 0;
    int l = 0;
    int min_window = INT_MAX;
    int min_window_start = -1;
    while (r < s.size()) {
      ++s_freq[s[r]];
      if (s_freq[s[r]] == t_freq[s[r]] && t_freq[s[r]] > 0) {
        ++formed;
        if (formed >= required) {
          if (r - l + 1 < min_window) {
            min_window = r - l + 1;
            min_window_start = l;
          }
        }
      }
      ++r;
      while (formed >= required) {
        if (r - l < min_window) {
          min_window = r - l;
          min_window_start = l;
        }
        --s_freq[s[l]];
        if (s_freq[s[l]] == t_freq[s[l]] - 1) {
          --formed;
        }
        ++l;
      }
    }
    if (min_window_start == -1) {
      return "";
    } else {
      return s.substr(min_window_start, min_window);
    }
  }
};
// @lc code=end
