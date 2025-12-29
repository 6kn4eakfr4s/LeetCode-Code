/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
#include <string>
#include <unordered_map>
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    std::unordered_map<char, int> s_counter;
    for (const auto& c : s) {
      if (s_counter.find(c) != s_counter.end()) {
        ++s_counter[c];
      } else {
        s_counter.insert({c, 1});
      }
    }
    for (const auto& c : t) {
      if (s_counter.find(c) != s_counter.end()) {
        --s_counter[c];
        if (s_counter[c] == 0) {
          s_counter.erase(c);
        }
      } else {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

  