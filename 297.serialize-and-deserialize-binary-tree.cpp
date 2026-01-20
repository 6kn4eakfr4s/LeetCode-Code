/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
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
#include <string>
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (!root) {
      return "";
    }
    return EncodeTree(root);
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    // cout<<"deserializing: "<<data<<endl;
    if (data == "") {
      return nullptr;
    }
    int start_index = 0;
    return DecodeTree(data, start_index);
  }
 private:
  string EncodeTree(TreeNode* root) {
    string s;
    s.append("(");
    s.append(std::to_string(root->val));
    s.append("/");
    if (root->left == nullptr) {
      s.append("x");
    } else {
      s.append(EncodeTree(root->left));
    }
    s.append("/");
    if (root->right == nullptr) {
      s.append("x");
    } else {
      s.append(EncodeTree(root->right));
    }
    s.append(")");
    return s;
  }
  
  TreeNode* DecodeTree(std::string& s, int& start_index) {
    // cout<<"start_index: "<<start_index<<" "<<s[start_index]<<endl;
    if (s[start_index] == 'x') {
      ++start_index;
      return nullptr;
    }
    int first_number_end = start_index + 1;
    while (s[first_number_end] != '/') {
      ++first_number_end;
    }
    std::string root_val = s.substr(start_index + 1, 
      first_number_end - start_index - 1);
    // cout<<"root_val: "<<root_val<<endl;
    TreeNode* root = new TreeNode(std::stoi(root_val));
    // cout<<"successfuly stoi"<<endl;
    start_index = first_number_end + 1;
    if (s[start_index] == 'x') {
      start_index = first_number_end + 3;
      root->right = DecodeTree(s, start_index);
      ++start_index;
      return root;
    }
    /*
    int parenthesis_count = 1;
    int mid_index = first_number_end + 1;
    while (parenthesis_count != 0) {
      ++mid_index;
      if (s[mid_index] == '(') {
        ++parenthesis_count;
      } else if (s[mid_index] == ')') {
        --parenthesis_count;
      }
    }
    // cout<<"mid_index: "<<mid_index<<endl;
    root->right = DecodeTree(s, mid_index + 2);
    */
    root->left = DecodeTree(s, start_index);
    ++start_index;
    root->right = DecodeTree(s, start_index);
    ++start_index;
    
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
