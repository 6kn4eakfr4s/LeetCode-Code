/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
#include <cstdint>
class Solution {
 private:
  bool IsValid(TreeNode* root, int64_t lower_bound, int64_t upper_bound) {
    if (root == nullptr) {
      return true;
    }
    if (root->val >= upper_bound || root->val <= lower_bound) {
      return false;
    }
    return IsValid(root->left, lower_bound, root->val) &&
      IsValid(root->right, root->val, upper_bound);
  }
 public:
  bool isValidBST(TreeNode* root) {
    return IsValid(root, INT64_MIN, INT64_MAX);
  }
};
// @lc code=end
