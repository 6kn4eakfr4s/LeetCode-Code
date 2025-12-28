/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
#include <stack>
#include <vector>
class StockSpanner {
 public:
  std::stack<int> st;
  std::vector<int> prices;
  int next_index_;
  StockSpanner() {
    next_index_ = 0;
  }
    
  int next(int price) {
    prices.push_back(price);
    if (st.empty()) {
      st.push(next_index_);
      ++next_index_;
      return 1;
    } else if (prices[st.top()] <= price) { 
      while (!st.empty() && prices[st.top()] <= price) {
        st.pop();
      }
      ++next_index_;
      if (st.empty()) {
        st.push(next_index_ - 1);
        return next_index_;
      } else {
        int closest_larger_index = st.top();
        st.push(next_index_ - 1);
        return next_index_ - closest_larger_index - 1;
      }
    } else { //prices[st.top()] > price
      int closest_larger_index = st.top();
      st.push(next_index_);
      ++next_index_;
      return 1;
    }
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

