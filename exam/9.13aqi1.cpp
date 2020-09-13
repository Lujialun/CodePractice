/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-13 15:31:49
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-13 15:36:03
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
    string s;
    while(cin>>s){
        int l = s.length();
        if(l==0){
            cout << 0 << endl;
            continue;
        }
        vi dic(256);
        int res = 1;
        int i = 0, j = 0;
        while(j<l){
            dic[s[j]]++;
            while(dic[s[j]]>1){
                dic[s[i]]--;
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        cout << res << endl;
    }
}