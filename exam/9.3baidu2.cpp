/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-03 18:48:37
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-03 21:18:31
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

bool comp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}
int main()
{
    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<pair<int,int>> actor(n);
        vector<pair<int,int>> ch(m);
        for (int i = 0; i < n; i++){
            cin >> actor[i].first;
            actor[i].second = i;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> ch[i].first;
            ch[i].second = i;
        }
        sort(actor.begin(), actor.end(),comp);
        sort(ch.begin(), ch.end(),comp);
        int i = 0, j = 0;
        vi res(n,-1);
        while(i<n&&j<m){
            if(actor[i]<=ch[j]){
                res[i++] = ch[j].second+1;
            }
            j++;
        }
        for (int i = 0; i < n - 1; i++){

            cout << res[i] << " ";
        }
        cout <<res[n-1]<< endl;
    }
   // system("pause");
    return 0;
}