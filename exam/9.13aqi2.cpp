/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-13 15:37:52
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-13 15:54:52
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
#define fir first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define ull unsigned long long
#define ui unsigned int
#define cl(a, b) memset(a, b, sizeof(a))
#define quickio(a) ios::sync_with_stdio(a)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define vv vector<vector<int>>
#define vi vector<int>
using namespace std;

int main()
{
    vv res;
    vi a;
    int t;
    while(cin>>t){
        a.push_back(t);
    }
    //f(a.size()<3)
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++){
        if(i==0||a[i]!=a[i-1]){
            int t = a.size() - 1;
            for (int j = i + 1; j < t; j++){
                if(j==i+1||a[j]!=a[j-1]){
                    while(t>j&&a[i]+a[j]+a[t]>0){
                        t--;
                    }
                    if(i<j&&j<t&&a[i]+a[j]+a[t]==0){
                        vi tmp = {a[i], a[j], a[t]};
                        res.push_back(tmp);
                    }
                }
            }
        }
    }
    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[0].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
        system("pause");
}