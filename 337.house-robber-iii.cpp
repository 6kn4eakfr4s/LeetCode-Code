/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
public:
    pair<int, int> dfs(TreeNode* root){
        //first value means max money without rob, second value means max money with rob
        if(!root){
            return {0, 0};
        }
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int robThis = root->val + left.first + right.first; 
        int skipThis = max(left.first, left.second) + max(right.first, right.second);
        return {skipThis, robThis};
    }
    int rob(TreeNode* root) {
        auto result = dfs(root);
        return max(result.first, result.second);
    }
};
// @lc code=end

