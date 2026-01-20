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
    s.append(std::to_string(root->val));
    s.append(" ");
    if (root->left == nullptr) {
      s.append("x ");
    } else {
      s.append(EncodeTree(root->left));
    }
    if (root->right == nullptr) {
      s.append("x ");
    } else {
      s.append(EncodeTree(root->right));
    }
    return s;
  }
  
  TreeNode* DecodeTree(std::string& s, int& start_index) {
    if (start_index >= s.length()) {
      return nullptr;
    }
    // cout<<"start_index: "<<start_index<<" "<<s[start_index]<<endl;
    if (s[start_index] == 'x') {
      start_index += 2;
      return nullptr;
    }
    int sum = 0;
    bool is_negative = false;
    if (s[start_index] == '-') {
      is_negative = true;
      ++start_index;
    }
    while (s[start_index] != ' ') {
      sum *= 10;
      sum += s[start_index] - '0';
      ++start_index;
    }
    ++start_index;
    if (is_negative) {
      sum = sum * -1;
    }
    // cout<<"root_val: "<<root_val<<endl;
    TreeNode* root = new TreeNode(sum);
    // cout<<"successfuly stoi"<<endl;
    if (s[start_index] == 'x') {
      start_index += 2;
      root->right = DecodeTree(s, start_index);
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
    root->right = DecodeTree(s, start_index);
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end