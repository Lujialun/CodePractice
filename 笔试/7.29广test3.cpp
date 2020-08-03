/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-07-29 17:32:42
 * @LastEditors: Lucas
 * @LastEditTime: 2020-07-29 21:24:51
 */ 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n, m;
    while(cin>>n>>m){
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int b = a[n - 2], c = a[n - 1],cnt=0;
        for (int i = 0; i < n-2; i++){
            if(a[i]&b==a[i]||a[i]&c==a[i])
                continue;
            else{
                cnt++;
            }
        }
        if(cnt==1) cout << 2 << endl;
        else
            cout << 3 << endl;
    }
    system("pause");
    return 0;
}