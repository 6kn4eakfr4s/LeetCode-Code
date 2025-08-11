/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
private:
  const string letterMap[10] = {
    "", //0
    "", //1
    "abc", //2
    "def", //3
    "ghi", //4
    "jkl", //5
    "mno", //6
    "pqrs", //7
    "tuv", //8
    "wxyz" //9
  };
  string digits = "";
  vector<string> answers;
  string currentCombination;
  void calculateCombinations(int index){
    //Currently visiting the index th digit in digits
    if(index >= digits.size()){
      //if we already visited all digits, then just return
      answers.push_back(currentCombination);
      return;
    }
    for(int i = 0; i < letterMap[digits[index] - '0'].size(); i ++){
      currentCombination.push_back(letterMap[digits[index] - '0'][i]);
      calculateCombinations(index + 1);
      currentCombination.pop_back();
    }
    return;
  }
public:
  vector<string> letterCombinations(string digits) {
    this->digits = digits;
    if(digits.size() == 0){
      return answers;
    }
    calculateCombinations(0);
    return answers;
  }
};
// @lc code=end

