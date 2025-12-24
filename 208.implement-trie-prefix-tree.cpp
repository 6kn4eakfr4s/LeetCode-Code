/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class TrieNode {
 public:
  TrieNode *child_[26];
  bool is_word_;
  TrieNode() {
    is_word_= false;
    for (int i = 0; i < 26; ++i) {
      child_[i] = nullptr;
    }
  }

  TrieNode* GetChild(char index) {
    return child_[index - 'a'];
  }

  void InsertChild(char index) {
    child_[index - 'a'] = new TrieNode();
  }

  void SetWord() {
    is_word_= true;
  }
};
class Trie {
 public:
    TrieNode* root_ = nullptr;
    Trie() {
      root_ = new TrieNode();
    }
    
    void insert(string word) {
      TrieNode* cur = root_;
      // cout<<"insert"<<endl;
      for (int i = 0; i < word.length(); ++i) {
        // cout<<word[i];
        if (cur->GetChild(word[i]) == nullptr) {
          cur->InsertChild(word[i]);
        }
        cur = cur->GetChild(word[i]);
      }
      // cout<<endl;
      cur->SetWord();
    }
    
    bool search(string word) {
      TrieNode* cur = root_;
      // cout<<"search"<<endl;
      for (int i = 0; i < word.length(); ++i) {
        // cout<<word[i]<<" ";
        cur = cur->GetChild(word[i]);
        if (cur == nullptr) {
          return false;
        }
      }
      // cout<<endl;
      return cur->is_word_;
    }
    
    bool startsWith(string prefix) {
      TrieNode* cur = root_;
      for (int i = 0; i < prefix.length(); ++i) {
        cur = cur->GetChild(prefix[i]);
        if (cur == nullptr) {
          return false;
        }
      }
      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

