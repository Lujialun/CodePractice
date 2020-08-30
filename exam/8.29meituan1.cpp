/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-29 15:34:37
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-29 16:31:59
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

int main()
{
    int n;
    while(cin>>n){
        vector<vector<int>> a(n,vector<int>(n));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> a[i][j];
            }
        }
        bool p[n+1];
        cl(p, false);
        vector<int> res;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(!p[a[i][j]]){
                    res.push_back(a[i][j]);
                    p[a[i][j]] = true;
                    break;
                }
            }
        }
        for(auto i:res){
            cout << i << " ";
        }
        cout << endl;
    }
    //system("pause");
    return 0;
}