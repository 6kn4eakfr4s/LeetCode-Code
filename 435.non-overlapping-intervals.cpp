/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
#include <vector>
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int num_remove = 0;
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
      return a[1] < b[1];
    });
    int prev_end = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] < prev_end) {
        ++num_remove;
      } else {
        prev_end = intervals[i][1];
      }
    }
    return num_remove;
  }
};
// @lc code=end

