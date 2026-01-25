/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
#include <string>
#include <vector>
struct TrieNode {
  bool terminate_ = false;
  TrieNode* children_[26] = {};
  TrieNode() {}
};
class Solution {
 public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    for (int i = 0; i < words.size(); ++i) {
      InsertWord(words[i]);
    }
    visited_ = std::vector(board.size(), std::vector(board[0].size(), false));
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        search_string_.push_back(board[i][j]);
        visited_[i][j] = true;
        if (SearchWord(i, j, root, board)) {
          ans_.push_back(search_string_);
        }
        visited_[i][j] = false;
        search_string_.pop_back();
      }
    }
    return ans_;
  }

 private:
  TrieNode* root = new TrieNode; 
  int dx_[4] = {0, 1, 0, -1};
  int dy_[4] = {1, 0, -1, 0}; 
  std::string search_string_ = "";
  std::vector<std::string> ans_;
  std::vector<std::vector<bool>> visited_;
  void InsertWord(std::string& word) {
    TrieNode* cur = root;
    for (int i = 0; i < word.size(); ++i) {
      if (cur->children_[word[i] - 'a'] == nullptr) {
        cur->children_[word[i] - 'a'] = new TrieNode;
      }
      cur = cur->children_[word[i] - 'a'];
    }
    cur->terminate_ = true;
  }

  bool SearchWord(int x, int y, TrieNode *node, 
    std::vector<std::vector<char>>& board) {
    // cout<<x<<" "<<y<<" "<<search_string_<<endl;
    if (node->children_[board[x][y] - 'a'] == nullptr) {
      return false;
    }
    TrieNode* new_node = node->children_[board[x][y] - 'a'];
    int nx, ny;
    for (int i = 0; i < 4; ++i) {
      nx = x + dx_[i];
      ny = y + dy_[i];
      if (nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size() &&
        !visited_[nx][ny]) {
        visited_[nx][ny] = true;
        search_string_.push_back(board[nx][ny]);
        if (SearchWord(nx, ny, new_node, board)) {
          ans_.push_back(search_string_);
        }
        search_string_.pop_back();
        visited_[nx][ny] = false;
      }
    }
    bool terminate = new_node->terminate_;
    new_node->terminate_ = false;
    return terminate;
  }
};
// @lc code=end
