/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        //dp[i][0] means max cash w/o stock
        //dp[i][1] means max cash w/ stock    
        dp[0][1] = -prices[0];
        for(int i = 1; i < prices.size(); i ++){
            dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        }
        return dp[prices.size() - 1][0];
    }
};
// @lc code=end

