/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
#include <algorithm>
#include <stack>
#include <vector>
class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    std::stack<int> st;
    int largest_rectangle_area = 0;
    for (int i = 0; i < heights.size(); ++i) {
      while (!st.empty() && heights[i] <= heights[st.top()]) {
        int nse = i;
        int height = heights[st.top()];
        st.pop();
        int pse;
        if (!st.empty()) {
          pse = st.top();
        } else {
          pse = -1;
        }
        largest_rectangle_area = std::max(largest_rectangle_area, 
            height * (nse - pse - 1));
      }
      st.push(i);
    }
    while (!st.empty()) {
      int pse;
      int height = heights[st.top()];
      st.pop();
      if (st.empty()) {
        pse = -1;
      } else {
        pse = st.top();
      }
      largest_rectangle_area = std::max(largest_rectangle_area, 
          height * int(heights.size() - pse - 1));
    }
    return largest_rectangle_area;
  }
};
// @lc code=end
