/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
private:
    vector<vector<int>> answers;
    vector<int> used;
    vector<int> nums;
    vector<int> currentPermutation;
    
    void calculatePermutation(int index){
        for(int i = 0; i < nums.size(); i ++){
            if(used[i]){
                continue;
            }
            currentPermutation.push_back(nums[i]);
            used[i] = true;
            calculatePermutation(index + 1);
            used[i] = false;
            currentPermutation.pop_back();
        }
        if(index == nums.size()){
            answers.push_back(currentPermutation);
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums;
        vector<int> used(nums.size());
        this->used = used;
        calculatePermutation(0);
        return this->answers;
    }
};
// @lc code=end

