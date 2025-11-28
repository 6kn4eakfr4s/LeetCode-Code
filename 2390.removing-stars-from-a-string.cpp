/*
 * @lc app=leetcode id=2390 lang=cpp
 *
 * [2390] Removing Stars From a String
 */

// @lc code=start
class Solution {
public:
    string removeStars(string s) {
        int num = 0;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '*'){
                num ++;
            }
        }
        string ans(s.size() - 2 * num, '\0');
        int index = ans.size() - 1;
        int star = 0;
        for(int i = s.size() - 1; i >= 0; i --){
            if(s[i] == '*'){
                star ++;
            }
            else{
                if(star == 0){
                    ans[index--] = s[i];
                }
                else{
                    star --;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

