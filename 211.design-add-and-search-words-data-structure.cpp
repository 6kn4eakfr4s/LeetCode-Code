/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
#include <cstddef>
#include <queue>
struct TrieNode {
  bool terminate = false;
  TrieNode* children[26] = {};
  TrieNode() {}
};

class WordDictionary {
 public:
  WordDictionary() {
    root = new TrieNode;
  }
  
  void addWord(string word) {
    TrieNode *cur = root;    
    for (int i = 0; i < word.length(); ++i) {
      if (cur->children[word[i] - 'a'] == nullptr) {
        cur->children[word[i] - 'a'] = new TrieNode;
      }
      cur = cur->children[word[i] - 'a'];
    }    
    cur->terminate = true;
  }
  
  bool search(string word) {
    std::queue<TrieNode*> q;
    q.push(root);
    for (int i = 0; i < word.length(); ++i) {
      int q_size = q.size();
      while (q_size > 0) {
        TrieNode *node = q.front();
        q.pop();
        --q_size;
        if (node == nullptr) {
          continue;
        }
        if (word[i] == '.') {
          for (int j = 0; j < 26; ++j) {
            q.push(node->children[j]);
          }
        } else {
          q.push(node->children[word[i] - 'a']);
        }
      }
    }
    while (!q.empty()) {
      TrieNode *node = q.front();
      q.pop();
      if (node && node->terminate) {
        return true;
      }
    }
    return false;
}

 private:
  TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
