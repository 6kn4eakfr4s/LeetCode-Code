/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start
class Solution {
public:
    bool is_vowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int lo = 0;
        int hi = k; // exclusive
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < k; i ++){
            if(is_vowel(s[i])){
                cnt ++;
            }
        }
        ans = max(ans, cnt);
        while(hi <= s.size()){
            if(is_vowel(s[lo++])){
                cnt --;
            }
            if(is_vowel(s[hi++])){
                cnt ++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
// @lc code=end

