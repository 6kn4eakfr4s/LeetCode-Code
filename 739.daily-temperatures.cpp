/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
#include <stack>
#include <utility>
using namespace std;
class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<pair<int, int>> st;
    st.push(pair<int, int>(temperatures[0], 0));
    vector<int> ans(temperatures.size());
    for (int i = 1; i < temperatures.size(); ++i) {
      // cout<<"st.top: "<<st.top().first<<" "<<i<<" "<<temperatures[i]<<endl;
      while (!st.empty() && st.top().first < temperatures[i]) {
        // cout<<st.top().second<<" "<<i<<endl;
        ans[st.top().second] = i - st.top().second;
        st.pop();
      }
      st.push(pair<int, int>(temperatures[i], i));
    }
    return ans;
  }
};
// @lc code=end

