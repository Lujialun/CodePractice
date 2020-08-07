/*
 * @Descripttion:  https://leetcode-cn.com/problems/flower-planting-with-no-adjacent/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-07 15:13:09
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-07 16:56:44
 */
#include<bits\stdc++.h>
using namespace std;

vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
    vector<vector<int>> g(N);
    for(int i=0; i<paths.size(); i++){ 
        g[paths[i][0]-1].push_back(paths[i][1]-1);
        g[paths[i][1]-1].push_back(paths[i][0]-1);
    }
    vector<int> answer(N, 0);
    for (int i = 0; i < N; i++)
          {
              int m[4] = { 0 };
              for (int j = 0; j < g[i].size(); j++)
                  if(answer[g[i][j]]!=0)
                      m[ answer[g[i][j]]-1 ]++;
                  
              for (int k = 0; k < 4; k++)
                  if (m[k] == 0) {
                      answer[i]=k + 1;
                      break;
                  }            
          }
          return answer;
}
int main()
{
    vector<vector<int>> a={ { 1, 2 }, { 3, 4 }, { 3, 1 } };
    vector<int> b=gardenNoAdj(4, a);
    for(auto i:b){ 
        cout<<i<<" ";
    }
    system("pause");
}