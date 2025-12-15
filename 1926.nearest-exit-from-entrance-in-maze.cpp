/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
class Solution {
public:
  bool isExit(int x, int y, vector<int> &entrance, vector<vector<char>> &maze) {
    // cout<<((x == 0 || x == maze.size() - 1) || (y == 0 || y == maze[0].size()
    // - 1))<<(x != entrance[0] || y != entrance[1])<<(maze[x][y] != '+')<<endl;
    return ((x == 0 || x == maze.size() - 1) ||
            (y == 0 || y == maze[0].size() - 1)) &&
           (x != entrance[0] || y != entrance[1]) && maze[x][y] != '+';
  }
  int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> dy = {1, 0, -1, 0};
    vector<int> dx = {0, 1, 0, -1};
    maze[entrance[0]][entrance[1]] = '+';
    queue<pair<int, int>> q;
    q.push({entrance[0], entrance[1]});
    int ans = 0;
    while (!q.empty()) {
      int s = q.size();
      ans++;
      for (int j = 0; j < s; j++) {
        pair<int, int> curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        int nx, ny;
        for (int i = 0; i < 4; i++) {
          nx = x + dx[i];
          ny = y + dy[i];
          if (nx >= 0 && nx < maze.size() && ny >= 0 && ny < maze[0].size() &&
              maze[nx][ny] != '+') {
            if (isExit(nx, ny, entrance, maze)) {
              return ans;
            }
            q.push({nx, ny});
            maze[nx][ny] = '+';
          }
        }
      }
    }
    return -1;
  }
};
// @lc code=end
