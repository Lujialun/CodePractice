/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-08 16:46:45
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-08 21:36:24
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

//class Solution {
//public:
class Solution {
public:
    int missingNumber(vector<int>& a) {
        int l=0,r=a.size()-1,m;
        while(l<=r){
            m=l+(r-l)/2;
            if(a[m]==m) l=m+1;
            else r=m-1;
        }
        return l;
    }
};
//};
 int solve(int n, vector<int>& a) {
        int Min=INT_MAX;
        for(auto i:a){
            if(i<Min) Min=i;
        }
        if(Min!=0&&Min>n){
            for(int i=0; i<n; i++){
                a[i] -= Min;
            }  
        }
        int p=0;
        for(int i=0; i<a.size(); i++){
            if(a[i]==0) return i+1;
             for(int j  =0; j<n; j++){
                if(a[j]>0) a[j]--;
            }
            if(i==a.size()-1) i=-1; 
        }
        return 0;
    }
int main() {
    vector<int> a = {10,2,2};
    cout << solve(3,a) << endl;
    system("pause");
    return 0;
}