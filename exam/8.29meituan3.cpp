/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-29 15:49:16
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-29 16:22:12
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
    string s;
    while(cin>>n>>s){
        bool frontM = false;
        bool backT = false;
        int i,l,r;
        for (i = 0; i < n; i++)
        {
            if(s[i]=='M')
                frontM = true;
            if(s[i]=='T'&&frontM){
                l = i;
                break;
            }
        }

        for (i = n - 1; i >= 0; i--){
            if(s[i]=='T')
                backT = true;
            if(s[i]=='M'&&backT){
                r = i;
                break;
            }
        }
        cout << s.substr(l+1, r - l-1) << endl;
    }
    system("pause");
    return 0;
}