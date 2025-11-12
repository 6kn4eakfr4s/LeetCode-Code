/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 */

// @lc code=start
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int hi = nums.size() - 1;
        int lo= 0;
        int ans = 0;
        while(lo < hi){
            if(nums[lo] + nums[hi] ==k){
                lo ++;
                hi --;
                ans ++;
                continue;
            }
            else if(nums[lo] + nums[hi] < k){
                lo ++;
                continue;
            }
            else{
                hi --;
            }
        }
        return ans;
    }
};
// @lc code=end

