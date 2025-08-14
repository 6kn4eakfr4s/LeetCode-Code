/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        //dp[i] means the least number of perfect square numbers that sum to i.
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        //dp[i] = min(dp[i], dp[i - j * 2] + 1)
        for(int i = 1; i <= n; i ++){//iterate through numbers.
            for(int j = 1; j <= n; j ++){//iterate through target sum.
                if(j >= i * i && i * i <= n && dp[j - i * i] != INT_MAX){
                    dp[j] = min(dp[j], dp[j - i * i] + 1);
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

