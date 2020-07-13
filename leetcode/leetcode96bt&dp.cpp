/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-12 20:28:37
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-12 21:32:12
 */ 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 int numTrees(int n) {
     vector<int> dp(n+1, 0);
     if(n<2)
         return n;
     dp[0]=1, dp[1] = 1;
     for (int i = 2; i <= n; i++){
         for (int j = 1; j <= (i+1)/2; j++){
             if(i&1 && j==((i+1)/2)){ 
                 dp[i] += dp[i - j] * dp[j - 1];     
             }
             else dp[i] += 2*dp[i - j] * dp[j - 1];
         }
     }
     return dp[n];
}

int main()
{
    cout << numTrees(7) << endl;
    system("pause");
    return 0;
}