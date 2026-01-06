/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
#include <unordered_map>
struct Node {
  int key;
  int val;
  Node* next;
  Node* prev;
  Node() : key(0), val(0), next(nullptr), prev(nullptr) {}
  Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
  Node(int k, int v, Node* p, Node* n) : key(k), val(v), next(n), prev(p) {}
};
class LRUCache {
 public:
  int cap;
  Node* head = new Node(-1, -1);
  Node* tail = new Node(-1, -1);
  std::unordered_map<int, Node*> mp;

  LRUCache(int capacity) {
    cap = capacity;
    head->next = tail;
    tail->prev = head;
  }
  
  int get(int key) {
    if (mp.find(key) != mp.end()) {
      Node* temp = mp[key];
      int ans = temp->val;
      mp.erase(key);
      erase(temp);
      add(temp);
      mp[key] = temp;
      return ans;
    }
    return -1;
  }
  
  void put(int key, int value) {
    if (mp.find(key) != mp.end()) {
      Node* temp = mp[key];
      erase(temp);
      mp.erase(key);
    }
    
    if (mp.size() == cap) {
      mp.erase(tail->prev->key);
      erase(tail->prev);
    }
    add(new Node(key, value));
    mp[key] = head->next;
  }

  void add(Node* node) {
    Node* temp = head->next;
    head->next = node;
    node->prev = head;
    node->next = temp;
    temp->prev = node;
  }

  void erase(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
