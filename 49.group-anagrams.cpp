/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <array>
#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>
class Solution {
 public:
  std::array<int, 26> Hash(const std::string& s) {
    std::array<int, 26> hash;
    hash.fill(0);
    for (const auto& c : s) {
      ++hash[c - 'a'];
    }
    return hash;
  }
  static size_t ArrayHash(const std::array<int, 26>& arr) {
    size_t h = 0;
    for (int i : arr) {
      h ^= std::hash<int>{}(i) + 0x9e3779b9 + (h << 6) + (h >> 2);
    }
    return h;
  }
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    std::unordered_map<std::array<int, 26>, std::vector<std::string>,
                       decltype(&ArrayHash)> groups(0, ArrayHash);
    std::vector<std::vector<std::string>> ans;
    for (const auto& s : strs) {
      std::array<int, 26> hash_value = Hash(s);
      if (groups.find(hash_value) != groups.end()) {
        groups[hash_value].push_back(s);
      } else {
        groups.insert({hash_value, std::vector<std::string>{s}});
      }
    }
    for (auto const& it : groups) {
      ans.push_back(it.second);
    }
    return ans;
  }
};
// @lc code=end

