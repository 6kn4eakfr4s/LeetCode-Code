/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
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
    int pairSum(ListNode* head) {
        int length = 1;
        ListNode* it = head;
        // cout<<it->val<<endl;
        // cout<<"e1"<<endl;
        while(it -> next != NULL){
            // cout<<it->val<<endl;
            it = it -> next;
            length ++; 
        }    
        // cout<<"e2"<<endl;
        int cnt = 1;
        it = head;
        ListNode* prev = NULL;
        while(it -> next != NULL){
            // cout<<"begin-------"<<endl;
            // cout<<it->val<<endl;
            if(cnt > length / 2 + 1){
                ListNode* temp = it -> next;
                it -> next = prev;
                prev = it;
                it = temp;
                continue;
            }
            // cout<<it->val<<endl;
            if(cnt > length / 2){
                prev = it;
                ListNode* temp = it -> next;
                it -> next = NULL;
                it = temp;
                cnt ++;
                continue;
            }
            // cout<<it->val<<endl;
            it = it -> next;
            // cout<<it->val<<endl;
            cnt ++;
        }
        // cout<<"pass while loop"<<endl;
        it -> next = prev;
        int ans = 0;
        for(int i = 0; i < length / 2; i ++){
            ans = max(ans, head->val + it->val);
            head = head -> next;
            it = it -> next;
        }
        // cout<<"ans: "<<ans<<endl;
        return ans;
    }
};
// @lc code=end

