/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-11 21:05:12
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-11 22:00:27
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
    int n, m;
    cin >> n >> m;
    vector<pii> a(m);
    for (int i = 0; i < m; i++){
        cin >> a[i].first >> a[i].second;
    }
    vi res;
    vi f1(n+1, 0);
    if(a[0].first==a[m-1].first){
        f1[a[0].first] += 2;
        for (int i = 1; i < m - 1; i++){
            f1[a[i].first]++;
        }
        int t = true;
        for (int i = 1; i <= n;  i++)
        {
            if(f1[i]==1){
                t = false;
            }
            if(f1[i]==0){
                res.push_back(i);
            }
        }
        if(t){
            res.push_back(a[0].first);
        }
        //for(int )
    }else{
        vi f0(n+1, 0);
         for (int i = 0; i < m ; i++){
            if(a[i].second==1){
                f1[a[i].first]++;
            }else{
                f0[a[i].first]++;
            }
        }
        if(a[0].second==0){
            if(a[m-1].second==0&&f1[a[m-1].first]==0){
                res.push_back(a[m - 1].first);
                f1[a[m - 1].first] == 1;
            }
            
        }else if(a[0].second==1){
             if(f0[a[0].first]==0&&a[m-1].second==1){
                res.push_back(a[0].first);
                f1[a[0].first] == 1;
            }
        }
        for (int i = 1; i <= n; i++){
                if(!f1[i]&&!f0[i]){
                    res.push_back(i);
        //            cout << i <<" hh"<< endl;
                }
            }
    }
    sort(res.begin(), res.end());
    for(auto i:res){
        //if()
        cout << i << " ";
    }
    cout << endl;
    system("pause");
}