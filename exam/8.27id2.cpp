/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-08-27 15:31:50
 * @LastEditors: Lucas
 * @LastEditTime: 2020-08-27 22:09:11
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

int fund(int n){
    int res = 1;
    for (int i = 1; i <= n; ++i){
        res *= i;
        res = res % (1e9 + 7);
    }
}

int func(int i){
    int count = 0;
    while(i){
        if(i&1){
            ++count;
        }
        i >>= 1;
    }
    return count;
}

vv calc(int n, int m, vector<int> & a)
{
    int len = a.size();
    vv res;
    for (int i = 0; i < 1 << len; i++){
        if(func(i)==n){
            int s = 0;
            vector<int> temp;
            for (int j = 0; j < len; j++){
                if(i&1<<(len-1-j)){
                    s += a[j];
                    temp.push_back(a[j]);
                }
            }
            if(s==m){
                res.push_back(temp);
            }
        }
    }
    return res;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> card(n);
    for (int i = 0; i<n; i++){
        cin >> card[i];
    }
    sort(card.begin(), card.end());
    while(card.back()>m)
        card.pop_back();
    n = card.size();
    //vector<int> dp(n);
    for (int i = 1; i <= n; i++){
        vv res = calc(2, m, card);
        res.size()
    }

    
    //cout << res.size() << endl;
    // for (int i = 0; i < res.size(); i++){

    // }

        system("pause");
    return 0;
}