/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
#include <climits>
class Solution {
public:
  bool CanFinish(int speed, const vector<int>& piles, int h){
    int time = 0;
    for (int i = 0; i < piles.size(); ++i) {
      if (piles[i] <= speed) {
        ++time;
      } else {
        time += piles[i] / speed;
        if (piles[i] % speed != 0) {
          ++time;
        }
      }
    }
    return time <= h;
  }
  int BinarySearch(int l, int r, const vector<int>& piles, int h){
    // cout<<l<<" "<<r<<endl;
    if (l == r) return l;
    int mid = (l + r) / 2;
    if (CanFinish(mid, piles, h)) {
      return BinarySearch(l, mid, piles, h);
    } else {
      return BinarySearch(mid + 1, r, piles, h);
    }
  }
  int minEatingSpeed(vector<int>& piles, int h) {
    return BinarySearch(1, INT_MAX - 1, piles, h);
  }
};
// @lc code=end

