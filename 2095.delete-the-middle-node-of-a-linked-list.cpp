/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
    ListNode* deleteMiddle(ListNode* head) {
        int size = 1;
        ListNode* it = head;
        while(it-> next != nullptr){
            size ++;
            it = it -> next; 
        }
        size = size / 2;
        if(size == 0){
            return head -> next;
        }
        it = head;
        while(--size){
            it = it -> next;
        }
        it -> next = it -> next -> next;
        return head;
    }
};
// @lc code=end

