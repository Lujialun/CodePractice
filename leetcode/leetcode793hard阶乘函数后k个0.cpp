/*
 * @Descripttion: 793. 阶乘函数后K个零 https://leetcode-cn.com/problems/preimage-size-of-factorial-zeroes-function/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-07-31 20:48:49
 * @LastEditors: Lucas
 * @LastEditTime: 2020-07-31 21:27:57
 */ 
#include<bits/stdc++.h>

using namespace std;
 int preimageSizeFZF(int k) {
     long long  left = 0, right = LONG_LONG_MAX;
     while(left<right){
        long long m = left + (right - left) / 2;
        long long cnt = 0, temp = m;
        while(temp>0){
            temp /= 5;
            cnt += temp;
        }
        if(cnt<k)  left = m + 1;
        else if(cnt>k) right = m - 1;
        else return 5;
     }
     return 0;
}

    int main() {
    cout<<preimageSizeFZF(1000000000)<<endl;
    system("pause");
    return 0;
}