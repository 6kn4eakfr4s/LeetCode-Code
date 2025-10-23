/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

// @lc code=start
class Solution {
public:
    //if string a divide string b
    bool isDivide(string a, string b){
        if(b.length() % a.length() != 0){
            return false;
        }
        for(int i = 0; i < b.length(); i ++){
            if(a[i % a.length()] != b[i]){
                return false;
            }
        }
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        int commonSize = 0;
        while(commonSize < min(str1.length(), str2.length()) &&
              str1[commonSize] == str2[commonSize]){
            commonSize ++;
        }
        for(int i = commonSize; i > 0; i --){
            if(str1.length() % i != 0 || 
               str2.length() % i != 0){
                continue;
            }
            string commonStr = str1.substr(0, i);
            if(isDivide(commonStr, str1) && isDivide(commonStr, str2)){
                return commonStr;
            }
        }
        return "";

    }
};
// @lc code=end

