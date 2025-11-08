/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
class Solution {
public:
    int compress(vector<char>& chars) {
      bool isRep = false;
      int slowPointer= 0;
      int bookmark = 0;
      if(chars.size() <= 1){
        return chars.size();
      }
      for(int i = 1; i < chars.size(); i ++){
        if(chars[i] == chars[i - 1]){
          if(!isRep){
            isRep = true;
            chars[slowPointer ++] = chars[i];
            bookmark = i - 1;
          }
        }
        else{
          if(isRep){
            isRep = false;
            string seg_len = to_string(i - bookmark);
            for(int j = 0; j < seg_len.length(); j ++){
              chars[slowPointer ++] = seg_len[j];
            }
          }
          else{
            chars[slowPointer ++] = chars[i - 1];
          }
        }
    }
    if(isRep){
      string seg_len = to_string(chars.size() - bookmark);
      for(int j = 0; j < seg_len.length(); j ++){
          chars[slowPointer ++] = seg_len[j];
      }
    }
    else{
      chars[slowPointer ++] = chars[chars.size() - 1];
    }
    return slowPointer;
  }
};
// @lc code=end

