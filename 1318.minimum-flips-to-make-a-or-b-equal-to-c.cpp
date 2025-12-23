/*
 * @lc app=leetcode id=1318 lang=cpp
 *
 * [1318] Minimum Flips to Make a OR b Equal to c
 */

// @lc code=start
class Solution {
public:
  int minFlips(int a, int b, int c) {
    int ans = 0;
    for(int i = 0; i < 32; ++i) {
      if ((a % 2 | b % 2) != c % 2) {
        if (!(c % 2) && a % 2 && b % 2) {
          ++ans;
        }
        ++ans;
      }
      a = a >> 1;
      b = b >> 1;
      c = c >> 1;
    }
    return ans;
  }
};
// @lc code=end

