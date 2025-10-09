/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int counter = 1;
        int result = 1;
        for(int i = 1; i < nums.size(); i ++){
            if(nums[i] > nums[i - 1]){
                counter ++;
                result = max(result, counter);
            }
            else{
                counter = 1;
            }
        }        
        return result;
    }
};
// @lc code=end

