/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
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
    int dfs(TreeNode* node, long long sum, int targetSum, unordered_map<long long, int>& MP){
      if(node == nullptr){
        return 0;
      }
      sum += node->val;
      int newPath = 0;
      if(sum == targetSum){
        newPath ++;
      }
      newPath += MP[sum - targetSum];
      MP[sum] ++;
      newPath += dfs(node -> left, sum, targetSum, MP);
      newPath += dfs(node -> right, sum, targetSum, MP);
      MP[sum] --;
      return newPath;
    }
    int pathSum(TreeNode* root, int targetSum) {
      unordered_map<long long, int> MP;
      return dfs(root, 0, targetSum, MP);    
    }
};
// @lc code=end

