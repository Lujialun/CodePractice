/*
 * @Descripttion: https://leetcode-cn.com/problems/jian-sheng-zi-lcof/
 * @version: 
 * @Author: Lucas
 * @Date: 2020-07-29 12:05:47
 * @LastEditors: Lucas
 * @LastEditTime: 2020-07-29 12:36:54
 */ 
class Solution {
public:
    int cuttingRope(int n) {//数学法
        if(n<4) return n-1;
        int a=n/3;
        int b=n%3;
        if(b==0) return pow(3,a);
        if(b==1) return pow(3,a-1)*4;
        else return pow(3,a)*2;
        return 0;
    }
};

class Solution {
public:
    int integerBreak(int n) {//递推法
        if(n<4) return n-1;
        vector<int> f(n+1,0);
        f[2]=2;f[3]=3,f[4]=4;
        for(int i=5; i<=n; i++){
            f[i]=3*f[i-3];
        }
        return f[n];
    }
};