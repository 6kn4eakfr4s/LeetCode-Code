/*
 * @lc app=leetcode id=2336 lang=cpp
 *
 * [2336] Smallest Number in Infinite Set
 */

// @lc code=start
#include <iostream>
#include <set>
using namespace std;
class SmallestInfiniteSet {
public:
  std::set<int> smallest_numbers;
  int smallest_unpopped;
  SmallestInfiniteSet() {
    smallest_unpopped = 1;
  }
    
  int popSmallest() {
    // cout<<smallest_unpopped<<endl;
    if (smallest_numbers.empty()) {
      smallest_unpopped ++;
      return smallest_unpopped - 1;
    }
    int temp = *smallest_numbers.begin();
    smallest_numbers.erase(smallest_numbers.begin());
    return temp;
  }
    
  void addBack(int num) {
    // cout<<smallest_unpopped<<endl;
    if (num >= smallest_unpopped)return;
    if (num == smallest_unpopped - 1) {
      --smallest_unpopped;
      while (!smallest_numbers.empty() && 
            *smallest_numbers.rbegin() == smallest_unpopped) {
        smallest_numbers.erase(*smallest_numbers.rbegin());
        --smallest_unpopped;
      }
      if (smallest_unpopped == 0) smallest_unpopped = 1;
      return;
    }
    smallest_numbers.insert(num);
  }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end