/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
#include <utility>
class Solution {
public:
  int row_num;
  int col_num;
  std::pair<int, int> To2D(int index) {
    return {index / col_num, index % col_num};
  }
  int ToIndex(int row, int col) { 
    return row * col_num + col;
  }
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    row_num = matrix.size();
    col_num = matrix[0].size();
    int l = 0;
    int r = row_num * col_num;
    while (l < r) {
      int mid = (l + r) / 2;
      std::pair<int, int> mid_xy = To2D(mid);
      int mid_val = matrix[mid_xy.first][mid_xy.second];
      if (mid_val < target) {
        l = mid + 1;
      } else if (mid_val == target) {
        return true;
      } else {
        r = mid;
      }
    }
    return false;
  }
};
// @lc code=end

