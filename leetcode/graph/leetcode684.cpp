/*
 * @Descripttion:  https://leetcode-cn.com/problems/redundant-connection/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-07 15:08:24
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-07 20:17:37
 */

#include <bits/stdc++.h>
using namespace std;
//并查集 https://leetcode-cn.com/problems/redundant-connection/solution/tong-su-jiang-jie-bing-cha-ji-bang-zhu-xiao-bai-ku/

int find(int x,vector<int>& tree){
    while(x!=tree[x]){
        x=tree[x];
    }
     return x;
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    vector<int> tree(1001);
    for(int i=0; i<1001; i++){//初始化节点自己代表自己
        tree[i]=i;
    }
    for(int i=0; i<edges.size(); i++){
        int set1=find(edges[i][0],tree);//找父节点
        int set2=find(edges[i][1],tree);
        if(set1==set2){//父节点重合证明出现环
            return edges[i];
        }else{
            tree[set1]=set2;//没出现玩前者的父节点设置为后者父节点
        }
      }
}  