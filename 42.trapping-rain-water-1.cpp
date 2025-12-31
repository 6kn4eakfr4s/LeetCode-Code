/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include <vector>
#include <stack>
class Solution {
public:
  int trap(const std::vector<int>& height) {
    std::vector<int> next_taller(height.size(), 0);
    std::stack<int> st;
    st.push(0);
    for (int i = 1; i < height.size(); ++i) {
      while (!st.empty() && height[i] >= height[st.top()]) {
        next_taller[st.top()] = i;
        st.pop();
      }
      st.push(i);
    }
    while (!st.empty()) {
      next_taller[st.top()] = -1;
      st.pop();
    }
    int i = 0;
    int l_max = 0;
    int water_trapped = 0;
    while (i < height.size()) {
      if (next_taller[i] == -1) {
        l_max = height[i];
        ++i;
      } else {
        if (l_max > height[i]) {
          int r_max_index = i;
          while (next_taller[r_max_index] != -1) {
            r_max_index = next_taller[r_max_index];
          }
          for (int j = i; j < r_max_index; ++j) {
            water_trapped += height[r_max_index] - height[j];
          }
          i = r_max_index + 1;
          continue;
        } else {
          for (int j = i + 1; j < next_taller[i]; ++j) {
            water_trapped += height[i] - height[j];
          }
        }
        i = next_taller[i];
      }
    }
    return water_trapped;
  }
};
// @lc code=end