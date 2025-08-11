/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
private:
    bool isPalindrome(string s){
        string sReversed = s;
        reverse(sReversed.begin(), sReversed.end());
        return s == sReversed;
    }

    vector<vector<string>> answers;
    vector<string> currentAnswer;
    string s;

    void calculatePartition(int startIndex){
        if(startIndex >= s.size()){
            answers.push_back(currentAnswer);
            return;
        }
        for(int i = startIndex; i < s.size(); i ++){
            if(isPalindrome(s.substr(startIndex, i - startIndex + 1))){
                currentAnswer.push_back(s.substr(startIndex, i - startIndex + 1));
                calculatePartition(i + 1);
                currentAnswer.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        this->s = s;
        calculatePartition(0);
        return this->answers;
    }
};
// @lc code=end

