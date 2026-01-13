/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
class Solution {
 private:
  void SearchNode(TreeNode* root, int& num_searched, int k, int& ans) {
    if (root == nullptr) {
      return;
    }
    SearchNode(root->left, num_searched, k, ans);
    if (ans != -1) {
      return;
    }
    if (ans == -1 && num_searched == k - 1) {
      ans = root->val;
      return;
    }
    ++num_searched;
    SearchNode(root->right, num_searched, k, ans);
  }
 public:
  int kthSmallest(TreeNode* root, int k) {
    int ans = -1;
    int num_searched = 0;
    SearchNode(root, num_searched, k, ans);
    return ans;
  }
};
// @lc code=end
