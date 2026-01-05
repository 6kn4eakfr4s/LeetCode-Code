/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ptr_1 = l1;
    ListNode* ptr_2 = l2;
    int num_1;
    int num_2;
    int sum;
    int carry = 0;
    ListNode* dummy = new ListNode();
    ListNode* result_ptr = dummy;
    while (ptr_1 != nullptr || ptr_2 != nullptr) {
      if (ptr_1 == nullptr) {
        num_1 = 0;
      } else {
        num_1 = ptr_1->val;
        ptr_1 = ptr_1->next;
      }
      if (ptr_2 == nullptr) {
        num_2 = 0;
      } else {
        num_2 = ptr_2->val;
        ptr_2 = ptr_2->next;
      }
      sum = (num_1 + num_2 + carry) % 10;
      carry = (num_1 + num_2 + carry) / 10;
      result_ptr->next = new ListNode(sum);
      result_ptr = result_ptr->next;
    }
    if (carry != 0) {
      result_ptr->next = new ListNode(carry);
    }
    return dummy->next;
  }
};
// @lc code=end
