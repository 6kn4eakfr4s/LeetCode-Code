/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) {
      return nullptr;
    }
    Node* ptr = head;
    while (ptr != nullptr) {
      Node* temp = ptr->next;
      ptr->next = new Node(ptr->val);
      ptr->next->next = temp;
      ptr = temp;
    }
    ptr = head;
    while (ptr != nullptr && ptr->next != nullptr) {
      Node* temp = ptr->next->next;
      Node* new_list_node = ptr->next;
      if (ptr->random != nullptr) {
        new_list_node->random = ptr->random->next;
      } else {
        new_list_node->random = nullptr;
      }
      ptr = temp;
    }
    ptr = head;
    Node* new_head = head->next;
    while (ptr != nullptr) {
      Node* temp = ptr->next->next;
      Node* new_list_node = ptr->next;
      if (temp != nullptr) {
        new_list_node->next = temp->next;
      } else {
        new_list_node->next = nullptr;
      }
      ptr->next = temp;
      ptr = ptr->next;
    }
    return new_head;
  }
};
// @lc code=end
