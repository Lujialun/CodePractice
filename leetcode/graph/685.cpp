/*
 * @Descripttion:  https://leetcode-cn.com/problems/redundant-connection-ii/description/
 * @version: https://leetcode-cn.com/problems/redundant-connection-ii/solution/xian-tiao-guo-zhi-xiang-ru-du-wei-2de-jie-dian-de-/
 * @Author: Lucas
 * @Date: 2020-08-07 20:43:09
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-08 10:03:41
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
    int node=-1;
    for(int i=0; i<edges.size(); i++){
        indegree[edges[i][1]]++;
        if(indegree[edges[i][1]]>1){//记录有两个爹的另外处理
            node=edges[i][1];
        }
    } 
    for(int i=0; i<1001; i++){ 
        tree[i]=i;
    }
    vector<vector<int>> E;
    for(int i=0; i<edges.size(); i++){ 
        if(node==edges[i][1]){
            
            E.push_back(edges[i]);
            continue;
        }
        int set1=find(tree, edges[i][0]);
        int set2=find(tree, edges[i][1]);
        if(set1==set2){ 
           
            return edges[i];
        }else{ 
            tree[set2]=set1;
        }
    }
    for(int i=0; i<E.size(); i++){
        int set1=find(tree, E[i][0]);
        int set2=find(tree, E[i][1]);
        if(set1==set2){ 
            return E[i];
        }else{ 
            tree[set2]=set1;
        }
    }
    return {};
} 

int main()
{
    vector<vector<int>> a={ { 1, 2 }, { 1,3 }, { 2, 3 } };
    vector<int> b=findRedundantDirectedConnection(a);
    for(auto i:b){ 
        cout<<i<<" "; 
    }
    system("pause");
}