/*
 * @lc app=leetcode id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 */

// @lc code=start
#include <cstdint>
#include <vector>
class Solution {
public:
  int64_t BinarySearch(int l, int r, int64_t target, vector<int>& source) {
    // cout<<l<<" "<<r<<endl;
    if (l == r /*|| l == r - 1 && source[l] != target*/) {
      return r;
    }
    int mid = (l + r) / 2;
    // cout<<mid<<" "<<source[mid]<<"ajweifo"<<endl;
    if (source[mid] < target) {
      return BinarySearch(mid + 1, r, target, source);
    } else {
      return BinarySearch(l, mid, target, source);
    }
  }
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    sort(potions.begin(), potions.end());
    vector<int> ans(spells.size(), 0);
    for (size_t i = 0; i < spells.size(); ++i) {
      int64_t target = success / spells[i];
      if (success % spells[i] != 0) {
        ++target;
      }
      // cout<<"target: "<<target<<endl;
      ans[i] = potions.size() - BinarySearch(0, potions.size(), target, potions);
    }
    return ans;
  }
};
// @lc code=end

