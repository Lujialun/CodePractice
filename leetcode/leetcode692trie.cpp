/*
 * @Descripttion: 692. 前K个高频单词 https://leetcode-cn.com/problems/top-k-frequent-words/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-11 19:55:24
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-11 22:02:43
 */
#include <bits\stdc++.h>
using namespace std;

struct TrieNode{
    bool  isEnd;
    TrieNode* branch[26];
    int times;
    string s;
    TrieNode():isEnd(false ),times(0){
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
        for(int i=0; i<k&&!p.empty(); i++){
            res[i]=p.top().second;
            p.pop();
        //    cout<<p.top().second<<endl;
        }
        reverse(res.begin(),res.end()); 
       // sort(res.begin(),res.end());
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
        node->times++;
        node->s=word;
    }

    void dfs(TrieNode* root){
        if(root==nullptr) return;
        if(root->isEnd){
            p.push(make_pair(root->times,root->s));
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
private:
    TrieNode* root;
    int K;
    priority_queue<pair<int,string>,vector<pair<int,string>>,  greater<pair<int,string>>> p;
};