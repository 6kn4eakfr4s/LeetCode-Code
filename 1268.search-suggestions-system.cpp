/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */

// @lc code=start
#include <cstddef>
#include <stdexcept>
class TrieNode{
 public:
  TrieNode* child_[26];
  bool is_word_;
  TrieNode() {
    is_word_ = false;
    for (int i = 0; i < 26; ++i) {
      child_[i] = nullptr;
    }
  }

  void SetWord() {
    is_word_ = true;
  }

  TrieNode* GetChild(char index) {
    return child_[index - 'a'];
  }

  void InsertChild(char index) {
    child_[index - 'a'] = new TrieNode();
  }
};

class Trie{
 public:
  TrieNode* root;  
  Trie() {
    root = new TrieNode();
  }
  void InsertWord(string& word) {
    TrieNode* cur = root;
    for(int i = 0; i < word.length(); ++i) {
      if (cur->GetChild(word[i]) == nullptr) {
        cur->InsertChild(word[i]);
      }
      cur = cur->GetChild(word[i]);
    }
    cur->SetWord();
  }
  TrieNode* FindLastChar(string& word) {
    TrieNode* cur = root;
    for(int i = 0; i < word.length(); ++i) {
      if(cur->GetChild(word[i]) == nullptr) {
        return nullptr;
      }
      cur = cur->GetChild(word[i]);
    }
    return cur;
  }

  void FindSuggestions(TrieNode* node, string& prefix, 
                                 vector<string>& suggestions) {
    if (suggestions.size() == 3) {
      return;
    }
    if (node->is_word_) {
      suggestions.push_back(prefix);
    }
    for(int i = 0; i < 26; ++i) {
      if (suggestions.size() == 3) {
        break;
      }
      TrieNode* child = node->GetChild('a' + i);
      if (child != nullptr) {
        FindSuggestions(child, prefix + char('a' + i), suggestions);
      }
    }
  }
};
class Solution {
 public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    Trie* t = new Trie();
    for (int i = 0; i < products.size(); ++i) {
      t->InsertWord(products[i]);
    }
    vector<vector<string>> ans;
    string cur_string = "";
    TrieNode* node = t->root;
    for(int i = 0; i < searchWord.length(); ++i) {
      if (node != nullptr) {
        node = node->GetChild(searchWord[i]);
      }
      cur_string += searchWord[i];
      if (node == nullptr) {
        ans.push_back({});
        continue;
      }
      vector<string> cans;
      t->FindSuggestions(node, cur_string, cans);
      ans.push_back(cans);
    }
    return ans;
  }
};
// @lc code=end
