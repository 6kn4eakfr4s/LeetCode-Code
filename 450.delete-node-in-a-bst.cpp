/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* del(TreeNode* root){
        if(root -> left == NULL && root -> right == NULL){
            return NULL;
        }
        if(root -> left == NULL){
            return root -> right;
        }
        if(root -> right == NULL){
            return root -> left;
        }
        if(root -> left -> right == NULL){
            root -> left -> right = root -> right;
            return root -> left;
        }
        TreeNode* tempLeft = root -> left;
        TreeNode* tempRight = root -> right;
        TreeNode* newRoot = root -> left;
        while(newRoot -> right -> right != NULL){
           newRoot = newRoot -> right; 
        }
        TreeNode* temp = newRoot -> right;
        newRoot -> right = newRoot -> right -> left;
        temp -> left = root -> left;
        temp -> right = root -> right;
        return temp;
    } 
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return root;
        }
        if(root -> val == key){
            root = del(root);
        }    
        else{
            root -> left = deleteNode(root -> left, key);
            root -> right = deleteNode(root -> right, key);
        }
        return root;
    }
};
// @lc code=end

