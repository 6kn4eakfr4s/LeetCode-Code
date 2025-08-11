/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution {
private:
  vector<vector<int>> answers;
  vector<int> currentCombination;
  int currentSum = 0;

  void calculateCombination(int k, int n, int index){
    if(currentCombination.size() == k){
      if(currentSum == n){
        answers.push_back(currentCombination);
      }
      return;
    }
    if(index > 9){
      return;
    }
    if(currentSum + index > n){
      return;
    } 
    calculateCombination(k, n, index + 1);
    currentCombination.push_back(index);
    currentSum += index;
    calculateCombination(k, n, index + 1);
    currentSum -= index;
    currentCombination.pop_back();
    return;
  }
  
public:
  vector<vector<int>> combinationSum3(int k, int n) {
    calculateCombination(k, n, 1);
    return answers;
  }
};
// @lc code=end

