/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change II
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int coinSize = coins.size();
        // vector<vector<int>> dp(coinSize, vector<int>(amount + 1, 0));
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < coinSize; i ++){
            for(int j = coins[i]; j <= amount; j ++){
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
// @lc code=end

