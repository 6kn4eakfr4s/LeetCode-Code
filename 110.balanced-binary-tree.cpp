/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <algorithm>
class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    Height(root);
    return is_balanced;
  }

 private:
  bool is_balanced = true;
  int Height(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int l = Height(root->left);
    int r = Height(root->right);
    if (l - r > 1 || r - l > 1) {
      is_balanced = false;
    }
    return std::max(l, r) + 1;
  }
};
// @lc code=end
