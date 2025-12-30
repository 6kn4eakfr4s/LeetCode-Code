/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include <unordered_map>
class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    std::unordered_set<int> num_set(nums.begin(), nums.end());
    int ans = 0;
    for (int num : num_set) {
      if (num_set.find(num - 1) == num_set.end()) {
        int length = 1;
        while (num_set.find(num + length) != num_set.end() ) {
          ++length;
        }
        ans = max(ans, length);
      }
    }
    return ans;
  }
};
// @lc code=end

