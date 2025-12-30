/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
  bool IsAlphaNumeric(char c) {
    if ('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' || '0' <= c && c <= '9') {
      return true;
    }
    return false;
  }
  bool isPalindrome(string s) {
    if (s == "") {
      return true;
    }
    int l_pointer = 0;    
    int r_pointer = s.length() - 1;
    while (l_pointer < r_pointer) {
      while (l_pointer < s.length() && !IsAlphaNumeric(s[l_pointer])) {
        ++l_pointer;
      }
      while (r_pointer >= 0 && !IsAlphaNumeric(s[r_pointer])) {
        --r_pointer;
      }
      if (l_pointer >= r_pointer) {
        break;
      }
      if ('A' <= s[l_pointer] && s[l_pointer] <= 'Z') {
        s[l_pointer] = s[l_pointer] - 'A' + 'a';
      }
      if ('A' <= s[r_pointer] && s[r_pointer] <= 'Z') {
        s[r_pointer] = s[r_pointer] - 'A' + 'a';
      }
      if (s[l_pointer] != s[r_pointer]) {
        return false;
      }
      ++l_pointer;
      --r_pointer;
    }
    return true;
  }
};
// @lc code=end

