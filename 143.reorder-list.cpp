/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  void reorderList(ListNode* head) {
    if (!head || !head->next) {
      return;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode* second = slow->next;
    slow->next = nullptr;
    ListNode* prev = nullptr;
    while (second->next) {
      ListNode* temp = second->next;
      second->next = prev;
      prev = second;
      second = temp;
    }
    second->next = prev;
    while (second) {
      ListNode* temp = head->next;
      head->next = second;
      ListNode* temp_second = second->next;
      second->next = temp;
      second = temp_second;
      head = temp;
    }
  }
};
// @lc code=end
