/*
 * @Descripttion: https://leetcode-cn.com/problems/find-the-town-judge/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-07 16:57:27
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-07 17:10:31
 */
#include<bits\stdc++.h>
using namespace std;

int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> indegree(N,0);
    vector<int> outdegree(N,0);
    // vector<vector<int> >g(N);
    for(int i=0; i<trust.size(); i++){ 
        indegree[trust[i][1]-1]++;
        outdegree[trust[i][0]-1]++;
    }
    for(int i=0; i<N; i++){ 
        if(indegree[i]==N-1&&outdegree[i]==0){ 
            return i+1;
        }
    }
    return -1;
}

int main(){

}