/*
 * @lc app=leetcode id=1466 lang=cpp
 *
 * [1466] Reorder Routes to Make All Paths Lead to the City Zero
 */

// @lc code=start
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
      unsigned int ans = 0;
      vector<vector<int>> adjList(n, vector<int>());
      vector<vector<int>> adjList1(n, vector<int>());
      for(int i = 0; i < connections.size(); i ++){
        adjList[connections[i][1]].push_back(connections[i][0]);
        adjList1[connections[i][0]].push_back(connections[i][1]);
      }
      queue<int> q;
      q.push(0);
      vector<bool> visited(n, false);
      while(!q.empty()){
        int t = q.front();
        q.pop();
        visited[t] = true;
        for(int i = 0; i < adjList[t].size(); i ++){
          if(visited[adjList[t][i]])continue;
          q.push(adjList[t][i]);
        }
        for(int i = 0; i < adjList1[t].size(); i ++){
          if(visited[adjList1[t][i]])continue;
          q.push(adjList1[t][i]);
          ans ++;
        }
      }
      return ans;
    }
};
// @lc code=end

