/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
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
    int maxLen = 0;
public:
    void trace(TreeNode* node, int cur, bool left){
      cur ++;//current session ++
      maxLen = max(maxLen, cur);
      if(!left){//current node is from right path
        if(node -> left != nullptr){//if current node has a left child
          trace(node -> left, cur, true);
        }
        if(node -> right != nullptr){
          trace(node -> right, 1, false);
        }
      }
      else{
        if(node -> left != nullptr){//if current node has a left child
          trace(node -> left, 1, true);
        }
        if(node -> right != nullptr){
          trace(node -> right, cur, false);
        }
      }
    }
    int longestZigZag(TreeNode* root) {
        maxLen = 0;
        if(root==nullptr){
          return -1;
        }
        if(root -> left == nullptr && root -> right == nullptr){
          return 0;
        }
        if(root -> left != nullptr){
          trace(root -> left, 1, true);
        }
        if(root -> right != nullptr){
          trace(root -> right, 1, false);
        }
        return maxLen - 1;
    }
};
// @lc code=end

