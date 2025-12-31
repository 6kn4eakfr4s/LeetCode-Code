/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
#include <stack>
#include <string>
class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    std::stack<int> num_stack;
    for (int i = 0; i < tokens.size(); ++i) {
      if (tokens[i].length() > 1 || 
          ('0' <= tokens[i][0] && tokens[i][0] <= '9')) { 
        // tokens[i] is a number
        int num = std::stoi(tokens[i]);
        num_stack.push(num);
      } else { 
        // tokens[i] is a operator
        int num_2 = num_stack.top();
        num_stack.pop();
        int num_1 = num_stack.top();
        num_stack.pop();
        int result;
        if (tokens[i] == "+") {
          result = num_1 + num_2;
        } else if (tokens[i] == "-") {
          result = num_1 - num_2;
        } else if (tokens[i] == "*") {
          result = num_1 * num_2;
        } else {
          result = num_1 / num_2;
        }
        num_stack.push(result);
      }
    }
    return num_stack.top();
  }
};
// @lc code=end

