/*
 * @Descripttion: 1.Trie
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-22 22:47:40
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-23 00:16:11
 */ 
#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    char data;
    TrieNode * Son[26];
    TrieNode() : data('0'){};
    TrieNode(char d) : data(d){};
}; 
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        for(auto it:word){
            if
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {

    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {

    }
private:
    TrieNode *root;
};

