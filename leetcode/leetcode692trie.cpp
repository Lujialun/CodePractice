/*
 * @Descripttion: 692. 前K个高频单词 https://leetcode-cn.com/problems/top-k-frequent-words/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-11 19:55:24
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-12 10:55:06
 */
#include <bits\stdc++.h>
using namespace std;

struct TrieNode{
    bool  isEnd;
    TrieNode* branch[26];
    //int times;
    //string s;
    pair<int,string> show ;
    TrieNode():isEnd(false ){
        show.first=0;
        for(int i=0;i<26; i++){
             branch[i]=nullptr;
        }
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        root=new TrieNode();
        for(auto it:words){
            insert(it);
        }
        K=k;
        vector<string> res(k);
        dfs(root);
        for(int i=0; i<k; i++){
            res[i]=p.top().second;
            p.pop();
        }
        reverse(res.begin(),res.end()); 
        return res;
    }
     void insert(string &word){
        TrieNode* node=root;

        for(auto it:word){
            if(node->branch[it-'a']==nullptr){
                node->branch[it-'a']=new TrieNode();
            }
            node=node->branch[it-'a'];
        }
        node->isEnd=true;
        node->show.first++;
        node->show.second=word;
    }

    void dfs(TrieNode* root){
        if(root==nullptr) return;
        if(root->isEnd){
            p.push(root->show);
            if(p.size()>K){
                p.pop();
            }
        }  
        for(int i=0; i<26; i++){
            if(root->branch[i]!=nullptr){
                dfs(root->branch[i]);
            }
        } 
    }

    struct comp{
        bool operator()(pair<int,string> a, pair<int,string> b){
            if(a.first>b.first) return true;
            if(a.first<b.first) return false;
            if(a.second>=b.second) return false;
            return true;
        }
    };
private:
    TrieNode* root;
    int K;
    priority_queue<pair<int,string>,vector<pair<int,string>>,  comp> p;
};