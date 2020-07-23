/*
 * @Descripttion: LRU https://leetcode-cn.com/problems/lru-cache/
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-20 19:24:16
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-22 20:00:54
 */ 
#include <bits/stdc++.h>
using namespace std;

struct DListNode{
    int value;
    int key;
    DListNode *prev;
    DListNode *next;
    DListNode() : key(0),value(0), prev(nullptr), next(nullptr){};
    DListNode(int k,int v) : key(k),value(v), prev(nullptr), next(nullptr){}
};
class LRUCache {
public:
    LRUCache(int capacity) {
        cap=capacity;
        head = new DListNode();
        tail = new DListNode();
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    int get(int key) {
        auto iter = query.find(key);
        if(iter ==query.end()){
            return -1;
        }
        refresh(iter->second);
        return iter->second->value;
    }
    
    void put(int key, int value) {
        auto iter = query.find(key);
        if(iter!=query.end()){
            iter->second->value = value;
            refresh(iter->second);
            return;
        }
        DListNode *node = new DListNode(key,value);
        query[key] = node;
        push_back(node);
        size++;
        if(size>cap){
         //   cout << head->next->key << endl;
            head->next = head->next->next;
         //   cout << head->next->prev->key << endl;
            query.erase(head->next->prev->key);
            delete head->next->prev;
            head->next->prev = head;
            size--;
        }
    }

    
private:
    void refresh(DListNode *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        push_back(node);
    }
    void push_back(DListNode *node){
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
        
       // cout << head->next->key << " " << tail->prev->key << endl;
    }
    int cap;
    int size;
    DListNode *head;
    DListNode *tail;
    unordered_map<int, DListNode*> query;
};

int main()
{
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;
    system("pause");
    return 0;
}