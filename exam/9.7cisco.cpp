/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-07 20:23:45
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-07 20:34:05
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

bool flag = false;
void dfs(vector<int> &a,int k){
    if(k==a.size()-1){
        flag = true;
        return;
    }
    int t = a[k];
    for (int i = 1; i <= t; ++i ){
        k += i;
        dfs(a, k);
        k -= i;
    }
}
int main()
{
    string arr;
    cin >> arr;
    vector<int> a;
    int i = 1, j = arr.size() - 1,tem;
    string temp;
    while(i<j){
        tem = i;
        while(i<j&&arr[i]!=',')
            i++;
        temp = arr.substr(tem, i - tem);
        i++;
        a.pb(stoi(temp));
    }
    dfs(a, 0);
    if(flag){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    }
    system("pause");
    return 0;
}
