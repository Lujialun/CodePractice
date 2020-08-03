/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-02 10:42:06
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-02 10:52:49
 */ 
#include <bits/stdc++.h>
using namespace std;

int getWinner(vector<int>& arr, int k) {
    queue<int> q;
    int win = arr[0];
    for(int i=1; i<arr.size(); i++){
        q.push(arr[i]);
    }
    int cnt = 0;
    while(true){
        if(win>q.front()){
            cnt++;
            q.push(q.front());
            q.pop();
            if (cnt == k)
                return win;
        }else{
            cnt = 1;
            q.push(win);
            win=q.front();
            q.pop();
        }
    }
    return 0;
}