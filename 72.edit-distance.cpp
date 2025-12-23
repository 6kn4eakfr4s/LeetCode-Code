/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
  int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));
    //change the first i words in word1 to the first j words in word 2
    for (int i = 1; i <= word1.length(); ++i) {
      dp[i][0] = i;
    }
    for (int i = 1; i <= word2.length(); ++i) {
      dp[0][i] = i;
    }
    for (int i = 1; i <= word1.length(); ++i) {
      for (int j = 1; j <= word2.length(); ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]) + 1);
        } else {
          dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        }
      }
    }
    return dp[word1.length()][word2.length()];
  }
};
// @lc code=end

