/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-01 18:25:36
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-01 20:36:53
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
#define vvb vector<vector<bool>>
using namespace std;


void dfs(vv &a, vvb &f, vector<pii> &t, int i, int j){
    int n = a.size(), m = a[0].size();
    if(i<0||i>=n||j<0||j>=m||f[i][j]||!a[i][j]){
        return;
    }
    t.push_back(make_pair(i, j));
    f[i][j] = 1;
    dfs(a, f, t, i - 1, j);
    dfs(a, f, t, i + 1, j);
    dfs(a, f, t, i, j-1);
    dfs(a, f, t, i, j+1);
}
int main()
{
     int n,m;
    while(cin>>n>>m){
        vv a(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin>>a[i][j];
        //        if(a[i][j]==1)
                    //cnt++;
            }
        }
        vector<vector<pii>> s;
        vector<pii> t;
        vvb f(n, vector<bool>(m, 0));
        for (int i = 0; i < a.size(); i++){
            for (int j = 0; j < a[0].size(); j++){
                if(!f[i][j]&&a[i][j]){
                    dfs(a, f, t, i, j);
                    s.push_back(t);
                    t.clear();
                }
            }
        }
        vector<int> b;
        for (int i = 0; i < s.size(); i++){
            //cout << s[i].size() << endl;
            b.push_back(s[i].size());
        }
        sort(b.begin(), b.end());
        cout << b[b.size() - 1] + b[b.size() - 2] << endl;
    }
    system("pause");
    return 0;
}