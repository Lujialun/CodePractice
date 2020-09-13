/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-12 15:35:50
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-12 15:47:02
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

bool judge(string &s){
    for (int i = 0; i < s.size() / 2; i++){
        if(s[i]!=s[s.size()-1-i])
            return false;
    }
    return true;
}
int main()
{
    string s;
    while(cin>>s){
        int res = 0;
        for (int i = 0; i < s.size(); i++){
            for (int j = 1; j < s.size() + 1 - i; j++){
                string tmp = s.substr(i, j);
                if(judge(tmp)){
                    res++;
                }
            }
        }
        cout << res-s.size() << endl;
    }
    system("pause");
}