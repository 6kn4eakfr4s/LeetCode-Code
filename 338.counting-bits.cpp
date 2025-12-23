/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> ans(n + 1, 0);
    int sub = 1;
    for (int i = 1; i <= n; ++i) {
      if(sub * 2 == i) {
        sub = i;
      }
      ans[i] = ans[i - sub] + 1;
    }
    return ans;
  }
};
// @lc code=end

