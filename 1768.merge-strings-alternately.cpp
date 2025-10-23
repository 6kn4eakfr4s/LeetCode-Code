/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int minLength = min(word1.length(), word2.length());
        string ans = "";
        for(int i = 0; i < minLength; i ++){
            ans += word1[i];
            ans += word2[i];
        }
        if(word1.length() > minLength){
            for(int i = minLength; i < word1.length(); i++){
                ans += word1[i];
            }
        }
        else if(word2.length() > minLength){
            for(int i = minLength; i < word2.length(); i ++){
                ans += word2[i];
            }
        }
        return ans;
    }
};
// @lc code=end

