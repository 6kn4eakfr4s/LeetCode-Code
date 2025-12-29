/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
#include <vector>
#include <unordered_set>
class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    std::unordered_set<int> hash_table;    
    for (int i = 0; i < nums.size(); ++i) {
      if (hash_table.find(nums[i]) != hash_table.end()) {
        return true;
      }
      hash_table.insert(nums[i]);
    }
    return false;
  }
};
// @lc code=end

