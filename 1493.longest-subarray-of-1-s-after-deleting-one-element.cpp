/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        bool del = false;
        int cnt = 0;
        int ans = 0;
        int lo = 0;
        int hi = 0;
        while(hi < nums.size()){
            if(nums[hi] == 1){
                cnt ++;
                hi ++;
                ans = max(ans, cnt);
            }
            else{
                if(del){
                    while(lo < hi){
                        if(nums[lo] == 0){
                            lo ++;
                            hi ++;
                            break;
                        }
                        cnt --;
                        lo ++;
                    }
                    ans = max(ans, cnt);
                }
                else{
                    del = true;
                    hi ++;
                    ans = max(ans, cnt);
                }
            }
        }
        if(!del){
            ans --;
        }
        return ans;
    }
};
// @lc code=end

