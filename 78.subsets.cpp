/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */


class Solution {
private:
    vector<vector<int>> answers;
    vector<int> nums;
    vector<int> currentAnswer;

    void calculateSubsets(int currentIndex){
        if(currentIndex == nums.size()){
            answers.push_back(currentAnswer);
            return;
        }
        
        for(int i = currentIndex; i < nums.size(); i ++){
            currentAnswer.push_back(nums[i]);
            calculateSubsets(i + 1);
            currentAnswer.pop_back();
        }
        answers.push_back(currentAnswer);
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        calculateSubsets(0);
        return this->answers;
    }
};
// @lc code=end

