/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <stack>
class MinStack {
 private:
  std::stack<std::pair<int, int>> st;
 public:
  MinStack() {
  }
 
  void push(int val) {
    if (st.empty()) {
      st.push({val, val});
    } else {
      st.push({val, std::min(st.top().second, val)});
    }
  }
 
  void pop() {
    st.pop();
  }
 
  int top() {
    return st.top().first;      
  }
 
  int getMin() {
    return st.top().second;
  }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
