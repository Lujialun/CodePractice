/*
 * @Descripttion: 实现 Trie (前缀树) https://leetcode-cn.com/problems/implement-trie-prefix-tree/
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-22 21:28:17
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-23 10:55:33
 */ 
#include <bits/stdc++.h>
using namespace std;


class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    ~Trie(){
        destroy(root);
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        for(auto it:word){
            if(node->Son[it-'a']==nullptr){
                TrieNode *tmp = new TrieNode();
                node->Son[it - 'a'] = tmp;
            }
            node = node->Son[it - 'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = root;
        for(auto it:word){
            if(node->Son[it-'a']==nullptr)
                return false;
            node = node->Son[it - 'a'];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(auto it:prefix){
            if(node->Son[it-'a']==nullptr)
                return false;
            node = node->Son[it - 'a'];
        }
        return true;
    }
private:
    struct TrieNode{
        bool isEnd;
        TrieNode * Son[26];
        TrieNode() : isEnd(false){
            for (int i = 0; i < 26; i++){
            Son[i] = nullptr;
            }
        };
    }; 

    void destroy(TrieNode* node) {
        if(node ==nullptr) return;

        for(TrieNode* entry : node->Son)
        {
            destroy(entry); 
        } 

      if(node) 
      { 
          delete node;
          node = nullptr;
    }
  }

    TrieNode *root;
};



int main()
{
    Trie *trie=new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << endl;
    cout << trie->search("app") << endl;
    cout << trie->startsWith("app") << endl;
    trie->insert("app");
    cout << trie->search("app") << endl;
    system("pause");
}