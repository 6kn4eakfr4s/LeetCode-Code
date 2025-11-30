/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      vector<int> ans;
      int maxLeft = 0;
      int maxRight = 0;
      for(int i = 0; i < asteroids.size(); i ++){
        if(asteroids[i] < 0){
          bool add = ans.empty();
          while(!ans.empty()){
            if(ans[ans.size() - 1] < 0){
              add = true;
              break;
            }
            else{
              if(abs(ans[ans.size() - 1]) > abs(asteroids[i])){
                break;
              }
              else if(abs(ans[ans.size() - 1]) == abs(asteroids[i])){
                ans.pop_back();
                break;
              }
              else{
                ans.pop_back();
                if(ans.empty()){
                  add = true;
                }
              }
            }
              
          }
          if(add){
            ans.push_back(asteroids[i]);
          }
        }
        else{
          ans.push_back(asteroids[i]);
        }
      } 
      return ans;
    }
};
// @lc code=end

