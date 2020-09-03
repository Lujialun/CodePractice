/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-03 18:46:58
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-03 19:50:59
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
#define vl vector<int>
using namespace std;

int main()
{
    int t,l,n;
    cin >> t;
    while(t--){
        cin >> l >> n;
        vv a(n, vl(2));
        for (int i = 0; i < n; i++){
            cin >> a[i][0] >> a[i][1];
        }
        vector<int> res(l,0);
        for (int i = 0; i < n; i++){
            for (int j = a[i][0] - 1; j < a[i][1]; j++){
                res[j]++;
            }
        }
        for(int i:res){
            cout << i << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}