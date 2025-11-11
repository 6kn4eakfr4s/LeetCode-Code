/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int front = 0;
        int back = height.size() - 1;
        int best = 0;
        while(front != back){
            best = max(best, (back - front) * min(height[front], height[back]));
            if(height[front] < height[back]){
                front ++;
            }
            else{
                back --;
            }
        }
        return best;
    }
};
// @lc code=end

