/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        long min_num = LONG_MAX, mid_num = LONG_MAX, max_num = LONG_MAX;
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i] < min_num){
                min_num = nums[i];
            }
            else if(nums[i] < mid_num && nums[i] > min_num){
                mid_num = nums[i];
            }
            else if(nums[i] < max_num && nums[i] > mid_num){
                max_num = nums[i];
            }
        }
        return min_num != LONG_MAX && mid_num != LONG_MAX && max_num != LONG_MAX;
    }
};
// @lc code=end

