/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
#include <string>
#include <vector>
class Solution {
 public:
  std::vector<std::vector<string>> solveNQueens(int n) {
    board_ = std::vector(n, vector(n, '.'));
    col_ = vector(n, false);
    right_down_dia_ = vector(n * 2 - 1, false);
    left_up_dia_ = vector(n * 2 - 1, false);
    dfs(0);
    return ans_;
  }

 private:
  std::vector<vector<char>> board_;
  std::vector<bool> col_;
  std::vector<bool> right_down_dia_;
  std::vector<bool> left_up_dia_;
  std::vector<std::vector<std::string>> ans_;

  std::vector<std::string> BoardToStr() {
    std::vector<std::string> strs;
    for (int i = 0; i < board_.size(); ++i) {
      std::string s = "";
      for (int j = 0; j < board_[0].size(); ++j) {
        s.push_back(board_[i][j]);
      }
      strs.push_back(s);
    }
    return strs;
  }
  void dfs(int y) {
    if (y == board_.size()) {
      ans_.push_back(BoardToStr());
      return;
    }
    for (int i = 0; i < board_.size(); ++i) {
      if (!col_[i] && !right_down_dia_[i - y + board_.size() - 1] && 
        !left_up_dia_[i + y]) {
          board_[y][i] = 'Q';
          col_[i] = true;
          right_down_dia_[i - y + board_.size() - 1] = true;
          left_up_dia_[i + y] = true;
          dfs(y + 1);
          left_up_dia_[i + y] = false;
          right_down_dia_[i - y + board_.size() - 1] = false;
          col_[i] = false;
          board_[y][i] = '.';
        }
    }
  }
};
// @lc code=end
