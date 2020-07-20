/*
 * @Descripttion: LRU https://leetcode-cn.com/problems/lru-cache/
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-20 19:24:16
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-21 00:54:43
 */ 
#include <bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        auto it = query.find(key);
        if(it==query.end())
            return -1;
        int res = *(it->second);
        cache.erase(it->second);
         cache.push_back(res);
        query[key] = cache.rbegin();
       
        return res;
    }
    
    void put(int key, int value) {
        auto it = query.find(key);
        if(it!=query.end()){
            *(it->second) = value;
            return;
        }
        if()
    }
private:
    int cap;
    list<int> cache;
    unordered_map<int, list<int>::reverse_iterator> query;
};
