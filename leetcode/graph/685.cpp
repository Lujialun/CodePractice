/*
 * @Descripttion:  https://leetcode-cn.com/problems/redundant-connection-ii/description/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-07 20:43:09
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-07 22:56:57
 */
#include <bits/stdc++.h>
using namespace std;
int find(vector<int>& t, int x){
    int a=x;
    while(x!=t[x]){ 
        x=t[x];
    }
    return t[a]=x;//路径压缩
}
vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    vector<int> tree(1001);
    vector<int> indegree(1001,0);
    for(int i=0; i<edges.size(); i++){
        indegree[edges[]]
    }
    f or(int i=0; i<1001; i++){ 
        tree[i]=i;
    }
    for(int i=0; i<edges.size(); i++){ 
        int set1=find(tree, edges[i][0]);
        int set2=find(tree, edges[i][1]);
        if(set1==set2){ 
            return edges[i];
        }else{ 
            tree[set2]=set1;
        }
    }
}