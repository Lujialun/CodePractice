/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-25 11:01:40
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-25 15:14:44
 */
#include <bits\stdc++.h>

using namespace std;
//找出一个数组中重复的两个数
int main()
{
    vector<int> a = {1, 5, 2, 3, 4, 5};
    int f=0;
    for (int i = 0; i < a.size(); i++){
        f ^= a[i];
    }

    for (int i = 1; i < a.size(); i++){
        f ^= i;
    }
    cout << f << endl;
    system("pause");
}