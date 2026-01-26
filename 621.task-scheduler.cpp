/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
#include <queue>
class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    for (int i = 0; i < tasks.size(); ++i) {
      ++mp_[tasks[i] - 'A'];
    }
    for (int i = 0; i < 26; ++i) {
      if (mp_[i] != 0) {
        pq_.push(mp_[i]);
      }
    }
    int time = 0;
    while (!pq_.empty()) {
      int cycle = n + 1;
      std::vector<int> processed;
      while (cycle && !pq_.empty()) {
        int num_tasks_left = pq_.top();
        pq_.pop();
        if (num_tasks_left > 1) {
          processed.push_back(num_tasks_left - 1);
        }
        --cycle;
        ++time;
      }
      for (int i = 0; i < processed.size(); ++i) {
        pq_.push(processed[i]);
      }
      if (pq_.empty()) {
        break;
      }
      time += cycle;
    }
    return time;
  }

 private:
  std::priority_queue<int> pq_;
  std::vector<int> mp_ = std::vector(26, 0);
};
// @lc code=end
