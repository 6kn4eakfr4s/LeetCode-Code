/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    int numFresh = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == 1) {
          numFresh++;
        } else if (grid[i][j] == 2) {
          q.push({i, j});
        }
      }
    }
    int ans = 0;
    vector<int> dx = {0, 1, -1, 0};
    vector<int> dy = {1, 0, 0, -1};
    // cout<<numFresh<<" "<<q.size()<<endl;
    while(!q.empty() && numFresh > 0){
      int s = q.size();
      for(int i = 0; i < s; i ++){
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        for(int j = 0; j < 4; j ++){
          int nx = x + dx[j];
          int ny = y + dy[j];
          if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() &&
             grid[nx][ny] == 1){
               grid[nx][ny] = 2;
               numFresh --;
               q.push({nx, ny});
             }
        }
      }
      ans ++;
    }
    // cout<<numFresh<<endl;
    if(numFresh == 0) {
      return ans;
    } else {
      return -1;
    }
  }
};
// @lc code=end
