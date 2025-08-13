/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //dp[i][j] means the max subset size that there are
        //at most i 0's and j1's
        //formula: dp[i][j] = max(dp[i][j], dp[i - #0][j - #1] + 1)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        vector<int> num0(strs.size(), 0);
        vector<int> num1(strs.size(), 0);
        for(int i = 0; i < strs.size(); i ++){
            for(int j = 0; j < strs[i].size(); j ++){
                if(strs[i][j] == '0'){
                    num0[i] ++;
                }
                else{
                    num1[i] ++;
                }
            }
            for(int j = m; j >= num0[i]; j --){
                for(int k = n; k >= num1[i]; k --){
                    dp[j][k] = max(dp[j][k], dp[j - num0[i]][k - num1[i]] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

