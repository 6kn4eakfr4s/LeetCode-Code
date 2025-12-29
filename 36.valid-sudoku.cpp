/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<bool>> rows(9, vector<bool>(10, false));
    vector<vector<bool>> cols(9, vector<bool>(10, false));
    vector<vector<bool>> boxs(9, vector<bool>(10, false));
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.') {
          continue;
        }
        int num = board[i][j] - '0';
        if (rows[i][num] == true) {
          return false;
        } else {
          rows[i][num] = true;
        }
        if (cols[j][num] == true) {
          return false;
        } else {
          cols[j][num] = true;
        }
        if (boxs[(i / 3) * 3 + j / 3][num] == true) {
          return false;
        } else {
          boxs[(i / 3) * 3 + j / 3][num] = true;
        }
      }
    }
    return true;
  }
};
// @lc code=end

