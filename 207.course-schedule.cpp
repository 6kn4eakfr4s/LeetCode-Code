/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
#include <vector>
class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    course_map = vector(numCourses, vector<int>());
    visited = vector(numCourses, false);
    path = vector(numCourses, false);
    for (int i = 0;i < prerequisites.size(); ++i) {
      course_map[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    for (int i = 0; i < numCourses; ++i) {
      if (visited[i]) {
        continue;
      } else if (!ans) {
        return ans;
      }
      dfs(i);
    }
    return ans;
  }
 private:
  vector<vector<int>> course_map;
  vector<bool> visited;
  vector<bool> path;
  bool ans = true;
  void dfs(int x) {
    path[x] = true;
    visited[x] = true;
    for (int i = 0; i < course_map[x].size(); ++i) {
      if (path[course_map[x][i]]) {
        ans = false;
        return;
      }
      if (visited[course_map[x][i]]) {
        continue;
      }
      dfs(course_map[x][i]);
    }
    path[x] = false;
  }
};
// @lc code=end
