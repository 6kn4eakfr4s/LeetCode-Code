/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <unordered_map>
#include <vector>
class Solution {
 private:
  std::unordered_map<int, int> inorder_index_hashmap;
 public:
  TreeNode *Build(std::vector<int> &preorder, std::vector<int> &inorder,
    int preorder_l, int preorer_r, int inorder_l, int inorder_r) {
      if (preorder_l == preorer_r) {
        return nullptr;
      }
      TreeNode* node = new TreeNode(preorder[preorder_l]);
      if (preorder_l == preorer_r - 1) {
        return node;
      }
      int mid_index = inorder_index_hashmap[preorder[preorder_l]];
      int left_tree_size = mid_index - inorder_l; 
      int righ_tree_size = inorder_r - mid_index - 1;
      if (left_tree_size != 0) {
        node->left = Build(preorder, inorder, preorder_l + 1, 
          preorder_l + 1 + left_tree_size, inorder_l, mid_index);
      }
      if (righ_tree_size != 0) {
        node->right = Build(preorder, inorder, preorder_l + 1 + left_tree_size,
          preorer_r, mid_index + 1, inorder_r);
      }
      return node;
    }
  TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); ++i) {
      inorder_index_hashmap[inorder[i]] = i;
    }
    return Build(preorder, inorder, 0, preorder.size(), 0, inorder.size());
  }
};
// @lc code=end
