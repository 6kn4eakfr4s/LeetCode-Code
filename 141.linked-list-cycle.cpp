/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstddef>
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    ListNode *t = head;
    ListNode *h = head;
    while (h != nullptr && t != nullptr) {
      h = h->next;
      if (h != nullptr) {
        h = h->next;
      } else {
        return false;
      }
      t = t->next;
      if (h == t) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
