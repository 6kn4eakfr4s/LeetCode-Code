/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, 0)));
        //dp[i][j][k] means max money on day i with j stock and k trades.
        dp[0][1][0] = - prices[0];
        dp[0][1][1] = - prices[0];
        for(int i = 1; i < prices.size(); i ++){
            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][1][0] + prices[i]);
            dp[i][1][0] = max(dp[i - 1][1][0], dp[i - 1][0][0] - prices[i]);
            dp[i][1][1] = max(dp[i - 1][1][1], dp[i - 1][0][1] - prices[i]);
            dp[i][0][2] = max(dp[i - 1][0][2], dp[i - 1][1][1] + prices[i]);
        }
        return max(dp[prices.size() - 1][0][2], dp[prices.size() - 1][0][1]);
    }
};
// @lc code=end

