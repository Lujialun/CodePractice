/*
 * @Descripttion: 
 * @version: 
 * @Author: sueRimn
 * @Date: 2020-07-08 16:46:45
 * @LastEditors: Lucas
 * @LastEditTime: 2020-07-28 20:37:17
 */ 
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    
    vector<long> num(n);
    map<long,int> m;
    long len = 0, weigh = 0;
    long res = -1;

    for(int i = 0; i < n; i++) {
        cin >> num[i];
        m[num[i]]++;   //对出现的边进行统计

        if(m[num[i]] == 2 && num[i] > 0) {   
            if(num[i] > len) {
                weigh = len;
                len = num[i];
                res = len*weigh;
            }
        } else if(m[num[i]] == 4){
            if(num[i] > 0 && res < num[i]*num[i])
                res = num[i]*num[i];
        }
    }
    if(res <= 0)
        cout << -1 << endl;
    else
        cout << res << endl;
    system("pause");
    return 0;
}