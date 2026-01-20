/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
#include <climits>

class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int root_path = Max_Path(root);
    return std::max(max_sum, root_path);
  }
 private:
  int max_sum = INT_MIN;
  
  int Max_Path(TreeNode* root) {
    if (!root->left && !root->right) {
      max_sum = std::max(max_sum, root->val);
      return root->val;
    }
    int left_path_len = 0;
    int right_path_len = 0;
    if (root->left) {
      left_path_len = Max_Path(root->left);
      max_sum = std::max(max_sum, left_path_len);
    }
    if (root->right) {
      right_path_len = Max_Path(root->right);
      max_sum = std::max(max_sum, right_path_len);
    }
    max_sum = std::max(max_sum, root->val + left_path_len + right_path_len);
    return root->val + std::max(0, std::max(left_path_len, right_path_len));
  }
};
// @lc code=end

