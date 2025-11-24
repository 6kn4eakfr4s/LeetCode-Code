/*
 * @lc app=leetcode id=2536 lang=cpp
 *
 * [2536] Increment Submatrices by One
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < queries.size(); i ++){
            diff[queries[i][0]][queries[i][1]] ++;
            diff[queries[i][2] + 1][queries[i][3] + 1]++;
            diff[queries[i][0]][queries[i][3] + 1] --;
            diff[queries[i][2] + 1][queries[i][1]] --;
        } 
        vector<vector<int>> mat(n, vector<int>(n, 0));
        mat[0][0] = diff[0][0];
        for(int i = 1; i < n; i ++){
            mat[i][0] = mat[i - 1][0] + diff[i][0];
            mat[0][i] = mat[0][i - 1] + diff[0][i];
        }
        for(int i = 1; i < n; i ++){
            for(int j = 1; j < n; j ++){
                mat[i][j] = mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1] + diff[i][j];
            }
        } 
        return mat;
    }
};
// @lc code=end

