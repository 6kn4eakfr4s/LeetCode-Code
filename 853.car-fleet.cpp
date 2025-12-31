/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */

// @lc code=start
#include <algorithm>
#include <numeric>
#include <vector>
class Solution {
public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    std::vector<int> position_idx;
    position_idx.resize(position.size());
    std::iota(position_idx.begin(), position_idx.end(), 0);
    std::sort(position_idx.begin(), position_idx.end(),
        [&](const auto& a, const auto& b) { return position[a] > position[b]; });
    int num_fleets = 0;
    double fleet_target_time = 0;
    for (int i = 0; i < position_idx.size(); ++i) {
      double car_target_time = double(target - position[position_idx[i]]) /
                               double(speed[position_idx[i]]);
      if (car_target_time > fleet_target_time) {
        ++num_fleets;
        fleet_target_time = car_target_time;
      }
    }
    return num_fleets;
  }
};
// @lc code=end
