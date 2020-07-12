/*
 * @Descripttion: 树状数组 leetcode 315 https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-11 10:46:02
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-11 15:24:44
 */ 
#include <iostream>
#include <vector>
using namespace std;

vector<int> c(11);
vector<int> a(11);
int lowbit(int x)
{
    return x & (-x);
}

int getSum(int x)
{
    int res = 0;
    while(x>0){
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}

void update(int x, int value)
{
    a[x] += value;
    while(x<=a.size()){
        c[x] += value;
        x += lowbit(x);
    }
}
int main()
{ 
    c.resize(a.size(), 0);
    for (int i = 1; i < 11; i++){
        update(i, i);
    }
    for (int i = 1; i < 11; i++){
        cout << getSum(i) << " ";
    }

    system("pause");
    return 0;
}

//https://www.cnblogs.com/findview/archive/2019/08/01/11281628.html