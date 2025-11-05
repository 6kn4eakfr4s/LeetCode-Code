/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> results(nums.size(), 1);
        int left = 1, right = 1;
        for(int i = 1; i < nums.size(); i ++){
            left *= nums[i - 1];
            results[i] *= left;
        }        
        for(int i = nums.size() - 2; i >= 0; i --){
            right *= nums[i + 1];
            results[i] *= right;
        }
        return results;
    }
};
// @lc code=end

