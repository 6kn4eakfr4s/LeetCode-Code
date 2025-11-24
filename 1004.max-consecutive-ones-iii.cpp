/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lo = 0;
        int hi = 0;
        int cntFlip = 0;
        int cnt = 0;
        int ans = 0;
        if(k == 0){
            for(int i = 0; i < nums.size(); i ++){
                if(nums[i] == 1){
                    cnt ++;
                    ans = max(ans, cnt);
                }
                else{
                    cnt = 0;
                }
            }
            return ans;
        }
        while(hi < nums.size()){
            if(nums[hi] == 0){
                if(cntFlip < k){
                    cntFlip ++;
                    hi ++;
                    cnt ++;
                    ans = max(ans, cnt);
                }
                else{
                    while(lo < hi){
                        if(nums[lo] == 0){
                            cntFlip --;
                            cnt --;
                            lo ++;
                            break;
                        }
                        else{
                            lo ++;
                            cnt --;
                        }
                        
                    }
                    hi ++;
                    cnt ++;
                    cntFlip ++;
                    ans = max(ans, cnt);
                }
            }
            else{
                cnt ++;
                hi ++;
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};
// @lc code=end

