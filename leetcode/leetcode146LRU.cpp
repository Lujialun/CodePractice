/*
 * @Descripttion: LRU https://leetcode-cn.com/problems/lru-cache/
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-20 19:24:16
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-20 23:10:50
 */ 
#include <bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        int tmp = -1;
        while(!cache.empty()){
            if(key==cache.front().first){
                
            }
        }
        
        
    }
    
    void put(int key, int value) {

    }
private:
    int size;
    queue<pair<int,int>> cache;
    stack<int> temp;
};
