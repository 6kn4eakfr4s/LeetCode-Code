/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>
struct TimeStampedData {
  std::string data;
  int timestamp;
};

class TimeMap {
public:
  std::unordered_map<std::string, std::vector<TimeStampedData>> mp;
  TimeMap() {
        
  }
    
  void set(string key, string value, int timestamp) {
    mp[key].push_back({value, timestamp});
  }
    
  string get(string key, int timestamp) {
    int l = 0;
    int r = mp[key].size();
    while (l < r) {
      int mid = (l + r) / 2;
      if (mp[key][mid].timestamp < timestamp) {
        l = mid;
        if (r - l == 1) {
          return mp[key][l].data;
        }
      } else if (mp[key][mid].timestamp > timestamp) {
        r = mid;
      } else {
        return mp[key][mid].data;
      }
    }
    return "";
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end
