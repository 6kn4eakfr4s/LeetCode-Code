/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        /*
        dp[i][0] means the max profit achieved doing nothing and holding nothing 
            on day i
        dp[i][1] means the max profit achieved buying in stock on day i
        dp[i][2] means the max profit achieved selling stock on day i;
        dp[i][3] means the max profit achieved holding a stock on day i 
            (including buyin a stock on day i and hold it);
        */
        if(prices.size() < 2)
            return 0;

        
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        dp[1][3] = max(-prices[0], -prices[1]);
        dp[1][2] = max(0, prices[1] - prices[0]);
        dp[1][1] = -prices[1];
        for(int i = 2; i < prices.size(); i ++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2]);
            dp[i][1] = dp[i - 1][0] - prices[i];
            dp[i][2] = dp[i - 1][3] + prices[i];
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][1]);
            dp[i][3] = max(dp[i][3], dp[i][1]);
        }
        return max(dp[prices.size() - 1][2], dp[prices.size() - 1][0]);
    }
};
// @lc code=end

