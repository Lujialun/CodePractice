/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-07-29 17:32:28
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-02 20:52:07
 */ 
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    while(cin>>m>>n){
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        if(m!=0&&n==0){
            cout<<m<<endl;
            continue;  
        } 
        if(m<0||m>600||n<1||n>100) continue;
        if(m==0&&n==1){
            cout<<"paradox"<<endl;
            continue;
        }
        int back = 0;
        bool flag = false;
        for(int i=0; i<n; i++){
            if(m==a[i]&&i!=n-1){
                flag = true;
                break;
            }
            if(m>a[i]) m -= a[i];
            else{
                back++;
                m = a[i] - m;
            }
        }
        if(flag){
            cout<<"paradox"<<endl;
        }
        else{
            cout << m << " " << back << endl;
        }
    }
   
   // system("pause");
    return 0;
}