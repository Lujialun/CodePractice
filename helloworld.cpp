/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-08 16:46:45
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-02 23:05:20
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

int main() {
    vector<int> a = {0,1,2,3,4,5,6,7,9};
    cout << missingNumber(a) << endl;
    system("pause");
    return 0;
}