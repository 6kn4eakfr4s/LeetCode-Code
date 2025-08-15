/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        //dp[i] means if the first i characters in s can be formed using dict
        for(int i = 1; i <= s.size(); i ++){
            for(int j = 0; j < wordDict.size(); j ++){
                if(wordDict[j].size() > i){
                    continue;
                }
                if(dp[i - wordDict[j].size()] && 
                    s.substr(i - wordDict[j].size(), wordDict[j].size()) == wordDict[j]
                ) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

