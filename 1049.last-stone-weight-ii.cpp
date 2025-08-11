/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int numStones = stones.size();
        int sum = 0;
        for(int i = 0; i < stones.size(); i ++){
            sum += stones[i];
        }
        int target = sum / 2 + sum % 2;
        int dp[target + 1];
        for(int i = 0; i < target + 1; i ++){
            dp[i] = 0;
        }
        for(int i = 0; i < stones.size(); i ++){
            for(int j = target; j >= stones[i]; j --){
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return abs(dp[target] * 2 - sum);
    }
};
// @lc code=end

