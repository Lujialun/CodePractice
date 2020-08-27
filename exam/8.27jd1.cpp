/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-27 15:31:50
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-27 20:02:21
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
    while(cin>>n){
        s = to_string(n);
        while(s.back()=='0'){
            s.pop_back();
        }
        //cout << s << endl;
        reverse(s.begin(), s.end());
        n = stoi(s);
        vector<int> res;
        while(n){
            res.push_back(n % 5);
            n = n / 5;
        }
        for (int i = res.size() - 1; i >= 0; --i)
            cout << res[i];
        cout << endl;
    }
  //  system("pause");
    return 0;
}