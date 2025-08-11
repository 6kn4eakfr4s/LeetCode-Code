/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution {
private:
    bool isValidIpNumber(string numberStr){
        if(numberStr.empty() || numberStr.size() > 3){
            return false;
        }
        if(numberStr.size() > 1 && numberStr[0] == '0'){
            return false;
        }
        int number =  stoi(numberStr);
        return (number >=0 && number <=255);
    }
    string s;
    vector<string> answers;
    string currentAnswer = "";
    int currentSections = 0;
    void calcualteCombinations(int startIndex){
        if(startIndex >= s.size() && currentSections == 4){
            answers.push_back(currentAnswer);
            return;
        }
        if(currentSections == 4 && startIndex < s.size()){
            return;
        }
        for(int i = startIndex; i < s.size(); i ++){
            if(isValidIpNumber(s.substr(startIndex, i - startIndex + 1))){
                currentAnswer.append(s.substr(startIndex, i - startIndex + 1));
                if(i != s.size() - 1){
                    currentAnswer.append(".");
                }
                currentSections ++;
                calcualteCombinations(i + 1);
                currentSections --;
                if(i != s.size() - 1){
                    currentAnswer.pop_back();
                }
                currentAnswer.resize(currentAnswer.size() - (i - startIndex + 1));
            }
        }
        return;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        this->s = s;
        calcualteCombinations(0);
        return this->answers;
    }
};
// @lc code=end

