/*
 * @Descripttion:  1025. 除数博弈 https://leetcode-cn.com/problems/divisor-game/
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-24 16:31:11
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-24 17:07:16
 */ 
#include <bits/stdc++.h>
using namespace std;

bool divisorGame(int N) {
    if(N==1) return false;
    vector<int> dp(N + 1);
    dp[0] = 1, dp[1] = 0,dp[2] = 1;
    for (int i = 3; i <= N; i++){
        for (int j = 1; j <= i/2; j++){
            if(i%j==0&&(dp[i-j]==0||dp[i-i/j]==0)){
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[N];
}

int main()
{
    cout << divisorGame(1000) << endl;
    system("pause");
    return 0;
}