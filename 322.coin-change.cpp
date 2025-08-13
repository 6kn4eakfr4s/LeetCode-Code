/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        //dp[i] means the min # of coins used to form value i
        dp[0] = 0;
        for(int i = 0; i < coins.size(); i ++){
            for(int j = coins[i]; j <= amount; j ++){
                if(dp[j - coins[i]] != INT_MAX){
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }    
        return dp[amount];
    }
};
// @lc code=end

