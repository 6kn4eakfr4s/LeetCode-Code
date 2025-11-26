/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()){
            return false;
        }
        vector<int> bucket1(26, 0);
        vector<int> bucket2(26, 0);
        for(int i = 0; i < word1.size(); i ++){
            bucket1[word1[i] - 'a'] ++;
            bucket2[word2[i] - 'a'] ++;
        }
        for(int i = 0; i < 26; i ++){
            if(bucket1[i] > 0 && bucket2[i] == 0 || bucket1[i] == 0 && bucket2[i] > 0){
                return false;
            }
        }
        sort(bucket1.begin(), bucket1.end());
        sort(bucket2.begin(), bucket2.end());
        for(int i = 0; i < 26; i ++){
            if(bucket1[i] != bucket2[i]){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

