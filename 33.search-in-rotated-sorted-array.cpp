/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size();
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] < target) {  // if mid is less than target
        if (nums[mid] < nums[0]) {  // if mid goes to the rotated part
          if (target >= nums[0]) {  // if target exists in the rotated part
            r = mid;
          } else {
            l = mid + 1;
          }
        } else {
          // mid is in the first part, and mid is less than target
          l = mid + 1;
        }
      } else if (nums[mid] == target) {
        return mid;
      } else {
        // mid is greater than target
        if (nums[mid] >= nums[0]) {
          // mid is in the first part
          if (target >= nums[0]) {
            // target is in the first part
            r = mid;
          } else {
            // target is in the second part
            l = mid + 1;
          }
        } else {
          // mid is in the second part
          r = mid;
        }
      }
    }
    return -1;
  }
};
// @lc code=end
