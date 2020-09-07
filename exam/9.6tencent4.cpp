/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-06 19:57:21
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-06 21:49:39
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
bool comp(pii &a, pii &b){
    return a.first < b.first;
}
int main()
{
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].fir;
        a[i].se = i;
    }
    sort(a.begin(), a.end(), comp);
    int p = a[n / 2].first;
    int q = a[n / 2 - 1].first;
    vi res(n);
    for (int i = 0; i < a.size(); i++){
        if(a[i].first<p){
            res[a[i].second] = p;
        }else{
            res[a[i].second] = q;
        }
    }
    for(auto i:res){
        cout << i << endl;
    }
    
    system("pause");
    return 0;
}
