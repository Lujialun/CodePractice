/*
 * @Descripttion: 求最大公约数最优法--更相相减法加移位
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-26 14:53:26
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-26 15:02:56
 */ 
#include<bits\stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(a==b)
        return a;
    if(!(a&1)&&!(b&1)){
        return gcd(a >> 1, b >> 1)<<1;
    }
    if(!(a&1)){
        return gcd(a >> 1, b);
    }
    if(!(b&1)){
        return gcd(a, b >> 1);
    }
    int big = a > b ? a : b;
    int small = a < b ? a : b;
    return gcd(big - small, small);
}

int main()
{
    cout << gcd(110,1111) << endl;
    system("pause");
}
