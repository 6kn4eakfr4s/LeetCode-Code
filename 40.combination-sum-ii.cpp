/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
private:
  vector<vector<int>> answers;
  vector<int> currentCombination;
  int currentSum = 0;
  vector<bool> used;

  vector<int> candidates; 
  int target;

  void calcualteCombinations(int index){
    if(currentSum == target){
      answers.push_back(currentCombination);
      return;
    }
    for(int i = index; i < candidates.size(); i ++){
      if(currentSum + candidates[i] > target){
        //no need to go bigger numbers cuz it will be over target
        break;
      }
      if(i > 0 && candidates[i - 1] == candidates[i] && !used[i - 1]){
        continue;
      }
      currentSum += candidates[i];
      currentCombination.push_back(candidates[i]);
      used[i] = true;
      calcualteCombinations(i + 1);
      used[i] = false;
      currentCombination.pop_back();
      currentSum -= candidates[i];
    }
    return;
  }
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    this->candidates = candidates;
    this->target = target;
    vector<bool> used(candidates.size(), false);
    this->used = used;
    calcualteCombinations(0);
    return answers;
  }
};
// @lc code=end

