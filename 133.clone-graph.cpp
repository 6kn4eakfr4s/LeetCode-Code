/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

#include <map>
#include <unordered_map>
class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) {
      return nullptr;
    }
    Node* clone = new Node(node->val);
    mp_[node] = clone;
    dfs(node, clone);
    return clone;
  }

 private:
  std::unordered_map<Node*, Node*> mp_;
  void dfs(Node* original, Node* clone) {
    for (int i = 0; i < original->neighbors.size(); ++i) {
      if (mp_.find(original->neighbors[i]) != mp_.end()) {
        clone->neighbors.push_back(mp_[original->neighbors[i]]);
      } else {
        Node* new_node = new Node(original->neighbors[i]->vaml);
        clone->neighbors.push_back(new_node);
        mp_[original->neighbors[i]] = new_node;

        dfs(original->neighbors[i], clone->neighbors[i]);
      }
    }
  }
};
// @lc code=end
