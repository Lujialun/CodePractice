/*
 * @Descripttion: 211. 添加与搜索单词 - 数据结构设计 https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-23 12:53:50
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-23 15:20:02
 */ 
#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *node = root;
        for(auto c:word){
            if(node->branch[c-'a']==nullptr){
                node->branch[c-'a']=new TrieNode();
            }
            node = node->branch[c - 'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to         represent any one letter. */
    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    struct TrieNode{
        bool isEnd;
        TrieNode *branch[26];
        TrieNode():isEnd(false){
            for (int i = 0; i < 26; i++){
                branch[i] = nullptr;
            }
        }
    };
    TrieNode *root;

    bool dfs(string word, int cur, TrieNode* node){
        if(cur==word.size())
            return node->isEnd;
        
        for (int i = cur; i < word.size(); i++)
        {
            if(word[i]=='.'){
                for(TrieNode* t:node->branch){
                    if(t==nullptr)
                        continue;
                    if(dfs(word,i+1,t))
                        return true;
                }
                return false;
            }
            if(node->branch[word[i]-'a']==nullptr)
                return false;
            node = node->branch[word[i] - 'a'];
        }
        return node->isEnd;
    }
};

int main()
{
    WordDictionary *dic = new WordDictionary();
    dic->addWord("at");
    dic->addWord("and");
    dic->addWord("an");
    dic->addWord("add");
    dic->addWord("bat");
    cout << dic->search("b.") << endl;
    system("pause");
}