/*
 * @Descripttion:  地下城游戏,救公主！ https://leetcode-cn.com/problems/dungeon-game/
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-12 14:16:10
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-23 12:06:16
 */ 
#include<bits/stdc++.h>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int n = dungeon.size(), m = dungeon[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));//初始化为最大值（最后一行比较时有用）
    dp[n][m - 1] = dp[n - 1][m] = 1;//用于计算dp[n-1][m-1]
    for (int i = n - 1; i >= 0;i--){
        for (int j = m - 1; j >= 0; j--){
            int min_path = min(dp[i + 1][j], dp[i][j + 1]);//选一条需要初始值最小de
            dp[i][j] = max(min_path - dungeon[i][j], 1);//
        }
    }
    return dp[0][0];
}
int main()
{
    system("pause");
    return 0;
}
