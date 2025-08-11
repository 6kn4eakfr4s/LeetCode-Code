/*
 * @lc app=leetcode id=491 lang=cpp
 *
 * [491] Non-decreasing Subsequences
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> answers;
    vector<int> currentAnswer;
    vector<int> nums;

    void calculateSubsequences(int index){
        if(currentAnswer.size() > 1){
            answers.push_back(currentAnswer);
        }
        unordered_set<int> diffDetectSet;
        for(int i = index; i < nums.size(); i++){
            if(index > 0 && nums[i] >= nums[index - 1] || index == 0){
                if(diffDetectSet.find(nums[i]) == diffDetectSet.end()){
                    diffDetectSet.insert(nums[i]);
                    currentAnswer.push_back(nums[i]);
                    calculateSubsequences(i + 1);
                    currentAnswer.pop_back();
                }
            }
        }
        return;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        this->nums = nums;
        calculateSubsequences(0);
        return this->answers;
    }
};
// @lc code=end

