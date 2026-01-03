/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <utility>
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      std::swap(nums1, nums2);
    }
    int l = 0;
    int r = nums1.size() + 1;
    int total_size = nums1.size() + nums2.size();
    int half_size = (total_size + 1) / 2;
    while (l < r) {
      int mid = (l + r) / 2;
      int cut_1 = mid;
      int cut_2 = half_size - cut_1;
      int left_max_1;
      int left_max_2;
      int right_min_1;
      int right_min_2;
      if (cut_1 == 0) {
        left_max_1 = INT_MIN;
      } else {
        left_max_1 = nums1[cut_1 - 1];
      }
      if (cut_2 == 0) {
        left_max_2 = INT_MIN;
      } else {
        left_max_2 = nums2[cut_2 - 1];
      }
      if (cut_1 == nums1.size()) {
        right_min_1 = INT_MAX;
      } else {
        right_min_1 = nums1[cut_1];
      }
      if (cut_2 == nums2.size()) {
        right_min_2 = INT_MAX;
      } else {
        right_min_2 = nums2[cut_2];
      }

      if (left_max_1 > right_min_2) {
        r = mid;
      } else if (left_max_2 > right_min_1) {
        l = mid + 1;
      } else {
        if (total_size % 2 == 0) {
          return (double(std::max(left_max_1, left_max_2)) + 
                  double(std::min(right_min_1, right_min_2))) / 2.0;
        } else {
          return double(std::max(left_max_1, left_max_2));
        }
      }
    }
    return -1.0;
  }
};
// @lc code=end
