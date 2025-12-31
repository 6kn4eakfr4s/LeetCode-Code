/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
  int trap(vector<int>& height) {
    int l = 0;
    int r = height.size() - 1;
    int l_max = height[l];
    int r_max = height[r];
    ++l;
    --r;
    int water_trapped = 0;
    while (l < r) {
      if (l_max < r_max) {
        water_trapped += max(0, l_max - height[l]);
        l_max = max(l_max, height[l]);
        ++l;
      } else {
        water_trapped += max(0, r_max - height[r]);
        r_max = max(r_max, height[r]);
        --r;
      }
    }
    return water_trapped;
  }
};
// @lc code=end
