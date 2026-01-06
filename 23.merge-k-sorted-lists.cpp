/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
#include <vector>
#include <queue>
struct Compare {
  bool operator()(ListNode* a, ListNode* b) const {
    return a->val > b->val;
  }
};
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> pq;
    for (auto node : lists) {
      if (node != nullptr) {
        pq.push(node);
      }
    }
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;
    while (!pq.empty()) {
      ListNode* top = pq.top();
      pq.pop();
      tail->next = top;
      tail = tail->next;
      if (top->next != nullptr) {
        pq.push(top->next);
      }
    }
    return dummy->next;
  }
};
// @lc code=end

