/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <unordered_map>
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int max_length = 0;
    std::unordered_map<char, bool> counter;
    int head = 0;
    int tail = 0;
    int cur_length = 0;
    while (head < s.size()) {
      if (!counter[s[head]]) {
        counter[s[head]] = true;
        ++head;
        ++cur_length;
        max_length = std::max(max_length, cur_length);
      } else {
        while (counter[s[head]]) {
          counter[s[tail++]] = false;
          --cur_length;
        }
      }
    }
    return max_length;
  }
};
// @lc code=end
