/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
private:
  vector<vector<int>> answers;
  vector<int> currentCombination;

  int target;
  int currentSum = 0;
  vector<int> candidates;
  void calcualteCombinations(int index) {
    if(currentSum == target){
      answers.push_back(currentCombination);
      return;
    }
    if(currentSum > target){
      return;
    }
    for(int i = index; i < candidates.size(); i ++){
      currentCombination.push_back(candidates[i]);
      currentSum += candidates[i];
      calcualteCombinations(i);
      currentSum -= candidates[i];
      currentCombination.pop_back();
    }
    return;
  }
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    this->target = target;
    this->candidates = candidates;
    calcualteCombinations(0);
    return answers;
  }
};
// @lc code=end

