/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
#include <algorithm>
#include <functional>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
class Twitter {
 public:
  Twitter() {
      
  }
  
  void postTweet(int userId, int tweetId) {
    posts_[userId].push_back({count++, tweetId});
  }
  
  vector<int> getNewsFeed(int userId) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, 
      std::greater<std::pair<int, int>>> pq;
    for (int i = 0; i < follow_[userId].size(); ++i) {
      for (int j = 0; j < std::min(posts_[follow_[userId][i]].size(), 
        (unsigned long)(10)); ++j) {
        pq.push(posts_[follow_[userId][i]][posts_[follow_[userId][i]].size() - 1
           - j]);
        if (pq.size() > 10) {
          pq.pop();
        }
      }
    }    
    for (int i = 0; i < posts_[userId].size(); ++i) {
      pq.push(posts_[userId][i]);
      if (pq.size() > 10) {
        pq.pop();
      }
    }
    std::vector<int> ans;
    while (!pq.empty()) {
      ans.push_back(pq.top().second);
      pq.pop();
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
  }
  
  void follow(int followerId, int followeeId) {
    if (followerId == followeeId) return;
    unfollow(followerId, followeeId);
    follow_[followerId].push_back(followeeId);
  }
  
  void unfollow(int followerId, int followeeId) {
    auto it = std::find(follow_[followerId].begin(), follow_[followerId].end(),
      followeeId);
    if (it == follow_[followerId].end()) {
      return;
    }
    std::swap(*it, follow_[followerId].back());
    follow_[followerId].pop_back();
  }

 private:
  std::unordered_map<int, std::vector<int>> follow_;
  std::unordered_map<int, std::vector<pair<int, int>>> posts_;
  int count = 0;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end
