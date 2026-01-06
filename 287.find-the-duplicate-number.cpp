/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
#include <cstddef>
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int t = nums[0];
    int h = nums[nums[0]];
    while (t != h) {
      t = nums[t];
      h = nums[nums[h]];
    }
    int t_2 = 0;
    while (t_2 != t) {
      t_2 = nums[t_2];
      t = nums[t];
    }
    return t;
  }
};
// @lc code=end

