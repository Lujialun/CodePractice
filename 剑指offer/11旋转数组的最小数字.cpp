/*
 * @Descripttion: 剑指 Offer 11. 旋转数组的最小数字 https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-by-leetcode-s/
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-22 16:28:41
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-07-22 16:51:50
 */ 
 #include <bits/stdc++.h>
using namespace std;
 int minArray(vector<int>& a) {
        int len=a.size();
        int l=0,r=len-1,m;
        if(a[l]<a[r]||a.size()==1) return a[0];
        while(l<r){
            m=(l+r)/2;
            if(a[m]>a[r])
                l += 1;
            else if(a[m]<a[r])
                r = m;
            else
                r--;
        }
        return a[l];
    }
int main()
{
    vector<int> a = {5, 6, 7, 8, 8, 8, 1, 1, 2, 3, 4};
    cout << minArray(a) << endl;
    system("pause");
    return 0;
}