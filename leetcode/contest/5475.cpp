/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-02 10:33:31
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-02 10:41:59
 */ 
#include <bits/stdc++.h>
using namespace std;

int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    // int p=0,q=1,m=2;
    int n = arr.size();
    int ans = 0;
    for (int p = 0; p < n - 2; p++){
        for (int q = p + 1; q<n-1; q++){
            for (int m = q + 1; m<n; m++){
                if(abs(arr[p]-arr[q])>a)
                    continue;
                if(abs(arr[q]-arr[m])>b)
                    continue;
                if(abs(arr[i]-arr[m])>c)
                    continue;
                ans++;
            }
        }
    }
    return ans;
}