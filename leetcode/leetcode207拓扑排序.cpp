/*
 * @Descripttion: 207. 课程表 拓扑排序 https://leetcode-cn.com/problems/course-schedule/ 
 * @version:  
 * @Author: sueRimn
 * @Date: 2020-07-26 15:29:01
 * @LastEditors: Lucas
 * @LastEditTime: 2020-07-26 16:46:17
 */ 
#include<bits/stdc++.h>
using namespace std;
//判断有向无环图 1.拓扑排序  2.dfs
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> indegree(numCourses, 0);//计算入度
    vector<int> v;
    vector<vector<int>> graph(numCourses,v);
    for (int i = 0; i < prerequisites.size(); i++){
        indegree[prerequisites[i][0]]++;
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++){
        if(indegree[i]==0)
            q.push(i);
    }
    int cnt = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < graph[cur].size(); i++){
            indegree[graph[cur][i]]--;
            if(indegree[graph[cur][i]]==0)
                q.push(graph[cur][i]);
        }
    }
    return cnt == numCourses;
}