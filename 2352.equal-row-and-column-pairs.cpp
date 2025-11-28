/*
 * @lc app=leetcode id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
 */

// @lc code=start
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;
        for(int i = 0; i < grid.size(); i ++){
            mp[grid[i]] ++;
        }
        int ans = 0;
        for(int i = 0; i < grid.size(); i ++){
            vector<int> col;
            for(int j = 0; j < grid.size(); j ++){
                col.push_back(grid[j][i]);
            }
            auto it = mp.find(col);
            if(it != mp.end()){
                ans += it->second;
            }
        }
        return ans;
    }
};
// @lc code=end

