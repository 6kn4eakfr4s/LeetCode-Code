/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
#include <cstddef>
#include <string>
class Solution {
 public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    std::string tree_str = EncodeTree(root);
    std::string subtree_str = EncodeTree(subRoot);
    return tree_str.find(subtree_str) != std::string::npos;
  }
 private:
  std::string EncodeTree(TreeNode* root) {
    if (root == nullptr) {
      return "#";
    }
    return "(" + EncodeTree(root->left) + "," + std::to_string(root->val) + ","
      + EncodeTree(root->right) + ")";
  }
};
// @lc code=end
