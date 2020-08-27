/*
 * @Descripttion: 不管是不是最小值重复就改第二个重复的值，第一个重复值改成0
 * @version: 
 * @Author: Lucas
 * @Date: 2020-07-29 17:32:28
 * @LastEditors: Lucas
 * @LastEditTime: 2020-07-29 20:45:41
 */ 
#include<iostream>
#include<vector>
#include<algorithm>
#include <map>
#include<queue>
using namespace std;


int main()
{
    int n;
    queue<int> a;
    while(cin>>n){
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        map<int, int> m;
        for (int i = 0; i < n; i++){
            int temp=a[i];
            while(m.find(temp)!=m.end()){
        
                m.erase(temp);
                temp = temp * 2;
            }
            m[temp] = i;
        }
        vector<int> b(n, 0);
        for (auto it = m.begin(); it != m.end(); it++){
            b[it->second] = it->first;
        }
        for (int i = 0; i < n; i++){
            if(b[i]!=0)
                cout << b[i] << " ";
        }
    }
    system("pause");
    return 0;
}