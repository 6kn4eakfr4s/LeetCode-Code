/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i ++){
            sum += nums[i];
        }        
        if(sum % 2)return false;
        int target = sum / 2;
        //if we get some numbers with half of sum, the other half must have the same sum
        int numSize = nums.size();
        int dp[target + 1];
        for(int i = 0; i < target + 1; i ++){
            dp[i] = 0;
        }
        for(int i = 0; i < numSize; i ++){
            for(int j = target; j >= nums[i]; j --){
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[target] == target;
    }
};
// @lc code=end

