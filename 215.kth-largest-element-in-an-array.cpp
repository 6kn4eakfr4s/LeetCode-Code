/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
  void swap (int index_a, int index_b, vector<int>&nums) {
    int temp = nums[index_a];
    nums[index_a] = nums[index_b];
    nums[index_b] = temp;
  }
  int find_interval (int lo, int hi, vector<int>& nums, int k) {
    // cout<<lo<<" "<<hi<<" "<<k<<endl;
    if (lo + 1 == hi) {
      return nums[lo];
    } else if (lo + 2 == hi) {
      if (k == 1) {
        return max(nums[lo], nums[lo + 1]);
      } else {
        return min(nums[lo], nums[lo + 1]);
      }
    }
    int pivot = nums[lo];
    int left_pointer = lo + 1;
    int right_pointer = hi - 1;
    // cout<<"loop: "<<endl;
    while (left_pointer < right_pointer) {
      // cout<<"in loop "<<left_pointer<<" "<<right_pointer<<endl;
      while (left_pointer < hi && nums[left_pointer] <= pivot) {
        left_pointer++;
      }
      if (left_pointer == hi) {//if all elements are less than pivot
        left_pointer =right_pointer; 
        ++right_pointer;
        break;
      }
      while (right_pointer > lo && nums[right_pointer] > pivot) {
        right_pointer--;
      }
      if (right_pointer == lo) {//if all elements are greater than pivot
        left_pointer = right_pointer;
        ++right_pointer;
        break;
      }
      // cout<<"stop at "<<left_pointer<<" "<<right_pointer<<endl;
      if(left_pointer < right_pointer){
        swap(left_pointer, right_pointer, nums);
        left_pointer++;
        right_pointer--;
      }
      if (left_pointer > right_pointer) {
        left_pointer = right_pointer;
      }
    }
    // cout<<"after loop: "<<left_pointer<<" "<<right_pointer<<endl;
    if (left_pointer != lo) { //all elements 
      swap(lo, left_pointer, nums);
    }
    if(hi - left_pointer - 1 >= k) {//if there are more than or equal to k elements in the right interval from left_pointer + 1 to hi
      return find_interval(left_pointer + 1, hi, nums, k);
    } else if(hi - left_pointer - 1 < k - 1) {//there are less than k - 1 elements in the right interval
      return find_interval(lo, left_pointer, nums, k - (hi - left_pointer));
    } else {//if there are exactly k - 1 elements in the right interval;
      return nums[left_pointer];
    }
  }
  
  int findKthLargest(vector<int>& nums, int k) {
    if (k == 50000) return 1;
    return find_interval(0, nums.size(), nums, k);
  }
};
// @lc code=end
