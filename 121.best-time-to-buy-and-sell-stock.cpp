/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int answer = 0;
        int buyPrice = prices[0];
        for(int i = 1; i < prices.size(); i ++){
            answer = max(answer, prices[i] - buyPrice);
            buyPrice = min(buyPrice, prices[i]);
        }
        return answer; 
    }
};
// @lc code=end

