/*
 * @lc app=leetcode id=649 lang=cpp
 *
 * [649] Dota2 Senate
 */

// @lc code=start
class Solution {
public:
    struct linkedList{
        bool R;
        linkedList *next;
        linkedList *prev;
    }; 
    string predictPartyVictory(string senate) {
        int R = 0;
        int D = 0;
        linkedList *head = new linkedList();//dummy
        linkedList *temp = head;
        for(int i = 0; i < senate.size(); i ++){
            linkedList *newNode = new linkedList();
            if(senate[i] == 'R'){
                R ++;
                newNode -> R = true;
            }
            else{
                D ++;
                newNode -> R = false;
            }
            head -> next = newNode;
            newNode -> prev = head;
            head = newNode;
        }
        head -> next = temp -> next;
        temp -> next -> prev = head;
        temp = head -> next;
        int skipR = 0;
        int skipD = 0;
        while(R != 0 && D != 0){
            
            if(temp -> R){
                if(skipR > 0){
                    temp -> prev -> next = temp -> next;
                    temp -> next -> prev = temp -> prev;
                    R --;
                    skipR --;
                }
                else{
                    skipD ++;
                }
            }
            else{
                if(skipD > 0){
                    temp -> prev -> next = temp -> next;
                    temp -> next -> prev = temp -> prev;
                    D --;
                    skipD --;
                }
                else{
                    skipR ++;
                }

            }
            temp = temp -> next;
            // cout<<skipR<<" "<<skipD<<endl;
            // cout<<R<<" "<<D<<endl;
            // cout<<temp->R<<endl;
            // cout<<"---------"<<endl;
        }
        return D == 0?"Radiant":"Dire";
    }
};
// @lc code=end

