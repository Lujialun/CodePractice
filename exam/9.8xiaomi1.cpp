/*
 * @Descripttion: 
 * @version: 
 * @Author: Lucas
 * @Date: 2020-09-08 18:30:36
 * @LastEditors: Lucas
 * @LastEditTime: 2020-09-08 18:37:28
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

int main(){
    string s;
    while(cin>>s){
        int n = s.size();
        int digit = 0, upper = 0, lower = 0, sy = 0;
        if(n<8||n>120){
            cout << 1 << endl;
            continue;
        }
        for(auto i:s){
            if(i>='0'&&i<='9'){
                digit = 1;
            }else if( i>='a'&&i<='z'){
                lower = 1;
            }else if(i>='A'&&i<='Z'){
                upper = 1;
            }else{
                sy = 1;
            }
        }
        if(digit&&upper&&lower&&sy){
            cout << 0 << endl;
        }else{
            cout << 2 << endl;
        }

    }
    system("pause");
}