/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
#include <functional>
#include <queue>
#include <vector>
class MedianFinder {
 public:
  MedianFinder() {
      
  }
  
  void addNum(int num) {
    if (smaller_half_.empty()) {
      smaller_half_.push(num);
      return;
    } else if (bigger_half_.empty()) {
      if (num >= smaller_half_.top()) {
        bigger_half_.push(num);
        return;
      } else {
        bigger_half_.push(smaller_half_.top());
        smaller_half_.pop();
        smaller_half_.push(num);
        return;
      }
    }
    if (num < smaller_half_.top()) {
      smaller_half_.push(num);
    } else if (num > bigger_half_.top()) {
      bigger_half_.push(num);
    } else {
      if (smaller_half_.size() > bigger_half_.size()) {
        bigger_half_.push(num);
      } else {
        smaller_half_.push(num);
      }
    }
    if (int(smaller_half_.size()) - int(bigger_half_.size()) > 1) {
      bigger_half_.push(smaller_half_.top());
      smaller_half_.pop();
    } else if (int(bigger_half_.size()) - int(smaller_half_.size()) > 1) {
      smaller_half_.push(bigger_half_.top());
      bigger_half_.pop();
    }
  }
  
  double findMedian() {
    if ((smaller_half_.size() + bigger_half_.size()) % 2 == 1) {
      if (smaller_half_.size() > bigger_half_.size()) {
        return smaller_half_.top();
      } else {
        return bigger_half_.top();
      }
    } else {
      return double((smaller_half_.top() + bigger_half_.top())) / 2.0;
    }
  }

 private:
  std::priority_queue<int> smaller_half_;
  std::priority_queue<int, std::vector<int>, std::greater<int>> bigger_half_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
