/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
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
    int trace(TreeNode* x, int maxPath){
        if(x == nullptr){
            return 0;
        }
        if(maxPath <= x -> val){
            return trace(x -> left, max(maxPath, x -> val)) +
                   trace(x -> right, max(maxPath, x -> val)) + 1;
        }
        else{
            return trace(x -> left, max(maxPath, x -> val)) +
                   trace(x -> right, max(maxPath, x -> val));
        }
    }
    int goodNodes(TreeNode* root) {
        return trace (root, -10e4-9); 
    }
};
// @lc code=end

