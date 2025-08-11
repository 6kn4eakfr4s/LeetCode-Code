/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> answers;
    vector<int> currentAnswer;
    vector<int> nums;
    vector<int> used;

    void calculateSubset(int index){
        if(index > nums.size()){
            return;
        }
        for(int i = index; i < nums.size(); i ++){
            if(i > index && nums[i] == nums[i - 1] && used[i - 1] == false){
                continue;
            }
            currentAnswer.push_back(nums[i]);
            calculateSubset(i + 1);
            currentAnswer.pop_back();
        }
        answers.push_back(currentAnswer);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        this->nums = nums;
        vector<int> used(nums.size());
        this->used = used;
        calculateSubset(0);
        return this->answers;
    }
};
// @lc code=end

