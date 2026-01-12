/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val > q->val) {
      return lowestCommonAncestor(root, q, p);
    }
    if (root == p) {
      return p;
    }
    if (root == q) {
      return q;
    }
    int root_val = root->val;
    int p_val = p->val;
    int q_val = q->val;
    if (root_val > p_val && root_val < q_val) {
      return root;
    }
    if (root_val < p_val) {
      return lowestCommonAncestor(root->right, p, q);
    }
    return lowestCommonAncestor(root->left, p, q);
  }
};
// @lc code=end
