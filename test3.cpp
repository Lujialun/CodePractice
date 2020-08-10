/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-07-29 17:32:42
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-08 15:24:19
 */ 
#include<bits/stdc++.h>
using namespace std;


int main()
{
    string s;
    while(cin>>s){//kmp算法
        string r=s;
        reverse(s.begin(), s.end());
        int len=s.size();
        s=' '+s+'#'+r;
        int n=s.size();
        vector<int>next(n,0);
        for(int i=2,j=0; i<n; i++){ 
            while (j&&s[i]!=s[j+1]) j=next[j];
            if (s[i]==s[j+1]) j++;
            next[i]=j;
        }
        cout<<s.substr(len+2, len-next[n-1])+s.substr(1, len)<<endl;;
    }
    return 0;
}