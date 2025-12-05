/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head -> next == NULL || head -> next -> next == NULL){
            return head;
        }
        ListNode* oddNode = head;
        ListNode* prevOdd = oddNode;
        ListNode* evenNode = head->next;
        ListNode* prevEven = evenNode;
        ListNode* it = head -> next -> next;
        bool even = false;
        while(it != NULL){
            if(even){
                prevEven -> next = it;
                prevEven = it;
            }
            else{
                prevOdd -> next = it;
                prevOdd = it;
            }
            even = !even;
            it = it -> next;
        }
        prevOdd -> next = evenNode;
        prevEven -> next = nullptr;
        return head;
    }
};
// @lc code=end

