/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-07-31 20:14:10
 * @LastEditors: Lucas
 * @LastEditTime: 2020-07-31 20:14:18
 */ 
#include<bits/stdc++.h>

using namespace std;

// int trailingZeroes(int n) { 超时
//         int res=0;
//         for(int i=1; i<=n; i++){
//             int temp = i;
//             while(temp%5==0&&temp>0){
//                 res++;
//                 temp=temp/5;
//             }
//               if(i>temp) i+=4;
//         }
//         return res;
// }
int trailingZeroes(int n) {//100=5*20 20=4*5 20+4=24个5
    int res=0;
    while(n>0){
        n /= 5;
        res += n;
    }
    return res;
}
int main() {
    cout<<trailingZeroes(100)<<endl;
    system("pause");
    return 0;
}