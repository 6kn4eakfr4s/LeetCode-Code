/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
  int binary_search(int l, int r, const vector<int>& nums){
    if (r == l)return l;
    int mid = (r + l) / 2;
    if (mid == 0) {
      if (nums[mid] > nums[mid + 1]) {
        return mid;
      } else return binary_search(mid, r, nums);
    } else if (mid == nums.size() - 1) {
      if (nums[mid] > nums[mid - 1]) {
        return mid;
      } else return binary_search(l, mid, nums);
    } else {
      if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
        return mid;
      } else if (nums[mid] > nums[mid - 1]) {
        return binary_search(mid + 1, r, nums);
      } else {
        return binary_search(l, mid, nums);
      }
    }
  }
  int findPeakElement(vector<int>& nums) {
    if (nums.size() == 1) return 0;
    return binary_search(0, nums.size(), nums);
  }
};
// @lc code=end

