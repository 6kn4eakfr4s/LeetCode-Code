/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      vector<bool> visited(rooms.size(), false);  
      int roomsLeft = rooms.size() - 1;
      visited[0] = true; 
      queue<int> q;
      q.push(0);
      while(!q.empty()){
        int f = q.front();
        q.pop();
        for(int i = 0; i < rooms[f].size(); i ++){
          if(!visited[rooms[f][i]]){
            roomsLeft --;
            q.push(rooms[f][i]);
            visited[rooms[f][i]] = true;
          }
        }
      }
      return roomsLeft == 0;
    }
};
// @lc code=end

