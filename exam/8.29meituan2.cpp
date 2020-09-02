/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-29 15:35:37
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-29 17:45:13
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
using namespace std;

void dfs(vv &a, vector<bool> &f, int now,int k, int cnt,int &res){
    if(now==k){
        res=cnt;
    }
    cnt++;
    f[now] = true;
    //cout << " here" << endl;
    for (int i = 0; i < a[now].size(); i++){
        if(!f[a[now][i]]){
            dfs(a, f, a[now][i], k, cnt, res);
        }
    }
    f[now] = false;
    cnt--;
}

int func1(vv &a, int x, int y){
    queue<int> q1;
    q1.push(y);
    int d = 0;
    vector<bool> m(a.size());
    while(true){
        queue<int> q2;
        while(!q1.empty()){
            int node = q1.front();
            q1.pop();
            m[node] = true;
            if(a[node].size()==1)
                return d;
            for (int i = 0; i < a[node].size(); i++){
                int n = a[node][i];
                if(m[n]||n==x)
                    continue;
                else{
                    q2.push(n);
                }
            }
        }
        d++;
        q1 = q2;
    }
}

int func2(vv &a, int x, int y){
    queue<int> q1;
    q1.push(x);
    int d = 0;
    vector<bool> m(a.size());
    while(true){
        d++;
        queue<int> q2;
        while(!q1.empty()){
            int node = q1.front();
            q1.pop();
            m[node] = true;
            if(a[node].empty())
                continue;
            for (int i = 0; i < a[node].size(); i++){
                int n = a[node][i];
                if(m[n])
                    continue;
                if(n==y)
                    return d;
                else{
                    q2.push(n);
                }
            }
           
        }
         q1 = q2;
    }
}
int main()
{
    int n, m, t;
    while(cin>>n>>m>>t){
        vector<vector<int>> g(n+1);
        int p, q;
        for(int i=0; i<n-1; i++){
            cin >> p >> q;
            g[p].push_back(q);
            g[q].push_back(p);
        }
        vector<bool> f(n, false);
        int res = 0;
       // dfs(g, f, m, t, 0, res);
        // if(g[t].size()==1)
        //     cout << res << endl;
        // else cout << res + 1 << endl;
        cout << func2(g,m,t) + func1(g, m, t)<<endl;
        ;
    }
   // system("pause");
    return 0;
}