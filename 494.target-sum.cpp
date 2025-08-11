/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i ++){
            sum += nums[i];
        }
        if(abs(target) > sum)return 0;
        if((target + sum) % 2) return 0;
        int right = (target + sum) / 2;
        int dp[right + 1];
        for(int i = 0; i < right + 1; i ++){
            dp[i] = 0;
        }
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i ++){
            for(int j = right; j >= nums[i]; j --){
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[right];

    }
};
// @lc code=end

