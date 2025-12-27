/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), 
         [](const auto& a, const auto& b) { return a[1] < b[1]; });  
    int num_arrows = 1;
    int prev_end = points[0][1];
    for (int i = 1; i < points.size(); ++i) {
      if (points[i][0] > prev_end) {
        prev_end = points[i][1];
        ++num_arrows;
      }
    }
    return num_arrows;
  }
};
// @lc code=end

