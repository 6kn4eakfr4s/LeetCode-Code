/*
 * @lc app=leetcode id=2462 lang=cpp
 *
 * [2462] Total Cost to Hire K Workers
 */

// @lc code=start
#include <queue>
class Solution {
public:
  long long totalCost(vector<int>& costs, int k, int candidates) {
    if (candidates * 2 >= costs.size()) {
      sort(costs.begin(), costs.end());
      int total_cost = 0;
      for (int i = 0; i < k; ++i) {
        total_cost += costs[i];          
      }
      return total_cost;
    }
    std::priority_queue<pair<int, int>, vector<pair<int, int>>, 
                        greater<pair<int, int>>> lpq;
    std::priority_queue<pair<int, int>, vector<pair<int, int>>, 
                        greater<pair<int, int>>> rpq;
    for (int i = 0; i < candidates; ++i) {
      lpq.push({costs[i], i});
    }
    for (int i = costs.size() - candidates; i < costs.size(); ++i) {
      rpq.push({costs[i], i});
    }
    int num_works_left = costs.size();
    unsigned long long total_cost = 0;
    int l_index = candidates;
    int r_index = costs.size() - candidates - 1;
    for (int i = 0; i < k; ++i) {// Choose k workers
      if (candidates * 2 >= num_works_left) {// If can choose from every worker
        for (int j = l_index; j < costs.size(); ++j) {
          if (costs[j] != -1) {
            // cout<<"push: "<<costs[j]<<endl;
            lpq.push({costs[j], j});// Push the rest of workers into lpq
          }
        }
        for (int j = i; j < k; ++j) {// Pick the rest k workers
          // cout<<"top: "<<lpq.top().first<<endl;
          total_cost += lpq.top().first;
          lpq.pop(); 
        }
        return total_cost;
      }
      if (lpq.top().first <= rpq.top().first) {
        total_cost += lpq.top().first;
        // cout<<"left: "<<lpq.top().first<<endl;
        costs[lpq.top().second] = -1;// Mark as used
        lpq.pop();
        lpq.push({costs[l_index], l_index});
        ++l_index;
      } else {
        total_cost += rpq.top().first;
        // cout<<"right: "<<rpq.top().first<<endl;
        costs[rpq.top().second] = -1;//mark as used
        rpq.pop();
        rpq.push({costs[r_index], r_index});
        --r_index;
      }
      --num_works_left;
    }
    return total_cost;
  }
};
// @lc code=end

