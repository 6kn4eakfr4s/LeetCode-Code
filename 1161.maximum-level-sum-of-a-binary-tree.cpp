/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
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
static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int maxLevelSum(TreeNode* root){
      queue<TreeNode*> pq;
      pq.push(root);
      int maxSum = -1e5-9;
      int curSum;
      int curHeight = 0;
      int maxHeight = 0;
      while(!pq.empty()){
        int size = pq.size();
        curHeight++;
        curSum = 0;
        // cout<<t.node -> val<<" "<<t.height<<endl;
        while(size--){
            TreeNode* n = pq.front();
            pq.pop();
            curSum += n -> val;
            if(n -> left != NULL){
                pq.push(n -> left);
            }
            if(n -> right != NULL){
                pq.push(n -> right);
            }
        }
        if(curSum > maxSum){
            maxSum = curSum;
            maxHeight = curHeight;
        }
      }
      return maxHeight;
    }
};
// @lc code=end

