/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-13 17:34:27
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-13 18:05:31
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
    int n;
    vv a;
    string s;
    // char c,q,w,e;
    // cin >> c;
    // n = c - '0';
    // cin >> c;
    // while(cin>>q>>w>>e){
    //     a.pb({q - '0', e - '0'});
    // }
    getline(cin, s);
    n = s[0] - '0';
    vi tem;
    for (int i = 1; i < s.size(); i++){
        if(s[i]>='0'&&s[i]<='9')
            tem.pb(s[i] - '0');
    }
    for (int i = 0; i < tem.size() - 1; i++){
        a.pb({tem[i], tem[i + 1]});
        i++;
    }
        vv edg(n);
    vi indegree(n);
    int t = a.size();
    for (int i = 0; i < t; i++){
        indegree[a[i][0]]++;
        edg[a[i][1]].pb(a[i][0]);
    }
    queue<int> que;
    for (int i = 0; i < n; i++){
        if(indegree[i]==0){
            que.push(i);
        }
    }
    int vis = 0;
    while(!que.empty()){
        ++vis;
        int cur = que.front();
        que.pop();
        int k = edg[cur].size();
        for (int i = 0; i < k; ++i){
            indegree[edg[cur][i]]--;
            if(indegree[edg[cur][i]]==0){
                que.push(edg[cur][i]);
            }
        }
    }
    bool f = vis == n ? 1 : 0;
    cout << f<<endl;
}