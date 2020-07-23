/*
 * @Descripttion: 最小路径和 https://leetcode-cn.com/problems/minimum-path-sum/
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-23 11:02:41
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-23 11:19:18
 */ 
#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    if(grid.empty())
        return 0;
    int m = grid.size(),n=grid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
    dp[1][1] = grid[0][0];
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
        }
    }
    return dp[m][n];
}

int main()
{
    system("pause");
}