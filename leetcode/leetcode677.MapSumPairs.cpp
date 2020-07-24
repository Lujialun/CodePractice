/*
 * @Descripttion:  键值映射  https://leetcode-cn.com/problems/map-sum-pairs/
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-23 23:12:14
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-23 23:56:58
 */ 
#include <bits/stdc++.h>
using namespace std;

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode *node = root;
        for(auto c:key){
            if(node->branch[c-'a']==nullptr){
                node->branch[c - 'a'] = new TrieNode();
            }
            node = node->branch[c - 'a'];
        }
        node->value = val;
        node->isEnd = true;
    }
    
    int sum(string prefix) {
        TrieNode *node = root;
        for(auto c:prefix){
            if(node->branch[c-'a']==nullptr){
                return 0;
            }
            node = node->branch[c - 'a'];
        }
        return Sum(node);
    }

private:
    struct TrieNode{
        bool isEnd;
        int value;
        TrieNode* branch[26];
        TrieNode():isEnd(false),value(0){
            for(int i=0; i<26; i++){
                branch[i] = nullptr;
            }
        }
    };
    TrieNode *root;
    int Sum(TrieNode* node){
        if(node==nullptr)
            return 0;
        int sum = 0;
        if(node->isEnd)
            sum += node->value;
        for(TrieNode* t:node->branch){
            sum += Sum(t);
        }
        return sum;
    }
};

int main()
{
    MapSum* map=new MapSum();
    map->insert("apple", 3);
    system("pause");
    return 0;
}