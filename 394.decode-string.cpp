/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
#include <string>
class Solution {
public:
    string decodeString(string s) {
        int size = 0;
        int cnt = 0;
        stack<int> st;
        stack<int> sz;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] >= '0' && s[i] <= '9'){
                int multiplier = (s[i] - '0');
                i ++;
                while(s[i] >= '0' && s[i] <= '9'){
                    multiplier *= 10;
                    multiplier += (s[i] - '0');
                    i ++;
                }
                i --;
                st.push(multiplier);
            }
            else if(s[i] == '['){
                sz.push(cnt);
                cnt = 0;
                continue;
            }
            else if(s[i] == ']'){
                int temp = cnt;
                cnt = sz.top();
                sz.pop();
                cnt += st.top() * temp;
                st.pop();
                if(st.empty()){
                    size += cnt;
                    cnt = 0;
                }
            }
            else{
                cnt ++;
            }
        }
        size += cnt;
        cnt = 0;
        // cout<<size<<endl;
        string ans(size, '\0');
        for(int i = 0; i < s.size(); i ++){
            if(s[i] >= '0' && s[i] <= '9'){
                int multiplier = (s[i] - '0');
                i ++;
                while(s[i] >= '0' && s[i] <= '9'){
                    multiplier *= 10;
                    multiplier += (s[i] - '0');
                    i ++;
                }
                i --;
                st.push(multiplier);
            }
            else if(s[i] == '['){
                sz.push(cnt);
                continue;
            }
            else if(s[i] == ']'){
                int curEnd = cnt;
                for(int j = 1; j < st.top(); j ++){
                    for(int k = sz.top(); k < curEnd; k ++){
                        ans[cnt++] = ans[k];
                    }
                }
                st.pop();
                sz.pop();
            }
            else{
                ans[cnt++] = s[i];
            }
        }
        return ans;
    }
};
// @lc code=end

