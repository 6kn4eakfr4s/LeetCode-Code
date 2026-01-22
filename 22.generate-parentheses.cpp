/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <string>
#include <vector>
class Solution {
 private:
  std::vector<std::string> ans;
  std::string cur;
  void Search(int lp_num, int rp_num, int n) {
    int p_sum = lp_num + rp_num;
    if (p_sum == n) {
      ans.push_back(cur);
      return;
    }
    if (lp_num > rp_num) {
      cur.push_back(')');
      Search(lp_num, rp_num + 1, n);
      cur.pop_back();
    }
    if (n - p_sum > lp_num - rp_num) {
      cur.push_back('(');
      Search(lp_num + 1, rp_num, n);
      cur.pop_back();
    }
  }
 public:
  vector<string> generateParenthesis(int n) {
    Search(0, 0, n * 2);
    return ans;
  }
};
// @lc code=end
