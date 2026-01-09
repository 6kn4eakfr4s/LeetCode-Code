/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
  int diameterOfBinaryTree(TreeNode* root) {
    Dfs(root);
    return max_diameter;
  }
 private:
  int max_diameter = 0;
  int Dfs(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    } 
    int l = Dfs(root->left);
    int r = Dfs(root->right);
    max_diameter = std::max(max_diameter, l + r);
    return std::max(l, r) + 1;
  }
};
// @lc code=end
