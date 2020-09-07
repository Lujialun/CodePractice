/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-06 19:57:02
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-06 20:48:43
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
#include <unordered_set>
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
int n, m, t;
vv team;
//int res = 0;
unordered_set<int> res;
void dfs(int pos,vector<bool> &know, vector<int>& p){
    if(know[pos])
        return;
    know[pos] = true;
   // res += team[pos].size();
    for (int i = 0; i < team[pos].size(); i++){
        int t=team[pos][i];
        res.insert(t);
        if(p[t]==0)
            continue;
        for (int j = 0; j < know.size(); j++){
            if(i!=j){
                auto it=find(team[j].begin(), team[j].end(), t);
                if(it!=team[j].end()){
                    dfs(j, know, p);
                }
            }
        }
    }
}
int main()
{
   
    cin >> n >> m;
    vector<bool> know(m,false);
    vector<int> p(n+1,-1);
    int zero_pos=-1,q=m;
    while(m--){
        cin >> t;
        int temp;
        vi tem;
        while(t--){
            cin >> temp;
            p[temp]++;
            if(temp==0){
                zero_pos = q - m;
            }
            tem.pb(temp);
        }
        team.pb(tem);
    }
    cout << zero_pos << endl;
    // if(zero_pos==-1){
    //     cout<<0<<endl;
    //     return 0;
    // }
    dfs(zero_pos, know, p);
    // for (int i = 0; i < know.size(); i++){
    //     if(know[i]){
    //         for (int j = 0; j < team[i].size(); j++)
    //     }
    // }

        cout << res.size() << endl;
    //for(team)
    system("pause");
    return 0;
}
