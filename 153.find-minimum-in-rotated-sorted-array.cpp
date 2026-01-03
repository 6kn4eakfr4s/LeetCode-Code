/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
  int findMin(vector<int>& nums) {
    int cur_min = nums[0];
    int l = 0;
    int r = nums.size();
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] < cur_min) {
        cur_min = nums[mid];
        r = mid + 1;
      } else if (nums[mid] > cur_min) {
        if (mid == l) {
          return nums[0];
        }
        l = mid;
      } else {
        return cur_min;
      }
    }
    return -1;
  }
};
// @lc code=end
