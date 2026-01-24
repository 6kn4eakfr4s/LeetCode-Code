/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
 private:
  std::string search_word_;
  std::vector<int> dx = {1, 0, -1, 0};
  std::vector<int> dy = {0, 1, 0, -1};
  std::vector<std::vector<bool>> visited_;
  bool dfs(int x, int y, std::vector<std::vector<char>>& board, 
    int search_index) {
    if (search_index == search_word_.length()) {
      return true;
    }
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 0 && nx < visited_.size() && ny >= 0 && ny < visited_[0].size()
        && !visited_[nx][ny] && board[nx][ny] == search_word_[search_index]) {
        visited_[nx][ny] = true;
        if (dfs(nx, ny, board, search_index + 1)) {
          return true;
        }
        visited_[nx][ny] = false;
      }
    }
    return false;
  }
 public:
  bool exist(vector<vector<char>>& board, string word) {
    visited_ = std::vector(board.size(), std::vector(board[0].size(), false));
    search_word_ = word;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] == word[0]) {
          visited_[i][j] = true;
          if (dfs(i, j, board, 1)) {
            return true;
          }
          visited_[i][j] = false;
        }
      }
    }
    return false;
  }
};
// @lc code=end

