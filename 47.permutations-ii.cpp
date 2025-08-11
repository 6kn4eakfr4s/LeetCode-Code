/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> answers;
    vector<int> currentAnswer;
    vector<int> nums;
    vector<int> used;

    void calculatePermutations(int index) {
        if(index > nums.size()){
            return;
        }
        unordered_set<int> diffDetectSet;
        for(int i = 0; i < nums.size(); i ++){
            if(!used[i] && diffDetectSet.find(nums[i]) == diffDetectSet.end()){
                currentAnswer.push_back(nums[i]);
                used[i] = true;
                diffDetectSet.insert(nums[i]);
                calculatePermutations(index + 1);
                used[i] = false;
                currentAnswer.pop_back();
            }
        }
        if(index == nums.size()){
            answers.push_back(currentAnswer);
        }
        return;
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        this->nums = nums;
        this->used = vector<int>(nums.size());
        calculatePermutations(0);
        return this->answers;
    }
};
// @lc code=end

