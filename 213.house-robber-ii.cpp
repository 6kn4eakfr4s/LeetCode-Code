/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1)
            return nums[0];
        else if (nums.size() == 2){
            return max(nums[0], nums[1]);
        }
        else{
            return max(calculateDp(0, nums.size() - 2, nums), calculateDp(1, nums.size() - 1, nums));
        }
    }
    int calculateDp(int start, int end, vector<int>& nums){
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        if(start == end)
            return nums[start];
        if((end - start) == 1){
            return max(nums[end], nums[start]);
        }
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for(int i = start + 2; i <= end; i ++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        } 
        return dp[end];
    }
};
// @lc code=end

