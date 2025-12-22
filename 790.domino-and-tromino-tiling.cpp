/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 */

// @lc code=start
class Solution {
public:
  int numTilings(int n) {
    const int64_t kMod = 1e9 + 7;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 5;       
    vector<int64_t> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    int64_t sum = 8;
    for (int i = 4; i <= n; ++i) {
      dp[i] = (sum * 2 - dp[i - 1] - dp[i - 2] + 2) % kMod;
      sum += dp[i];
    }
    return dp[n];
  }
};
// @lc code=end

