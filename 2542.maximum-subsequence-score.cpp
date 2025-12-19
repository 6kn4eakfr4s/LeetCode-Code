/*
 * @lc app=leetcode id=2542 lang=cpp
 *
 * [2542] Maximum Subsequence Score
 */

// @lc code=start
#include <queue>
class Solution {
public:
  long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int, int>> p;
    for (int i = 0; i < nums1.size(); ++i) {
      p.push_back({nums2[i], nums1[i]});
    }
    sort(p.rbegin(), p.rend());
    std::priority_queue<int, vector<int>, greater<int>> pq;
    long long sum = 0;
    long long ans = 0;
    for (int i = 0; i < k - 1; ++i) {
      // cout<<"sum: "<<sum<<endl;
      sum += p[i].second;
      pq.push(p[i].second);
    }
    for (int i = k - 1; i < p.size(); ++i){
      // cout<<"sum: "<<sum<<endl;
      sum += p[i].second;
      pq.push(p[i].second);
      ans = max(ans, sum * p[i].first);
      sum -= pq.top();
      pq.pop();
    }
    return ans;
  }
};
// @lc code=end

